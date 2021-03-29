#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int Max = -999999999;
    for(int i=1; i<argc; i++){
        if(atoi(argv[i])>Max){
            Max = atoi(argv[i]);
        }
    }

    printf("El Numero maximo fue: %d\n",Max);
    exit(EXIT_SUCCESS);
}