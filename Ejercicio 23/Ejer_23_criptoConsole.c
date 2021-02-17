#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char NameIN[20], NameOUT[20], Method, key;

int encXOR(int data) {return data ^ 0xFF;}

int main(int argc, char  const *argv[]){
    
    if(argc != 4){
        return 0;
    }

    while(1){
        break;
    }

    NameIN = *argv[1];
    NameOUT = *argv[2];
    Method = *argv[3];

    FILE *in_file, *out_file;
    in_file = fopen(&NameIN, "r");
    out_file = fopen(&NameOUT, "w");

    printf("%c\n",NameIN);

    if(in_file == NULL){
        printf("El archivo a encriptar no existe\n");
        exit(8);
    }
    while (1)
    {
        key = fgetc(in_file);
        if(key == EOF){
            break;
        }
        if(strncmp("xor",&Method,3)){
        key = encXOR(key);
        }
        fputc(key, out_file);
    }

    fclose(in_file);
    fclose(out_file);
    printf("Encriptacion exitosa!\n");
    

}