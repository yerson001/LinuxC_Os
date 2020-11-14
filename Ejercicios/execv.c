/*Sobre escribe al programa no crea otro
*/
#include <stdio.h>
#include <unistd.h>

int main(int argc,char* argv[]) {
  
  char*argv2[] = {"slave","hola","como","estas",NULL};
  
  printf("%s:%i",argv[0],getpid());
  execv("./slaved",argv2);
  //Si la llamada funciona estas lineas de abajo
  //ya no se llaman solo en caso de error
  printf("Error al reemplazar slave\n");

  return 0;
}
