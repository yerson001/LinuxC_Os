/*SIGNAL en Linux c
 *controlar programa
 */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
//ps -la
//>>kill ID or -2 849 or -9 849 delete
//stop -19
//start -18
//
void controlar(int);

int main () {
   signal(SIGINT, controlar);
   int c=0;

   while(1) {
      printf("Going to sleep for a second...%i\n",++c);
      sleep(1); 
   }
   return(0);
}

void controlar(int signum) {
   printf("Caught signal %d, coming out...\n", signum);
}



















