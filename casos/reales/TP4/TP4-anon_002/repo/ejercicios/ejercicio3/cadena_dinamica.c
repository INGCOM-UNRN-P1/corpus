/**
 * @file cadena_dinamica.c
 * @brief Implementación para Ejercicio 3 (Cadenas en Heap).
 */

#include "cadena_dinamica.h"
#include <stdlib.h>


char *clonar_cadena(const char *origen)
{
    char *cadena_clonada = NULL;

    if (origen == NULL)
    {
        cadena_clonada = NULL;
    }
    else
    {
        size_t longitud = 0;
        const char *actual = origen;

        while (*actual != '\0')
        {
            longitud++;
            actual++;
        }

        cadena_clonada = malloc((longitud + 1) * sizeof(char));

        if (cadena_clonada == NULL)
        {
            cadena_clonada = NULL;
        }
        else
        {
            const char *origen_actual = origen;
            char *destino = cadena_clonada;

            while (*origen_actual != '\0')
            {
                *destino = *origen_actual;
                destino++;
                origen_actual++;
            }

            *destino = '\0';
        }
    }
    return cadena_clonada;
}


char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    char *cadena_unida = NULL;

    if (primera == NULL || segunda == NULL)
    {
        cadena_unida = NULL;
    }
    else
    {
        size_t longitud_primera = 0;
        size_t longitud_segunda = 0;

        const char *actual_primera = primera;
        const char *actual_segunda = segunda;

        while (*actual_primera != '\0')
        {
            longitud_primera++;
            actual_primera++;
        }

        while (*actual_segunda != '\0')
        {
            longitud_segunda++;
            actual_segunda++;
        }

        size_t longitud_total = longitud_primera + longitud_segunda;

        cadena_unida = malloc((longitud_total + 1) * sizeof(char));

        if (cadena_unida == NULL)
        {
            cadena_unida = NULL;
        }
        else
        {
            char *destino = cadena_unida;

            actual_primera = primera;

            while (*actual_primera != '\0')
            {
                *destino = *actual_primera;
                destino++;
                actual_primera++;
            }

            actual_segunda = segunda;

            while (*actual_segunda != '\0')
            {
                *destino = *actual_segunda;
                destino++;
                actual_segunda++;
            }

            *destino = '\0';
        }
    }
    return cadena_unida;
}
