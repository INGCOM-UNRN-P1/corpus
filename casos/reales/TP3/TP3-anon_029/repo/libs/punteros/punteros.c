/**
 * @file punteros.c
 * @brief Esqueleto de implementación para la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if (primer == NULL || segundo == NULL)
    {
        return;
    }
    if (primer == segundo)
    {
        return;
    }
    
    int auxiliar = 0;
    auxiliar = *primer;
    *primer = *segundo;
    *segundo = auxiliar;
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    int *puntero = arreglo;
    int *fin = arreglo + cantidad;
    if (arreglo == NULL || cantidad <= 0 || minimo == NULL || maximo == NULL)
    {
        return false;
    }

    *minimo = *puntero;
    *maximo = *puntero;
    
    while (puntero < fin)
    {
        if (*puntero <= *minimo)
        {
            *minimo = *puntero;
        }
        else if (*puntero >= *maximo)
        {
            *maximo = *puntero;
        }
        puntero ++;
    }
     
    return true;
}
