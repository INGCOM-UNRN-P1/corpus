/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char **sin
 * structs).
 */

#include "registro_csv.h"
#include <stdlib.h>
#include <string.h>

char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL)
    {
        return NULL;
    }

    size_t cant = 1;
    for (const char *p = linea; *p != '\0'; p++)
    {
        if (*p == delimitador)
        {
            cant++;
        }
    }

    char **tokens = malloc(cant * sizeof(char *));
    if (tokens == NULL)
    {
        return NULL;
    }
    size_t idx = 0;
    const char *inicio = linea;
    const char *p = linea;

    while (1)
    {
        if (*p == delimitador || *p == '\0')
        {
            size_t largo_token = (size_t)(p - inicio);

            tokens[idx] = malloc((largo_token + 1) * sizeof(char));
            if (tokens[idx] == NULL)
            {
                for (size_t k = 0; k < idx; k++)
                {
                    free(tokens[k]);
                }
                free(tokens);
                return NULL;
            }

            for (size_t k = 0; k < largo_token; k++)
            {
                tokens[idx][k] = inicio[k];
            }
            tokens[idx][largo_token] = '\0';

                idx++;
            if (*p == '\0')
            {
                break;
            }
            inicio = p + 1;
        }
        p++;
    }
    *cantidad_tokens = cant;
    return tokens;
}

void liberar_arreglo_cadenas(char ***arreglo, size_t cantidad) {
    if (arreglo == NULL || *arreglo == NULL) {
        return;
    }
    for (size_t i = 0; i < cantidad; i++) {
        free((*arreglo)[i]);
    }
    free(*arreglo);
    *arreglo = NULL;
}
