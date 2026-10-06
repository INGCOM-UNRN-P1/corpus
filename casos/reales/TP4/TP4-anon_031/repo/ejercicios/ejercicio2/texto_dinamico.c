/**
 * @file texto_dinamico.c
 * @brief Funciones de limpieza y repetición de texto dinámico.
 */

#include <ctype.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    char *recortada = NULL;
    size_t longitud = 0U;
    size_t inicio = 0U;
    size_t fin = 0U;
    size_t longitud_recortada = 0U;
    size_t indice = 0U;

    if (origen != NULL)
    {
        longitud = strlen(origen);
        inicio = 0U;
        while ((inicio < longitud) && isspace((unsigned char)origen[inicio]))
        {
            inicio++;
        }

        fin = longitud;
        while ((fin > inicio) && isspace((unsigned char)origen[fin - 1U]))
        {
            fin--;
        }

        longitud_recortada = fin - inicio;
        if (longitud_recortada > 0U)
        {
            recortada = malloc((longitud_recortada + 1U) * sizeof(char));
        }
    }

    if (recortada != NULL)
    {
        for (indice = 0U; indice < longitud_recortada; indice++)
        {
            recortada[indice] = origen[inicio + indice];
        }
        recortada[longitud_recortada] = '\0';
    }

    return recortada;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    char *repetida = NULL;
    size_t longitud = 0U;
    size_t longitud_total = 0U;
    size_t repeticion = 0U;
    size_t indice = 0U;

    if (origen != NULL)
    {
        longitud = strlen(origen);
        if ((veces == 0U) || (longitud == 0U))
        {
            repetida = malloc(sizeof(char));
            if (repetida != NULL)
            {
                repetida[0] = '\0';
            }
        }
        else if (longitud <= (SIZE_MAX - 1U) / veces)
        {
            longitud_total = longitud * veces;
            repetida = malloc((longitud_total + 1U) * sizeof(char));
        }
    }

    if ((repetida != NULL) && (longitud_total > 0U))
    {
        for (repeticion = 0U; repeticion < veces; repeticion++)
        {
            for (indice = 0U; indice < longitud; indice++)
            {
                repetida[(repeticion * longitud) + indice] = origen[indice];
            }
        }
        repetida[longitud_total] = '\0';
    }

    return repetida;
}

char *recortar_espacios_dinamico(const char *origen)
{
    return cadena_recortar_espacios(origen);
}

char *normalizar_mayusculas_dinamico(const char *origen)
{
    char *normalizada = NULL;
    size_t longitud = 0U;
    size_t indice = 0U;

    if (origen != NULL)
    {
        longitud = strlen(origen);
        normalizada = malloc((longitud + 1U) * sizeof(char));
    }

    if (normalizada != NULL)
    {
        for (indice = 0U; indice < longitud; indice++)
        {
            normalizada[indice] = (char)toupper((unsigned char)origen[indice]);
        }
        normalizada[longitud] = '\0';
    }

    return normalizada;
}
