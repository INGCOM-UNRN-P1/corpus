/**
 * @file cadenas.c
 * @brief Implementacion de la biblioteca libcadenas.
 *
 * Trabajo Practico 2 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#include "cadenas.h"


size_t cadena_longitud(
    const char cadena[],
    size_t capacidad
)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t posicion = 0;

    while (posicion < capacidad && cadena[posicion] != '\0')
    {
        posicion++;
    }

    return posicion;
}


bool cadena_copiar(
    char destino[],
    size_t capacidad,
    const char origen[]
)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (origen == NULL)
    {
        destino[0] = '\0';
        return false;
    }

    size_t posicion = 0;

    while (
        posicion < capacidad - 1 &&
        origen[posicion] != '\0'
    )
    {
        destino[posicion] = origen[posicion];
        posicion++;
    }

    destino[posicion] = '\0';

    return origen[posicion] == '\0';
}


bool cadena_concatenar(
    char destino[],
    size_t capacidad,
    const char origen[]
)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (origen == NULL)
    {
        destino[capacidad - 1] = '\0';
        return false;
    }

    size_t longitud = cadena_longitud(destino, capacidad);

    if (longitud == capacidad)
    {
        destino[capacidad - 1] = '\0';
        return false;
    }

    size_t lectura = 0;

    while (
        longitud < capacidad - 1 &&
        origen[lectura] != '\0'
    )
    {
        destino[longitud] = origen[lectura];
        longitud++;
        lectura++;
    }

    destino[longitud] = '\0';

    return origen[lectura] == '\0';
}


size_t cadena_a_mayusculas(
    char cadena[],
    size_t capacidad
)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t posicion = 0;
    size_t contador = 0;

    while (
        posicion < capacidad &&
        cadena[posicion] != '\0'
    )
    {
        if (
            cadena[posicion] >= 'a' &&
            cadena[posicion] <= 'z'
        )
        {
            cadena[posicion] =
                cadena[posicion] - 'a' + 'A';

            contador++;
        }

        posicion++;
    }

    return contador;
}


bool cadena_subcadena(
    char destino[],
    size_t capacidad,
    const char origen[],
    size_t inicio,
    size_t cantidad
)
{
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    destino[0] = '\0';

    if (origen == NULL)
    {
        return false;
    }

    size_t lectura = 0;

    while (
        lectura < inicio &&
        origen[lectura] != '\0'
    )
    {
        lectura++;
    }

    if (lectura < inicio)
    {
        return true;
    }

    size_t escritura = 0;

    while (
        escritura < cantidad &&
        escritura < capacidad - 1 &&
        origen[lectura] != '\0'
    )
    {
        destino[escritura] = origen[lectura];

        escritura++;
        lectura++;
    }

    destino[escritura] = '\0';

    if (escritura == cantidad)
    {
        return true;
    }

    if (origen[lectura] == '\0')
    {
        return true;
    }

    return false;
}