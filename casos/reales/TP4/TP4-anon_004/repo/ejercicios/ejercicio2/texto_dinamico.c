
/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"

static size_t medir_longitud(const char *cadena)
{
    size_t longitud = 0;

    if (cadena == NULL)
    {
        return 0;
    }

    while (cadena[longitud] != '\0')
    {
        longitud++;
    }

    return longitud;
}

char *cadena_recortar_espacios(const char *origen)
{
    size_t inicio = 0;
    size_t limite_final = 0;
    size_t longitud_resultado = 0;
    size_t i = 0;

    char *resultado = NULL;

    if (origen == NULL)
    {
        return NULL;
    }

    limite_final = medir_longitud(origen);

    while (inicio < limite_final && origen[inicio] == ' ')
    {
        inicio++;
    }

    while (limite_final > inicio &&
           origen[limite_final - 1] == ' ')
    {
        limite_final--;
    }

    if (inicio == limite_final)
    {
        return NULL;
    }

    longitud_resultado = limite_final - inicio;

    resultado = malloc(
        (longitud_resultado + 1) * sizeof(char)
    );

    if (resultado == NULL)
    {
        return NULL;
    }

    for (i = 0; i < longitud_resultado; i++)
    {
        resultado[i] = origen[inicio + i];
    }

    resultado[longitud_resultado] = '\0';

    return resultado;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    size_t longitud = 0;
    size_t longitud_total = 0;
    size_t repeticion = 0;
    size_t i = 0;
    size_t posicion = 0;

    char *resultado = NULL;

    if (origen == NULL)
    {
        return NULL;
    }

    longitud = medir_longitud(origen);
    longitud_total = longitud * veces;

    resultado = malloc(
        (longitud_total + 1) * sizeof(char)
    );

    if (resultado == NULL)
    {
        return NULL;
    }

    for (repeticion = 0; repeticion < veces; repeticion++)
    {
        for (i = 0; i < longitud; i++)
        {
            resultado[posicion] = origen[i];
            posicion++;
        }
    }

    resultado[posicion] = '\0';

    return resultado;
}
