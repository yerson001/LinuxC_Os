#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define READ_END 0  // Extremo de lectura
#define WRITE_END 1 // Extremo de escritura

#define FILE_NAME "out.txt"

int main(int argc, char* argv[]) {
  /*Definimos el array de file descriptors
   * para el pipe
   * file descriptor fd2 para el archivo .txt
   */
  int fd1[2],fd2;
  int status,pid;

  pipe(fd1); // cramos el pipe que va ha comunicar  ls -l con | a wc
  /*Cuando se crea el pipe se abren los extremos de lectura y escritura
   * poreso es necesarios cerrarlas
   * */
  
  pid = fork(); // cremos el fork

  if(pid == 0) // creamos el hijo que ejecutara "ls -l"
  {// como el hijo debe escribir "ls -l" debo cerrar lectura
    close(fd1[READ_END]); // cerramos extremos no necesarios
    dup2(fd1[WRITE_END],STDOUT_FILENO);// cambiamos el standar output
    close(fd1[WRITE_END]);// estamos escribiendo en fd[1]
    execlp("ls","-l",NULL);
  }else {
    close(fd1[WRITE_END]); // extremo no necesario
    
    pid = fork();

    if(pid == 0)
    {
      fd2 = open(FILE_NAME,O_WRONLY);// domo de escritura O_WRONLY
      dup2(fd1[READ_END],STDIN_FILENO);
      close(fd1[READ_END]);

      dup2(fd2,STDOUT_FILENO);
      execlp("/usr/bin/wc","wc",NULL);
    } else // padre 
    { 
      close(fd1[READ_END]);
    }
  }

  wait(&status);
  wait(&status);


  return 0;
}
