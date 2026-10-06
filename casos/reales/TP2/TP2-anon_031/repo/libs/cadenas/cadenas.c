/**
 * @file cadenas.c
 * @brief Esqueleto de implementación para la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Las funciones provistas son esqueletos iniciales para ser completados
 * íntegramente por los estudiantes como parte de la entrega.
 */

#include "cadenas.h"

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t longitud = 0;

    if (cadena != NULL)
    {
        while ((longitud < capacidad) && (cadena[longitud] != '\0'))
        {
            longitud++;
        }
    }

    return longitud;
}
bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool completa = true;
    size_t posicion = 0;

    if ((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        completa = false;
    }
    else
    {
        while ((posicion + 1 < capacidad) && (origen[posicion] != '\0'))
        {
            destino[posicion] = origen[posicion];
            posicion++;
        }

        destino[posicion] = '\0';

        if (origen[posicion] != '\0')
        {
            completa = false;
        }
    }

    return completa;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool completa = true;
    size_t longitud = 0;
    size_t posicion = 0;

    if ((destino == NULL) || (origen == NULL) || (capacidad == 0))
    {
        completa = false;
    }
    else
    {
        longitud = cadena_longitud(destino, capacidad);

        if (longitud == capacidad)
        {
            completa = false;
        }
        else
        {
            while ((longitud + posicion + 1 < capacidad)
                   && (origen[posicion] != '\0'))
            {
                destino[longitud + posicion] = origen[posicion];
                posicion++;
            }

            destino[longitud + posicion] = '\0';

            if (origen[posicion] != '\0')
            {
                completa = false;
            }
        }
    }

    return completa;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t conversiones = 0;
    size_t posicion = 0;

    if (cadena != NULL)
    {
        while ((posicion < capacidad) && (cadena[posicion] != '\0'))
        {
            if ((cadena[posicion] >= 'a') && (cadena[posicion] <= 'z'))
            {
                cadena[posicion] = cadena[posicion] - ('a' - 'A');
                conversiones++;
            }

            posicion++;
        }
    }

    return conversiones;
}




