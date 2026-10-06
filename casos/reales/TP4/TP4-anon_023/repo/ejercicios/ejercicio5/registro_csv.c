/**
 * @file registro_csv.c
 * @brief Implementacion de tokenizacion dinamica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"
#include <stdint.h>
#include <stdlib.h>

static size_t contar_delimitadores(const char *linea, char delimitador)
{
    if (linea == NULL)
    {
        return 0;
    }

    size_t count = 0;
    const char *p = linea;
    while (*p != '\0')
    {
        if (*p == delimitador)
        {
            count++;
        }
        p++;
    }
    return count;
}

char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    if (cantidad_tokens != NULL)
    {
        *cantidad_tokens = 0;
    }

    if (linea == NULL || cantidad_tokens == NULL)
    {
        return NULL;
    }

    size_t tokens_esperados = contar_delimitadores(linea, delimitador) + 1;

    char **arreglo = malloc(tokens_esperados * sizeof(*arreglo));
    if (arreglo == NULL)
    {
        return NULL;
    }

    const char *inicio = linea;
    const char *actual = linea;
    size_t idx = 0;

    while (idx < tokens_esperados)
    {
        if (*actual == delimitador || *actual == '\0')
        {
            size_t longitud_token = (size_t)(actual - inicio);

            char *token = malloc((longitud_token + 1) * sizeof(*token));
            if (token == NULL)
            {
                
                for (size_t i = 0; i < idx; i++)
                {
                    free(*(arreglo + i));
                }
                free(arreglo);
                return NULL;
            }

            for (size_t i = 0; i < longitud_token; i++)
            {
                *(token + i) = *(inicio + i);
            }
            *(token + longitud_token) = '\0';

            *(arreglo + idx) = token;
            idx++;

            if (*actual == '\0')
            {
                break;
            }

            inicio = actual + 1;
        }
        actual++;
    }

    *cantidad_tokens = idx;
    return arreglo;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }

    char **arreglo = *puntero_arreglo;
    for (size_t i = 0; i < cantidad; i++)
    {
        if (*(arreglo + i) != NULL)
        {
            free(*(arreglo + i));
            *(arreglo + i) = NULL;
        }
    }

    free(arreglo);
    *puntero_arreglo = NULL;
}