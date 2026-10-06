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
        int temporal = *primer;
        *primer = *segundo;
        *segundo = temporal;
    }
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    bool valido = false;
    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL)
    {
        int menor = *arreglo;
        int mayor = *arreglo;
        const int *actual = arreglo + 1;
        const int *fin = arreglo + cantidad;

        while (actual < fin)
        {
            if (*actual < menor)
            {
                menor = *actual;
            }
            if (*actual > mayor)
            {
                mayor = *actual;
            }
            actual++;
        }
        *maximo = mayor;
        *minimo = menor;
        valido = true;
    }
    return valido;
}
