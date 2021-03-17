#include <stdio.h>
float suma(float ,float );
float suma(float sumando1,float sumando2){
    return sumando1+sumando2;
}

float resta(float ,float );
float resta(float minuendo,float sustraendo){
    return minuendo-sustraendo;
}

float multiplicar(float ,float );
float multiplicar(float multiplicando,float multiplicador){
    return (multiplicando) * (multiplicador);
}
int main(void)
{
    char entrada="c";
    do
    {
        float operando1;
        float operando2;
        printf("\nIngrese el operando 1\n");
        scanf("%f",&operando1);
        printf("\nIngrese el operando 2\n");
        scanf("%f",&operando2);
        printf("\nIngrese la operacion a realizar (+ - *)\n");
        getc(stdin);
        scanf("%c",&entrada);
        switch (entrada)
        {
        case '+':
            printf("%f + %f = %f",operando1,operando2,suma(operando1,operando2));
            break;
        case '-':
            printf("%f - %f = %f",operando1,operando2,resta(operando1,operando2));
            break;
        case '*':
            printf("%f * %f = %f",operando1,operando2,multiplicar(operando1,operando2));
        default:
            break;
        }
        printf("\nq para salir\n");
        getc(stdin);
        scanf("%c",&entrada);   
    } while (entrada!='q');
    return 0;
}