/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }
    return calloc(cantidad, sizeof(int));
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
    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }
    if (nueva_cantidad > SIZE_MAX / sizeof(int))
    {
        return NULL; 
    }
    return realloc(bloque, nueva_cantidad * sizeof(int));
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo)
{
    if (primero == NULL && segundo == NULL)
    {
        return NULL;
    }
    if ((primero == NULL && cant_segundo != 0) || (segundo == NULL && cant_segundo !=0))
    {
        return NULL;
    }
    if (cant_primero > SIZE_MAX - cant_segundo)
    {
        return NULL;
    }

    int *fusionado = crear_bloque_enteros(cant_primero + cant_segundo);
    if (fusionado == NULL)
    {
        return NULL;
    }
    if (cant_primero > 0)
    {
        memcpy(fusionado + cant_primero, segundo, cant_segundo * sizeof(int));
    }
    return fusionado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }
    if (*puntero_bloque == NULL && *cantidad != 0)
    {
        return false;
    }
    if (*cantidad == SIZE_MAX)
    {
        return false;
    }

    int *nuevo = redimensionar_bloque_enteros(*puntero_bloque, *cantidad +1);
    if (nuevo == NULL)
    {
        return false;
    }
    nuevo[*cantidad] = valor;
    (*cantidad)++;
    *puntero_bloque = nuevo;
    return true;
}


