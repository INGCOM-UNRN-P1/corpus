
#include <stdio.h>
#include <stdlib.h>
#include "mis_funciones.h"

#define MAX 5

int get_min(int array[]){
    int minimo = array[0];

    for (int iterador = 1; iterador < MAX; iterador++){
        if (minimo > array[iterador])
            minimo = array[iterador];
    }

    return minimo;
}

int get_max(int array[]){
    int maximo = array[0];

    for (int iterador = 1; iterador < MAX; iterador++){
        if (maximo < array[iterador])
            maximo = array[iterador];
    }

    return maximo;
}

double compute_mean(int array[]){
    double promedio = 0;

    for (int iterador = 0; iterador < MAX; iterador++)
        promedio += array[iterador];

    return promedio /= MAX;
}

int main(){
    int valores[MAX] = {23, 4, 67, 32, 13};

    printf("El minimo es %d\n", get_min(valores));
    printf("El maximo es %d\n", get_max(valores));
    printf("El promedio es %lf\n", compute_mean(valores));

    return 0;
}

