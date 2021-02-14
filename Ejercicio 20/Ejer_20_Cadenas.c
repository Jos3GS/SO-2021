#include <stdio.h>

char nombres[3][20] = {"fulano","mengano","perano"};

int main(void){
    char *a;
    char (*b)[20];
    char *c;
    char (*d)[3][20];

    a = &nombres[0][0];
    printf("El nombre es %s",a);
    b = nombres;
    c = &nombres[0][0];
    d = &nombres;

    for(int i=0; i < 3;i++){
        printf("char (*)[] el nombre [%d] es %s \n",i,(char *)(b+i));
        printf("char*: el nombre [%d] es %s \n",i,(char *)(c + (i*2)));
        printf("char (*)[][]: el nombre [%d] es %s\n",i,(char *)(d+i));
    }
    return 0;
}