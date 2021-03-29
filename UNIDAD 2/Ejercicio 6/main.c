#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    pid_t pid_hijo;
    printf("Soy el padre y mi PID es: %d\n", (int)getpid());
    int nroHijo=0;
    for(int i=0; i < 3; i++){
        nroHijo=i;
        pid_hijo= fork();
        if(pid_hijo == 0){
            printf("Hijo %d creado\n",i+1);
            break;
        }else{
            wait(NULL);
        }
    }
    int fact=1;
    for(int i=1; i<=10; i++){
        
        fact = fact * i;
        if(0 == (int)pid_hijo){
            printf("Hijo(%d) de PID = %d: fact(%d) = %d \n",nroHijo+1, (int)getpid(), i, fact);
        }
    }

    printf("Soy el Proceso %d y Estoy terminando\n", (int)getpid());
    exit(EXIT_SUCCESS);

}