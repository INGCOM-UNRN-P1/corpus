/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin
 * structs).
 */

#include "vector_enteros.h"
#include <stdlib.h>


int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *arreglo_clonado = NULL;
    if (origen == NULL || cantidad == 0)
    {
        arreglo_clonado = NULL;
    }
    else
    {
        arreglo_clonado = malloc(cantidad * sizeof(int));
        if (arreglo_clonado == NULL)
        {
            arreglo_clonado = NULL;
        }
        else
        {
            const int *inicio_copia = origen;
            int *destino_copia = arreglo_clonado;
            const int *limite = origen + cantidad;

            while (inicio_copia < limite)
            {
                *destino_copia = *inicio_copia;
                inicio_copia++;
                destino_copia++;
            }
        }
    }
    return arreglo_clonado;
}


int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    int *arreglo_pares = NULL;

    if (cantidad_pares == NULL)
    {
        arreglo_pares = NULL;
    }
    else
    {
        *cantidad_pares = 0;

        if (origen == NULL || cantidad_origen == 0)
        {
            arreglo_pares = NULL;
        }
        else
        {
            *cantidad_pares = 0;
            const int *actual = origen;
            const int *limite = origen + cantidad_origen;

            while (actual < limite)
            {
                if (*actual % 2 == 0)
                {
                    (*cantidad_pares)++;
                }
                actual++;
            }
            if (*cantidad_pares == 0)
            {
                arreglo_pares = NULL;
            }
            else
            {
                arreglo_pares = malloc((*cantidad_pares) * sizeof(int));

                if (arreglo_pares == NULL)
                {
                    arreglo_pares = NULL;
                    *cantidad_pares = 0;
                }
                else
                {
                    actual = origen;
                    int *destino = arreglo_pares;

                    while (actual < limite)
                    {
                        if (*actual % 2 == 0)
                        {
                            *destino = *actual;
                            destino++;
                        }
                        actual++;
                    }
                }
            }
        }
    }
    return arreglo_pares;
}
