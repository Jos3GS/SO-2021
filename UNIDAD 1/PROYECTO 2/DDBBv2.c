#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct estudiante
{
    int cedula;
    char nombre[30];
    int semestre;
} estudiante;

typedef struct database{
    int nroRegistros;
    char nombrebd[30];
    struct estudiante *registros;
} database;

database* mdb(database *BD,char *nombre,int registros, int *cont){
    strcpy((BD+*cont) -> nombrebd,nombre);
    (BD+*cont) -> nroRegistros = registros;
    (BD+*cont) -> registros = calloc(sizeof (struct estudiante), (BD+*cont)->nroRegistros);
    (*cont)++;
    return BD;
}

void mreg(estudiante *Registros,char *nombre,int cedula,int semestre,int *contReg){
    strcpy((Registros+*contReg)->nombre,nombre);
    (Registros+*contReg)->cedula = cedula;
    (Registros+*contReg)->semestre = semestre;
    (*contReg)++;
}

void savedb(FILE *archivo2, struct estudiante *Registros, char *nombre, int tamanoRegistros, int contadorRegistro){
    fprintf(archivo2, "NombreDB: %s\n",nombre);
    fprintf(archivo2, "Tamaño: %d\n", tamanoRegistros);
    fprintf(archivo2, "|Nombre |Cedula |Semestre |\n");
    for (int i = 0; i < contadorRegistro; i++)
    {
        fprintf(archivo2, "%s %d %d\n", (Registros + i)->nombre, (Registros + i)->cedula, (Registros + i)->semestre);
    }
    
}

void loaddb(FILE *archivo, struct database *espaciobda, struct estudiante *Registros, int *contadorRegistro,int *contDatabase)
{
    char LTrash[50];
    char linea[50];
    char lineaAnt[50];
    char nombrebd[20];
    char nombreEstudiante[30];
    int tamanobd;
    int contRegistros = 0;
    int cedula;
    int semestre;
    fscanf(archivo, "%s", LTrash);       //Omitimos la primer palabra
    fscanf(archivo, "%s", nombrebd);     //guardamos el nombre de la BD
    fscanf(archivo, "%s", LTrash);       //Omitimos la tercer palabra
    fscanf(archivo, "%d", &tamanobd);     //guardamos el tamaño de la BD
    fgets(lineaAnt, "%[^\n]", archivo); //Omitir primera linea.
    fgets(lineaAnt, "%[^\n]", archivo); //Omitir Segunda linea.
    fgets(lineaAnt, "%[^\n]", archivo); //Omitir Tercera linea.
    while (1)
    {
        fgets(linea, "%[^\n]", archivo);
        if (strncmp(lineaAnt, linea, 50) == 0)
        {
            contRegistros++;
            break;
        }
        strcpy(lineaAnt, linea);
        contRegistros++;
    }
    *contadorRegistro = contRegistros;
    rewind(archivo);
    fscanf(archivo, "%s", LTrash);       //Omitimos la primer palabra
    fscanf(archivo, "%s", LTrash);     //guardamos el nombre de la BD
    fscanf(archivo, "%s", LTrash);       //Omitimos la tercer palabra
    fscanf(archivo, "%d", LTrash);     //guardamos el tamaño de la BD
    fgets(lineaAnt, "%s[^\n]", archivo); //Omitir primera linea.
    fgets(lineaAnt, "%s[^\n]", archivo); //Omitir Segunda linea.
    //fgets(lineaAnt, "%s[^\n]", archivo); //Omitir Tercera linea.
    //escrituras
    strcpy((espaciobda+*contDatabase)->nombrebd,nombrebd);
    (espaciobda+*contDatabase)->nroRegistros = tamanobd;
    (espaciobda+*contDatabase)->registros = calloc(sizeof (struct estudiante),tamanobd);
    Registros = (espaciobda+*contDatabase)->registros;
    for (int i = 0; i < contRegistros; i++)
    {
        fscanf(archivo, "%s", nombreEstudiante);
        fscanf(archivo, "%d", &cedula);
        fscanf(archivo, "%d", &semestre);
        strcpy((Registros+i)->nombre, nombreEstudiante);
        (Registros+i)->cedula = cedula;
        (Registros+i)->semestre = semestre;
    }
    (*contDatabase)++;
}

void readall(struct estudiante *bd, int tamanobd)
{
    printf("|Nombre |Cedula |Semestre |\n");
    for (int i = 0; i < tamanobd; i++)
    {
        printf("%s\t%d\t%d\n", (bd + i)->nombre,(bd + i)->cedula,(bd + i)->semestre);
    }
}

void ChangeActive(struct database *espacioBD,char *nombre,int *contDatabase,int *contadorRegistro)
{
    *contadorRegistro = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strncmp((espacioBD + i)->nombrebd,nombre,3)==0)
        {
            struct database BackUp = *(espacioBD+(*contDatabase-1));
            struct database *Actual = (espacioBD + i);
            struct database *Active = (espacioBD+(*contDatabase-1));
            if (i!=*contDatabase)
            {
               *Active = *Actual;
               *Actual = BackUp;
               struct estudiante *bdAct = Active->registros;
               for (int j = 0; j < Active->nroRegistros; j++)
               {
                   if ((bdAct + j)->cedula != 0)
                   {
                       (*contadorRegistro)++;
                   }
               }
            }
            break; 
        }
        
    }
}

void readdbs(struct database *espaciobases)
{
    struct estudiante *bdAct; 
    
    
    for (int i = 0; i > -1; i++)
    {
        if((espaciobases+i) -> nroRegistros == 0){ break; }
        printf("Nombre base de datos: %s\n",(espaciobases+i) -> nombrebd);
        printf("Numero de registros: %d\n",(espaciobases+i) -> nroRegistros);
        bdAct = (espaciobases+i) -> registros;
        int numregistros=0;
        for (int j = 0; j < (espaciobases+i) -> nroRegistros; j++)
        {
            if ((bdAct+j)->cedula!=0)
            {
                numregistros++;
            }
        }
        printf("Registros almacenados: %d\n",numregistros);
        
    }
}


void infoActive(struct database *espaciobases,int contdatabase,int contRegistros){
    printf("Base de datos activa: %s\n",(espaciobases+(contdatabase-1))->nombrebd);
    printf("Registros disponibles: %d\n",((espaciobases+(contdatabase-1))->nroRegistros)-contRegistros);
}

void cantRegActive(struct database *espaciobases,int contdatabase)
{
    printf("Cantidad de registros que puede almacenar %s: %d\n",(espaciobases+(contdatabase-1))->nombrebd,(espaciobases+(contdatabase-1))->nroRegistros);
}

void readreg(struct database *espaciobases,struct estudiante *Registros,int contdatabase,int cedula)
{
    int found = 0;
    for (int i = 0; i < (espaciobases+(contdatabase-1))->nroRegistros; i++)
    {
        if ((Registros + i)->cedula == cedula)
        {
            printf("-------------Registro encontrado---------\n");
            printf("%s\n", (Registros + i)->nombre);
            printf("%d\n", (Registros + i)->cedula);
            printf("%d\n", (Registros + i)->semestre);
            found = 1;
            break;
        }
    }
    if (found == 0)
    {
        printf("Registro no encontrado.\n");
    }
}
int main(int argc, char const *argv[])
{
    struct database *espaciobases;
    struct estudiante *bdAct;
    espaciobases = malloc((sizeof (struct database)*5)); //Limite de bases de datos cargadas
    bdAct = espaciobases->registros;
    int contdatabase = 0;
    int contRegistros = 0;
    char comando[20];
    do
    {
        printf("---> ");
        fscanf(stdin, "%s", comando);
        getc(stdin);
        if (strncmp("mdb", comando, 3) == 0)
        {
            char nombre[20];
            int tamanoRegistros;
            fscanf(stdin, "%s", nombre);
            fscanf(stdin, "%d", &tamanoRegistros);
            // fgets("nan", "%s[^\n]", stdin); //Eliminar argumentos extras.
            espaciobases = mdb(espaciobases,nombre,tamanoRegistros,&contdatabase);
            bdAct = (espaciobases+(contdatabase-1))->registros; //Siempre que cambiamos base de datos actual cambiamos el contador de registros
            contRegistros = 0;                                  //En este caso 0 por que es una base de datos nueva.
            printf("La Base de Datos activa es %s\n",nombre);
        }
        else if (strncmp("mreg", comando, 4) == 0)
        {
            char nombre[20];
            int cedula;
            int semestre;
            fscanf(stdin, "%s", nombre);
            fscanf(stdin, "%d", &cedula);
            fscanf(stdin, "%d", &semestre);
            // fgets("nan", "%s[^\n]", stdin); //Eliminar argumentos extras.
            mreg(bdAct,nombre,cedula,semestre,&contRegistros);
            printf("OK registro creado\n");
        }
        else if (strncmp("svdb", comando, 4) == 0)
        {
            // fgets("nan", "%s[^\n]", stdin); //Eliminar argumentos extras.
            FILE *archivo2 = fopen((espaciobases+(contdatabase-1))->nombrebd, "w+");
            savedb(archivo2,bdAct,((espaciobases+(contdatabase-1))->nombrebd),((espaciobases+(contdatabase-1))->nroRegistros),contRegistros);
            fclose(archivo2);
        }
        else if (strncmp("loaddb", comando, 6) == 0)
        {

            char nombre[20];
            fscanf(stdin, "%s", nombre);
            // fgets("nan", "%s[^\n]", stdin); //Eliminar argumentos extras. Descartada esta linea por bug con los fgets al declarar un archivo en modo lectura
            FILE *archivo = fopen(nombre, "r");
            if (archivo == NULL)
            {
                perror("Error: ");
                return EXIT_FAILURE;
            }
            loaddb(archivo,espaciobases,bdAct,&contRegistros,&contdatabase);
            bdAct = (espaciobases+(contdatabase-1))->registros; 
            fclose(archivo);
            printf("La Base de Datos activa es %s\n",(espaciobases+(contdatabase-1))->nombrebd);
        }
        else if (strncmp("radb", comando, 4) == 0)
        {
            readall(bdAct,(espaciobases+(contdatabase-1))->nroRegistros);
        }
        else if (strncmp("sdb", comando, 3) == 0)
        {
            char nombre[20];
            fscanf(stdin, "%s", nombre);
            ChangeActive(espaciobases,nombre,&contdatabase,&contRegistros);
            printf("La Base de Datos activa es %s\n",(espaciobases+(contdatabase-1))->nombrebd);
            bdAct = (espaciobases+(contdatabase-1))->registros;
        }
        else if (strncmp("lsdbs", comando, 5) == 0)
        {
            readdbs(espaciobases);
        }
        else if (strncmp("gdb", comando, 3) == 0)
        {
            infoActive(espaciobases,contdatabase,contRegistros);
        }
        else if (strncmp("rsdb ", comando, 4) == 0)
        {
            cantRegActive(espaciobases,contdatabase);
        }
        else if (strncmp("rr", comando, 2) == 0)
        {
            int cedula;
            fscanf(stdin, "%d", &cedula);
            readreg(espaciobases,bdAct,contdatabase,cedula);
        }
        else if (strncmp("exit", comando, 4) == 0)
        {
            int opcion;
            printf("Desea guardar la base de datos %s?\n1 si desea guardarla.\n2 si no desea guardarla.\n",(espaciobases+(contdatabase-1))->nombrebd);
            scanf("%d", &opcion);
            getc(stdin);
            if (opcion == 1)
            {
                FILE *archivo2 = fopen((espaciobases+(contdatabase-1))->nombrebd, "w+");
                savedb(archivo2,bdAct,((espaciobases+(contdatabase-1))->nombrebd),((espaciobases+(contdatabase-1))->nroRegistros),contRegistros);
                fclose(archivo2);
            }
            break;
        }
    } while (1);
    free(bdAct);
    free(espaciobases);
    return 0;
}