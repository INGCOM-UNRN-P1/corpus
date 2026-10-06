/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */
#include "registro_csv.h"
#include <stdlib.h>
#include <string.h>


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

    char **arreglo = malloc(tokens * sizeof(char *));
    
    if (arreglo == NULL) 
    {
        return NULL;
    }

    const char *inicio = linea;
    size_t idx = 0;

    for (size_t i = 0; ; i++) 
    {
        if (linea[i] == delimitador || linea[i] == '\0') 
        {
            size_t len = (size_t)(&linea[i] - inicio);
            arreglo[idx] = malloc((len + 1) * sizeof(char));
            
            if (arreglo[idx] == NULL) 
            {
                for (size_t j = 0; j < idx; j++) 
                {
                    free(arreglo[j]);
                }
                free(arreglo);
                return NULL;
            }

            memcpy(arreglo[idx], inicio, len);
            arreglo[idx][len] = '\0';
            idx++;
            inicio = &linea[i + 1];

            if (linea[i] == '\0') 
            {
                break;
            }
        }
    }
    *cantidad_tokens = tokens;
    return arreglo;
}





void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad) {
    
    if (puntero_arreglo == NULL || *puntero_arreglo == NULL) 
    {
        return;
    }

    for (size_t i = 0; i < cantidad; i++) 
    {
        free((*puntero_arreglo)[i]);
    }

    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}