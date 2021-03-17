#include <stdio.h>

double Operar (int N1, int N2, char OP){
    
    if(OP == '+'){
        return(N1 + N2);
    }else if(OP == '-'){
        return(N1 - N2);
    }else if(OP == '*'){
        return(N1 * N2);
    }else if(OP){
        if(N2 == 0){
            return(0);
        }else{
            return(N1/N2);
        }
    }else{
        return(0);
    }
}

int main (void){
    float Num1=0, Num2=0;
    char Ope='a', exit='a';

    do{
    printf("Ingrese el Primer Numero\n");
    scanf("%f",&Num1);
    printf("Ingrese el Segundo numero\n");
    scanf("%f",&Num2);
    printf("Ingrese el operando ( + - * / )\n");
    scanf("%c",&Ope);
    scanf("%c",&Ope);

    printf("El resultado de la operacion fue:  %f\n", Operar(Num1, Num2, Ope));
    printf("Para terminar la ejecución escriba una q\n");
    scanf("%c",&exit);
    scanf("%c",&exit);
    }while(exit!='q');

    return(0);
}