/**
 * @file ordenamiento.c
 * @brief Implementación de ordenamiento por selección empleando aritmética de punteros.
 */

#include "ordenamiento.h"

const int *buscar_puntero_minimo (const int *inicio, const int *fin)
{
    if (inicio == NULL || fin == NULL || fin < inicio)
    {
        return NULL;
    }
    else
    {
        const int *ptr_min = inicio;
        while (inicio <= fin)
        {
            if (*inicio < *ptr_min)
            {
                ptr_min = inicio;
            }
            inicio++;
        }
        return ptr_min;
    }
}

void ordenar_seleccion_punteros (int *arreglo, size_t cantidad)
{
    if (arreglo == NULL || cantidad <2)
    {
        return;
    }
    else
    {
        int *inicio = arreglo;
        int *fin = arreglo + cantidad - 1;

        while (inicio < fin)
        {
            const int *elemento_minimo = buscar_puntero_minimo(inicio, fin);
            intercambiar(inicio, (int *)elemento_minimo);   // lo casteo a int sin el 'const' porque si no salen alertas
            inicio++;
        }
    }
}