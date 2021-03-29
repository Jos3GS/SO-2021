#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    long Suma=0;
    double Promedio=0;

    for(int i=1; i<argc; i++){
        Suma = Suma + atoi(argv[i]);
    }
    Promedio = Suma / (argc -1);

    printf("El Promedio fue de: %f\n",Promedio);
    exit(EXIT_SUCCESS);
}