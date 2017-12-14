#include "pipe_networking.h"


void do_stuff(char* msg){
  while(*msg){
    if(*msg >= 'a' && *msg <= 'm')
      *msg += 13;
    if(*msg >= 'n' && *msg <= 'z')
      *msg -= 13;
    msg ++;
  }
}


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char buf[BUFFER_SIZE];
  read(from_client, buf, BUFFER_SIZE);

  do_stuff(buf);
  
  write(to_client, buf, BUFFER_SIZE);
}
