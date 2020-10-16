/*
Escriba un programa en C que reciba como argumento la ejecución de un comando 
cualquiera de Unix 
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
     int rc = fork();
     for (int i =1; i<argc; i++){
      if (rc < 0) {
       // fork failed; exit
       fprintf(stderr, "fork failed\n");
       exit(1);
     }else if (rc == 0) {
       // child (new process)
       printf("hello, I am child (pid:%d)\n", (int) getpid());
        //Creamos un arreglo de cadena de caracteres con los argumentos 
       // que reciba argv
       char *myargs[] = {argv[i],NULL};
       execvp(myargs[0], myargs); 
       printf("this souldn't print out");
    }
   }
     if(rc > 0) {
        // parent goes down this path (original process)
        int wc = wait(NULL);
         printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
