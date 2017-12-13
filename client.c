#include "pipe_networking.h"


int main() {

  int to_server;
  int from_server;

  from_server = client_handshake( &to_server );

  char buf[BUFFER_SIZE];
  printf("Enter some text: ");
  fgets(buf, BUFFER_SIZE, stdin);

  write( to_server, buf, BUFFER_SIZE);

  read( from_server, buf, BUFFER_SIZE);
}
