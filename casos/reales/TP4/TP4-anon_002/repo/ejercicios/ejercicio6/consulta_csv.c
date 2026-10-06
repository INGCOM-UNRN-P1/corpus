/**
 * @file consulta_csv.c
 * @brief Implementación del almacenamiento y filtrado de texto multilinea.
 */

#include "consulta_csv.h"
#include <stdio.h>
#include <stdlib.h>

bool agregar_linea(char ***lineas, size_t *cantidad, const char *linea)
{
    bool pudo_agregar = false;

    if (lineas != NULL && cantidad != NULL && linea != NULL)
    {
        size_t longitud_linea = 0;
        const char *actual = linea;

        while (*actual != '\0')
        {
            longitud_linea++;
            actual++;
        }

        char *linea_duplicada = malloc((longitud_linea + 1) * sizeof(char));

        if (linea_duplicada != NULL)
        {
            char *destino = linea_duplicada;
            actual = linea;

            while (*actual != '\0')
            {
                *destino = *actual;
                destino++;
                actual++;
            }

            *destino = '\0';

            char **lineas_redimensionadas =
                realloc(*lineas, (*cantidad + 1) * sizeof(char *));

            if (lineas_redimensionadas != NULL)
            {
                *(lineas_redimensionadas + *cantidad) = linea_duplicada;
                *lineas = lineas_redimensionadas;
                (*cantidad)++;
                pudo_agregar = true;
            }
            else
            {
                free(linea_duplicada);
            }
        }
    }

    return pudo_agregar;
}


bool contiene_subcadena(const char *linea, const char *subcadena)
{
    bool encontrada = false;

    if (linea != NULL && subcadena != NULL)
    {
        const char *inicio_linea = linea;

        if (*subcadena == '\0')
        {
            encontrada = true;
        }
        else
        {
            while (*inicio_linea != '\0' && !encontrada)
            {
                const char *actual_linea = inicio_linea;
                const char *actual_subcadena = subcadena;

                while (*actual_linea != '\0' && *actual_subcadena != '\0' &&
                       *actual_linea == *actual_subcadena)
                {
                    actual_linea++;
                    actual_subcadena++;
                }

                if (*actual_subcadena == '\0')
                {
                    encontrada = true;
                }
                else
                {
                    inicio_linea++;
                }
            }
        }
    }

    return encontrada;
}


void mostrar_lineas_filtradas(char **lineas, size_t cantidad,
                              const char *subcadena)
{
    if (lineas != NULL && subcadena != NULL)
    {
        char **actual = lineas;
        char **limite = lineas + cantidad;

        while (actual < limite)
        {
            if (contiene_subcadena(*actual, subcadena))
            {
                printf("%s", *actual);
            }

            actual++;
        }
    }
}


void liberar_lineas(char **lineas, size_t cantidad)
{
    if (lineas != NULL)
    {
        char **actual = lineas;
        char **limite = lineas + cantidad;

        while (actual < limite)
        {
            free(*actual);
            actual++;
        }

        free(lineas);
    }
}
