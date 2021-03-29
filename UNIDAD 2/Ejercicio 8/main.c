#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    pid_t pid_hijo;
    int nroHijo=-1;

    printf("PID programa padre: %d\n",(int)getpid()); 

    for(int i=0; i<3;i++){
        nroHijo=i;
        pid_hijo = fork();
        if(pid_hijo == 0){
            printf("Hijo %d\n",i);
            break;
        }else{
            wait(NULL);
        }
    }

    switch(nroHijo){
        case 0:
        execv("./Prom",argv);
        break;
        case 1:
        execv("./Max",argv);
        break;
        case 2:
        execv("./Min",argv);
        break;
        default:
        break;
    }

    printf("Terminando la ejecucion del PID: %d",(int)getpid());
    exit(EXIT_SUCCESS);
}