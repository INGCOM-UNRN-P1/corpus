/**
 * @file registro_csv.c
 * @brief Tokenización CSV simple y listas dinámicas de cadenas.
 */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "registro_csv.h"

static char *duplicar_segmento(const char *origen, size_t inicio, size_t longitud)
{
    char *copia = NULL;
    size_t indice = 0U;

    if ((origen != NULL) && (longitud < SIZE_MAX))
    {
        copia = malloc((longitud + 1U) * sizeof(char));
    }

    if (copia != NULL)
    {
        for (indice = 0U; indice < longitud; indice++)
        {
            copia[indice] = origen[inicio + indice];
        }
        copia[longitud] = '\0';
    }

    return copia;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    size_t indice = 0U;

    if ((puntero_arreglo != NULL) && (*puntero_arreglo != NULL))
    {
        for (indice = 0U; indice < cantidad; indice++)
        {
            free((*puntero_arreglo)[indice]);
            (*puntero_arreglo)[indice] = NULL;
        }
        free(*puntero_arreglo);
        *puntero_arreglo = NULL;
    }
}

char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens)
{
    char **tokens = NULL;
    size_t longitud = 0U;
    size_t cantidad = 0U;
    size_t indice = 0U;
    size_t inicio = 0U;
    size_t indice_token = 0U;
    bool correcto = true;

    if (cantidad_tokens != NULL)
    {
        *cantidad_tokens = 0U;
    }

    if ((linea != NULL) && (cantidad_tokens != NULL))
    {
        longitud = strlen(linea);
        cantidad = 1U;
        for (indice = 0U; indice < longitud; indice++)
        {
            if (linea[indice] == delimitador)
            {
                cantidad++;
            }
        }

        if (cantidad <= SIZE_MAX / sizeof(char *))
        {
            tokens = calloc(cantidad, sizeof(char *));
        }
    }

    if (tokens != NULL)
    {
        inicio = 0U;
        for (indice = 0U; indice <= longitud; indice++)
        {
            if ((indice == longitud) || (linea[indice] == delimitador))
            {
                if (correcto)
                {
                    tokens[indice_token] = duplicar_segmento(linea, inicio, indice - inicio);
                    if (tokens[indice_token] == NULL)
                    {
                        correcto = false;
                    }
                    else
                    {
                        indice_token++;
                    }
                }
                inicio = indice + 1U;
            }
        }

        if (correcto)
        {
            *cantidad_tokens = cantidad;
        }
        else
        {
            liberar_arreglo_cadenas(&tokens, indice_token);
        }
    }

    return tokens;
}

char **lista_cadenas_crear(void)
{
    return NULL;
}

bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena)
{
    bool agregada = false;
    char *copia = NULL;
    char **lista_redimensionada = NULL;
    size_t longitud = 0U;

    if ((lista != NULL) && (cantidad != NULL) && (cadena != NULL) &&
        (*cantidad < SIZE_MAX / sizeof(char *)) &&
        ((*cantidad == 0U) || (*lista != NULL)))
    {
        longitud = strlen(cadena);
        copia = duplicar_segmento(cadena, 0U, longitud);
    }

    if (copia != NULL)
    {
        lista_redimensionada = realloc(*lista, (*cantidad + 1U) * sizeof(char *));
        if (lista_redimensionada != NULL)
        {
            lista_redimensionada[*cantidad] = copia;
            *lista = lista_redimensionada;
            *cantidad += 1U;
            agregada = true;
        }
        else
        {
            free(copia);
        }
    }

    return agregada;
}

void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    size_t indice = 0U;

    if (lista != NULL)
    {
        for (indice = 0U; indice < cantidad; indice++)
        {
            free(lista[indice]);
        }
        free(lista);
    }
}
