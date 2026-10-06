/**
 * @file intercambio.c
 * @brief Implementacion de ordenamiento de pares, trios y sumatoria por referencia.
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

void ordenar_tria(int *a, int *b, int *c)
{
    if (a == NULL || b == NULL || c == NULL)
    {
        return;
    }

    ordenar_par(a, b);
    ordenar_par(b, c);
    ordenar_par(a, b);
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    if (resultado == NULL)
    {
        return false;
    }

    if (cantidad == 0)
    {
        *resultado = 0;
        return true;
    }

    if (arreglo == NULL)
    {
        return false;
    }

    long long suma = 0;
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        suma += *actual;
        actual++;
    }

    *resultado = suma;
    return true;
}