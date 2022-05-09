#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

void signalHandler(int sig){
    printf("señal recibida %d \n", sig);
    signal(SIGALRM,SIG_DFL);        //RESTUARO LA SEÑAL ALARMA Y AL EJECUTARLA OTRAVEZ YYA FUNCIONARIA
}

int main(){

    signal(SIGALRM,&signalHandler);
    while(1){
        printf("-----Esperando recibir un programa ---- \n");
        sleep(3);   //dormir 3 segundos
    }

    return 0;
}