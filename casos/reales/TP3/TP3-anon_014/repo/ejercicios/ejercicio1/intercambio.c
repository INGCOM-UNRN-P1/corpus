/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por
 *        referencia.
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
    // Tres comparaciones alcanzan: las dos primeras llevan el mayor a 'c'
    // y la última ordena los dos restantes.
    ordenar_par(a, b);
    if (*b > *c)
    {
        intercambiar(b, c);
    }
    ordenar_par(a, b);
}

bool sumar_acumulado(const int *arreglo, size_t cantidad,
                     long long *resultado)
{
    if (arreglo == NULL || resultado == NULL)
    {
        return false;
    }

    long long suma = 0;
    const int *fin = arreglo + cantidad;
    for (const int *actual = arreglo; actual < fin; actual++)
    {
        suma = suma + *actual;
    }

    *resultado = suma;
    return true;
}
