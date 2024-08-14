#include <arpa/inet.h> // For inet_pton and sockaddr_in
#include <cstdio>      // For perror
#include <cstdlib>     // For exit and EXIT_FAILURE
#include <cstring>     // For strlen
#include <iostream>    // For std::cout
#include <unistd.h>    // For close and other POSIX functions

#define PORT 8084 // Define the port number to be used

int main() {
  int server_fd, new_socket;
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  const char *message = "Hello from server";

  // Creating socket file descriptor
  // AF_INET: IPv4, SOCK_STREAM: TCP, 0: default protocol
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("socket failed"); // Print error if socket creation fails
    exit(EXIT_FAILURE);      // Exit the program with failure status
  }

  // Attaching socket to the port 8084
  // SOL_SOCKET: Socket level, SO_REUSEADDR: Allow reuse of local addresses
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                 sizeof(opt))) {
    perror("setsockopt"); // Print error if setting socket options fails
    exit(EXIT_FAILURE);   // Exit the program with failure status
  }

  address.sin_family = AF_INET; // Address Family IPv4 (INET=IPv4, INET6=IPv6)
  address.sin_addr.s_addr = INADDR_ANY; // Bind to any local address
  address.sin_port = htons(PORT); // Convert port number to network byte order

  // Binding socket to the address
  // Cast address to sockaddr* and provide its size
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("bind failed"); // Print error if binding fails
    exit(EXIT_FAILURE);    // Exit the program with failure status
  }

  // Listening for incoming connections
  // 3: maximum number of pending connections in the queue
  if (listen(server_fd, 3) < 0) {
    perror("listen");   // Print error if listening fails
    exit(EXIT_FAILURE); // Exit the program with failure status
  }

  std::cout << "Server is listening on port " << PORT << std::endl;

  // Accepting an incoming connection
  // Cast address to sockaddr* and provide its size
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                           (socklen_t *)&addrlen)) < 0) {
    perror("accept");   // Print error if accepting connection fails
    exit(EXIT_FAILURE); // Exit the program with failure status
  }

  // Sending a message to the client
  // new_socket: connected socket, message: message to send, strlen(message):
  // message length, 0: no flags
  send(new_socket, message, strlen(message), 0);
  std::cout << "Hello message sent" << std::endl;

  // Closing the socket
  close(new_socket); // Close the connected socket
  close(server_fd);  // Close the listening socket

  return 0; // Return success status
}

