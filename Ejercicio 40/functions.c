int suma(int a , int b){
    return (a+b);
}

int sumatoria(int* numeros, int cantidad){
    int acumulado=0;
    for(int i=0; i<cantidad; i++){
        acumulado += numeros[i];
    }
    return acumulado;
}