/**
 * @file main.c
 * @brief Programa principal del Ejercicio 1.
 */

#include <stdio.h>
#include "intercambio.h"

#include <stdio.h>
#include <stdbool.h>
#include "intercambio.h"

int main(void)
{
    int primero = 0;
    int segundo = 0;
    int tercero = 0;
    int lista[5] = {10, -3, 25, 8, -12};
    long long suma = 0LL;
    bool estado = false;

    printf("--- Ejercicio 1: Ordenamiento y Suma ---\n\n");

    printf("Ingrese el primer entero: ");
    if (scanf("%d", &primero) != 1)
    {
        return 1;
    }
    printf("Ingrese el segundo entero: ");
    if (scanf("%d", &segundo) != 1)
    {
        return 1;
    }

    printf("Antes ordenar_par: %d, %d\n", primero, segundo);
    ordenar_par(&primero, &segundo);
    printf("Despues ordenar_par: %d, %d\n\n", primero, segundo);

    printf("Ingrese el primer entero para tria: ");
    if (scanf("%d", &primero) != 1)
    {
        return 1;
    }
    printf("Ingrese el segundo entero para tria: ");
    if (scanf("%d", &segundo) != 1)
    {
        return 1;
    }
    printf("Ingrese el tercer entero para tria: ");
    if (scanf("%d", &tercero) != 1)
    {
        return 1;
    }

    printf("Antes ordenar_tria: %d, %d, %d\n", primero, segundo, tercero);
    ordenar_tria(&primero, &segundo, &tercero);
    printf("Despues ordenar_tria: %d, %d, %d\n\n", primero, segundo, tercero);

    estado = sumar_acumulado(lista, 5, &suma);
    if (estado)
    {
        printf("Suma acumulada de lista fija: %lld\n", suma);
    }

    return 0;
}
