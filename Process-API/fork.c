
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    /*  Lo que hace al iniciar el programa es imprimir un hello world, 
	imprime el valor del pid y toma el valor entero que corresponde 
	al identificador del proceso que está corriendo el programa
    */ 
    printf("hello world (pid:%d)\n", (int) getpid());
    // se invoca la función fork y lo que retorna se guarda en rc
    int rc = fork();
    /* si este valor retornado por fork es menor que cero quiere decir que 
  	hubo un error */ 
    if (rc < 0) {
        // el fork falló; exit
        fprintf(stderr, "fork failed\n");
        /* Recordemos que los programas en C terminan con un valor de 0 si 
	han terminado correctamente de lo contrario fallaron */ 
        exit(1);
    } else if (rc == 0) {
         // Esta parte del código la ejecuta el hijo
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        /* si todo salió bien, quiere decir que es un valor positivo y esto 
         es ejecutado por el padre
         parent goes down this path (original process)*/
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
    }
    return 0;
}

