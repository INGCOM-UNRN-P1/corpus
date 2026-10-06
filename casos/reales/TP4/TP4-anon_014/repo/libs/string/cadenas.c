/**
 * @file string.c
 * @brief Implementación de la biblioteca libstring.
 */

#include <stdlib.h>
#include <string.h>
#include "cadenas.h"

static size_t longitud_segura(const char *cadena, size_t capacidad_max);
static char *copiar_en_heap(const char *origen, size_t longitud);

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }
    return copiar_en_heap(origen, longitud_segura(origen, capacidad_max));
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }
    size_t largo_primera = longitud_segura(primera, cap_primera);
    size_t largo_segunda = longitud_segura(segunda, cap_segunda);
    char *unida = (char *)malloc(largo_primera + largo_segunda + 1);
    if (unida == NULL)
    {
        return NULL;
    }
    memcpy(unida, primera, largo_primera);
    memcpy(unida + largo_primera, segunda, largo_segunda);
    unida[largo_primera + largo_segunda] = '\0';
    return unida;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena == NULL)
    {
        return;
    }
    free(*puntero_cadena);
    *puntero_cadena = NULL;
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t longitud = longitud_segura(origen, capacidad_max);
    if (inicio >= longitud)
    {
        return copiar_en_heap("", 0);
    }
    size_t disponibles = longitud - inicio;
    if (cantidad > disponibles)
    {
        cantidad = disponibles;
    }
    return copiar_en_heap(origen + inicio, cantidad);
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL)
    {
        return NULL;
    }
    size_t longitud = longitud_segura(origen, capacidad_max);
    char *invertida = (char *)malloc(longitud + 1);
    if (invertida == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < longitud; i++)
    {
        invertida[i] = origen[longitud - 1 - i];
    }
    invertida[longitud] = '\0';
    return invertida;
}

/**
 * @brief Mide una cadena sin leer más de capacidad_max caracteres.
 * @param cadena cadena a medir.
 * @param capacidad_max máximo de caracteres a inspeccionar.
 * @pre cadena no es NULL.
 * @returns la longitud, acotada a capacidad_max.
 */
static size_t longitud_segura(const char *cadena, size_t capacidad_max)
{
    size_t longitud = 0;
    while (longitud < capacidad_max && cadena[longitud] != '\0')
    {
        longitud++;
    }
    return longitud;
}

/**
 * @brief Copia los primeros 'longitud' caracteres de origen en un bloque
 *        nuevo de longitud + 1 bytes, terminado en '\0'.
 * @param origen caracteres a copiar.
 * @param longitud cantidad de caracteres a copiar.
 * @pre origen no es NULL y tiene al menos 'longitud' caracteres.
 * @returns el bloque nuevo, o NULL si falla malloc.
 */
static char *copiar_en_heap(const char *origen, size_t longitud)
{
    char *copia = (char *)malloc(longitud + 1);
    if (copia == NULL)
    {
        return NULL;
    }
    memcpy(copia, origen, longitud);
    copia[longitud] = '\0';
    return copia;
}
