#include <pthread.h>
#include <stdio.h>

void* imprime_x (void* unused){
    while(1) fputc('X',stderr);
    return NULL;
}

int main(){
    pthread_t id_hilo;
    pthread_create(&id_hilo,NULL, &imprime_x, NULL);
    while(1) fputc("O", stderr);
    return 0;
}