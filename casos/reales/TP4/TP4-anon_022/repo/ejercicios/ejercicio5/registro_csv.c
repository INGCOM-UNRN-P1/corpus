/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include <stdlib.h>
#include "registro_csv.h"
#include "cadenas.h"

char **dividir_linea_csv(const char *linea,
                         char delimitador,
                         size_t *cantidad_tokens)
{
    if (cantidad_tokens == NULL)
    {
        return NULL;
    }

    *cantidad_tokens = 0;

    if (linea == NULL)
    {
        return NULL;
    }

    *cantidad_tokens = 1;
    size_t longitud_linea = 0;

    while (linea[longitud_linea] != '\0')
    {
        if (linea[longitud_linea] == delimitador)
        {
            (*cantidad_tokens)++;
        }

        longitud_linea++;
    }

    char **tokens = malloc(*cantidad_tokens * sizeof *tokens);

    if (tokens == NULL)
    {
        *cantidad_tokens = 0;
        return NULL;
    }

    size_t i = 0;
    size_t inicio = 0;

    for (size_t creados = 0; creados < *cantidad_tokens; creados++)
    {
        while (linea[i] != delimitador && linea[i] != '\0')
        {
            i++;
        }

        tokens[creados] = cadena_subcadena_dinamica(
            linea,
            longitud_linea + 1,
            inicio,
            i - inicio
        );

        if (tokens[creados] == NULL)
        {
            liberar_arreglo_cadenas(&tokens, creados);
            *cantidad_tokens = 0;
            return NULL;
        }

        i++;
        inicio = i;
    }

    return tokens;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo,
                             size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }

    for (size_t i = 0; i < cantidad; i++)
    {
        cadena_liberar_segura(&(*puntero_arreglo)[i]);
    }

    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}