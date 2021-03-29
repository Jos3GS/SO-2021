#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]){
    pid_t pid_hijo;
    int nroHijo=-1;

    for(int i= 0; i<2; i++){
        nroHijo=i;
        pid_hijo = fork();
        if(pid_hijo == 0){
            printf("Proceso Hijo #%d con PID %d\n",nroHijo,(int) getpid());
        }else{
            wait(NULL);
        }
    }

    switch(nroHijo){
        case 0:
        execv("./p1 ", argv);
        break;
        case 1:
        execv("./p2 ",argv);
        break;
        default:
        break;
    }
    

    FILE* archivo = fopen(argv[2],"r");
    if(archivo == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }
    char c;
    int contRegistros = 1;
    for (c = getc(archivo); c != EOF; c = getc(archivo)){
        if(c == "\n"){
            contRegistros++;
        }
    }
    rewind(archivo);
    printf("Archivo ordenado por valor, Mayor a Menor\n");
    printf("Clave   |   Valor\n");
    for(int i=0; i<contRegistros; i++){
        char clave[20];
        int valor;
        fscanf(archivo,"%s", clave);
        fscanf(archivo,"%d",&valor);
        printf("%s\t%d\n",clave, valor);
    }
    fclose(archivo);

    archivo = fopen(argv[3], "r");
    if(archivo == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }
    printf("Archivo En orden inverso, al original\n");
    printf("Clave   |   Valor\n");
    for(int i=0;i<contRegistros; i++){
        char clave[20];
        int valor;
        fscanf(archivo,"%s", clave);
        fscanf(archivo,"%d",&valor);
        printf("%s\t%d\n",clave, valor);
    }
    fclose(archivo);
    return 0;

}