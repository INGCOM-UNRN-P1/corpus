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

    if(cadena != NULL && capacidad > 0)
    {
        while(longitud < capacidad && cadena[longitud] != '\0')
        {
            longitud++;
        }
    }

    return longitud;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool copiado = false;

    if(destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t i = 0;

        while(i < capacidad - 1 && origen[i] != '\0')
        {
            destino[i] = origen[i];
            i++;
        }

        destino[i] = '\0';

        if(origen[i] == '\0')
        {
            copiado = true;
        }
    }

    return copiado;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool concatenado = false;

    if(destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t i = 0;
        size_t j = 0;

        while(i < capacidad && destino[i] != '\0')
        {
            i++;
        }

        if(i < capacidad)
        {
            while(i < capacidad - 1 && origen[j] != '\0')
            {
                destino[i] = origen[j];
                i++;
                j++;
            }

            destino[i] = '\0';

            if(origen[j] == '\0')
            {
                concatenado = true;
            }
        }
    }

    return concatenado;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t cantidad_convertida = 0;

    if(cadena != NULL && capacidad > 0)
    {
        for(size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            if(cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - 'a' + 'A';
                cantidad_convertida++;
            }
        }
    }

    return cantidad_convertida;
}




