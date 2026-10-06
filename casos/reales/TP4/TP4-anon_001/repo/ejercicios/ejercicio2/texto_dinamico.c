/**
 * @file texto_dinamico.c
 * @brief Implementación de funciones de texto dinámico en heap.
 */

#include "texto_dinamico.h"
#include "cadenas_tp2.h"
#include <stdlib.h>


char *cadena_recortar_espacios(const char *origen)
{
    char *nueva_cadena = NULL;

    if (origen != NULL)
    {
        const char *ptr_inicio = origen;
        while (*ptr_inicio == ' ' && *ptr_inicio != '\0')
        {
            ptr_inicio++;
        }
        if (*ptr_inicio != '\0')
        {
            const char *ptr_fin = ptr_inicio;
            while (*ptr_fin != '\0')
            {
                ptr_fin++;
            }
            ptr_fin--;
            while (ptr_fin > ptr_inicio && *ptr_fin == ' ')
            {
                ptr_fin--;
            }
            size_t len = (size_t)(ptr_fin - ptr_inicio) + 1;
            nueva_cadena = (char *)malloc((len + 1) * sizeof(char));

            if (nueva_cadena != NULL)
            {
                for (size_t k = 0; k < len; k++)
                {
                    *(nueva_cadena + k) = *(ptr_inicio + k);
                }
                *(nueva_cadena + len) = '\0';
            }
        }
    }
    return nueva_cadena;
}


char *cadena_repetir(const char *origen, size_t veces)
{
    char *nueva_cadena = NULL;

    if (origen != NULL && veces != 0)
    {
        size_t len = 0;
        for (; *(origen + len) != '\0'; len++)
        {
        }
        size_t q_reservar = (len * veces) + 1;
        nueva_cadena = (char *)calloc(q_reservar, sizeof(char));
        if (nueva_cadena != NULL)
        {
            for (size_t j = 0; j < veces; j++)
            {
                cadena_concatenar(nueva_cadena, q_reservar, origen);
            }
        }
    }
    else
    {
        nueva_cadena = (char *)calloc(1, sizeof(char));
    }
    return nueva_cadena;
}
