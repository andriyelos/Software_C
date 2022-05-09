#include <unistd.h>
#include <stdio.h>

int var = 10;


int main(void){
    
    pid_t pidC;
    printf("** proc. PID = %d  comienza ** \n",getpid(),pidC);
    pidC = fork(); //retorna un valor positivo si se ejecuta todo bien

    //al crearse el hijo empezara a ejecutar instrucciones 

    printf("** proc. PID = %d , PidC = %d comienza ** \n",getpid(),pidC); // se ejecutara 2 veces

    if(pidC > 0){
        var = 44;
        
    }else if(pidC==0) {
        var = 33;

    }else{
        perror("error ,valor es -1");
    }

    while (1)
    {
        sleep(5);
        printf("** proc. PID = %d , var = %d comienza ** \n",getpid(),var);
        printf("** PID = %d de prueba",getppid());
    }
    

    return 0;
}

/*
0  1000    1478    1029  20   0   2304   504 -      S+   pts/0      0:00  \_ ./fork1
1  1000    1479    1478  20   0      0     0 -      Z+   pts/0      0:00      \_ [fork1] <def

el de abajo que es el hijo ,se ha quedado como zombi al haberlo matado

*/