/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include <stdlib.h>
#include <string.h>
#include "cadenas.h"
#include "cadena_dinamica.h"

char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    return cadena_duplicar_segura(origen, strlen(origen) + 1);
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }
    return cadena_unir_dinamica(primera, strlen(primera) + 1,
                                segunda, strlen(segunda) + 1);
}

char *invertir_cadena_dinamico(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }
    return cadena_invertir_dinamica(origen, strlen(origen) + 1);
}

char **partir_por_delimitador(const char *cadena, char delimitador,
                              size_t *cantidad)
{
    if (cantidad == NULL)
    {
        return NULL;
    }
    *cantidad = 0;
    if (cadena == NULL)
    {
        return NULL;
    }

    size_t longitud = strlen(cadena);
    size_t total_tokens = 1;
    for (size_t i = 0; i < longitud; i++)
    {
        if (cadena[i] == delimitador)
        {
            total_tokens++;
        }
    }

    
    char **tokens = (char **)calloc(total_tokens, sizeof(*tokens));
    if (tokens == NULL)
    {
        return NULL;
    }

    bool sin_error = true;
    size_t inicio = 0;
    size_t actual = 0;
    for (size_t i = 0; i <= longitud && sin_error == true; i++)
    {
        if (cadena[i] == delimitador || cadena[i] == '\0')
        {
            tokens[actual] = cadena_subcadena_dinamica(cadena, longitud + 1,
                                                       inicio, i - inicio);
            sin_error = tokens[actual] != NULL;
            actual++;
            inicio = i + 1;
        }
    }

    if (sin_error == false)
    {
        liberar_tokens(&tokens, total_tokens);
        return NULL;
    }
    *cantidad = total_tokens;
    return tokens;
}

void liberar_tokens(char ***tokens, size_t cantidad)
{
    if (tokens == NULL || *tokens == NULL)
    {
        return;
    }
    for (size_t i = 0; i < cantidad; i++)
    {
        free((*tokens)[i]);
        (*tokens)[i] = NULL;
    }
    free(*tokens);
    *tokens = NULL;
}
