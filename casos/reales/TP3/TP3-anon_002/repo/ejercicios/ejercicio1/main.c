/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

    int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");

    int num1 = 30;
    int num2 = 10;

    printf("Antes del intercambio: num1 = %d, num2 = %d\n", num1, num2);

    intercambiar(&num1, &num2);

    printf("Despues del intercambio: num1 = %d, num2 = %d\n", num1, num2);

    ordenar_par(&num1, &num2);

    printf("Despues de ordenar: num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}