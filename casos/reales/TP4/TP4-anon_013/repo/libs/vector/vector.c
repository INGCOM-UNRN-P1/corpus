/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include "vector.h"
#include <stdlib.h>

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }
    int *ptr = calloc(cantidad, sizeof(int));
    return ptr;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }
    else
    {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }
    int *ptr_aux = realloc(bloque, sizeof(int) * nueva_cantidad);
    if (ptr_aux == NULL)
    {
        return NULL;
    }
    else
    {
        return ptr_aux;
    }
}


int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{

    if (primero == NULL && segundo == NULL)
    {
        return NULL;
    }
    else
    {
        size_t cant_total = cant_primero + cant_segundo;
        int *destino = malloc(sizeof(int) * cant_total);
        if (destino == NULL)
        {
            return NULL;
        }

        if (primero != NULL)
        {
            memcpy(destino, primero, sizeof(int) * cant_primero);
        }
        if (segundo != NULL)
        {
            memcpy(destino + cant_primero, segundo, sizeof(int) * cant_segundo);
        }
        return destino;
    }
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }
    int *temp = realloc(*puntero_bloque, (*cantidad + 1) * sizeof(int));
    if (temp == NULL)
    {
        return false;
    }
    else
    {
        *puntero_bloque = temp;
        temp[*cantidad] = valor;
        (*cantidad)++;
        return true;
    }
}
