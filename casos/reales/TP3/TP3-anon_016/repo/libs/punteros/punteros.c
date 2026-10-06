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
    int temp = 0;
    if (primer == NULL || segundo == NULL)
    {
        return;
    }
    else if(primer == segundo)
    {
        return;
    }
    else
    {
        temp = *primer;
        *primer = *segundo;
        *segundo = temp;
    }
    
}



bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    if(arreglo == NULL || cantidad == 0
       || minimo == NULL || maximo == NULL)
       {
        return false;
       }

    *maximo = *arreglo;
    *minimo = *arreglo;
    const int *actual = arreglo + 1;
    const int *fin = arreglo + cantidad;
        
    while(actual != fin)
    {
       if(*actual > *maximo )
       {
            *maximo = *actual;
       }
       if(*actual < *minimo)
      {
           *minimo = *actual;
      }
      actual++;
    }
    return true;

}

