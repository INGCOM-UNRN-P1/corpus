/**
 * @file vector.c
 * @brief Implementación de la biblioteca libvector (sin estructuras).
 */

#include "vector.h"
#include <stdlib.h>

/**
 * @brief Descripción de la función crear_bloque_enteros.
 *
 * @param cantidad Descripción del parámetro cantidad.
 * @return Descripción del valor de retorno.
 */
int *crear_bloque_enteros(size_t cantidad)
{
    if (cantidad == 0)
    {
        return NULL;
    }

    int *bloque = (int *)calloc(cantidad, sizeof(int));

    if (bloque == NULL)
    {
        return NULL;
    }

    return bloque;
}

/**
 * @brief Descripción de la función liberar_bloque_enteros.
 *
 * @param puntero_bloque Descripción del parámetro puntero_bloque.
 */
void liberar_bloque_enteros(int **puntero_bloque)
{
    if (puntero_bloque == NULL || *puntero_bloque == NULL)
    {
        return;
    }

    free(*puntero_bloque);
    *puntero_bloque = NULL;
}

/**
 * @brief Descripción de la función redimensionar_bloque_enteros.
 *
 * @param bloque Descripción del parámetro bloque.
 * @param nueva_cantidad Descripción del parámetro nueva_cantidad.
 * @return Descripción del valor de retorno.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad)
{
    if (nueva_cantidad == 0)
    {
        free(bloque);

        return NULL;
    }

    int *aux = realloc(bloque, nueva_cantidad * sizeof(int));

    if (aux == NULL)
    {
        return NULL;
    }

    return bloque = aux;
}

/**
 * @brief Descripción de la función fusionar_bloques_enteros.
 *
 * @param primero Descripción del parámetro primero.
 * @param cant_primero Descripción del parámetro cant_primero.
 * @param segundo Descripción del parámetro segundo.
 * @param cant_segundo Descripción del parámetro cant_segundo.
 * @return Descripción del valor de retorno.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo)
{
    if (primero == NULL || segundo == NULL)
    {
        return NULL;
    }

    size_t cantidad_total = cant_primero + cant_segundo;

    int *fusion_bloques = crear_bloque_enteros(cantidad_total);
    if (fusion_bloques == NULL)
    {
        return NULL;
    }

    for (size_t indice = 0; indice < cant_primero; indice++)
    {
        // copio el primer bloque en el nuevo
        *(fusion_bloques + indice) = *(primero + indice);
    }

    for (size_t indice = 0; indice < cant_segundo; indice++)
    {
        *(fusion_bloques + cant_primero + indice) = *(segundo + indice);
    }

    return fusion_bloques;
}

/**
 * @brief Descripción de la función agregar_al_bloque_enteros.
 *
 * @param puntero_bloque Descripción del parámetro puntero_bloque.
 * @param cantidad Descripción del parámetro cantidad.
 * @param valor Descripción del parámetro valor.
 * @return Descripción del valor de retorno.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor)
{
    if (puntero_bloque == NULL || cantidad == NULL)
    {
        return false;
    }

    int *aux = (int *)realloc(*puntero_bloque, ((*cantidad) + 1) * sizeof(int));

    if (aux == NULL)
    {
        return false;
    }
    // asigno valor en la ultima posicion
    *(aux + *cantidad) = valor;
    // actualizo cantidad
    (*cantidad)++;
    *puntero_bloque = aux;

    return true;
}
