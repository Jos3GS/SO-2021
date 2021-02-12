#include <stdio.h>

int main(){
    int *p;
    int (*ptr)[5];
    int arr[5];

    p = arr;
    ptr = &arr;
    printf("P = %p, ptr = %p\n",p,ptr);
    p++;
    ptr++;
    printf("p = %p, ptr = %p\n",p,ptr);
    return 0;
}