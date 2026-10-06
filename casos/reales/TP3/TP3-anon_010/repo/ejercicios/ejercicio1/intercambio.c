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
        ordenar_par(a, c);
        ordenar_par(b, c);
    }
}

bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado)
{
    bool valido = false;
    if (arreglo != NULL && resultado != NULL)
    {
        long long resultado_suma = 0;
        const int *inicio = arreglo;
        const int *fin = arreglo + cantidad;

        while ( inicio < fin)
        {
            resultado_suma += *inicio;
            inicio++;
        }

        *resultado = resultado_suma;
        valido = true;
    }
    return valido;
}
