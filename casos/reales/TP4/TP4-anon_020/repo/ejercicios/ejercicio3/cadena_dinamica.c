/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include <stdlib.h>
#include <string.h>
#include "cadena_dinamica.h"

char *clonar_cadena(const char *origen)
{
    size_t longitud = 0U;
    char *copia = NULL;
    size_t i = 0U;

    if (origen == NULL)
    {
        return NULL;
    }

    longitud = strlen(origen);
    copia = malloc(longitud + 1U);
    if (copia == NULL)
    {
        return NULL;
    }

    for (i = 0U; i < longitud; ++i)
    {
        copia[i] = origen[i];
    }
    copia[longitud] = '\0';

    return copia;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    size_t longitud_primera = 0U;
    size_t longitud_segunda = 0U;
    size_t longitud_total = 0U;
    char *resultado = NULL;
    size_t i = 0U;
    size_t j = 0U;

    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    longitud_primera = strlen(primera);
    longitud_segunda = strlen(segunda);
    longitud_total = longitud_primera + longitud_segunda;

    resultado = malloc(longitud_total + 1U);
    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0U; i < longitud_primera; ++i)
    {
        resultado[i] = primera[i];
    }

    j = 0U;
    for (i = longitud_primera; i < longitud_total; ++i)
    {
        resultado[i] = segunda[j];
        ++j;
    }

    resultado[longitud_total] = '\0';

    return resultado;
}