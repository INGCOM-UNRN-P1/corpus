/**
 * @file cadenas.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include "cadenas.h"

static size_t longitud_segura(const char *origen, size_t capacidad_max)
{
    size_t longitud;

    if (origen == NULL || capacidad_max == 0)
    {
        return 0;
    }

    longitud = 0;
    while (longitud < capacidad_max && origen[longitud] != '\0')
    {
        ++longitud;
    }

    return longitud;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    size_t longitud;
    char *copia;
    size_t i;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud = longitud_segura(origen, capacidad_max);
    copia = malloc(longitud + 1U);
    if (copia == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud; ++i)
    {
        copia[i] = origen[i];
    }
    copia[longitud] = '\0';

    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    size_t longitud_primera;
    size_t longitud_segunda;
    size_t total;
    char *resultado;
    size_t i;
    size_t j;

    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    if (cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

    longitud_primera = longitud_segura(primera, cap_primera);
    longitud_segunda = longitud_segura(segunda, cap_segunda);
    total = longitud_primera + longitud_segunda + 1U;

    resultado = malloc(total);
    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud_primera; ++i)
    {
        resultado[i] = primera[i];
    }

    j = 0;
    for (i = longitud_primera; i < total - 1U; ++i)
    {
        resultado[i] = segunda[j];
        ++j;
    }

    resultado[total - 1U] = '\0';
    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL || *puntero_cadena == NULL)
    {
        return;
    }

    free(*puntero_cadena);
    *puntero_cadena = NULL;
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                               size_t inicio, size_t cantidad)
{
    size_t longitud;
    size_t limite;
    char *subcadena;
    size_t i;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud = longitud_segura(origen, capacidad_max);
    if (inicio >= longitud)
    {
        subcadena = malloc(1U);
        if (subcadena == NULL)
        {
            return NULL;
        }
        subcadena[0] = '\0';
        return subcadena;
    }

    limite = longitud - inicio;
    if (cantidad < limite)
    {
        limite = cantidad;
    }

    subcadena = malloc(limite + 1U);
    if (subcadena == NULL)
    {
        return NULL;
    }

    for (i = 0; i < limite; ++i)
    {
        subcadena[i] = origen[inicio + i];
    }
    subcadena[limite] = '\0';

    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    size_t longitud;
    char *invertida;
    size_t i;

    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    longitud = longitud_segura(origen, capacidad_max);
    invertida = malloc(longitud + 1U);
    if (invertida == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud; ++i)
    {
        invertida[i] = origen[longitud - 1U - i];
    }
    invertida[longitud] = '\0';

    return invertida;
}
