/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include <string.h>
#include "vector_enteros.h"

static bool es_par(int valor);
static bool es_positivo(int valor);
static int *filtrar_con_criterio(const int *origen, size_t cantidad_origen,
                                 bool (*criterio)(int),
                                 size_t *cantidad_resultado);

int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    if (origen == NULL || cantidad == 0)
    {
        return NULL;
    }
    int *clon = (int *)malloc(cantidad * sizeof(*clon));
    if (clon == NULL)
    {
        return NULL;
    }
    memcpy(clon, origen, cantidad * sizeof(*clon));
    return clon;
}

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares)
{
    return filtrar_con_criterio(origen, cantidad_origen, es_par,
                                cantidad_pares);
}

int *clonar_bloque(const int *origen, size_t n)
{
    return clonar_arreglo_enteros(origen, n);
}

int *filtrar_bloque_positivos(const int *origen, size_t n,
                              size_t *cantidad_positivos)
{
    return filtrar_con_criterio(origen, n, es_positivo, cantidad_positivos);
}

/**
 * @brief Indica si un valor es par.
 * @param valor valor a evaluar.
 * @returns true si valor es par.
 */
static bool es_par(int valor)
{
    return valor % 2 == 0;
}

/**
 * @brief Indica si un valor es mayor a cero.
 * @param valor valor a evaluar.
 * @returns true si valor > 0.
 */
static bool es_positivo(int valor)
{
    return valor > 0;
}

/**
 * @brief Copia en un bloque exacto los elementos que cumplen el criterio.
 * @param origen arreglo a filtrar.
 * @param cantidad_origen cantidad de elementos de origen.
 * @param criterio función que decide si un elemento se copia.
 * @param cantidad_resultado salida: cantidad de elementos copiados.
 * @returns el bloque nuevo, o NULL si ninguno cumple, algún puntero es NULL
 *          o falla la memoria.
 */
static int *filtrar_con_criterio(const int *origen, size_t cantidad_origen,
                                 bool (*criterio)(int),
                                 size_t *cantidad_resultado)
{
    if (cantidad_resultado == NULL)
    {
        return NULL;
    }
    *cantidad_resultado = 0;
    if (origen == NULL)
    {
        return NULL;
    }

    size_t cumplen = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (criterio(origen[i]) == true)
        {
            cumplen++;
        }
    }
    if (cumplen == 0)
    {
        return NULL;
    }

    int *filtrado = (int *)malloc(cumplen * sizeof(*filtrado));
    if (filtrado == NULL)
    {
        return NULL;
    }
    size_t destino = 0;
    for (size_t i = 0; i < cantidad_origen; i++)
    {
        if (criterio(origen[i]) == true)
        {
            filtrado[destino] = origen[i];
            destino++;
        }
    }
    *cantidad_resultado = cumplen;
    return filtrado;
}
