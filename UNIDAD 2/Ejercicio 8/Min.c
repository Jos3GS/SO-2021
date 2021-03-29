#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int Min = 999999999;
    for(int i=1; i < argc; i++){
        if(atoi(argv[i])<Min){
            Min = atoi(argv[i]);
        }
    }

    printf("El valor minimo fue: %d\n",Min);
    exit(EXIT_SUCCESS);
}