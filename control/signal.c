/*Sobre escribe al programa no crea otro
*/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc,char* argv[]) {
  int pid;
   
    for(int i=0; i<argc; i++)
  {
   printf("argv: %s\n",argv[i]);
  }
  argv[2]="c";
  pid = atoi(argv[1]);
  kill(pid,SIGINT);
  //execv("./exec",argv);
  printf("END SIGNAL\n");

  return 0;
}
