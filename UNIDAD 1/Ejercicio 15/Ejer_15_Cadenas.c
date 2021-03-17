#include <stdio.h>
#include <string.h>

int main(void){
    char name[40];
    printf("Como te llamas?\n");
    if(fgets(name,40,stdin)){
        name[strcspn(name, "\n")] =0;
        printf("Hola %s!\n", name);
    }
}