/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


static char *duplicar_cadena(const char *str)
{
    if (str == NULL) {
        return NULL;
    }
    size_t len = strlen(str);
    char *copia = (char *)malloc(len + 1);
    if (copia == NULL) {
        return NULL;
    }
    strcpy(copia, str);
    return copia;
}

char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL) {
        return NULL;
    }

    *cantidad_tokens = 0;

    char *linea_copia = duplicar_cadena(linea);
    if (linea_copia == NULL) {
        return NULL;
    }

    size_t len = strlen(linea_copia);
    if (len > 0 && (linea_copia[len - 1] == '\n' || linea_copia[len - 1] == '\r')) {
        linea_copia[len - 1] = '\0';
    }
    len = strlen(linea_copia);
    if (len > 0 && (linea_copia[len - 1] == '\r')) {
        linea_copia[len - 1] = '\0';
    }

    size_t contador = 1;
    for (size_t i = 0; linea_copia[i] != '\0'; i++) {
        if (linea_copia[i] == delimitador) {
            contador++;
        }
    }

    char **tokens = (char **)malloc(contador * sizeof(char *));
    if (tokens == NULL) {
        free(linea_copia);
        return NULL;
    }

    char str_delim[2] = {delimitador, '\0'};
    char *ptr = linea_copia;
    size_t idx = 0;

    const char *inicio = linea_copia;
    for (size_t i = 0; ; i++) {
        if (linea_copia[i] == delimitador || linea_copia[i] == '\0') {
            size_t token_len = &linea_copia[i] - inicio;
            char *token_str = (char *)malloc(token_len + 1);
            if (token_str == NULL) {
                liberar_arreglo_cadenas(&tokens, idx);
                free(linea_copia);
                return NULL;
            }
            strncpy(token_str, inicio, token_len);
            token_str[token_len] = '\0';
            tokens[idx++] = token_str;

            if (linea_copia[i] == '\0') {
                break;
            }
            inicio = &linea_copia[i + 1];
        }
    }

    free(linea_copia);
    *cantidad_tokens = idx;
    return tokens;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL) {
        return;
    }

    char **arreglo = *puntero_arreglo;
    for (size_t i = 0; i < cantidad; i++) {
        if (arreglo[i] != NULL) {
            free(arreglo[i]);
        }
    }

    free(arreglo);
    *puntero_arreglo = NULL;
}