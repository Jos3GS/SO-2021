#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    void* ptr = malloc(1024);
    printf("Address: %p\n", ptr);

    while(1){
        sleep(1);
    };

    return 0;
}