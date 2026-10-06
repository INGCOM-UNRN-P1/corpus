/**
 * @file puntero_cadena.c
 * @brief Implementación de copia y concatenación de cadenas mediante punteros.
 */

#include "puntero_cadena.h"



bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool copiado = false;
    if ((destino != NULL) && (origen != NULL) && (capacidad > 0))
    {
        size_t i = 0;
        for (i = 0; (i < capacidad - 1) && (*(origen + i) != '\0'); i++)
        {
            *(destino + i) = *(origen + i);
        }
        *(destino + i) = '\0';
        if (*(origen + i) == '\0')
        {
            copiado = true;
        }
    }
    return copiado;
}


bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen)
{
    bool concatenado = false;

    if ((destino != NULL) && (origen != NULL) && (capacidad > 0))
    {
        size_t i = 0;
        while ((i < capacidad) && (*(destino + i) != 0))
        {
            i++;
        }
        if (i < capacidad)
        {
            size_t j = 0;

            while ((i + j < capacidad - 1) && (*(origen + j) != '\0'))
            {
                *(destino + i + j) = *(origen + j);
                j++;
            }
            *(destino + i + j) = '\0';

            if (*(origen + j) == '\0')
            {
                concatenado = true;
            }
        }
    }
    return concatenado;
}

