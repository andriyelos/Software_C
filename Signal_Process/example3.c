#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_HIJOS 5

int doSomethin(void){

    int ret;

    srand(getpid());
    ret = (rand() % 256);
    printf("Hijo: Pid = %d valor aleatorio calculado % d \n ",getpid(),ret);

    return ret;
}
int main(){

    pid_t pidC;
    int status;

    for(int i =0 ; i<NUM_HIJOS ; i++){
        pidC = fork();
        if(pidC > 0){
            continue;
        }else if(pidC == 0)
        {
            exit(doSomethin());
        }else{
            perror("error");
        }
    }
    for (int i = 0; i < NUM_HIJOS; i++)
    {
        pidC = wait(&status);
        printf("Padre de Pid: %d y hijo de Pid %d terminado, estado st = %d \n",getpid(),pidC,WEXITSTATUS(status));
    }
    

    while (1)
    {
        sleep(10);
    }
    
    return 0;
}