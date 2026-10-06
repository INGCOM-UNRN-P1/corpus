/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include <stdlib.h>
#include "texto_dinamico.h"

char *cadena_recortar_espacios(const char *origen, size_t capacidad)
{
    if (origen == NULL || capacidad == 0)
    {
        return NULL;
    }

    size_t largo = 0;
    while (largo < capacidad && origen[largo] != '\0')
    {
        largo++;
    }

    // Primero calcula la primer ocurrencia de un caracter diferente a espacio
    // para pasar a cadena_subcadena_dinamica()
    size_t inicio = 0;
    while (inicio < largo && origen[inicio] == ' ')
    {
        inicio++;
    }
    // Si todos los caracteres son espacio retorna NULL
    if (inicio == largo)
    {
        return NULL;
    }

    // Por ultimo calcula la ultima ocurrencia de un caracter diferente a espacio
    size_t final = (largo - 1);
    while (final != 0 && origen[final] == ' ')
    {
        final--;
    }

    size_t cantidad = (final - inicio) + 1;
    char *bloque = cadena_subcadena_dinamica(origen, largo , inicio, cantidad);

    return bloque;
}


char *cadena_repetir(const char *origen, size_t capacidad, size_t veces)
{
    if (origen == NULL || capacidad == 0)
    {
        return NULL;
    }
    if (veces == 0)
    {
        char *cadena_vacia = malloc(1);
        if (cadena_vacia == NULL)
        {
            return NULL;
        }
        cadena_vacia[0] = '\0';
        return cadena_vacia;
    }

    size_t largo = 0;
    while (largo < capacidad && origen[largo] != '\0')
    {
        largo++;
    }

    char *bloque = malloc((largo)* veces);
    if (bloque == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < veces; i++)
    {
        for (size_t j = 0; j < (largo); j++)
        {
            bloque[(veces * i) + j] = origen[j];
        }
    }

    bloque[veces * (largo)] = '\0';

    return bloque;
}