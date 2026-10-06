/**
 * @file registro_csv.c
 * @brief Implementación de tokenización y listas dinámicas en heap.
 */

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cadenas.h"
#include "registro_csv.h"

char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens)
{
    char **tokens = NULL;
    char *buffer = NULL;
    char *inicio = NULL;
    char *cursor = NULL;
    size_t cantidad = 0U;
    size_t i = 0U;
    size_t longitud = 0U;

    if (linea == NULL || cantidad_tokens == NULL)
    {
        return NULL;
    }

    buffer = cadena_duplicar_segura(linea, strlen(linea) + 1U);
    if (buffer == NULL)
    {
        return NULL;
    }

    cantidad = 1U;
    for (i = 0U; buffer[i] != '\0'; ++i)
    {
        if (buffer[i] == delimitador)
        {
            ++cantidad;
        }
    }

    tokens = calloc(cantidad, sizeof(*tokens));
    if (tokens == NULL)
    {
        cadena_liberar_segura(&buffer);
        return NULL;
    }

    inicio = buffer;
    cursor = buffer;
    i = 0U;
    while (*cursor != '\0')
    {
        if (*cursor == delimitador)
        {
            *cursor = '\0';
            longitud = (size_t)(cursor - inicio);
            tokens[i] = cadena_duplicar_segura(inicio, longitud + 1U);
            if (tokens[i] == NULL)
            {
                size_t j = 0U;
                while (j < i)
                {
                    cadena_liberar_segura(&tokens[j]);
                    ++j;
                }
                free(tokens);
                cadena_liberar_segura(&buffer);
                return NULL;
            }
            ++i;
            inicio = cursor + 1;
        }
        ++cursor;
    }

    longitud = (size_t)(cursor - inicio);
    tokens[i] = cadena_duplicar_segura(inicio, longitud + 1U);
    if (tokens[i] == NULL)
    {
        size_t j = 0U;
        while (j < i)
        {
            cadena_liberar_segura(&tokens[j]);
            ++j;
        }
        free(tokens);
        cadena_liberar_segura(&buffer);
        return NULL;
    }
    ++i;

    *cantidad_tokens = i;
    cadena_liberar_segura(&buffer);
    return tokens;
}

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad)
{
    size_t i = 0U;

    if (puntero_arreglo == NULL || *puntero_arreglo == NULL)
    {
        return;
    }

    for (i = 0U; i < cantidad; ++i)
    {
        cadena_liberar_segura(&((*puntero_arreglo)[i]));
    }
    free(*puntero_arreglo);
    *puntero_arreglo = NULL;
}

char **lista_cadenas_crear(void)
{
    return NULL;
}

bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena)
{
    char *copia = NULL;
    char **nuevo = NULL;

    if (lista == NULL || cantidad == NULL || cadena == NULL)
    {
        return false;
    }

    copia = cadena_duplicar_segura(cadena, strlen(cadena) + 1U);
    if (copia == NULL)
    {
        return false;
    }

    nuevo = realloc(*lista, (*cantidad + 1U) * sizeof(*nuevo));
    if (nuevo == NULL)
    {
        cadena_liberar_segura(&copia);
        return false;
    }

    *lista = nuevo;
    (*lista)[*cantidad] = copia;
    (*cantidad)++;

    return true;
}

void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    size_t i = 0U;

    if (lista == NULL)
    {
        return;
    }

    for (i = 0U; i < cantidad; ++i)
    {
        cadena_liberar_segura(&lista[i]);
    }
    free(lista);
}