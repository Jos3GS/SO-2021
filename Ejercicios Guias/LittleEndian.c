#include <stdio.h>
 #define LITTLE_ENDIAN 0
 #define BIG_ENDIAN 1

 int machineEndianness(){
     int i = 1;
     char *p =(char *) &i;
     if(p[0] == 1)
        return LITTLE_ENDIAN;
    else
        return BIG_ENDIAN;
 }
 int main(){
     if(machineEndianness())
        printf("Big Endian\n");
    else
    printf("little Endian\n");
    return 0;
 }