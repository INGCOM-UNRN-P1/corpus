/**
 * @file cadenas.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdint.h>
#include <stdlib.h>
#include "cadenas.h"

static size_t cadena_longitud_acotada(const char *cadena, size_t capacidad_max)
{
    size_t longitud = 0U;

    if (cadena != NULL)
    {
        while ((longitud < capacidad_max) && (cadena[longitud] != '\0'))
        {
            longitud++;
        }
    }

    return longitud;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    char *duplicada = NULL;
    size_t longitud = 0U;
    size_t indice = 0U;

    if ((origen != NULL) && (capacidad_max > 0U))
    {
        longitud = cadena_longitud_acotada(origen, capacidad_max);
        if (longitud < SIZE_MAX)
        {
            duplicada = malloc((longitud + 1U) * sizeof(char));
        }
    }

    if (duplicada != NULL)
    {
        for (indice = 0U; indice < longitud; indice++)
        {
            duplicada[indice] = origen[indice];
        }
        duplicada[longitud] = '\0';
    }

    return duplicada;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    char *unida = NULL;
    size_t longitud_primera = 0U;
    size_t longitud_segunda = 0U;
    size_t longitud_total = 0U;
    size_t indice = 0U;

    if ((primera != NULL) && (segunda != NULL) &&
        (cap_primera > 0U) && (cap_segunda > 0U))
    {
        longitud_primera = cadena_longitud_acotada(primera, cap_primera);
        longitud_segunda = cadena_longitud_acotada(segunda, cap_segunda);

        if (longitud_primera <= SIZE_MAX - longitud_segunda - 1U)
        {
            longitud_total = longitud_primera + longitud_segunda;
            unida = malloc((longitud_total + 1U) * sizeof(char));
        }
    }

    if (unida != NULL)
    {
        for (indice = 0U; indice < longitud_primera; indice++)
        {
            unida[indice] = primera[indice];
        }
        for (indice = 0U; indice < longitud_segunda; indice++)
        {
            unida[longitud_primera + indice] = segunda[indice];
        }
        unida[longitud_total] = '\0';
    }

    return unida;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    char *subcadena = NULL;
    size_t longitud_origen = 0U;
    size_t longitud_extraida = 0U;
    size_t indice = 0U;

    if ((origen != NULL) && (capacidad_max > 0U))
    {
        longitud_origen = cadena_longitud_acotada(origen, capacidad_max);

        if (inicio < longitud_origen)
        {
            longitud_extraida = longitud_origen - inicio;
            if (cantidad < longitud_extraida)
            {
                longitud_extraida = cantidad;
            }
        }

        subcadena = malloc((longitud_extraida + 1U) * sizeof(char));
    }

    if (subcadena != NULL)
    {
        for (indice = 0U; indice < longitud_extraida; indice++)
        {
            subcadena[indice] = origen[inicio + indice];
        }
        subcadena[longitud_extraida] = '\0';
    }

    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    char *invertida = NULL;
    size_t longitud = 0U;
    size_t indice = 0U;

    if ((origen != NULL) && (capacidad_max > 0U))
    {
        longitud = cadena_longitud_acotada(origen, capacidad_max);
        invertida = malloc((longitud + 1U) * sizeof(char));
    }

    if (invertida != NULL)
    {
        for (indice = 0U; indice < longitud; indice++)
        {
            invertida[indice] = origen[longitud - 1U - indice];
        }
        invertida[longitud] = '\0';
    }

    return invertida;
}
