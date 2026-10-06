/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

int main(void)
{
    printf("ejercicio 1: intervambio con punteros\n");

    int primero = 8;
    int segundo = 3;
    printf("intercambiar: antes (%d, %d", primero, segundo);
    intercambiar(&primero, &segundo);
    printf(" -> depues (%d, %d)\n", primero, segundo);

    int menor = 50;
    int mayor = 10;
    printf("ordenar_par: antes(%d, %d)". menor, mayor);
    ordenar_par(&menor, &mayor);
    printf(" -> despues (%d, %d)\n", menor, mayor);

    int a = 30;
    int b = 5;
    int c = 17;
    printf("ordenar_tria: atnes (%d, %d, %d)", a, b, c);
    ordenar_tria(&a, &b, &c);
    printf(" -> despues (%d, %d, %d)\n", a, b, c);

    int datos[] = {10, 20, 30, 40};
    long long suma = 0,
    if (sumar_acumulado(datos, 4, &suma))
    {
        printf("sumar_acumulado: %11d\n", suma);
    }

    return 0;
}