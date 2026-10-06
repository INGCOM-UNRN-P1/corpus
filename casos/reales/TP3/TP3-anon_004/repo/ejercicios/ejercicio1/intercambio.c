/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *menor, int *mayor)
{
    if (menor == NULL || mayor == NULL)
    {
        return;
    }

    if (*menor > *mayor)
    {
        intercambiar(menor, mayor);
    }
}

void ordenar_tria(int *primero, int *segundo, int *tercero)
{
    if (primero == NULL || segundo == NULL || tercero == NULL)
    {
        return;
    }

    ordenar_par(primero, segundo);
    ordenar_par(segundo, tercero);
    ordenar_par(primero, segundo);
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    const int *actual = NULL;
    const int *limite = NULL;
    long long suma = 0LL;

    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }

    actual = arreglo;
    limite = arreglo + cantidad;

    while (actual < limite)
    {
        suma += *actual;
        actual++;
    }

    *resultado = suma;

    return true;
}
