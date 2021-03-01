#include <stdio.h>

int suma(int,int);
int sumatoria(int*,int);

int main(int argc, char* argv[]){
    int a = suma(4,5);
    int array[] = {1,2,3,4,5};
    int b = sumatoria(array,(sizeof(array))/(sizeof(int)));
    printf("suma(4,5): %d\n",a);
    printf("sumatoria(1..5): %d\n",b);
    return 0;
}