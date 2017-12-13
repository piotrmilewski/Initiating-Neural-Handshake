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

  char buf[BUFFER_SIZE];
  read(from_client, buf, BUFFER_SIZE);

  write(to_client, buf, BUFFER_SIZE);
}
