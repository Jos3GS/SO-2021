#include <stdio.h>
#include "file1.h"

int main(int argc, char* argv[]){
    int a = suma(4,5);
    int b = multiplicacion(9, a);
    printf("b value is: %d\n",b);
    return 0;
}