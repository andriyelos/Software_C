#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void manejador (int s){
    signal(SIGALRM,manejador);
}

int main(){
    struct itimerval timer;
    struct timeval valor;

    valor.tv_sec = 2;
    valor.tv_usec = 2000;

    timer.it_value = valor;
    timer.it_interval = valor;

    setitimer(ITIMER_REAL,&timer,NULL);

    signal(SIGALRM,manejador);
    signal(SIGINT,SIG_IGN);
    while(1){
        write(1,".\n",2);
        pause();
    }

    return 0;
}

/*
/"ejercicio4b" 
.
.
^C.
^Z
[1]+  Detenido                ./"ejercicio4b"
*/