#include <stdint.h>
#include <stdlib.h>
#include "cadena_dinamica.h"

static size_t aux_longitud(const char *cadena)
{
    size_t len = 0;
    while (cadena != NULL && *(cadena + len) != '\0')
    {
        len++;
    }
    return len;
}

char *clonar_cadena(const char *origen)
{
    if (origen == NULL)
    {
        return NULL;
    }

    size_t longitud = aux_longitud(origen);

    if (longitud > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *clon = malloc((longitud + 1) * sizeof(*clon));
    if (clon == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i <= longitud; i++)
    {
        *(clon + i) = *(origen + i);
    }

    return clon;
}

char *unir_cadenas_dinamicas(const char *primera, const char *segunda)
{
    if (primera == NULL || segunda == NULL)
    {
        return NULL;
    }

    size_t len1 = aux_longitud(primera);
    size_t len2 = aux_longitud(segunda);

    if (len1 > SIZE_MAX - len2 - 1)
    {
        return NULL;
    }

    char *unida = malloc((len1 + len2 + 1) * sizeof(*unida));
    if (unida == NULL)
    {
        return NULL;
    }

    size_t cursor = 0;
    for (size_t i = 0; i < len1; i++)
    {
        *(unida + cursor) = *(primera + i);
        cursor++;
    }

    for (size_t i = 0; i < len2; i++)
    {
        *(unida + cursor) = *(segunda + i);
        cursor++;
    }

    *(unida + cursor) = '\0';

    return unida;
}