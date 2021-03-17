#include <stdio.h>
void Imprimir(int *ptr, int n){
    for(int i=0; i<n;i++){
        printf(" %d ",ptr[i]);
    }
    printf("\n");
}

char key;
int tamanno=0, N=0, A=0;
int main(void){
    printf("Ingrese el tamaño del arreglo deseado\n");
    scanf("%d", &tamanno);
    scanf("%c",&key);
    int Arreglo[tamanno];
    for(int i=0; i<tamanno; i++){
        printf("Ingrese el elemento %d de arreglo\n",(i+1));
        scanf("%d",&Arreglo[i]);
        scanf("%c",&key);
    }
    Imprimir(Arreglo, tamanno);
    do{
    printf("Ahora vamos a cambiar un numero del arreglo, escribe la posicion del numero a cambiar\n");
    scanf("%d",&N);
    scanf("%c",&key);
    }while(N<1 || N>tamanno);
    printf("Ingrese el numero nuevo que desea poner\n");
    scanf("%d",&A);
    scanf("%c",&key);
    Arreglo[N-1] = A;
    Imprimir(Arreglo, tamanno);


    return 0;
}

