#include <stdio.h>

int main(){
    int num;
    char key;
    printf("Prueba scanf, ingrese un numero, y presione Enter\n");
    scanf("%d",&num);
    scanf("%c",&key);
    printf("Ingrese cualquier tecla para terminar y presione enter");
    scanf("%c", &key);
    return 0;
}