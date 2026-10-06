/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector.
 */

#include <stdint.h>
#include <stdlib.h>
#include "vector.h"

int *crear_bloque_enteros(size_t cantidad)
{
    int *bloque = NULL;

    if ((cantidad > 0U) && (cantidad <= SIZE_MAX / sizeof(int)))
    {
        bloque = calloc(cantidad, sizeof(int));
    }

    return bloque;
}

void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque != NULL)
    {
        free(*puntero_bloque);
        *puntero_bloque = NULL;
    }
}

int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    int *bloque_redimensionado = NULL;

    if (nueva_cantidad == 0U)
    {
        free(bloque);
    }
    else if (nueva_cantidad <= SIZE_MAX / sizeof(int))
    {
        bloque_redimensionado = realloc(bloque, nueva_cantidad * sizeof(int));
    }

    return bloque_redimensionado;
}

int *fusionar_bloques_enteros(const int *primero, size_t cantidad_primero,
                              const int *segundo, size_t cantidad_segundo)
{
    int *fusion = NULL;
    size_t cantidad_total = 0U;
    size_t indice = 0U;
    bool parametros_validos = true;

    if (((primero == NULL) && (cantidad_primero > 0U)) ||
        ((segundo == NULL) && (cantidad_segundo > 0U)))
    {
        parametros_validos = false;
    }

    if (cantidad_primero > SIZE_MAX - cantidad_segundo)
    {
        parametros_validos = false;
    }

    if (parametros_validos)
    {
        cantidad_total = cantidad_primero + cantidad_segundo;
        if (cantidad_total > 0U)
        {
            fusion = malloc(cantidad_total * sizeof(int));
        }
    }

    if (fusion != NULL)
    {
        for (indice = 0U; indice < cantidad_primero; indice++)
        {
            fusion[indice] = primero[indice];
        }

        for (indice = 0U; indice < cantidad_segundo; indice++)
        {
            fusion[cantidad_primero + indice] = segundo[indice];
        }
    }

    return fusion;
}

bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor)
{
    bool agregado = false;
    int *bloque_redimensionado = NULL;

    if ((puntero_bloque != NULL) && (cantidad != NULL) &&
        (*cantidad < SIZE_MAX / sizeof(int)))
    {
        bloque_redimensionado = realloc(*puntero_bloque, (*cantidad + 1U) * sizeof(int));
        if (bloque_redimensionado != NULL)
        {
            bloque_redimensionado[*cantidad] = valor;
            *puntero_bloque = bloque_redimensionado;
            *cantidad += 1U;
            agregado = true;
        }
    }

    return agregado;
}
