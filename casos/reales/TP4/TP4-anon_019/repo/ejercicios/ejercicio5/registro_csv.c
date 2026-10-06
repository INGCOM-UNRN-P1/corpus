#include <stdlib.h>
#include "registro_csv.h"

char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    if (linea == NULL || cantidad_tokens == NULL)
    {
        if (cantidad_tokens != NULL) *cantidad_tokens = 0;
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
        *cantidad_tokens = 0;
        return NULL;
    }

    size_t inicio = 0;
    size_t idx = 0;
    
    for (size_t i = 0; ; i++)
    {
        if (linea[i] == delimitador || linea[i] == '\0')
        {
            size_t len = i - inicio;
            arreglo[idx] = (char *)malloc((len + 1) * sizeof(char));
            
            if (arreglo[idx] == NULL)
            {
                for (size_t k = 0; k < idx; k++)
                {
                    free(arreglo[k]);
                }
                free(arreglo);
                *cantidad_tokens = 0;
                return NULL;
            }

            for (size_t j = 0; j < len; j++)
            {
                arreglo[idx][j] = linea[inicio + j];
            }
            arreglo[idx][len] = '\0';
            
            idx++;
            inicio = i + 1;

            if (linea[i] == '\0')
            {
                break;
            }
        }
    }

    *cantidad_tokens = tokens;
    return arreglo;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
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