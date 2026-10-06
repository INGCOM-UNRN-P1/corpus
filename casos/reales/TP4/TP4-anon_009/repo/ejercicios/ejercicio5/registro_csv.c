/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"



char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL)
    {
        return NULL;
    }
    size_t num_tokens = 1;
    const char *ptr = linea;
    while (*ptr != '\0')
    {
        if (*ptr == delimitador)
        {
            num_tokens++;
        }
        ptr++;
    }
    char **arreglo = (char **)malloc(num_tokens * sizeof(char *));
    if (arreglo == NULL)
    {
        return NULL;
    }
    const char *inicio = linea;
    const char *actual = linea;
    char **ptr_arreglo = arreglo;

    while (1)
    {
        if (*actual == delimitador || *actual == '\0')
        {
            size_t longitud = (size_t)(actual - inicio);
            char *token = (char *)malloc(longitud + 1);
            if (token == NULL)
            {
                size_t creados = (size_t)(ptr_arreglo - arreglo);
                liberar_arreglo_cadenas(&arreglo, creados);
                return NULL;
            }
            char *dst = token;
            const char *src = inicio;
            while (src < actual)
            {
                *dst = *src;
                dst++;
                src++;
            }
            *dst = '\0';
            *ptr_arreglo = token;
            ptr_arreglo++;
            inicio = actual + 1;
        }
        if (*actual == '\0')
        {
            break;
        }
        actual++;
    }
    *cantidad_tokens = num_tokens;
    return arreglo;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }
    char **arreglo = *puntero_arreglo;
    char **ptr_actual = arreglo;
    char **fin = arreglo + cantidad;
    while (ptr_actual < fin)
    {
        if (*ptr_actual != NULL)
        {
            free(*ptr_actual);
        }
        ptr_actual++;
    }
    free(arreglo);
    *puntero_arreglo = NULL;
}
