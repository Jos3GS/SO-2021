#include <stdio.h>

//Prototipar una funcion  
void functionPointer(int *,int);

//Desarrollo de la funcion
void functionPointer(int * pVar,int sumar){
    *pVar = (*pVar)+sumar;
}

int main(void)
{
    char name[40];
    int edad;
    int *punteroEdad;
    printf("Cual es su nombre? ");
    scanf("%39s", name);
    printf("Cual es su edad? ");
    punteroEdad = &edad;
    scanf("%d",punteroEdad);
    printf("hola, %s de %d años %c",name,edad,0x0A);
    functionPointer(punteroEdad,5);
    printf("En 5 años tendrás %d", (int)edad);
    return 0;
}