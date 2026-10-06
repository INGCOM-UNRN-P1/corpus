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
    
    if (destino == NULL || capacidad == 0)
    {
        return false;
    }

    if (origen == NULL)
    {
        destino[0] = '\0';
        return false;
    }
    size_t i = 0;

    while (i < capacidad - 1 && origen[i] != '\0')
    {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';

    if (origen[i] != '\0')
    {
        return false;
    }
    return true;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    
    if (destino == NULL || capacidad == 0 || origen == NULL)
    {
        return false;
    }

    size_t j = 0;
    while (j < capacidad && destino[j] != '\0')
    {
        j++;
    }

    if (j == capacidad)
    {
        return false;
    }
    size_t i = 0;
    while (j < capacidad - 1 && origen[i] != '\0')
    {
        destino[j] = origen[i];
        j++;
        i++;
    }
    destino[j] = '\0';
    if (origen[i] != '\0')
    {
        return false;
    }
    return true;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    
    if (cadena == NULL || capacidad == 0)
    {
        return 0;
    }

    size_t convertidos = 0;
    size_t i = 0;

    while (i < capacidad && cadena[i] != '\0')
    {
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = cadena[i] - 32;
            convertidos++;
        }
        i++;
    }
    return convertidos;
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

    size_t len_origen = 0;
    while (origen[len_origen] != '\0')
    {
        len_origen++;
    }

    if (inicio >= len_origen)
    {
        destino[0] = '\0';
        return false;
    }

    size_t i = 0;
    size_t j = inicio;

    while (i < capacidad - 1 && i < cantidad && origen[j] !='\0')
    {
        destino[i] = origen[j];
        i++;
        j++;
    }

    destino[i] = '\0';

    if (i < cantidad && origen[j] !='\0')
    {
        return false;
    }
    return true;
}


