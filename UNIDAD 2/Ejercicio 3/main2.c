#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    pid_t pid_hijo;
    printf("Este proceso va a crear otro proceso\n\n");
    printf("el pid del programa padre es: %d\n", (int)getpid());
    pid_hijo = fork();
    switch(pid_hijo){
        case -1:
        printf("Error al crear el proceso");
        return -1;
        case 0:
        printf("PROCESO HIJO:\n");
        printf("Soy el Proceso hijo, mi pid es %d\n", (int)getpid());
        break;
        default:
        printf("PROCESO PADRE: proceso hijo con pid %d creado\n", (int)pid_hijo);

    }

    printf("Soy el proceso %d Terminando \n", (int)getpid());
    exit(EXIT_SUCCESS);
}