/*Procesos fork()
 * crea un nuevo proceso hijo con estas condiciones
 * retorno del Padre mayor a 0
 * retorno del hijo = 0
 * no se creo el proceso en -1
 */  
#include <unistd.h>
#include <stdio.h>

int var = 40;

int main() {

  pid_t pid;  
  
  //Parte del programa se ejecuta una sola vez
  printf("******Init Start_Proces. PID = %d *********\n",getpid());

  pid = fork();

  //Esta parte del pragrama se ejecuta 2 veces por el padre y el hijo
  printf("******Proces. PID = %d,pid = %d *********\n",getpid(),pid);

  if(pid > 0) { // proceso padre
    var = 90;

  } else if(pid == 0) { // proceso hijo
    var = 30;
  } else { // error
    printf("error en fork");
  }

  while(1) {
     sleep(2);
     printf("******PID = %d,var = %d *********\n",getpid(),var);
  }

  return 0;
}
