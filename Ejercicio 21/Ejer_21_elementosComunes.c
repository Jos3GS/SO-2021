#include <stdio.h>

int N1=0,N2=0,NR=0, a=0;
char key;

void arrayCommon(int* ArrA, int N1, int* ArrB, int N2, int* ArrRE, int NR){
    int aux=-1;
    for(int i=0; i<N1;i++){
        for(int j=0; j<N2; j++){
            if(ArrA[i]==ArrB[j]){
                for(int k=0; k<NR; k++){
                    if(k>aux){
                        if(ArrA[i]!=ArrRE[k]){
                            ArrRE[k] = ArrA[i];
                            aux++;
                            break;
                        }
                    }
                }
            }
        }
    }

    printf("Se encontraron %d Elementos en comun\n",aux+1);
    for(int i=0;i<aux+1;i++){
        printf(" %d ",ArrRE[i]);
    }
    printf("\n");
    
}

int main (void){

    printf("Ingrese el tamaño del primer Arreglo\n");
    while(scanf("%d", &N1) != 1){
        printf("Ingrese el tamaño del primer Arreglo\n");
        scanf("%c",&key);

    }
    scanf("%c",&key);
    int ArrayA[N1];
    printf("Ahora ingrese los elementos del Array\n");
    for(int i=0; i<N1; i++){
        printf("Ingrese el elemento %d del array\n",i);
        scanf("%d",&a);
        scanf("%c",&key);
        ArrayA[i] = a;
    }

    printf("Ingrese el tamaño del segundo Arreglo\n");
    while(scanf("%d", &N2) != 1){
        printf("Ingrese el tamaño del segundo Arreglo\n");
        scanf("%c",&key);

    }
    scanf("%c",&key);
    int ArrayB[N2];
    printf("Ahora ingrese los elementos del Array\n");
    for(int i=0; i<N2; i++){
        printf("Ingrese el elemento %d del array\n",i);
        scanf("%d",&a);
        scanf("%c",&key);
        ArrayB[i] = a;
    }

    if(N1 < N2){
        NR = N1;
    }else{
        NR = N2;
    }

    int ArrayRe[NR];

    arrayCommon(ArrayA,N1,ArrayB,N2,ArrayRe,NR);
    
    return 0;
}