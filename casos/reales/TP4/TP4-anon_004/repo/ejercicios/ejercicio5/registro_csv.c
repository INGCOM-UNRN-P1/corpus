
/**
 * @file registro_csv.c
 * @brief Implementación de tokenización dinámica de cadenas en heap (char** sin structs).
 */

#include "registro_csv.h"
#include <stdlib.h>

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    size_t indice = 0;

    if (puntero_arreglo != NULL && *puntero_arreglo != NULL)
    {
        for (indice = 0; indice < cantidad; indice++)
        {
            free((*puntero_arreglo)[indice]);
            (*puntero_arreglo)[indice] = NULL;
        }

        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}

char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    size_t total = 1;
    size_t indice = 0;
    size_t inicio = 0;
    size_t token = 0;
    size_t posicion = 0;
    char **resultado = NULL;

    if (cantidad_tokens == NULL)
    {
        return NULL;
    }

    *cantidad_tokens = 0;

    if (linea == NULL || delimitador == '\0')
    {
        return NULL;
    }

    while (linea[indice] != '\0')
    {
        if (linea[indice] == delimitador)
        {
            total++;
        }

        indice++;
    }

    resultado = calloc(total, sizeof(char *));

    if (resultado == NULL)
    {
        return NULL;
    }

    indice = 0;

    while (token < total)
    {
        if (linea[indice] == delimitador || linea[indice] == '\0')
        {
            resultado[token] = malloc(
                (indice - inicio + 1) * sizeof(char)
            );

            if (resultado[token] == NULL)
            {
                liberar_arreglo_cadenas(&resultado, token);
                return NULL;
            }

            posicion = 0;

            while (inicio + posicion < indice)
            {
                resultado[token][posicion] =
                    linea[inicio + posicion];

                posicion++;
            }

            resultado[token][posicion] = '\0';

            token++;
            inicio = indice + 1;
        }

        indice++;
    }

    *cantidad_tokens = total;

    return resultado;
}
