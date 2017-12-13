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
  char clientPID[HANDSHAKE_BUFFER_SIZE];
  
  mkfifo( SERVERNAME, 0644);
  to_server = open( SERVERNAME, O_RDONLY);

  read(to_server, clientPID, HANDSHAKE_BUFFER_SIZE); 

  remove(SERVERNAME);
  
  *to_client = open( clientPID, O_WRONLY);
  
  write( *to_client, ACK, HANDSHAKE_BUFFER_SIZE);

  char msg[HANDSHAKE_BUFFER_SIZE];
  read(to_server, msg, HANDSHAKE_BUFFER_SIZE);

  printf("%s\n", msg);
  
  return to_server;
}


/*=========================
  client_handshake
  args: int * to_server

  Performs the client side pipe 3 way handshake.
  Sets *to_server to the file descriptor for the upstream pipe.

  returns the file descriptor for the downstream pipe.
  =========================*/
int client_handshake(int *to_server) {

  *to_server = open(SERVERNAME, O_WRONLY);

  char client[HANDSHAKE_BUFFER_SIZE];
  sprintf(client, "%d",  getpid());

  mkfifo(client, 0644);
  
  write(*to_server, client, HANDSHAKE_BUFFER_SIZE);
  
  int to_client = open(client, O_RDONLY);
  
  char msg[HANDSHAKE_BUFFER_SIZE];
  read(to_client, msg, HANDSHAKE_BUFFER_SIZE);

  remove(client);
  
  write(*to_server, msg, HANDSHAKE_BUFFER_SIZE);
  
  return to_client;
}
