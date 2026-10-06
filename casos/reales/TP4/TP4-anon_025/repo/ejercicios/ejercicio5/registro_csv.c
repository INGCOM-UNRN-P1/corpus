/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"
#include <stdlib.h>
#include <string.h>


static size_t medir_token(const char *inicio, char delimitador)
{
    size_t len = 0;
    while (inicio[len] != '\0' && inicio[len] != delimitador)
    {
        len++;
    }
    return len;
}

char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL)
    {
        return NULL;
    }
    size_t tokens = 1;
    for (size_t i = 0; linea[i] != '\0'; i++)
    {
        if (linea[i] == delimitador)
        {
            tokens++;
        }
    }

    char **arreglo = (char **)malloc(tokens * sizeof(char *));
    if (arreglo == NULL)
    {
        return NULL;
    }

    size_t token_actual = 0;
    const char *cursor = linea;
    while (token_actual < tokens)
    {
        size_t len = medir_token(cursor, delimitador);

        arreglo[token_actual] = (char*)malloc((len + 1) * sizeof(char));
        if (arreglo[token_actual] == NULL)
        {
            for (size_t k = 0; k < token_actual; k++)
            {
                free(arreglo[k]);
            }
            free(arreglo);
            return NULL;
        }

        for (size_t i = 0; i < len; i++)
        {
            arreglo[token_actual][i] = cursor[i];
        }
        arreglo[token_actual][len] = '\0';
        cursor += len;
        if (*cursor == delimitador)
        {
            cursor++;
        }
        token_actual++;
    }
    *cantidad_tokens = tokens;
    return arreglo;
}

void liberar_arreglo_cadena(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo != NULL && *puntero_arreglo != NULL)
    {
        for (size_t i = 0; i < cantidad; i++)
        {
            if ((*puntero_arreglo)[i] != NULL)
            {
                free((*puntero_arreglo)[i]);
            }
        }
        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}