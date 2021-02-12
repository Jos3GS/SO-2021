#include <stdio.h>

int arr[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

int main(void){
    int (*p)[3][4] = &arr;
    printf("%d\n",((*p)[2])[3]);
    printf("%d\n", *(*(*p+2)+3));
    return 0;
}