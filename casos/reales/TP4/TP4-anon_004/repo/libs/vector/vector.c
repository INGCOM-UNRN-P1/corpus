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
    int *temporal = NULL;

    if (nueva_cantidad == 0)
    {
        free(bloque);
        return NULL;
    }

    temporal = realloc(bloque, nueva_cantidad * sizeof(int));

    if (temporal == NULL)
    {
        return NULL;
    }

    return temporal;
}

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    int *resultado = NULL;
    size_t total = 0;
    size_t i = 0;

    if ((primero == NULL && cant_primero > 0) ||
        (segundo == NULL && cant_segundo > 0))
    {
        return NULL;
    }

    total = cant_primero + cant_segundo;

    resultado = crear_bloque_enteros(total);

    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < cant_primero; i++)
    {
        resultado[i] = primero[i];
    }

    for (i = 0; i < cant_segundo; i++)
    {
        resultado[cant_primero + i] = segundo[i];
    }

    return resultado;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    int *temporal = NULL;
    bool resultado = false;

    if (puntero_bloque != NULL && cantidad != NULL)
    {
        temporal = redimensionar_bloque_enteros(
            *puntero_bloque,
            *cantidad + 1
        );

        if (temporal != NULL)
        {
            temporal[*cantidad] = valor;
            *puntero_bloque = temporal;
            *cantidad = *cantidad + 1;
            resultado = true;
        }
    }

    return resultado;
}
