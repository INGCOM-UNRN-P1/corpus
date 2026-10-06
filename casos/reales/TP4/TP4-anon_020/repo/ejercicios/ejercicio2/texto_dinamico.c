/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include <string.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    size_t inicio = 0U;
    size_t fin = 0U;
    size_t longitud = 0U;
    char *resultado = NULL;

    if (origen == NULL)
    {
        return NULL;
    }

    longitud = strlen(origen);
    while (inicio < longitud && origen[inicio] == ' ')
    {
        ++inicio;
    }

    fin = longitud;
    while (fin > inicio && origen[fin - 1U] == ' ')
    {
        --fin;
    }

    if (inicio == fin)
    {
        return NULL;
    }

    resultado = cadena_subcadena_dinamica(origen, longitud + 1U, inicio,
                                          fin - inicio);
    return resultado;
}

char *cadena_repetir(const char *origen, size_t veces)
{
    size_t longitud = 0U;
    size_t i = 0U;
    char *acumulado = NULL;
    char *temporal = NULL;

    if (origen == NULL)
    {
        return NULL;
    }

    longitud = strlen(origen);
    if (veces == 0U)
    {
        return cadena_duplicar_segura("", 1U);
    }

    acumulado = cadena_duplicar_segura(origen, longitud + 1U);
    if (acumulado == NULL)
    {
        return NULL;
    }

    for (i = 1U; i < veces; ++i)
    {
        temporal = cadena_unir_dinamica(acumulado, longitud * i + 1U,
                                       origen, longitud + 1U);
        if (temporal == NULL)
        {
            cadena_liberar_segura(&acumulado);
            return NULL;
        }
        cadena_liberar_segura(&acumulado);
        acumulado = temporal;
    }

    return acumulado;
}