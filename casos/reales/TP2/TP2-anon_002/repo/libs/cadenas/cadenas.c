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
    size_t largo = 0;

    if (cadena == NULL || capacidad == 0)
    {
        largo = 0;
    }
    else
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            largo++;
        }
    }
    return largo;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool cadena_copiada = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t largo = cadena_longitud(origen, capacidad - 1);

        for (size_t i = 0; i < largo; i++)
        {
            destino[i] = origen[i];
        }

        destino[largo] = '\0';

        if (origen[largo] == '\0')
        {
            cadena_copiada = true;
        }
    }

    return cadena_copiada;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    bool exito = false;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t largo_dest = cadena_longitud(destino, capacidad);
        size_t largo_origen = cadena_longitud(origen, capacidad);

        if (largo_dest < capacidad)
        {
            size_t largo_copiable = cadena_longitud(origen, capacidad - largo_dest - 1);

            for (size_t i = 0; i < largo_copiable; i++)
            {
                destino[largo_dest + i] = origen[i];
            }

            destino[largo_dest + largo_copiable] = '\0';

            if (largo_copiable == largo_origen)
            {
                exito = true;
            }
        }
    }

    return exito;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    size_t cant_mayus = 0;

    if (cadena != NULL && capacidad > 0)
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            if(cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = cadena[i] - ('a' - 'A');

                cant_mayus++;
            }
        }
    }
    return cant_mayus;
}

bool cadena_subcadena(char destino[], size_t capacidad, const char origen[], size_t inicio, size_t cantidad)
{
    bool porcion_extraida = false;

    if (destino == NULL || origen == NULL || capacidad == 0)
    {
        porcion_extraida = false;
    }
    else
    {
        size_t largo_origen = cadena_longitud(origen, inicio + 1);

        if (inicio >= largo_origen)
        {
            destino = '\0';
            porcion_extraida = true;
        }
        else
        {
            destino = '\0';
            for (size_t i = 0; i < cantidad && i < capacidad - 1 && origen[inicio + i] != '\0'; i++)
            {
                destino[i] = origen[inicio + i];
                destino[i + 1] = '\0';
            }
            porcion_extraida = true;
        }
    }
    return porcion_extraida;
}


