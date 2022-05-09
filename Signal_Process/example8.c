#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define T 10

void manejador (int s){

    write(1,"ALARMA \n" ,11);

}

int main(int argc , char* argv[]){
    char a[T];
    signal(SIGALRM,manejador);
    alarm(4);

    printf("introduce una cadena de caracteres: \n ");
    int leido = read(0,a,10);

    if(leido == -1){
        perror("leido");
        leido = read (0,a,10);
    }
    pause();

    printf("Leido = %d \n",leido);
    printf("%s",a);

    return 0;
}

/*
introduce una cadena de caracteres: 
hola
ALARMA 
 Leido = 5 
hola
*/