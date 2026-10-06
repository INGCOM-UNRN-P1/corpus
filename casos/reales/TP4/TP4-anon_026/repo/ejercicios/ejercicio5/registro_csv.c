/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include <stdlib.h>
#include "registro_csv.h"
 
/**
 * @brief Duplica en el heap un tramo de @p largo caracteres, agregando '\0'.
 * @param inicio Primer carácter del tramo.
 * @param largo Cantidad de caracteres a copiar.
 * @return Copia en heap terminada en '\0', o NULL si falla malloc.
 */
static char *duplicar_tramo(const char *inicio, size_t largo)
{
    char *copia = malloc(largo + 1);
    if (copia == NULL) 
    {
        return NULL;
    }
    for (size_t i = 0; i < largo; ++i) 
    {
        copia[i] = inicio[i];
    }
    copia[largo] = '\0';
    return copia;
}
 
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
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

    size_t cantidad = 1;
    for (size_t i = 0; linea[i] != '\0'; ++i) 
    {
        if (linea[i] == delimitador) 
        {
            ++cantidad;
        }
    }
 
    char **tokens = calloc(cantidad, sizeof(char *));
    if (tokens == NULL) 
    {
        return NULL;
    }
 
    size_t inicio = 0;
    for (size_t token = 0; token < cantidad; ++token) 
    {
        size_t fin = inicio;
        while (linea[fin] != '\0' && linea[fin] != delimitador) 
        {
            ++fin;
        }
        tokens[token] = duplicar_tramo(linea + inicio, fin - inicio);
        if (tokens[token] == NULL) 
        {
            liberar_arreglo_cadenas(&tokens, cantidad);
            return NULL;
        }
        inicio = fin + 1;
    }
 
    *cantidad_tokens = cantidad;
    return tokens;
}
 
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL) 
    {
        return;
    }
    for (size_t i = 0; i < cantidad; ++i) 
    {
        free((*puntero_arreglo)[i]);
    }
    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}