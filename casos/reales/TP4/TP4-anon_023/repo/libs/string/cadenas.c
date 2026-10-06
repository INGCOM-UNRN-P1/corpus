/**
 * @file string.c
 * @brief Implementacion de la biblioteca libstring.
 */

#include "string.h"
#include <stdint.h>
#include <stdlib.h>

/**
 * @brief Funcion auxiliar para calcular longitud acotada de una cadena.
 */
static size_t medir_longitud_acotada(const char *str, size_t limite)
{
    if (str == NULL || limite == 0)
    {
        return 0;
    }

    size_t len = 0;
    while (len < limite && *(str + len) != '\0')
    {
        len++;
    }

    return len;
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = medir_longitud_acotada(origen, capacidad_max);

    char *copia = malloc((longitud + 1) * sizeof(*copia));
    if (copia == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++)
    {
        *(copia + i) = *(origen + i);
    }
    *(copia + longitud) = '\0';

    return copia;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

    size_t len1 = medir_longitud_acotada(primera, cap_primera);
    size_t len2 = medir_longitud_acotada(segunda, cap_segunda);

    if (len1 > SIZE_MAX - len2 - 1)
    {
        return NULL;
    }

    size_t total = len1 + len2;

    char *resultado = malloc((total + 1) * sizeof(*resultado));
    if (resultado == NULL)
    {
        return NULL;
    }

    char *dst = resultado;
    for (size_t i = 0; i < len1; i++)
    {
        *dst = *(primera + i);
        dst++;
    }

    for (size_t j = 0; j < len2; j++)
    {
        *dst = *(segunda + j);
        dst++;
    }

    *dst = '\0';

    return resultado;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t len_origen = medir_longitud_acotada(origen, capacidad_max);

    if (inicio >= len_origen || cantidad == 0)
    {
        char *vacia = malloc(1 * sizeof(*vacia));
        if (vacia != NULL)
        {
            *vacia = '\0';
        }
        return vacia;
    }

    size_t disponibles = len_origen - inicio;
    size_t len_sub = (cantidad < disponibles) ? cantidad : disponibles;

    char *subcadena = malloc((len_sub + 1) * sizeof(*subcadena));
    if (subcadena == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < len_sub; i++)
    {
        *(subcadena + i) = *(origen + inicio + i);
    }
    *(subcadena + len_sub) = '\0';

    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = medir_longitud_acotada(origen, capacidad_max);

    char *invertida = malloc((longitud + 1) * sizeof(*invertida));
    if (invertida == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++)
    {
        *(invertida + i) = *(origen + (longitud - 1 - i));
    }
    *(invertida + longitud) = '\0';

    return invertida;
}