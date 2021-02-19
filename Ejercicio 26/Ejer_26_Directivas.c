#include <stdio.h>
#define CONDITION

int main (int argc, char* argv[]){
    #ifdef CONDITION
    printf("CODIGO IF\n");
    #else
    printf("CODIGO ELSE\n");
    #endif
    return 0;
}