/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"

/**
 * @brief Descripción de la función clonar_cadena.
 *
 * @param origen Descripción del parámetro origen.
 * @return Descripción del valor de retorno.
 */
char *clonar_cadena(const char *origen)
{

    if (origen == NULL)
    {
        return NULL;
    }

    const char *puntero = origen;
    while (*puntero != '\0')
    {
        puntero++;
    }

    size_t largo = puntero - origen;

    char *clon = (char *)calloc((largo + 1), sizeof(char));

    if (clon == NULL)
    {
        return NULL;
    }

    char *aux = clon;

    while (*origen != '\0')
    {
        *aux = *origen;
        aux++;
        origen++;
    }

    *aux = '\0';

    return clon;
}

/**
 * @brief Descripción de la función unir_cadenas_dinamicas.
 *
 * @param primera Descripción del parámetro primera.
 * @param segunda Descripción del parámetro segunda.
 * @return Descripción del valor de retorno.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    const char *puntero_primero = primera;
    while (*puntero_primero != '\0')
    {
        puntero_primero++;
    }
    size_t largo_primera = puntero_primero - primera;

    const char *puntero_segundo = segunda;
    while (*puntero_segundo != '\0')
    {
        puntero_segundo++;
    }
    size_t largo_segunda = puntero_segundo - segunda;

    size_t largo_max = ((largo_primera + largo_segunda) + 1);

    char *unidos = (char *)calloc((largo_max), sizeof(char));
    if (unidos == NULL)
    {
        return NULL;
    }
    char *aux = unidos;

    while (*primera != '\0')
    {
        *aux = *primera;
        aux++;
        primera++;
    }
    while (*segunda != '\0')
    {
        *aux = *segunda;
        aux++;
        segunda++;
    }
    *aux = '\0';

    return unidos;
}
