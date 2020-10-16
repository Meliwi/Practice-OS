/*Escriba un programa en Cc en el cual el padre sea capaz de obtener el valor 
 que devuelve su hijo después de terminar su ejecución 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

/*
WIFEEXITED(status): Es distinto de cero si el hijo terminó normalmente
WEXITSTATUS(status): Permite obtener el valor devuelto por el proceso hijo

*/

//Creamos la función que retorna el número aleatorio
int random_numbers(int max){
 //Inicializamos la generación de números aleatorios
 srand(time(NULL));
 //retornamos el valor random
 return rand()%max;
}


int main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    //Declaramos la variable status
    int status; 
    int rc = fork();
    if (rc < 0) {
     // Caso del error
     fprintf(stderr, "fork failed\n");
     exit(1);
    }
    else if (rc == 0) {
     // Proceso de hijo (nuevo proceso)
     //Hacemos el llamado a la función y almacenamos su valor 
     int rand_number = random_numbers(20);
     //Imprimimos el valor random generado y el pid del proceso hijo
     printf("hello, I am child (pid:%d)\n", (int) getpid());
     printf("Random number is %d\n",rand_number);
     exit(rand_number);
     sleep(1);
    }
    //Proceso del padre(proceso original)
    else {
    // Terminación de ejecución de su hijo  
     int wc = wait(&status);
    // Validamos que el estatus del hijo es de salida con WIFEXITED
     printf("hello, I am parent of %d (wc:%d) (pid:%d)\n ",rc,wc,(int) getpid());
     if (WIFEXITED(status)){
        //Obtenemos el valor de salida del hijo
	printf("Exit status of the child was %d\n",WEXITSTATUS(status));
     }
    }
   return 0;
}

