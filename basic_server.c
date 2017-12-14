#include "pipe_networking.h"


void rot13(char* msg){
  while(*msg){
    if((*msg >= 'a' && *msg <= 'm') || (*msg >= 'A' && *msg <= 'M')){
      printf("adding\n");
      *msg += 13;
    } 
    else if((*msg >= 'n' && *msg <= 'z')||(*msg >= 'N' && *msg <= 'Z')) {
      printf("subtracting\n");
      *msg -= 13;
    }
    msg ++;
  }
}


int main() {

  int to_client;
  int from_client;

  from_client = server_handshake( &to_client );

  char buf[BUFFER_SIZE];
  read(from_client, buf, BUFFER_SIZE);

  rot13(buf);
  
  write(to_client, buf, BUFFER_SIZE);
}
