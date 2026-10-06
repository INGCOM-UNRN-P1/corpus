/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin
 * structs).
 */

#include "vector_enteros.h"
#include <stdlib.h>


int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *nuevo_arreglo = NULL;
    if (origen != NULL && cantidad != 0)
    {
        nuevo_arreglo = malloc(cantidad * sizeof(int));
        if (nuevo_arreglo != NULL)
        {
            size_t i = 0;
            while (i < cantidad)
            {
                nuevo_arreglo[i] = origen[i];
                i++;
            }
        }
    }
    return nuevo_arreglo;
}


int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    int *array_pares = NULL;
    if (origen != NULL && cantidad_origen != 0 && cantidad_pares != NULL)
    {
        *cantidad_pares = 0;
        size_t i = 0;
        for (i = 0; i < cantidad_origen; i++)
        {
            if (*(origen + i) % 2 == 0)
            {
                *cantidad_pares += 1;
            }
        }
        if (*cantidad_pares != 0)
        {
            size_t k = 0;
            array_pares = (int *)malloc((*cantidad_pares) * sizeof(int));
            for (size_t j = 0; j < cantidad_origen; j++)
            {
                if (*(origen + j) % 2 == 0)
                {
                    *(array_pares + k) = *(origen + j);
                    k++;
                }
            }
        }
        else
        {
            array_pares = NULL;
        }
    }
    return array_pares;
}
