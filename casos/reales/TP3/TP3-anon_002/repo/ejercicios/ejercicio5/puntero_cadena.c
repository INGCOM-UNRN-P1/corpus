/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"

bool copiar_con_punteros(char *dest, size_t cap, const char *src)
{
    bool resultado = false;

    if (dest == NULL || src == NULL)
    {
        resultado = false;
    }
    else if (cap == 0)
    {
        resultado = false;
    }
    else
    {
        char *limite = dest + (cap - 1);

        while (dest < limite && *src != '\0')
        {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';

        if (*src == '\0')
        {
            resultado = true;
        }
        else
        {
            resultado = false;
        }
    }
    return resultado;
}

bool concatenar_con_punteros(char *dest, size_t cap, const char *src)
{
    bool exito = false;

    if (dest == NULL || src == NULL)
    {
        exito = false;
    }
    else if (cap == 0)
    {
        exito = false;
    }
    else
    {
        char *ptr_copia = dest;

        const char *limite_concatenado = dest + (cap - 1);

        while (*ptr_copia != '\0' && ptr_copia < limite_concatenado)
        {
            ptr_copia++;
        }

        if (*ptr_copia == '\0')
        {
            while (*src != '\0' && ptr_copia < limite_concatenado)
            {
                *ptr_copia = *src;
                ptr_copia++;
                src++;
            }

            *ptr_copia = '\0';

            if (*src == '\0')
            {
                exito = true;
            }
        }
        else
        {
            exito = false;
        }
    }
    return exito;
}

size_t longitud_con_punteros(const char *s, size_t cap)
{
    size_t largo = 0;

    if (s == NULL)
    {
        largo = 0;
    }
    else if (cap == 0)
    {
        largo = 0;
    }
    else
    {
        const char *ptr = s;
        const char *ptr_limite = s + cap;

        while (ptr < ptr_limite && *ptr != '\0')
        {
            ptr++;
            largo++;
        }
    }
    return largo;
}