#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    long suma=0, max=0, min=9999999999;
    for(int i=1; i<argc;i++){
        suma = suma + atoi(argv[i]);
        if(atoi(argv[i])>max){
            max = atoi(argv[i]);
        }
        if(atoi(argv[i])<min){
            min = atoi(argv[i]);
        }
    }
    double prom = suma / (argc - 1);
    printf("El promedio fue: %f\n", prom);
    printf("El valor maximo fue: %ld\n", max);
    printf("El valor minimo fue: %ld\n", min);

    exit(EXIT_SUCCESS);
}