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
    bool es_valido = false;
    if (arreglo != NULL && cantidad > 0)
    {
        if (resultado != NULL)
        {
            *resultado = 0;
            const int *inicio = arreglo;
            const int *fin = arreglo + cantidad;
            while(inicio < fin)
            {
                *resultado += *inicio;
                inicio++;
            }
            es_valido = true;
        }
    }
    else if (cantidad == 0 && resultado != NULL)
    {
        *resultado = 0;
        es_valido = true;
    }
    return es_valido;
}
