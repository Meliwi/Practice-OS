/*Escriba un programa en C en el cual el hijo ejecuta el cálculo del número de 
Fibonacci 50

Recordemos la sucesión de Fibonacci:
0, 1, 1, 2,3,5,8,13,21,34,55,89,144,233,377,610,987...

*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// inicializo las variables 
int initial = 0;
int initial2 = 1;
int generate = 0;

int fibonacci(){
 initial = initial2; //1,0,1,1,1,2...
 initial2 = generate; //0,1,1,2,3...
 generate = initial + initial2;//1,1,2,3,5...
 return generate;//1,1,1,2,3,5...
}

int main(int argc, char *argv[])
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
        // Cremos el ciclo for hasta el 50 
        for (int i=0; i<50;i++){
         printf("%d\n",fibonacci());
	}
	sleep(1);
    } else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent of %d(wc:%d) (pid:%d)\n",
	       rc,wc, (int) getpid());
    }
    return 0;
}
