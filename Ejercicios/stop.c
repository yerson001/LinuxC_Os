#include<stdio.h> 
#include<signal.h> 
   
int main() { 
     kill(755,SIGSTOP);
    return 0; 
} 
