#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*Hágalo usted mismo, primer punto correspondiente a la sección 3.fork() */

int main(int argc, char**argv[]){
 //inicializo el contador
 int contador = 1;
 int rc = fork();
 if (rc < 0){
  fprintf(stderr,"fork failed\n");
  exit(1);
 }
 else if (rc == 0){
  // child (new process)
  contador = contador + 5;
 }
 else {
  //parents goes down this path (original process)
  contador = contador + 2; 
  
 }
 // counter value: 
 printf("el valor del contador es %d.\n", contador);
 return 0; 	
 
}
