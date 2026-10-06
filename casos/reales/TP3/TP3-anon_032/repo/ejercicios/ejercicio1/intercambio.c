/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"



void ordenar_par(int *menor, int *mayor)
{
    if (menor == NULL ||
        mayor == NULL)
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
    if (a == NULL ||
        b == NULL ||
        c == NULL)
    {
        return;
    }

    if (*a > *b)
    {
        intercambiar(a, b);
    }
    if (*b > *c)
    {
        intercambiar(b, c);
    }
    if (*a > *b)
    {
        intercambiar(a, b);
    }
}


bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }

    *resultado = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        *resultado += *(arreglo + i);
    }

    return true;
}
