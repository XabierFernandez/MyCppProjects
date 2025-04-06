#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <open62541/plugin/log_stdout.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

/* Global variables */
static volatile UA_Boolean running = true;
static const int SESSION_DURATION = 10; // Delay (in seconds) before closing the session

/* Structure to pass data to the thread that closes the session */
typedef struct {
    UA_Server *server;
    UA_NodeId sessionId;
} CloseSessionData;

/* Thread function: waits SESSION_DURATION seconds then closes the session */
void *closeSessionThread(void *arg) {
    CloseSessionData *data = (CloseSessionData *)arg;
    sleep(SESSION_DURATION);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, 
                "Force closing session with ID: %u", 
                data->sessionId.identifier.numeric);
    UA_StatusCode ret = UA_Server_closeSession(data->server, &data->sessionId);
    if(ret == UA_STATUSCODE_GOOD) {
        UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Session closed successfully.");
    } else {
        UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, 
                       "Error closing session: 0x%08x", ret);
    }
    UA_NodeId_clear(&data->sessionId);
    free(data);
    return NULL;
}

/* Global pointer to store the default session activation callback */
static UA_StatusCode (*defaultActivateSession)(UA_Server *server,
    UA_AccessControl *ac,
    const UA_EndpointDescription *endpoint,
    const UA_ByteString *secureChannelRemoteCertificate,
    const UA_NodeId *sessionId,
    const UA_ExtensionObject *userIdentityToken,
    void **sessionContext) = NULL;

/* Signal handler for clean shutdown */
static void stopHandler(int sign) {
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_SERVER, 
                "Received signal %d. Stopping server", sign);
    running = false;
}

/* Custom session activation callback.
   It first calls the default activation callback.
   If activation succeeds, it spawns a thread that will close the session after SESSION_DURATION seconds.
*/
static UA_StatusCode customActivateSession(UA_Server *server,
    UA_AccessControl *ac,
    const UA_EndpointDescription *endpoint,
    const UA_ByteString *secureChannelRemoteCertificate,
    const UA_NodeId *sessionId,
    const UA_ExtensionObject *userIdentityToken,
    void **sessionContext) {

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Activating new session.");
    UA_StatusCode ret = defaultActivateSession(server, ac, endpoint,
                                               secureChannelRemoteCertificate,
                                               sessionId, userIdentityToken,
                                               sessionContext);
    if(ret == UA_STATUSCODE_GOOD) {
        /* Allocate and fill data for the thread */
        CloseSessionData *data = malloc(sizeof(CloseSessionData));
        if(data) {
            data->server = server;
            data->sessionId = *sessionId;
            pthread_t tid;
            /* Spawn the thread that will close the session after SESSION_DURATION seconds */
            if(pthread_create(&tid, NULL, closeSessionThread, data) == 0) {
                pthread_detach(tid);
            } else {
                UA_LOG_WARNING(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND, "Failed to create session closing thread.");
                free(data);
            }
        }
    }
    return ret;
}

int main(void) {
    signal(SIGINT, stopHandler);
    signal(SIGTERM, stopHandler);

    UA_Server *server = UA_Server_new();
    UA_ServerConfig *config = UA_Server_getConfig(server);
    UA_ServerConfig_setMinimal(config, 4848, NULL);

    /* Optionally, set a maximum session timeout */
    config->maxSessionTimeout = 60000;
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Session timeout set to: %f ms", config->maxSessionTimeout);
    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Server running at opc.tcp://0.0.0.0:4848", 0);

    /* Use the default access control settings */
    UA_AccessControl acDefault = config->accessControl;
    defaultActivateSession = acDefault.activateSession;
    UA_AccessControl ac = acDefault;
    ac.activateSession = customActivateSession;
    config->accessControl = ac;

    UA_StatusCode retval = UA_Server_run(server, &running);
    UA_Server_delete(server);
    return (retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE);
}
