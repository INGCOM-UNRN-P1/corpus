/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    int numero1 = 4;
    int numero2 = 14;
    int numero3 = 1;
    int numeros[] = {1, 2, 3, 4, 5};
    long long total = 0;

    printf("Antes: primer numero: %d \n, segundo numero: %d \n", numero1, numero2);
    ordenar_par(&numero1, &numero2);
    printf("Ahora: primer numero: %d \n, segundo numero: %d \n", numero1, numero2);

    printf("Antes: primer numero: %d \n, segundo numero: %d \n, tercer numero: %d \n", numero1, numero2, numero3);
    ordenar_tria(&numero1, &numero2, &numero3);
    printf("Ahora: primer numero: %d \n, segundo numero: %d \n, tercer numero: %d \n", numero1, numero2, numero3);

    sumar_acumulado(numeros, 4, &total);
    printf("La suma total de los elementos del arreglo es: %lld. \n", total);
    return 0;
}
