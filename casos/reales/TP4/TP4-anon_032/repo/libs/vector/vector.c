/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }

    int *bloque = calloc(cantidad, sizeof(int));

    if (bloque == NULL)
    {
        return NULL;
    }

    return bloque;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }

    free(*puntero_bloque);
    *puntero_bloque = NULL;
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if (bloque == NULL)
    {
        return NULL;
    }
    if (nueva_cantidad == 0)
    {
        liberar_bloque_enteros(&bloque);
        return NULL;
    }
    
    void *bloque_redimensionado = realloc(bloque, (nueva_cantidad * sizeof(int)));
    
    if (bloque_redimensionado != NULL)
    {
        return bloque_redimensionado;
    }
    else
    {
        return NULL;
    }
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    if (primero == NULL || segundo == NULL)
    {
        return NULL;
    }
    size_t cantidad_total = (cant_primero + cant_segundo);

    int *bloque = crear_bloque_enteros(cantidad_total);

    if (bloque != NULL)
    {
        size_t i = 0;
        for (size_t j = 0; j < cant_primero; j++)
        {
            *(bloque + i) = *(primero + j);
            i++;
        }
        for (size_t j = 0; j < cant_segundo; j++)
        {
            *(bloque + i) = *(segundo + j);
            i++;
        }
        return bloque;
    }
    else
    {
        return NULL;
    }
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }

    int *bloque = redimensionar_bloque_enteros(*puntero_bloque, (*cantidad + 1));
    if (bloque != NULL)
    {
        *(bloque + *cantidad) = valor;
        (*cantidad)++;
        *puntero_bloque = bloque;
        return true;
    }
    else
    {
        return false;
    }
}