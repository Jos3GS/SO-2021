#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    int CC;
    char Nombre[40];
    int Semestre;
};

struct Student *mkdb(char *Nombre, int size)
{
    return (struct Student *)malloc(sizeof(struct Student) * size);
}

void mkreg(struct Student *bd, int CC, char *Nombre, int Semestre, int *nroRegistro){
    strcpy((bd + *nroRegistro)->Nombre, Nombre);
    (bd + *nroRegistro)->CC = CC;
    (bd + *nroRegistro)->Semestre = Semestre;
    (*nroRegistro)++;
}

void savebd(FILE *archivo, struct Student *espaciobd, char *Nombre, int tamannobd, int contRegistro){
    fprintf(archivo,"Tamaño: %d\n", tamannobd);
    fprintf(archivo, "Nombre | Cedula | Semestre \n");
    for(int i=0; i<contRegistro; i++){
        fprintf(archivo, "%s %D %d\n", (espaciobd + i)->Nombre, (espaciobd +i)-> CC, (espaciobd ->Semestre));
    }
}

struct Student *loadbd(FILE *Archivo, struct Student *espaciobd, int *tamanobd, int *contaRegistro, char* Nombre){
    char etp[50];
    char ln[50];
    char lnAnt[50];
    char nameStudent[40];
    int contRegistro = 0;
    int CC;
    int Semestre;

    fscanf(Archivo, "%s", etp);
    fscanf(Archivo,"%d", tamanobd);
    fgets(lnAnt, "%[^\n]", Archivo);
    fgets(lnAnt,"%[^\n]",Archivo);

    while(1){
        fgets(ln,"%[^\n]",Archivo);
        if(strcmp(lnAnt, ln) == 0){
            break;
        }
        printf("%s\n",ln);
        strcpy(lnAnt,ln);
        contRegistro++;
    }
    *contaRegistro = contaRegistro;
    printf("%d\n",contRegistro);
    espaciobd = mkdb(Nombre, *tamanobd);
    rewind(Archivo);
    fgets(lnAnt, "%[^\n", Archivo);
    fgets(lnAnt,"%[^\n]",Archivo);
    for(int i=0; i < contRegistro; i++){
        fscanf(Archivo, "%sfget",Nombre);
        fscanf(Archivo,"%d", &CC);
        fscanf (Archivo, "%d", &Semestre);
        strcpy((espaciobd + i)-> Nombre,Nombre);
        (espaciobd +i)-> CC = CC;
        (espaciobd + i )->Semestre = Semestre;
    }
    return espaciobd
}

