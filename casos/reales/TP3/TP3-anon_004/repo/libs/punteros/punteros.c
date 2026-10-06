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
    int temporal = 0;

    if (primer == NULL || segundo == NULL || primer == segundo)
    {
        return;
    }

    temporal = *primer;
    *primer = *segundo;
    *segundo = temporal;
}

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo)
{
    const int *actual = NULL;
    const int *limite = NULL;
    int menor = 0;
    int mayor = 0;

    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL)
    {
        return false;
    }

    menor = *arreglo;
    mayor = *arreglo;
    actual = arreglo + 1;
    limite = arreglo + cantidad;

    while (actual < limite)
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

    *minimo = menor;
    *maximo = mayor;

    return true;
}
