/**
 * @file punteros.c
 * @brief Implementación de la biblioteca libpunteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#include "punteros.h"

void intercambiar(int *primer, int *segundo)
{
    if (primer == NULL || segundo == NULL)
    {
        return;
    }
    int auxiliar = *primer;
    *primer = *segundo;
    *segundo = auxiliar;
}

bool obtener_min_max(const int *arreglo, size_t cantidad,
                     int *minimo, int *maximo)
{
    bool entrada_invalida = arreglo == NULL || cantidad == 0;
    bool salida_invalida = minimo == NULL || maximo == NULL;
    if (entrada_invalida == true || salida_invalida == true)
    {
        return false;
    }

    const int *fin = arreglo + cantidad;
    int menor = *arreglo;
    int mayor = *arreglo;
    for (const int *actual = arreglo + 1; actual < fin; actual++)
    {
        if (*actual < menor)
        {
            menor = *actual;
        }
        if (*actual > mayor)
        {
            mayor = *actual;
        }
    }

    *minimo = menor;
    *maximo = mayor;
    return true;
}
