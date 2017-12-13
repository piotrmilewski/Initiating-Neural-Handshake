#include "pipe_networking.h"

/*
char do_stuff(char msg){
  return msg;
}
*/

int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char msg_from_client[BUFFER_SIZE];
  read(from_client, msg_from_client, BUFFER_SIZE);

  char msg_to_client[BUFFER_SIZE];
  sprintf(msg_to_client, "%s", msg_from_client);

  write(to_client, msg_to_client, BUFFER_SIZE);
}
