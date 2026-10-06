/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
    printf("Prueba de funcion intercambiar\n");
    int a = 10;
    int b = 20;
    printf("Valores antes del intercambio: a = %d, b = %d\n", a,b);
    intercambiar(&a,&b);
    printf("Valores post intercambio: a = %d, b = %d\n", a, b);

    printf("Prueba de funcion ordenar_par\n");
    printf("Valores desordenados: a = %d, b = %d\n", a,b);
    ordenar_par(&a,&b);
    printf("Valores luego de la funcion: a = %d, b = %d\n", a,b);

    return 0;
}
