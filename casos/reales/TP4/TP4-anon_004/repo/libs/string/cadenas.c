/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include "cadenas.h"
#include <stdlib.h>

static size_t medir_longitud_acotada(const char *cadena, size_t capacidad_max)
{
    size_t longitud = 0;

    if (cadena == NULL || capacidad_max == 0)
    {
        return 0;
    }

    while (longitud < capacidad_max && cadena[longitud] != '\0')
    {
        longitud++;
    }

    return longitud;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    size_t longitud = 0;
    size_t i = 0;
    char *copia = NULL;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud = medir_longitud_acotada(origen, capacidad_max);

    copia = malloc((longitud + 1) * sizeof(char));

    if (copia == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud; i++)
    {
        copia[i] = origen[i];
    }

    copia[longitud] = '\0';

    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    size_t len_primera = 0;
    size_t len_segunda = 0;
    size_t i = 0;
    size_t j = 0;
    char *resultado = NULL;

    if (primera == NULL || segunda == NULL ||
        cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

    len_primera = medir_longitud_acotada(primera, cap_primera);
    len_segunda = medir_longitud_acotada(segunda, cap_segunda);

    resultado = malloc(
        (len_primera + len_segunda + 1) * sizeof(char)
    );

    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < len_primera; i++)
    {
        resultado[i] = primera[i];
    }

    for (j = 0; j < len_segunda; j++)
    {
        resultado[len_primera + j] = segunda[j];
    }

    resultado[len_primera + len_segunda] = '\0';

    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    size_t longitud_origen = 0;
    size_t longitud_extraida = 0;
    size_t i = 0;
    char *subcadena = NULL;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud_origen = medir_longitud_acotada(origen, capacidad_max);

    if (inicio >= longitud_origen)
    {
        subcadena = malloc(sizeof(char));

        if (subcadena == NULL)
        {
            return NULL;
        }

        subcadena[0] = '\0';

        return subcadena;
    }

    longitud_extraida = longitud_origen - inicio;

    if (longitud_extraida > cantidad)
    {
        longitud_extraida = cantidad;
    }

    subcadena = malloc(
        (longitud_extraida + 1) * sizeof(char)
    );

    if (subcadena == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud_extraida; i++)
    {
        subcadena[i] = origen[inicio + i];
    }

    subcadena[longitud_extraida] = '\0';

    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    size_t longitud = 0;
    size_t i = 0;
    char *invertida = NULL;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud = medir_longitud_acotada(origen, capacidad_max);

    invertida = malloc(
        (longitud + 1) * sizeof(char)
    );

    if (invertida == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud; i++)
    {
        invertida[i] = origen[longitud - 1 - i];
    }

    invertida[longitud] = '\0';

    return invertida;
}