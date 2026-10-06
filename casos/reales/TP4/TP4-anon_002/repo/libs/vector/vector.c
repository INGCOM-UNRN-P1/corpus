/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include "vector.h"
#include <stdlib.h>


int *crear_bloque_enteros(size_t cantidad)
{
    int *bloque = NULL;

    if (cantidad > 0)
    {
        bloque = calloc(cantidad, sizeof(int));
    }
    return bloque;
}


void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque != NULL && *puntero_bloque != NULL)
    {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}


int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *bloque_redimensionado = NULL;
    if (nueva_cantidad == 0)
    {
        free(bloque);
        bloque_redimensionado = NULL;
    }
    else
    {
        int *temporal = realloc(bloque, nueva_cantidad * sizeof(int));

        if (temporal != NULL)
        {
            bloque_redimensionado = temporal;
        }
        else
        {
            bloque_redimensionado = NULL;
        }
    }
    return bloque_redimensionado;
}


int *fusionar_bloques_enteros(const int *primero, size_t cantidad_primero,
                              const int *segundo, size_t cantidad_segundo)
{
    int *bloque_fusionado = NULL;

    if (primero == NULL && segundo == NULL)
    {
        bloque_fusionado = NULL;
    }
    else
    {
        size_t cantidad_total = cantidad_primero + cantidad_segundo;

        if (cantidad_total > 0)
        {
            bloque_fusionado = crear_bloque_enteros(cantidad_total);

            if (bloque_fusionado != NULL)
            {
                const int *copia_primera = primero;
                const int *copia_segunda = segundo;
                int *destino = bloque_fusionado;
                size_t inicio_primero = 0;
                size_t inicio_segundo = 0;

                while (inicio_primero < cantidad_primero)
                {
                    *destino = *copia_primera;
                    copia_primera++;
                    destino++;
                    inicio_primero++;
                }
                while (inicio_segundo < cantidad_segundo)
                {
                    *destino = *copia_segunda;
                    copia_segunda++;
                    destino++;
                    inicio_segundo++;
                }
            }
        }
        else
        {
            bloque_fusionado = NULL;
        }
    }
    return bloque_fusionado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    bool agregado = false;

    if (puntero_bloque == NULL || cantidad == NULL)
    {
        agregado = false;
    }
    else
    {
        size_t nueva_cantidad = *cantidad + 1;
        int *nuevo_bloque =
            redimensionar_bloque_enteros(*puntero_bloque, nueva_cantidad);

        if (nuevo_bloque != NULL)
        {
            *(nuevo_bloque + *cantidad) = valor;
            *puntero_bloque = nuevo_bloque;
            (*cantidad)++;
            agregado = true;
        }
    }
    return agregado;
}
