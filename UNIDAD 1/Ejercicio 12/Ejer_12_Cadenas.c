#include <stdio.h>

int main(void){
    char name[40];
    printf("Cual es tu nombre?\n");
    scanf("%39s", name);
    printf("Hello %s!\n", name);
}