#include<signal.h> 
#include<unistd.h>  
#include<stdio.h> 
#include<stdlib.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 


int main() {
  int num;
  char str1[10] = "parar";
  char str2[10] = "continuar";
  char str3[10] = "terminar";
  char cadena[10];

  //printf("Num Proces\n");
  //scanf("%d",&num);

  pid_t pid;
  pid = 2649; 

  while(1){
    printf("Introduce una cadena:\n");
    scanf("%s",cadena);

    if(strcmp(cadena,str1)==0)
     {
       printf("STOP\n");
       kill(pid,SIGSTOP);
     }
     else if(strcmp(cadena,str2)==0)
    {
       printf("RESTART\n");
       kill(pid,SIGCONT);
    }
    else if(strcmp(cadena,str3)==0)
    {
      printf("TERMINATE\n");
      kill(pid,SIGQUIT);
      return 0;
    }
  }
  return 0; 
} 
