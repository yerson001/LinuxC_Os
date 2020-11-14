#include<stdio.h> 
#include<unistd.h> 
#include<stdlib.h>
  
int main(int argc, char **argv) { 
    printf("Soy en programa io.c\n");
    int num1 = strtol(argv[1],0,0);
    int num2 = strtol(argv[2],0,0);

    printf("suma:%i\n",num1+num2);
    return 0; 
} 
