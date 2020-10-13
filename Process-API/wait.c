
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int
main(int argc, char *argv[])
{
    // se imprime el mismo mensaje con el pid 	
    printf("hello world (pid:%d)\n", (int) getpid());
    // se hace el llamado a la función fork y se almacena en la variable rc
    int rc = fork();
    // caso en el que el fork falla
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    // 
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
        // El proceso del hijo se queda dormido por un segundo 
	sleep(1);
    } else {
        // parent goes down this path (original process)
       // Mientras el hijo está durmiendo el padre está esperando 
        int wc = wait(NULL);
        printf("hello, I am parent of %d (wc:%d) (pid:%d)\n",
	       rc, wc, (int) getpid());
    }
    return 0;
}
