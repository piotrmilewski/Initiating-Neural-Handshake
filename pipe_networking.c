#include "pipe_networking.h"


/*=========================
  server_handshake
  args: int * to_client

  Performs the client side pipe 3 way handshake.
  Sets *to_client to the file descriptor to the downstream pipe.

  returns the file descriptor for the upstream pipe.
  =========================*/
int server_handshake(int *to_client) {

  int to_server, clientPID;
  
  mkfifo( "toServer", 0644);
  to_server = open( "toServer", O_RDONLY);

  read(to_server, clientPID, sizeof(clientPID)); 

  close("toServer");
  
  *to_client = open( clientPID, O_WRONLY);

  close(*to_client);
  
  write( *to_client, ACK, HANDSHAKE_BUFFER_SIZE);

  return 0;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {
  *to_server = open("toServer", O_WRONLY);
  mkfifo(getpid(), 0644);
  int to_client = open(getpid(), O_RDONLY);
  int *client = getpid();
  
  write(*to_server, client, HANDSHAKE_BUFFER_SIZE);

  char* msg;
  read(*to_client, msg, HANDSHAKE_BUFFER_SIZE);

  close(getpid());
  
  write(*to_server, msg, HANDSHAKE_BUFFER_SIZE);
  
  return 0;
}
