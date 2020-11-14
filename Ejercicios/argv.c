/*Para este programa mandamos datos para
 * el vector de argumentos argv
 * : ./a.out holas mundo
 * lo que contiene el vector 
 * argv[0] = ./a.out 'el ejecutable'
 * argv[1] = holas
 * argv[2] = mundo
 * argv[3] = \0
*/
#include <stdio.h>

int main(int argc,char *argv[]) {

  for(int i=0; i<argc; ++i) {
    printf("Argumentos %d,%s\n",i,argv[i]);
  }
  printf("argc = %i\n",argc);
  printf("argv[argc] = %s\n",argv[argc]);

  return 0;
}
