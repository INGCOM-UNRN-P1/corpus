#include <stdint.h>
#include <stdlib.h>
#include "cadenas.h"

static size_t aux_longitud(const char *cadena, size_t cap_max)
{
    size_t len = 0;
    while (len < cap_max && *(cadena + len) != '\0')
    {
        len++;
    }
    return len;
}

static void aux_copiar(char *destino, size_t cap_max, const char *origen)
{
    size_t i = 0;
    while (i < cap_max - 1 && *(origen + i) != '\0')
    {
        *(destino + i) = *(origen + i);
        i++;
    }
    *(destino + i) = '\0';
}

static void aux_concatenar(char *destino, size_t cap_max, const char *origen)
{
    size_t i = 0;
    while (i < cap_max && *(destino + i) != '\0')
    {
        i++;
    }
    size_t j = 0;
    while (i < cap_max - 1 && *(origen + j) != '\0')
    {
        *(destino + i) = *(origen + j);
        i++;
        j++;
    }
    *(destino + i) = '\0';
}

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = aux_longitud(origen, capacidad_max);
    
    if (longitud > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *nueva = malloc((longitud + 1) * sizeof(*nueva));
    if (nueva == NULL)
    {
        return NULL;
    }

    aux_copiar(nueva, longitud + 1, origen);
    
    return nueva;
}

char *cadena_unir_dinamica(const char *primera, size_t cap_primera, const char *segunda, size_t cap_segunda)
{
    if (primera == NULL || segunda == NULL || cap_primera == 0 || cap_segunda == 0)
    {
        return NULL;
    }

    size_t len1 = aux_longitud(primera, cap_primera);
    size_t len2 = aux_longitud(segunda, cap_segunda);
    
    if (len1 > SIZE_MAX - len2 - 1)
    {
        return NULL;
    }

    char *unida = malloc((len1 + len2 + 1) * sizeof(*unida));
    if (unida == NULL)
    {
        return NULL;
    }

    aux_copiar(unida, len1 + len2 + 1, primera);
    aux_concatenar(unida, len1 + len2 + 1, segunda);

    return unida;
}

void cadena_liberar_segura(char **puntero_cadena)
{
    if (puntero_cadena != NULL && *puntero_cadena != NULL)
    {
        free(*puntero_cadena);
        *puntero_cadena = NULL;
    }
}

char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud_total = aux_longitud(origen, capacidad_max);
    
    if (inicio >= longitud_total)
    {
        char *vacia = malloc(1 * sizeof(*vacia));
        if (vacia != NULL)
        {
            *vacia = '\0';
        }
        return vacia;
    }

    size_t disponibles = longitud_total - inicio;
    size_t extraidos = (cantidad < disponibles) ? cantidad : disponibles;

    if (extraidos > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *subcadena = malloc((extraidos + 1) * sizeof(*subcadena));
    if (subcadena == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < extraidos; i++)
    {
        *(subcadena + i) = *(origen + inicio + i);
    }
    *(subcadena + extraidos) = '\0';

    return subcadena;
}

char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    if (origen == NULL || capacidad_max == 0)
    {
        return NULL;
    }

    size_t longitud = aux_longitud(origen, capacidad_max);
    
    if (longitud > SIZE_MAX - 1)
    {
        return NULL;
    }

    char *invertida = malloc((longitud + 1) * sizeof(*invertida));
    if (invertida == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < longitud; i++)
    {
        *(invertida + i) = *(origen + longitud - 1 - i);
    }
    *(invertida + longitud) = '\0';

    return invertida;
}