#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <pthread.h>
#include <fcntl.h> 

void *Impar(void *vargp) {
 int out = open("par.txt",O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
 dup2(out,1);//extremo abierto para escritura
 close(out);
 for(int i=0; i<10; i+=2)
 {
   printf("%d\n",i);

 }
}
void *Par(void *vargp) { 
   int out = open("Impar.txt",O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
   dup2(out,1);//extremo abierto para escritura
   close(out);
  for(int i=0; i<10; i+=1)
  {
    printf("%d\n",i);
  }
} 
  
int main() { 
    //pthread_t Thread[2];
    pthread_t T1;
    pthread_t T2;
    pthread_create(&T1,NULL,Impar,(void*)&T1);
    pthread_create(&T2,NULL,Par,(void*)&T2);
    //esperar a que teminen
    pthread_join(T1,NULL);
    pthread_join(T2,NULL);

    pthread_exit(NULL); 
    return 0; 
}
