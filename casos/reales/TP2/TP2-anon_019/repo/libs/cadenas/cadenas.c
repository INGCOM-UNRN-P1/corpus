/**
 * @file cadenas.c
 * @brief Implementación para la biblioteca libcadenas.
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include "cadenas.h"

size_t cadena_longitud(const char cadena[], size_t capacidad)
{
    size_t i;

    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    for (i = 0; i < capacidad; i++)
    {
        if (cadena[i] == '\0')
        {
            return i;
        }
    }

    return capacidad;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    size_t i;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    for (i = 0; i < capacidad - 1 && origen[i] != '\0'; i++)
    {
        destino[i] = origen[i];
    }

    destino[i] = '\0';

    return origen[i] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    size_t long_dest;
    size_t i;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    long_dest = cadena_longitud(destino, capacidad);

    if (long_dest >= capacidad - 1)
    {
        return false;
    }

    for (i = 0; long_dest + i < capacidad - 1 && origen[i] != '\0'; i++)
    {
        destino[long_dest + i] = origen[i];
    }

    destino[long_dest + i] = '\0';

    return origen[i] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t i;
    size_t contador = 0;

    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    for (i = 0; i < capacidad && cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
            contador++;
        }
    }

    return contador;
}


bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    size_t pos;
    size_t i = 0;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    for (pos = 0; pos < inicio; pos++)
    {
        if (origen[pos] == '\0')
        {
            destino[0] = '\0';
            return true;
        }
    }

    while (i < cantidad && i < capacidad - 1 && origen[inicio + i] != '\0')
    {
        destino[i] = origen[inicio + i];
        i++;
    }

    destino[i] = '\0';

    if (i < cantidad && origen[inicio + i] != '\0')
    {
        return false;
    }

    return true;
}

