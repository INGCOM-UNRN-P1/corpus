/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include <stdlib.h>
#include "cadena_dinamica.h"



char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t longitud = 0;

    while (origen[longitud] != '\0')
    {
        longitud++;
    }

    char *copia = malloc((longitud + 1) * sizeof(char));

    if (copia == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++)
    {
        copia[i] = origen[i];
    }

    copia[longitud] = '\0';

    return copia;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if(primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    size_t longitud_primera = 0;

    while (primera[longitud_primera] != '\0')
    {
        longitud_primera++;
    }

    size_t longitud_segunda = 0;

    while (segunda[longitud_segunda] != '\0')
    {
        longitud_segunda++;
    }

    size_t longitud_total = longitud_primera + longitud_segunda;

    char *resultado = malloc((longitud_total + 1) * sizeof(char));
    if(resultado == NULL)
    {
        return NULL;
    }

    cadena_copiar(resultado, longitud_total + 1, primera);
    cadena_concatenar(resultado, longitud_total + 1, segunda);

    return resultado;
}