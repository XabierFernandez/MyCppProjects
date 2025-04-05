#include <stdio.h>
#include <stdlib.h>
#include <open62541/server.h>
#include <open62541/server_config_default.h>
#include <open62541/plugin/log_stdout.h>

volatile UA_Boolean running = true;

int main(void) {
    // Create a new OPC UA server instance
    UA_Server *server = UA_Server_new();
    UA_ServerConfig *config = UA_Server_getConfig(server);

    // Use the minimal configuration on port 4840
    UA_ServerConfig_setMinimal(config, 4840, NULL);

    // Set a very short session timeout (in milliseconds)
    config->sessionTimeout = 1000;

    UA_LOG_INFO(UA_Log_Stdout, UA_LOGCATEGORY_USERLAND,
                "Session timeout set to: %f ms", config->sessionTimeout);

    // Run the server (this call blocks until running becomes false)
    UA_StatusCode retval = UA_Server_run(server, &running);

    // Clean up
    UA_Server_delete(server);
    return (retval == UA_STATUSCODE_GOOD ? EXIT_SUCCESS : EXIT_FAILURE);
}

