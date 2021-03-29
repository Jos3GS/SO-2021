#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Dato{
    char key[20];
    int value;
};

void swap(struct Dato *A, struct Dato *B){
    struct Dato Temp = *A;
    *A = *B;
    *B = Temp;
}

void Ordena(struct Dato *Registro, int cantRegistros){
    int i,j;
    for(i=0;i<cantRegistros; i++){
        for(j=0; j<cantRegistros-i; j++){
            if(Registro[j].value < Registro[j+1].value){
                swap(&Registro[j], &Registro[j+1]);
            }
        }
    }
}

int main(int agrc, char* argv[]){
    struct Dato *p_Dato = malloc(sizeof(struct Dato) * 100);
    int contRegistros=1;
    char c;

    FILE *archivo = fopen(argv[1], "r");
    FILE *archivo2 = fopen(argv[2], "w+");

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

    for(int i=0; i < contRegistros; i++){
        fscanf(archivo, "%s", (p_Dato+i)->key);
        fscanf(archivo, "%d", &(p_Dato+i)->value);
    }

    Ordena(p_Dato, contRegistros);

    for(int i=0; i < contRegistros; i++){
        fprintf(archivo2, "%s %d\n",(p_Dato +i)-> key, (p_Dato + i)->value);
    }

    fclose(archivo);
    fclose(archivo2);
    free(p_Dato);

    printf("Archivo %s Generado\n",argv[2]);
    exit(EXIT_SUCCESS);
}