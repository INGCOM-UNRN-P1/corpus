/**
 * @file cadena_dinamica.c
 * @brief Implementacion para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <stdint.h>
#include <stdlib.h>

static size_t medir_longitud(const char *cadena)
{
    if (cadena == NULL)
    {
        return 0;
    }

    size_t len = 0;
    while (*(cadena + len) != '\0')
    {
        len++;
    }
    return len;
}

char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t len = medir_longitud(origen);
    if (len > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *copia = malloc((len + 1) * sizeof(*copia));
    if (copia == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len; i++)
    {
        *(copia + i) = *(origen + i);
    }
    *(copia + len) = '\0';

    return copia;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    size_t len1 = medir_longitud(primera);
    size_t len2 = medir_longitud(segunda);

    if (len1 > SIZE_MAX - len2 - 1)
    {
        return NULL;
    }

    size_t total = len1 + len2;

    char *union_str = malloc((total + 1) * sizeof(*union_str));
    if (union_str == NULL)
    {
        return NULL;
    }

    char *dst = union_str;
    for (size_t i = 0; i < len1; i++)
    {
        *dst = *(primera + i);
        dst++;
    }

    for (size_t j = 0; j < len2; j++)
    {
        *dst = *(segunda + j);
        dst++;
    }
    *dst = '\0';

    return union_str;
}