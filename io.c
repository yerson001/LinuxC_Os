#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
   srand (time(NULL));
  /*
  int n;
  char *str = "12345.67";

  n = atoi(str);
  printf("string = %s integer = %d\n", str, n);
 */
  int numero = rand() % 11;

  printf("numero:%i\n",numero);
  char a = '4';
  int ia = a - '0';
  printf("ia:%i\n",ia+2);
  return 0;
}
