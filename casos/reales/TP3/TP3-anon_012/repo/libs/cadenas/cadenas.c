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
    
    size_t i = 0;
    if (cadena != NULL && capacidad > 0)
    {
        while (i < capacidad && cadena[i] != 0)
        {
            i++;
        }
    }

    return i;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    bool copiado_completo = false;
    size_t i = 0;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        while (i < capacidad - 1 && origen[i] != '\0')
        {
            destino[i] = origen[i];
            i++;
        }

        destino[i] = '\0';

        if (origen[i] == '\0')
        {
            copiado_completo = true;
        }
    }

    return copiado_completo;
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    
    bool concatenado_completo = true;

    if (destino != NULL && origen != NULL && capacidad > 0)
    {
        size_t len_destino = cadena_longitud(destino, capacidad);

        if (len_destino < capacidad)
        {
            size_t espacio_restante = capacidad - len_destino;
            concatenado_completo = cadena_copiar(&destino[len_destino], espacio_restante, origen);
        }
    }

    return concatenado_completo;
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    
    size_t convertidos = 0;

    if (cadena != NULL && capacidad > 0)
    {
        for (size_t i = 0; i < capacidad && cadena[i] != '\0'; i++)
        {
            if (cadena[i] >= 'a' && cadena[i] <= 'z')
            {
                cadena[i] = (char)(cadena[i] - ('a' - 'A'));
                convertidos++;
            }
        }   
    }

    return convertidos;
}




