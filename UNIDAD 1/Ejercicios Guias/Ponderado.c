#include <stdio.h>

int main (void){
    int cantMaterias=0;
    
    printf("Ingrese el numero de materias cursadas \n");
    scanf("%d", &cantMaterias);
    int i=cantMaterias, Creditos[cantMaterias];
    char nameMaterias[cantMaterias][20];
    float Sum=0, SumCred=0, Prom=0, NotaMateria[cantMaterias];
    for(int j=0; j<i; j++){
        printf("Ingrese el Nombre de la Materia, Creditos y la Nota (ejemplo: Sociales 3 4.0)\n");
        scanf("%s %d %f", nameMaterias[j], &Creditos[j], &NotaMateria[j]);
    }
    for(int j=0; j<i; j++){
        Sum = Sum + (NotaMateria[j]*Creditos[j]);
        SumCred = SumCred + Creditos[j];
    }
    Prom = Sum/SumCred;
    for(int j=0; j<i;j++){
        printf("%s Creditos: %d Nota: %f\n",nameMaterias[j], Creditos[j], NotaMateria[j]);
    }
    printf("El promedio de las notas obtenidas es: %f\n", Prom);
    return 0;
}