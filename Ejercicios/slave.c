#include <stdio.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  printf("%s:%i\n",argv[0],getpid());
  
  for(int i=0; i<argc; i++)
  {
   printf("Arguments %s\n",argv[i]);
  }
  return 0;
}
