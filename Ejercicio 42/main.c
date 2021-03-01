#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "api.h"

int main(int argc, char* argv[]){
    
    int (*func_ptr)() = NULL;
    void* handle = dlopen("./libstatic.so", RTLD_LAZY);

    if(!handle){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    func_ptr = dlsym(handle, "uno");
    if(!func_ptr){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    printf("uno(): %d\n", func_ptr());

    func_ptr = dlsym(handle, "dos");
    if(!func_ptr){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    printf("dos(): %d\n",func_ptr());

    func_ptr = dlsym(handle, "tres");
    if(!func_ptr){
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    printf("tres(): %d\n",func_ptr());
    return 0;
}