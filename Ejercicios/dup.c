#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h> 
/*se usa para hacer una copia al descriptor de archivos 
 * como en este ejemplo tenemos file_desc con el cual podemos acceder
 * a out.txt pero al usar dup copiamos este acceso y podemos usarlo
 * con copy_des como en este programa
 */ 
int main() {

    int file_desc = open("out.txt", O_WRONLY | O_APPEND); 
      
    if(file_desc < 0) 
        printf("Error opening the file\n"); 
      
    int copy_desc = dup(file_desc); 
    
    //los parametros para escribir son la texto y el tamaño
    write(copy_desc,"escrito con la copia\n", 30);       
    write(file_desc,"escrito con el original\n",30); 
      
    return 0; 
} 
