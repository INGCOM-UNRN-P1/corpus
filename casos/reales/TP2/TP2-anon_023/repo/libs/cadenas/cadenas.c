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
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t i = 0;
    while (i < capacidad && cadena[i] != '\0')
    {
        i++;
    }
    return i;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }

    size_t i = 0;
    while (origen[i] != '\0' && (i + 1) < capacidad)
    {
        destino[i] = origen[i];
        i++;
    }

    destino[i] = '\0';
    return (origen[i] == '\0');
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }

    size_t len_dest = 0;
    while (len_dest < capacidad && destino[len_dest] != '\0')
    {
        len_dest++;
    }

    if (len_dest >= capacidad)
    {
        return false;
    }

    size_t i = 0;
    while (origen[i] != '\0' && (len_dest + i + 1) < capacidad)
    {
        destino[len_dest + i] = origen[i];
        i++;
    }

    destino[len_dest + i] = '\0';
    return (origen[i] == '\0');
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t modificaciones = 0;
    for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = (char)(cadena[i] - ('a' - 'A'));
            modificaciones++;
        }
    }
    return modificaciones;
}

bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
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

    size_t len_orig = 0;
    while (origen[len_orig] != '\0')
    {
        len_orig++;
    }

    if (inicio >= len_orig || cantidad == 0)
    {
        destino[0] = '\0';
        return true;
    }

    size_t copiado = 0;
    while ((inicio + copiado) < len_orig && copiado < cantidad && (copiado + 1) < capacidad)
    {
        destino[copiado] = origen[inicio + copiado];
        copiado++;
    }

    destino[copiado] = '\0';
    return ((inicio + copiado) == len_orig || copiado == cantidad);
}


