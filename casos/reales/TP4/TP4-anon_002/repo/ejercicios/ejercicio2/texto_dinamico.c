/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include "texto_dinamico.h"
#include <stdlib.h>


char *cadena_recortar_espacios(const char *origen)
{
    char *cadena_recortada = NULL;

    if (origen == NULL)
    {
        cadena_recortada = NULL;
    }
    else
    {
        const char *inicio_cadena = origen;

        while (*inicio_cadena != '\0' && *inicio_cadena == ' ')
        {
            inicio_cadena++;
        }

        if (*inicio_cadena == '\0')
        {
            cadena_recortada = NULL;
        }
        else
        {
            const char *fin_cadena = inicio_cadena;

            while (*fin_cadena != '\0')
            {
                fin_cadena++;
            }

            while (fin_cadena > inicio_cadena && *(fin_cadena - 1) == ' ')
            {
                fin_cadena--;
            }

            size_t longitud = (size_t)(fin_cadena - inicio_cadena);

            cadena_recortada = malloc((longitud + 1) * sizeof(char));

            if (cadena_recortada == NULL)
            {
                cadena_recortada = NULL;
            }
            else
            {
                const char *actual = inicio_cadena;
                char *destino = cadena_recortada;

                while (actual < fin_cadena)
                {
                    *destino = *actual;
                    destino++;
                    actual++;
                }

                *destino = '\0';
            }
        }
    }
    return cadena_recortada;
}


char *cadena_repetir(const char *origen, size_t veces)
{
    char *cadena_repetida = NULL;

    if (origen == NULL)
    {
        cadena_repetida = NULL;
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

        if (veces == 0)
        {
            cadena_repetida = malloc(sizeof(char));

            if (cadena_repetida != NULL)
            {
                *cadena_repetida = '\0';
            }
        }
        else
        {
            size_t longitud_total = longitud * veces;

            cadena_repetida = malloc((longitud_total + 1) * sizeof(char));

            if (cadena_repetida != NULL)
            {
                char *destino = cadena_repetida;
                size_t repeticion = 0;

                while (repeticion < veces)
                {
                    actual = origen;

                    while (*actual != '\0')
                    {
                        *destino = *actual;
                        destino++;
                        actual++;
                    }

                    repeticion++;
                }

                *destino = '\0';
            }
        }
    }
    return cadena_repetida;
}
