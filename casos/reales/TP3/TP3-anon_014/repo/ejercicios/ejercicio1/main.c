/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("Ejercicio 1: Intercambio con punteros\n");

    int x = 5;
    int y = 9;
    printf("Intercambio antes:  x = %d, y = %d\n", x, y);
    intercambiar(&x, &y);
    printf("Intercambio despues: x = %d, y = %d\n", x, y);

    int primero = 80;
    int segundo = 20;
    printf("Par antes:  %d %d\n", primero, segundo);
    ordenar_par(&primero, &segundo);
    printf("Par despues: %d %d\n", primero, segundo);

    int a = 30;
    int b = 10;
    int c = 20;
    printf("Trio antes:  %d %d %d\n", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf("Trio despues: %d %d %d\n", a, b, c);

    int datos[] = {10, 20, 30, 40};
    size_t cantidad = sizeof(datos) / sizeof(*datos);
    long long suma = 0;
    if (sumar_acumulado(datos, cantidad, &suma) == true)
    {
        printf("Suma de {10, 20, 30, 40}: %lld\n", suma);
    }

    return 0;
}
