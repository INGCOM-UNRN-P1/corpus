/**
 * @file cadena_dinamica.c
 * @brief Operaciones con cadenas reservadas dinámicamente.
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "cadena_dinamica.h"

static char *copiar_segmento(const char *origen, size_t inicio, size_t longitud)
{
    char *copia = NULL;
    size_t indice = 0U;

    if ((origen != NULL) && (longitud < SIZE_MAX))
    {
        copia = malloc((longitud + 1U) * sizeof(char));
    }

    if (copia != NULL)
    {
        for (indice = 0U; indice < longitud; indice++)
        {
            copia[indice] = origen[inicio + indice];
        }
        copia[longitud] = '\0';
    }

    return copia;
}

char *clonar_cadena(const char *origen)
{
    char *clon = NULL;

    if (origen != NULL)
    {
        clon = copiar_segmento(origen, 0U, strlen(origen));
    }

    return clon;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    char *unida = NULL;
    size_t longitud_primera = 0U;
    size_t longitud_segunda = 0U;
    size_t longitud_total = 0U;
    size_t indice = 0U;

    if ((primera != NULL) && (segunda != NULL))
    {
        longitud_primera = strlen(primera);
        longitud_segunda = strlen(segunda);

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

char *invertir_cadena_dinamico(const char *origen)
{
    char *invertida = NULL;
    size_t longitud = 0U;
    size_t indice = 0U;

    if (origen != NULL)
    {
        longitud = strlen(origen);
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

void liberar_partes_cadena(char ***puntero_partes, size_t cantidad)
{
    size_t indice = 0U;

    if ((puntero_partes != NULL) && (*puntero_partes != NULL))
    {
        for (indice = 0U; indice < cantidad; indice++)
        {
            free((*puntero_partes)[indice]);
            (*puntero_partes)[indice] = NULL;
        }
        free(*puntero_partes);
        *puntero_partes = NULL;
    }
}

char **partir_por_delimitador(const char *origen, char delimitador,
                             size_t *cantidad_tokens)
{
    char **tokens = NULL;
    size_t cantidad = 0U;
    size_t indice = 0U;
    size_t inicio = 0U;
    size_t indice_token = 0U;
    size_t longitud = 0U;
    bool asignacion_correcta = true;

    if (cantidad_tokens != NULL)
    {
        *cantidad_tokens = 0U;
    }

    if ((origen != NULL) && (cantidad_tokens != NULL))
    {
        longitud = strlen(origen);
        cantidad = 1U;
        for (indice = 0U; indice < longitud; indice++)
        {
            if (origen[indice] == delimitador)
            {
                cantidad++;
            }
        }

        if (cantidad <= SIZE_MAX / sizeof(char *))
        {
            tokens = calloc(cantidad, sizeof(char *));
        }
    }

    if (tokens != NULL)
    {
        inicio = 0U;
        indice_token = 0U;
        for (indice = 0U; indice <= longitud; indice++)
        {
            if ((indice == longitud) || (origen[indice] == delimitador))
            {
                if (asignacion_correcta)
                {
                    tokens[indice_token] = copiar_segmento(origen, inicio, indice - inicio);
                    if (tokens[indice_token] == NULL)
                    {
                        asignacion_correcta = false;
                    }
                    else
                    {
                        indice_token++;
                    }
                }
                inicio = indice + 1U;
            }
        }

        if (!asignacion_correcta)
        {
            liberar_partes_cadena(&tokens, indice_token);
        }
        else
        {
            *cantidad_tokens = cantidad;
        }
    }

    return tokens;
}
