#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {

  int to_server;
  int *clientPID;
  
  mkfifo( "toServer", 0644);
  to_server = open( "toServer", O_RDONLY);

  read(to_server, clientPID, sizeof(clientPID)); 

  remove("toServer");
  
  *to_client = open( clientPID, O_WRONLY);
  
  write( *to_client, ACK, HANDSHAKE_BUFFER_SIZE);
  
  return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Perofrms the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  return 0;
}
