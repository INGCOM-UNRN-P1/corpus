#include <stdint.h>
#include <stdlib.h>
#include "vector.h"

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
    
    int *nuevo = calloc(cantidad, sizeof(*nuevo));
    return nuevo;
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

    if (nueva_cantidad > SIZE_MAX / sizeof(*bloque))
    {
        return NULL;
    }

    int *nuevo_bloque = realloc(bloque, nueva_cantidad * sizeof(*nuevo_bloque));
    if (nuevo_bloque == NULL)
    {
        return NULL;
    }

    return nuevo_bloque;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    if (cant_primero > SIZE_MAX - cant_segundo)
    {
        return NULL;
    }

    size_t total = cant_primero + cant_segundo;
    if (total == 0)
    {
        return NULL;
    }

    int *nuevo_bloque = crear_bloque_enteros(total);
    if (nuevo_bloque == NULL)
    {
        return NULL;
    }

    size_t cursor = 0;

    if (primero != NULL && cant_primero > 0)
    {
        for (size_t i = 0; i < cant_primero; i++)
        {
            *(nuevo_bloque + cursor) = *(primero + i);
            cursor++;
        }
    }

    if (segundo != NULL && cant_segundo > 0)
    {
        for (size_t i = 0; i < cant_segundo; i++)
        {
            *(nuevo_bloque + cursor) = *(segundo + i);
            cursor++;
        }
    }

    return nuevo_bloque;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }

    if (*cantidad == SIZE_MAX)
    {
        return false;
    }

    size_t nueva_cantidad = *cantidad + 1;
    int *bloque_expandido = redimensionar_bloque_enteros(*puntero_bloque, nueva_cantidad);
    
    if (bloque_expandido == NULL)
    {
        return false;
    }

    *(bloque_expandido + *cantidad) = valor;
    *puntero_bloque = bloque_expandido;
    *cantidad = nueva_cantidad;

    return true;
}