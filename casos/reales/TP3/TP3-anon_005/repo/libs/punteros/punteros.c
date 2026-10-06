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
    int auxiliar = 0;

    auxiliar = *segundo;
    *segundo = *primer;
    *primer = auxiliar;
    
    
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    if (arreglo == NULL || minimo == NULL || maximo == NULL || cantidad == 0)
    {
        return false;
    }
    
    *minimo = *arreglo;
    *maximo = *arreglo;

    const int *p = arreglo;
    const int *p_fin = arreglo + cantidad;

    while (p != p_fin)
    {
        if (*p < *minimo)
        {
            *minimo = *p;
        }
        if (*p > *maximo)
        {
            *maximo = *p;
        }
        p++;
    }
    
    return true;
}
