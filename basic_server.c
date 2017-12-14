#include "pipe_networking.h"


void do_stuff(char* msg){
  char* temp = msg;
  while(*temp){
    if((*temp >= 'a' && *temp <= 'm') || (*temp >= 'A' && *temp <= 'M')){
      printf("adding\n");
      *temp += 13;
    } 
    else if((*temp >= 'n' && *temp <= 'z')||(*temp >= 'N' && *temp <= 'Z')) {
      printf("subtracting\n");
      *temp -= 13;
    }
    temp ++;
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
