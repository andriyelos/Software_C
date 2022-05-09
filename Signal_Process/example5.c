#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

void wait_hijos(int sig){
    wait(0);
    signal(SIGCHLD,wait_hijos);
}

int main(){
    signal(SIGCHLD,wait_hijos);
    pid_t PidC;
    int num_hijos = 1;

    printf("Este es el Pid: %d \n",getpid());

    while (num_hijos <= 10)
    {
    PidC = fork();
    if(PidC < 0){
        perror("pid");
        exit(-1);

     }else if (PidC == 0){       /* en este caso el hijo*/
        if(getpid()%2 == 0){      /* si el pid es par */
            printf("\n PID: %d",getpid());

            int ex = execl("/bin/date","date",NULL);

            if (ex < 0)
            {
                perror("execl");
                exit(-1);
            }
            
        }else{                  /* el pid es impar */
            printf("\n PID: %d",getpid());
            int ex = execl("/home/andriy/Documentos/SOFTWARE/PRACTICA 3/p3ej2.c","ls","-l",NULL);

            if (ex < 0)
            {
                perror("execl");
                exit(-1);
            }
        }
        exit(0);
     }else{             /* el padre*/
        num_hijos++;
     }
    }

     for (int i = 0 ; i < 10;i++){
        pause();
    }
    
    while(1){
        sleep(5);
    }
    
    return 0;

}

/*
Este es el Pid: 2210 


execl: No such file or directory
 PID: 2217


execl: No such file or directory
 PID: 2219
execl: No such file or directory
 PID: 2215

execl: No such file or directory
 PID: 2213

execl: No such file or directory
 PID: 2211dom 17 abr 2022 20:51:54 CEST
dom 17 abr 2022 20:51:54 CEST
*/