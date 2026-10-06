/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include <stdlib.h>
#include <string.h>
#include "registro_csv.h"
 
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    char **tokens = NULL;
 
    if (linea != NULL && cantidad_tokens != NULL) {
        *cantidad_tokens = 0;
 
        size_t total = 1;
        for (size_t i = 0; linea[i] != '\0'; ++i) {
            if (linea[i] == delimitador) {
                total++;
            }
        }
 
        tokens = malloc(total * sizeof(char *));
        if (tokens != NULL) {
            size_t creados = 0;
            bool exito = true;
            const char *inicio = linea;
 
            while (exito && creados < total) {
                const char *fin = inicio;
                while (*fin != '\0' && *fin != delimitador) {
                    fin++;
                }
 
                size_t largo = (size_t)(fin - inicio);
                tokens[creados] = malloc(largo + 1);
                if (tokens[creados] == NULL) {
                    exito = false;
                } 
                else {
                    memcpy(tokens[creados], inicio, largo);
                    tokens[creados][largo] = '\0';
                    creados++;
                    inicio = fin + 1;
                }
            }
 
            if (exito) {
                *cantidad_tokens = total;
            } 
            else {
                liberar_arreglo_cadenas(&tokens, creados);
            }
        }
    }
    return tokens;
}
 
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo != NULL && *puntero_arreglo != NULL) {
        for (size_t i = 0; i < cantidad; ++i) {
            free((*puntero_arreglo)[i]);
        }
        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}