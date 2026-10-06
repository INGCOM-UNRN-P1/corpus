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
    if(cadena == NULL || capacidad == 0)
    {
        return 0;
    }
    size_t contador = 0;
    while(contador < capacidad && cadena[contador] != '\0')
    {
        contador++;
    }
    return contador;
}

bool cadena_copiar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || capacidad == 0)
    {
        return false;
    }
    size_t temp = 0;
    (void)destino;
    while(temp < capacidad - 1 && origen[temp] != '\0')
    {
        destino[temp] = origen[temp];
        temp++;
    }
    destino[temp] = '\0';
    return (origen[temp] == '\0');
}

bool cadena_concatenar(char destino[], size_t capacidad, const char origen[])
{
    if(destino == NULL || capacidad == 0)
    {
        return false;
    }
    size_t largo_d = 0;
        while (largo_d < capacidad && destino[largo_d] != '\0')
        {
            largo_d++;
        }
        if(largo_d == capacidad)
        {
            return false;
        }
    size_t i = 0;
    size_t j = largo_d;
    while(j < capacidad - 1 && origen[i] != '\0')
    {
        destino[j] = origen[i];
        i++;
        j++;
    }
    destino[j] = '\0';
    return (origen[i] == '\0');
}

size_t cadena_a_mayusculas(char cadena[], size_t capacidad)
{
    if(cadena == NULL|| capacidad == 0)
    {
        return 0;
    }
    size_t i = 0;
    size_t conversiones = 0;
    while(i < capacidad && cadena[i] != '\0')
    {
        if(cadena[i] >= 'a' && cadena[i] <= 'z')
        {
            cadena[i] = (char)(cadena[i] - ('a' - 'A'));
            conversiones++;
        }
        i++;
    }
    return conversiones;
}




