/**
 * @file registro_csv.c
 * @brief Implementación de listas dinámicas de cadenas en heap.
 */

#include "registro_csv.h"
#include <stdlib.h>


char **lista_cadenas_crear(void)
{
    char **lista = NULL;

    return lista;
}


bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena)
{
    bool pudo_agregar = false;

    if (lista != NULL && cantidad != NULL && cadena != NULL)
    {
        size_t longitud_cadena = 0;
        const char *actual = cadena;

        while (*actual != '\0')
        {
            longitud_cadena++;
            actual++;
        }

        char *cadena_duplicada = malloc((longitud_cadena + 1) * sizeof(char));

        if (cadena_duplicada != NULL)
        {
            char *destino = cadena_duplicada;
            actual = cadena;

            while (*actual != '\0')
            {
                *destino = *actual;
                destino++;
                actual++;
            }

            *destino = '\0';

            char **lista_redimensionada =
                realloc(*lista, (*cantidad + 1) * sizeof(char *));

            if (lista_redimensionada != NULL)
            {
                *(lista_redimensionada + *cantidad) = cadena_duplicada;
                *lista = lista_redimensionada;
                (*cantidad)++;
                pudo_agregar = true;
            }
            else
            {
                free(cadena_duplicada);
            }
        }
    }

    return pudo_agregar;
}


void lista_cadenas_destruir(char **lista, size_t cantidad)
{
    if (lista != NULL)
    {
        char **actual = lista;
        char **limite = lista + cantidad;

        while (actual < limite)
        {
            free(*actual);
            actual++;
        }

        free(lista);
    }
}
