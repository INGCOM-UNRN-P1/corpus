/**
 * @file vector.c
 * @brief Implementacion de la biblioteca libvector (sin estructuras).
 */

#include "vector.h"
#include <stdint.h>
#include <stdlib.h>

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }

    if (cantidad > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int *bloque = calloc(cantidad, sizeof(*bloque));
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
    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }

    if (nueva_cantidad > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int *temporal = realloc(bloque, nueva_cantidad * sizeof(*temporal));
    if (temporal == NULL)
    {
        
        return NULL;
    }

    return temporal;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    if ((primero == NULL && cant_primero > 0) || (segundo == NULL && cant_segundo > 0))
    {
        return NULL;
    }

    size_t total = cant_primero + cant_segundo;
    if (total == 0)
    {
        return NULL;
    }

    if (total > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int *resultado = malloc(total * sizeof(*resultado));
    if (resultado == NULL)
    {
        return NULL;
    }

    int *destino = resultado;

    for (size_t i = 0; i < cant_primero; i++)
    {
        *destino = *(primero + i);
        destino++;
    }

    for (size_t j = 0; j < cant_segundo; j++)
    {
        *destino = *(segundo + j);
        destino++;
    }

    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }

    size_t nueva_cant = *cantidad + 1;
    if (nueva_cant > SIZE_MAX / sizeof(int))
    {
        return false;
    }

    int *temporal = realloc(*puntero_bloque, nueva_cant * sizeof(*temporal));
    if (temporal == NULL)
    {
        
        return false;
    }

    *puntero_bloque = temporal;
    *(*puntero_bloque + *cantidad) = valor;
    *cantidad = nueva_cant;

    return true;
}