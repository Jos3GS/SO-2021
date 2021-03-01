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
        if(strncmp(lnAnt, ln, 50) == 0){
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
    return espaciobd;
}

void readall(struct Student *bd, int tamannobd){
    for( int i=0; i < tamannobd; i++){
        printf("%s\n", (bd + i)-> Nombre);
        printf("%d\n", (bd + i)-> CC);
        printf("%d\n", (bd + i)-> Semestre);
    }
}

void readsize(struct Student *bd, int tamannobd){
    for(int i=0; i>tamannobd; i++){
        if((bd + i)->CC==0){
            printf("La BBDD tiene: %d Registros de %d Diponibles\n",i,tamannobd);
            break;
        }
    }
}

void readreg(struct Student *bd, int tamannobd, int CC){
    int found=0;
    for(int i=0;i<tamannobd;i++){
        if((bd + i )->CC==CC){
            printf("-------------Registro encontrado---------\n");
            printf("%s\n", (bd + i)->Nombre);
            printf("%d\n", (bd + i)->CC);
            printf("%d\n", (bd + i)->Semestre);
            found = 1;
            break;
        }
    }
    if(found==0){
        printf("Registro no encontrado");
    }
}

int main(int argc, char const *argv[]){
    int contRegistro=0;
    int tamannobd=0;
    char command[30];
    struct Student *espaciobd;
    
    do{
        printf("Ingrese un Comando\n");
        fscanf(stdin,"%s", command);
        getc(stdin);
        if(strncmp("mkdb",command,4)==0){
            char Nombre[30];
            fscanf(stdin, "%s", Nombre);
            fscanf(stdin, "%d",&tamannobd);
            espaciobd = mkdb(Nombre,tamannobd);
        }else if(strncmp("mkreg", command, 5) == 0){
            char Nombre[30];
            int CC;
            int Semestre;
            fscanf(stdin, "%s",Nombre);
            fscanf(stdin, "%d", &CC);
            fscanf(stdin, "&d", &Semestre);
            mkreg(espaciobd, CC, Nombre, Semestre,&contRegistro);
        }else if(strncmp("savebd", command, 6) == 0){
            char Nombre[30];
            fscanf(stdin,"%s",Nombre);
            FILE *Archivo = fopen(Nombre, "w+");
            savebd(Archivo, espaciobd,Nombre,tamannobd,contRegistro);
            fclose(Archivo);
        }else if(strncmp("loadbd", command, 6) == 0){
            char Nombre[30];
            fscanf(stdin,"%s", Nombre);
            FILE *Archivo = fopen(Nombre, "r");
            if (Archivo == NULL){
                perror("Error: ");
                return EXIT_FAILURE;
            }
            espaciobd = loadbd(Archivo,espaciobd,&tamannobd,contRegistro, Nombre);
            fclose(Archivo);
        }else if(strncmp("readall",command, 7) == 0){
            readall(espaciobd,tamannobd);
        }else if(strncmp("readsize", command, 8)== 0){
            readsize(espaciobd,tamannobd);
        }else if(strncmp("readreg",command,7) == 0 ){
            int CC;
            fscanf(stdin,"%d", &CC);
            readreg(espaciobd, tamannobd, CC);
        }else if(strncmp("ecit",command, 4) == 0 ){
            int opcion;
            printf("Desea Guardar la BD?\n1. Guardar Cambios\n2. No Guardar Cambios\n");
            scanf("%d",&opcion);
            getc(stdin);
            if(opcion == 1){
                char Nombre[30];
                printf("Ingrese el nombre e}de la bd\n");
                scanf("%s", Nombre);
                getc(stdin);
                FILE *Archivo = fopen(Nombre, "w+");
                savebd(Archivo, espaciobd, Nombre,tamannobd,contRegistro);
                fclose(Archivo);
            }
            break;
        }
    }while(1);
    free(espaciobd);
    return 0;
}

