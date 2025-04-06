#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <open62541/plugin/log_stdout.h>
#include <signal.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

/* Global variables */
static volatile UA_Boolean running = true;
static const int SESSION_DURATION = 10;   // Force-close session after 10 seconds
static UA_NodeId currentSessionId;          // To store the active session ID

/* Global pointer to store the default session activation callback */
static UA_ActivateSessionCallback defaultActivateSession = NULL;

/* Signal handler for clean shutdown */
static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER,
                "Received signal %d. Stopping server", sign);
    running = false;
}

/* One-shot callback to force-close the current session */
static void forceCloseSessionCallback(UA_Server *server, void *data) {
    if (!UA_NodeId_equal(&currentSessionId, &UA_NODEID_NULL)) {
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                    "Force closing session with ID: %u",
                    currentSessionId.identifier.numeric);
        UA_StatusCode retval = UA_Server_closeSession(server, &currentSessionId);
        if (retval == UA_STATUSCODE_GOOD) {
            UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                        "Session closed successfully.");
        } else {
            UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                           "Error closing session: 0x%08x", retval);
        }
        UA_NodeId_clear(&currentSessionId); /* Reset current session ID */
    }
}

/* Custom session activation callback.
   - Saves the session ID and schedules a one‑shot callback to force-close it after SESSION_DURATION seconds.
   - Then calls the default activation routine to properly initialize the session.
*/
static UA_StatusCode customActivateSession(UA_Server *server,
                                             UA_AccessControl *ac,
                                             const UA_EndpointDescription *endpoint,
                                             const UA_ByteString *secureChannelRemoteCertificate,
                                             const UA_NodeId *sessionId,
                                             const UA_ExtensionObject *userIdentityToken,
                                             void **sessionContext) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Activating new session.");
    currentSessionId = *sessionId;  /* Save the session ID globally */
    /* Schedule a one-shot callback to force-close this session after SESSION_DURATION seconds */
    UA_Server_addTimedCallback(server, forceCloseSessionCallback, NULL,
                               (UA_Double)SESSION_DURATION * 1000, NULL);
    /* Call the default activation routine to properly initialize the session */
    return defaultActivateSession(server, ac, endpoint,
                                  secureChannelRemoteCertificate, sessionId,
                                  userIdentityToken, sessionContext);
}

int main(void) {
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    /* Create the OPC UA server and get its configuration */
    UA_Server *server = UA_Server_new();
    UA_ServerConfig *config = UA_Server_getConfig(server);

    /* Use minimal configuration on port 4848 with no certificate (None/None mode) */
    UA_ServerConfig_setMinimal(config, 4848, NULL);

    /* Initialize the global session ID to UA_NODEID_NULL */
    currentSessionId = UA_NODEID_NULL;

    /* Set a maximum session timeout (e.g., 60000 ms = 60 s) */
    config->maxSessionTimeout = 60000;
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Session timeout set to: %f ms", config->maxSessionTimeout);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Server running at opc.tcp://0.0.0.0:4848. A session will be forced closed after %d s.", SESSION_DURATION);

    /* --- Add default anonymous user token policy if missing --- */
    for (size_t i = 0; i < config->endpointsSize; i++) {
        if (config->endpoints[i].userIdentityTokensSize == 0) {
            UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                        "Adding default anonymous user token policy to endpoint %zu", i);
            UA_UserTokenPolicy anonPolicy;
            UA_UserTokenPolicy_init(&anonPolicy);
            anonPolicy.tokenType = UA_USERTOKENTYPE_ANONYMOUS;
            anonPolicy.policyId = UA_STRING("anonymous");

            size_t newSize = config->endpoints[i].userIdentityTokensSize + 1;
            config->endpoints[i].userIdentityTokens = (UA_UserTokenPolicy*)
                realloc(config->endpoints[i].userIdentityTokens,
                        newSize * sizeof(UA_UserTokenPolicy));
            if(!config->endpoints[i].userIdentityTokens) {
                UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                               "Memory allocation failed while adding anonymous policy");
                continue;
            }
            config->endpoints[i].userIdentityTokens[config->endpoints[i].userIdentityTokensSize] = anonPolicy;
            config->endpoints[i].userIdentityTokensSize = newSize;
        }
    }
    /* --- End default anonymous policy --- */

    /* Retrieve the default access control and store its activation callback */
    UA_AccessControl acDefault = UA_AccessControl_default();
    defaultActivateSession = acDefault.activateSession;

    /* Override only the activateSession callback with our custom implementation */
    UA_AccessControl ac = acDefault;
    ac.activateSession = customActivateSession;
    config->accessControl = ac;

    /* Run the server loop; the server remains running until a termination signal is received */
    UA_StatusCode retval = UA_Server_run(server, &running);
    UA_Server_delete(server);
    return (retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE);
}
