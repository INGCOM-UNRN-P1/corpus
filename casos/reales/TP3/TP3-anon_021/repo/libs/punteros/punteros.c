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
    if (primer != NULL && segundo != NULL)
    {
        int temporal = 0;
        temporal = *primer;
        *(primer) = *(segundo);
        *(segundo)= temporal;
    } 
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    bool resultado = false;
    if (arreglo == NULL || minimo == NULL || maximo == NULL || cantidad == 0)
    {
        resultado = false;
    }
    else
    {
        resultado = true;
        const int *temporal = NULL;   //seria el primer valor actual
        const int *limite = NULL;
        temporal = arreglo;
        limite = arreglo + cantidad;

        *minimo = *temporal;    //inicializo con primer valor
        *maximo = *temporal;

        while (temporal < limite)
        {
            if (*temporal < *minimo)
            {
                *minimo = *temporal;
            }
            else if (*temporal > *maximo)
            {
                *maximo = *temporal;
            }
            temporal ++; //avanzo en la siguiente posicion de memoria       
        }
    }
    return resultado;
}
