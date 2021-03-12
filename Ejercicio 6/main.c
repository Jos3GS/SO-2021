#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int cantMaterias;
    char (*espacioNombres)[30];
    double *espacioNotas;
    int *espacioCreditos;
    printf("ingrese la cantidad de materias\n");
    scanf("%d",&cantMaterias);
    espacioNombres = (char (*)[30])(malloc(sizeof(char[30])*cantMaterias));
    espacioNotas = (double *)(malloc(sizeof(double)*cantMaterias));
    espacioCreditos = (int *)(malloc(sizeof(int)*cantMaterias));
    for (int i = 0; i < cantMaterias; i++)
    {
        printf("Ingrese el nombre de la materia %d: ", i+1);
        scanf("%s",(espacioNombres+i));
        printf("Ingrese la nota en la materia %s: ",espacioNombres+i);
        scanf("%lf",(double *)(espacioNotas+i));
        getc(stdin);
        printf("ingrese los creditos de la materia: %s en la que obtuvo una nota de %4.1lf\n",espacioNombres+i, *(espacioNotas+i));
        scanf("%d",(int *)(espacioCreditos+i));
        getc(stdin);
        printf("Materia: %s de: %d creditos y con nota: %4.1lf registrada con exito\n",espacioNombres+i, *(espacioCreditos+i),*(espacioNotas+i));
    }
    double totalNotas;
    int totalCreditos;
    double promedioPonderado;

    printf("|#|Materia   |Nota|Creditos|\n");
    for (int i = 0; i < cantMaterias; i++)
    {
        printf("|%d|%10.10s|%4.1lf|%1d|\n",i+1,(espacioNombres+i),*(espacioNotas+i),*(espacioCreditos+i));
    }
    for (int i = 0; i < cantMaterias; i++)
    {
        totalNotas += *(espacioNotas+i);
        totalCreditos += *(espacioCreditos+i);
        promedioPonderado += *(espacioNotas+i)*(*(espacioCreditos+i));
    }
    
    printf("Promedio del semestre: %f\n",totalNotas/cantMaterias);
    printf("Total creditos: %d\n",totalCreditos);
    printf("Promedio Ponderado: %f\n",promedioPonderado/totalCreditos);  


    free(espacioCreditos);
    free(espacioNombres);
    free(espacioNotas);
    return 0;
}