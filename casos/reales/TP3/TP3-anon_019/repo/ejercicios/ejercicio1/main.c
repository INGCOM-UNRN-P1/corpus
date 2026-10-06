/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");
 
    int x = 50;
    int y = 15;
    printf("ordenar_par -> Antes: x = %d, y = %d\n", x, y);
    ordenar_par(&x, &y);
    printf("ordenar_par -> Despues: x = %d, y = %d\n\n", x, y);

    int a = 99;
    int b = 10;
    int c = 42;
    printf("ordenar_tria -> Antes: a = %d, b = %d, c = %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("ordenar_tria -> Despues: a = %d, b = %d, c = %d\n\n", a, b, c);

    int valores[] = {10, 20, 30, 40};
    long long total = 0;
    sumar_acumulado(valores, 4, &total);
    printf("sumar_acumulado -> El total del arreglo es: %lld\n", total);

    return 0;
}