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
    if(primer == NULL || segundo == NULL)
    {
        return;
    }
    
    if(primer == segundo)
    {
       return;
    }

    int aux = *primer;
    *primer = *segundo;
    *segundo = aux;
}


bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    if(arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL)
    {
        return false;
    }
    
    *minimo = arreglo[0];
    *maximo = arreglo[0];

    for (size_t i = 1; i < cantidad; i++) 
    {
        if (arreglo[i] < *minimo) 
        {
            *minimo = arreglo[i];
        }

        if (arreglo[i] > *maximo) 
        {
            *maximo = arreglo[i];
        }
    }
    
    return true;
}
