#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

/* int fd [2];
*tubería (fd);
*fd [0]; // -> para usar read end 
*fd [1]; // -> para usar escribir end
*/

int main() {

  //declaramos los pipes
  int fd1[2];
  int fd2[2];
  
  //la cadena
  char fixer[] = "-hola";
  char input_std[100];
  
  //declaramos la PID
  pid_t p;

  if(pipe(fd1)==-1)
  {
     printf("pipe fallo\n");
     return 1;
  }
  if(pipe(fd2)==-1)
  {
     printf("pipe fallo\n");
     return 1;
  }

  scanf("%s",input_std);

  p = fork();

  if(p < 0)
  { 
     printf("fork fallo\n");
     return 1;
  }
  else if(p > 0)
  {
    char concat[100];
    close(fd1[0]); // cerrar lectura del primer pipe
    //mandamos el input por fd1 
    write(fd1[1],input_std,strlen(input_std)+1); 
    close(fd1[1]); // cerrar escritura para fd1

    //esperamos a que el hijo envie la seginda cadena
    wait(NULL);
    
    close(fd2[1]); //cerramos para escribir en fd2

    // concat ya tiene la cadena unida para mostrarlo
    read(fd2[0],concat,100);
    printf("Cadena: %s\n",concat);
    close(fd2[0]);
  } else {

    close(fd1[1]); //cerrado para escritura
    char concatt[100];
    
    //obtenemos el input en concatt que fue enviado por el padre
    read(fd1[0],concatt,100);
    //printf("estamos en el hijo: %s\n",concatt);

    int k = strlen(concatt);
    
    for(int i=0; i<strlen(fixer); i++)
    {
      concatt[k++] = fixer[i];
    }

    concatt[k] = '\0';

    close(fd1[0]);
    close(fd2[0]);

    write(fd2[1],concatt,strlen(concatt)+1);
    close(fd2[1]);
    
    exit(0);
  }


  return 0;
}

