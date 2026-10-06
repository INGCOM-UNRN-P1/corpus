/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"
#include "punteros.h"



const int *buscar_puntero_minimo(const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || fin <= inicio)
    {
        return NULL;
    }

    const int *minimo = inicio;

    while (inicio != fin)
    {
        if (*inicio < *minimo)
        {
            minimo = inicio;
        }
        inicio++;
    }

    return minimo;
}

bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad == 0)
    {
        return false;
    }

    int *fin = (arreglo + cantidad);
    for (size_t i = 0; i < cantidad; i++)
    {
        int *menor = (int*)buscar_puntero_minimo(arreglo, fin);
        if (*arreglo != *menor)
        {
            intercambiar(arreglo, menor);
        }
        arreglo++;
    }

    return true;
}
