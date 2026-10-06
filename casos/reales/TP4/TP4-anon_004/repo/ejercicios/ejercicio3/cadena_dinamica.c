
/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <stdlib.h>

static size_t medir_longitud(const char *cadena)
{
    size_t longitud = 0;

    if (cadena == NULL)
    {
        return 0;
    }

    while (cadena[longitud] != '\0')
    {
        longitud++;
    }

    return longitud;
}

char *clonar_cadena(const char *origen)
{
    size_t longitud = 0;
    size_t i = 0;
    char *copia = NULL;

    if (origen == NULL)
    {
        return NULL;
    }

    longitud = medir_longitud(origen);

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

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    size_t longitud_primera = 0;
    size_t longitud_segunda = 0;
    size_t i = 0;
    size_t j = 0;
    char *resultado = NULL;

    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    longitud_primera = medir_longitud(primera);
    longitud_segunda = medir_longitud(segunda);

    resultado = malloc(
        (longitud_primera + longitud_segunda + 1) * sizeof(char)
    );

    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud_primera; i++)
    {
        resultado[i] = primera[i];
    }

    for (j = 0; j < longitud_segunda; j++)
    {
        resultado[longitud_primera + j] = segunda[j];
    }

    resultado[longitud_primera + longitud_segunda] = '\0';

    return resultado;
}
