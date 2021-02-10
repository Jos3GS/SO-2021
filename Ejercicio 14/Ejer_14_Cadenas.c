#include <stdio.h>

int main(void){
    char name[40];
    printf("Cual es tu nombre?\n");
    scanf("%s39[^\n]", name);
    printf("Hola %s!\n", name);
}