#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>

struct Data{
    char Nombre[20];
    char ocupacion[20];
    int Edad;
};

struct parametros_hilo{
    struct Data *Registro;
    int cantRegistros;
    FILE *archivo;
};

void Ordenar(void *parametros){
    struct parametros_hilo* p= (struct parametros_hil*) parametros;
    FILE *archivo = fopen(p->archivo, "w");
    for(int i=0; i < p-> cantRegistros; i++){
        for(int j=0; j< p-> cantRegistros-i;j++){
            if(strcmp(p->Registro[j].ocupacion, p->Registro[j+1].ocupacion)>0){
                struct Data Temp = p->Registro[i];
                p->Registro[i] = p->Registro[j];
                p->Registro[j] = Temp;
            }
        }
    }
    for(int i=0; i< p-> cantRegistros ; i++){
        fprintf(p->archivo,"%s %s %d\n", (p->Registro + i) ->Nombre,(p->Registro + i) -> ocupacion, (p->Registro +i) -> Edad);
    }
    fclose(archivo);
    return EXIT_SUCCESS;
}

void Inversed(void* parametros){
    struct parametros_hilo* p= (struct parametros_hil*) parametros;
    FILE *archivo = fopen(p->archivo, "w");
    for(int i = p->cantRegistros - 1; i>=0; i--){
        fprintf(p->archivo,"%s %s %d\n", (p->Registro + i) ->Nombre,(p->Registro + i) -> ocupacion, (p->Registro +i) -> Edad);

    }
    fclose(archivo);
    return EXIT_SUCCESS;
}

int main(int argc, char const *argv[]){
    struct Data *p_Datos = malloc(sizeof(struct Data*)*100);
    struct Data *Temp = malloc(sizeof(struct Data*)*1);
    struct parametros_hilo param;
    pthread_t hilos_ids[2];
    int contRegistros=1;
    char c;
    
    
    FILE* archivo = fopen(argv[1], "r");

    if(archivo == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }

    for(c = getc(archivo); c != EOF; c = getc(archivo)){
        if(c == "\n"){
            contRegistros++;
        }
    }

    rewind(archivo);

    for(int i=0; i<contRegistros; i++){
        fscanf(archivo,"%s %s %d",(p_Datos+i)->Nombre,(p_Datos+i)->ocupacion,&(p_Datos+i)->Edad);
    }

    param.Registro = p_Datos;
    param.cantRegistros = contRegistros;
    strcpy(param.archivo,argv[2]);
    pthread_create(&hilos_ids[0], NULL,&Inversed,&param);
    strcpy(param.archivo,argv[3]);
    pthread_create(&hilos_ids[1],NULL,&Ordenar,&param);
    pthread_join(hilos_ids[0],NULL);
    pthread_join(hilos_ids[1],NULL);
    
    FILE *archivo2 = fopen(argv[2], "r");
    FILE *archivo3 = fopen(argv[3],"r");
    if(archivo2 == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }
    if(archivo3 == NULL){
        perror("Error: ");
        return EXIT_FAILURE;
    }
    printf("Ordenado alfabeticamente\n");
    for(int i=0; i<contRegistros; i++){
        fscanf(archivo2, "%s %s %d", Temp ->Nombre, Temp->ocupacion, Temp->Edad);
        printf("%s %s %d\n", Temp->Nombre, Temp->ocupacion, Temp->Edad);
    }
    printf("Invetido\n");
    for(int i=0; i<contRegistros; i++){
        fscanf(archivo3, "%s %s %d", Temp ->Nombre, Temp->ocupacion, Temp->Edad);
        printf("%s %s %d\n", Temp->Nombre, Temp->ocupacion, Temp->Edad);
    }

    
    fclose(archivo);
    fclose(archivo2);
    fclose(archivo3);
    free(p_Datos);
    free(Temp);
    return EXIT_SUCCESS;
}