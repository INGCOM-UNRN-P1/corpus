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
    else
    {
        if (*menor > *mayor)
        {
            intercambiar(menor, mayor);
        }
    }
}

void ordenar_tria(int *a, int *b, int *c)
{
    if (a == NULL || b == NULL || c == NULL)
    {
        return;
    }
    else
    {
        ordenar_par(a, c);
        ordenar_par(a, b);
        ordenar_par(b, c);
    }
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }
    else
    {
        *resultado = 0;
        for (size_t i = 0; i < cantidad; i++)
        {
            *resultado = *resultado + *(arreglo + i);
        }
        return true;
    }
}
