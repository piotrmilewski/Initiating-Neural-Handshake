#include "pipe_networking.h"


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char[BUFFER_SIZE] msg_from_client;
  read(from_client, msg_from_client, BUFFER_SIZE);

  char[BUFFER-SIZE] msg_to_client;
  msg_to_client = do_stuff(msg_from_client);

  write(to_client, msg_to_client, BUFFER_SIZE);
}
