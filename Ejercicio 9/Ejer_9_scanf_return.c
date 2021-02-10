#include <stdio.h>

int main(void){

    int a;
    char key;
    printf("Ingrese un numero: ");
    while(scanf("%d", &a) != 1){
        printf("\nIngrese un numero: ");
        scanf("%c", &key);
    }
    printf("Igresaste el: %d. \n",a);
}