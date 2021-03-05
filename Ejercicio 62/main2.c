#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    char *ptr = malloc(20*sizeof(char));
    free(ptr);
    return 0;
}