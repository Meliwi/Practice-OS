
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        char *myargs[3]; //Definimos una variable de cadena de caracteres que 
                         //tiene 3 posiciones
        myargs[0] = strdup("wc");   // program: "wc" (word count) 
        //Recodemos que wc es un comando que nos permite conocer el número de 
        //palabras y caracteres de un archivo
        myargs[1] = strdup("exec.c"); // argument: file to count - archivo 
        myargs[2] = NULL;           // marks end of array  - final del array
        execvp(myargs[0], myargs);  // runs word count se invoca execvp 
        printf("this shouldn't print out");
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
