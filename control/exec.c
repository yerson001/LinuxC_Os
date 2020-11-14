#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void parar(int);

int main(int argc, char* argv[]) {
  signal(SIGINT,parar);
  int contador = 0;
  while(1){
    sleep(1);
    printf("exec en ejecusion: %i %i\n",getpid(),++contador);
  }
  return 0;
}

void parar(int n) {
  printf("Call thread\n");
  char*argv2[] = {"./thread",NULL};
  execv("./thread",argv2);
}
