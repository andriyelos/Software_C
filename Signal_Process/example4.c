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
            printf("Padre Pid : %d , hijo Pid : %d y numero de hijos: %d \n",getpid(),getppid(),num_hijos);
            exit(0);

        }else{      /* En este caso el padre */
            num_hijos ++ ;
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

/* Se puede observar que los hijos se ejecutan en orden desordenado

Este es el Pid: 2218 
Padre Pid : 2224 , hijo Pid : 2218 y numero de hijos: 6 
Padre Pid : 2225 , hijo Pid : 2218 y numero de hijos: 7 
Padre Pid : 2226 , hijo Pid : 2218 y numero de hijos: 8 
Padre Pid : 2223 , hijo Pid : 2218 y numero de hijos: 5 
Padre Pid : 2228 , hijo Pid : 2218 y numero de hijos: 10 
Padre Pid : 2227 , hijo Pid : 2218 y numero de hijos: 9 
Padre Pid : 2222 , hijo Pid : 2218 y numero de hijos: 4 
Padre Pid : 2221 , hijo Pid : 2218 y numero de hijos: 3 
Padre Pid : 2220 , hijo Pid : 2218 y numero de hijos: 2 
Padre Pid : 2219 , hijo Pid : 2218 y numero de hijos: 1 
*/