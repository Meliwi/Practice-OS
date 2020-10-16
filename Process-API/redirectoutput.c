
//Redireccionando la salida a un archivo 

#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>

#define MAXSTR 256

int main(){
 char cadena[MAXSTR];
 int s;
 int file;
 
 //Limpiar la memoria que estaba asociada con cadenass
 bzero(cadena, sizeof(char)*MAXSTR);
 s = read(STDIN_FILENO,cadena,MAXSTRL);
 //Permisos que tiene el archivo
 file = open("salida.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR, S_IWUSR);
 assert(file!=-1);
 //Se duplica el descriptor de archivos 
 dup2(file,STDOUT_FILENO);
 printf("%s",cadena);
 close(file);
 return 0; 

}
