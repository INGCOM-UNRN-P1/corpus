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
    if (cadena == NULL)
    {
        return 0
    }

    size_t posicion = 0;
    while (posicion < capacidad && cadena[posicion] != '\0')
    {
        ++posicion;
    }

    return posicion;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t posicion = 0;
    while (posicion < capacidad - 1 && origen[posicion] != '\0')
    {
        destino[posicion] = origen[posicion];
        ++posicion;
    }

    destino[posicion] = '\0';

    return origen[posicion] == '\0';
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || origen == NUll || capacidad == 0)
    {
        return false;
    }

    size_t longitud_destino = cadena_longitud(destino, capacidad);

    if (longitud_destino >= capacidad - 1)
    {
        destino[capacidad - 1] = '\0';
        return (origen[0] == '\0');
    }

    size_t posicion_origen = 0;
    size_t posicion_destino = longitud_destino;

    while(posicion_destino < capacidad - 1 && origen[posicion_origen] != '\0')
    {
        destino[posicion_destino] = origen[posicion_origen];
        ++posicion_destino;
        ++posicion_origen;
    }

    destino[posicion_destino] = '\0';

    return origen[posicion_origen] == '\0';
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t conversiones = 0;
    size_t posicion = 0;

    while (posicion < capacidad && cadena[posicion] != '\0')
    {
        if (cadena[posicion] >= 'a' && cadena[posicion] <= 'z')
        {
            cadena[posicion] = (char)(cadena[posicion] - 'a' + 'A');
        }
        ++posicion;
    }

    return conversiones;
}


bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad);
{
    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        return false;
    }

    size_t longitud_origen = cadena_longitud(origen, capacidad + inicio + cantidad);

    if (inicio >= longitud_origen)
    {
        destino[0] = '\0';
        return (cantidad == 0);
    }

    size_t posicion_destino = 0;
    size_t posicion_origen = inicio;
    size_t restantes = cantidad;

    while (posicion_destino < capacidad -1 && restantes > 0 && origen[posicion_origen] != '\0')
    {
        destino[posicion_destino] = origen[posicion_origen];
        ++posicion_destino;
        ++posicion_origen;
        --restantes;
    }

    destino[posicion_destino] = '\0';

    return (restantes == 0);
}

