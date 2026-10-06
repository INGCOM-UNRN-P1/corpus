/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");

    printf("\n===== Ordenar Par =====\n");
    int a = 10;
    int b = 2;
    int c = 5;
    printf("ANTES: a = %d, b = %d\n", a, b);
    ordenar_par(&a, &b);
    printf("DESPUES: a = %d, b = %d\n", a, b);

    printf("\n===== Ordenar Tria =====\n");
    a = 10;
    b = 2;
    c = 5;
    printf("ANTES: a = %d, b = %d, c = %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("DESPUES: a = %d, b = %d, c = %d\n", a, b, c);

    printf("\n===== Sumar Acumulado =====\n");
    int arreglo[] = {1,2,3,4};
    size_t cantidad = sizeof(arreglo)/sizeof(arreglo[0]);
    long long resultado = 0;
    printf("ARREGLO: ");
    for (size_t i = 0; i < cantidad; i++)
    {
        printf("%d, ", arreglo[i]);
    }
    printf("\n");
    printf("ANTES: resultado = %lld\n", resultado);

    sumar_acumulado(arreglo, cantidad, &resultado);

    printf("DESPUES: resultado = %lld\n", resultado);


    return 0;
}
