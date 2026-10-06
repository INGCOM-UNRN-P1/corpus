

#include "cadenas.h"
#include "../cadenas/cadenas_tp2.h"
#include <stdlib.h>

char *cadena_duplicar_segura(const char *origen, size_t capacidad_max)
{
    size_t len = 0;
    char *destino = NULL;
    if ((capacidad_max != 0) && (origen != NULL))
    {
        while (len < capacidad_max && origen[len] != '\0')
        {
            len++;
        }
        destino = (char *)malloc(len + 1);
        if (destino != NULL)
        {
            for (size_t i = 0; i < len; i++)
            {
                destino[i] = origen[i];
            }
            destino[len] = '\0';
        }
    }
    return destino;
}


char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda)
{
    char *concatenada = NULL;
    size_t len1 = 0;
    size_t len2 = 0;
    if ((primera != NULL) && (segunda != NULL) && (cap_primera > 0) &&
        (cap_segunda > 0))
    {
        while (len1 < cap_primera && primera[len1] != '\0')
        {
            len1++;
        }
        while (len2 < cap_segunda && segunda[len2] != '\0')
        {
            len2++;
        }
        concatenada = malloc(len1 + len2 + 1);
        if (concatenada != NULL)
        {
            cadena_copiar(concatenada, len1 + len2 + 1, primera);
            cadena_concatenar(concatenada, len1 + len2 + 1, segunda);
        }
    }
    return concatenada;
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
    char *nueva_cadena = NULL;

    if (origen != NULL)
    {
        size_t len = cadena_longitud(origen, capacidad_max);
        if (inicio >= len)
        {
            nueva_cadena = calloc(1, sizeof(char));
        }
        else
        {
            size_t disponibles = len - inicio;
            size_t a_extraer =
                (cantidad < disponibles) ? cantidad : disponibles;
            nueva_cadena = calloc(a_extraer + 1, sizeof(char));
            if (nueva_cadena != NULL)
            {
                for (size_t j = 0; j < a_extraer; j++)
                {
                    nueva_cadena[j] = origen[inicio + j];
                }
            }
        }
    }

    return nueva_cadena;
}


char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max)
{
    char *cadena_invertida = NULL;
    if (origen != NULL)
    {
        size_t len = cadena_longitud(origen, capacidad_max);
        cadena_invertida = calloc(len + 1, sizeof(char));
        if (cadena_invertida != NULL)
        {
            size_t i = 0;
            size_t j = len - 1;
            while (i < len)
            {
                cadena_invertida[j] = origen[i];
                i++;
                j--;
            }
        }
    }
    return cadena_invertida;
}

