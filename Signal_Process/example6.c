#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{

    signal(SIGQUIT,SIG_IGN);
    signal(SIGINT,SIG_IGN);

    if(argc< 2 ){
        printf("Usa:  %s \n", argv[0]);
        exit(-1);
    }

    printf("Pid del proceso: %d \n",getpid());

    pid_t pid;
    pid = fork();

    if(pid < 0){
        perror("error");
        exit(-1);

    }else if(pid == 0){         /* el hijo */
        int resultado = execl("/bin/sh","sh","-c",argv[1],NULL);

        if(resultado < 0){
            perror("execl");
            exit(-1);
        }
        exit(0);
    }else{                      /*padre*/
        wait(0);

    }
    return 0;
}