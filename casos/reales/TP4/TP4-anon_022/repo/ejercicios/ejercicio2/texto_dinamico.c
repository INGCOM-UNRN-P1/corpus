/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t largo = 0;
    while (origen[largo] != '\0')
    {
        largo++;
    }

    size_t inicio = 0;
    while (inicio < largo && origen[inicio] == ' ')
    {
        inicio++;
    }

    if (inicio == largo)    // Vacía o solo espacios
    {
        return NULL;
    }

    size_t fin = largo;
    while (origen[fin - 1] == ' ')
    {
        fin--;
    }

    return cadena_subcadena_dinamica(origen, largo, inicio, fin - inicio);
}

char *cadena_repetir(const char *origen, size_t veces)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t largo = 0;
    while (origen[largo] != '\0')
    {
        largo++;
    }

    size_t total = largo * veces;

    if (veces != 0 && total / veces != largo)
    {
        return NULL;
    }

    char *resultado = malloc(total + 1);

    if (resultado == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < veces; i++)
    {
        cadena_copiar(resultado + i * largo, largo + 1, origen);
    }

    resultado[total] = '\0';

    return resultado;
}