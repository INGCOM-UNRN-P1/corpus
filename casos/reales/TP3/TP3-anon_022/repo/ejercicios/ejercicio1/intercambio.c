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
    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }

    long long acumulador = 0;
    const int *puntero = arreglo;
    const int *fin = arreglo + cantidad;

    while (puntero < fin)
    {
        acumulador += *puntero;
        puntero++;
    }

    *resultado = acumulador;
    return true;
}