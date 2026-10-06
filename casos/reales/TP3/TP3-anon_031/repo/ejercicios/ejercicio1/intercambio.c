/**
 * @file intercambio.c
 * @brief Implementación de ordenamiento de pares, tríos y sumatoria por referencia.
 */

#include "intercambio.h"

void ordenar_par(int *menor, int *mayor)
{
    if (menor != NULL && mayor != NULL)
    {
        if (*menor > *mayor)
        {
            intercambiar(menor, mayor);
        }
    }
}

void ordenar_tria(int *a, int *b, int *c)
{
    if (a != NULL && b != NULL && c != NULL)
    {
        ordenar_par(a, b);
        ordenar_par(b, c);
        ordenar_par(a, b);
    }
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    bool operacion_exitosa = false;

    if (arreglo != NULL && resultado != NULL)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;
        long long suma = 0;

        while (actual < fin)
        {
            suma += *actual;
            actual++;
        }

        *resultado = suma;
        operacion_exitosa = true;
    }

    return operacion_exitosa;
}