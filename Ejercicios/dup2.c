// CPP program to illustrate dup2()  
#include<stdlib.h> 
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h> 
 /*El dup2 es parecido al dup con la diferencia de que 
  * en este caso el programador dice donde quiere la salida
  * 0 es standar input   "extremo lectura"
  * 1 es standar output "extremo escritura"
  * 2 es salida de error
  */ 
int main() { 
    int file_desc = open("stdout.txt",O_WRONLY | O_APPEND);  
    dup2(file_desc,1) ;  
          
    /*Nuestro programa esta usando el standar output entonces 
     * funcionará con la print pero llevandolo a un txt
     * al pasarle 1 activamos el que escriva en el txt
     * cuando le pasamos 0 lo bloquemos y la salida es por consola
     */ 
    printf("salida estandar \n");
    execlp("ls","-l",NULL);
      
return 0; 
} 
