#include <stdio.h>
#include <stdlib.h>

const char FILE_NAME[] = "Materias.txt";

int main(){
    FILE *in_file;

    int ch;
    //char palabra[50];
    in_file = fopen(FILE_NAME, "r");
    if(in_file == NULL){
        printf("No se puede Abrir el archivo %s\n", FILE_NAME);
        exit(8);
    }

    while(1){
        ch = fgetc(in_file);
        if(ch == EOF){
            break;
        }
        printf("Letra %c\n",ch);

    }
    fclose(in_file);
    in_file = fopen(FILE_NAME, "r");

    while(1){
        ch = fgetc(in_file);
        if(ch == EOF){
            break;
        }
        printf("Letra %c\n",ch);

    }

    fclose(in_file);
    return 0;
}