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
    if (nueva_cantidad == 0)
    {
        free(bloque);
        bloque = NULL;

        return NULL;
    }

    int *temp = realloc(bloque, nueva_cantidad * sizeof(int));

    if (temp == NULL)
    {
        return NULL;
    }
    
    return temp;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    if(primero == NULL && segundo == NULL){
        return NULL;
    }

    int *total = malloc((cant_primero + cant_segundo) * sizeof(int));

    if(total == NULL)
    {
        return NULL;
    }

    for(size_t i = 0; i < cant_primero; i++)
    {
        total[i] = primero[i];
    }

    for(size_t i = 0; i < cant_segundo; i++)
    {
        total[cant_primero + i] = segundo[i];
    }

    return total;
}

bool agregar_al_bloque_enteros(int **puntero_bloque,
                               size_t *cantidad,
                               int valor)
{
    int *temp = realloc(*puntero_bloque,
                        (*cantidad + 1) * sizeof(int));

    if (temp == NULL)
    {
        return false;
    }

    *puntero_bloque = temp;

    (*puntero_bloque)[*cantidad] = valor;

    (*cantidad)++;

    return true;
}