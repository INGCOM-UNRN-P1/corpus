/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL || minimo == NULL || maximo == NULL || promedio == NULL || cantidad == 0)
    {
        return false;
    }

    if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
    {
        return false;
    }

    long long suma = 0;
    const int *fin = arreglo + cantidad;

    for (const int *p = arreglo; p < fin; p++)
    {
        suma += *p;
    }

    *promedio = (double)suma / (double)cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }

    *coincidencias = 0;
    const int *fin = arreglo + cantidad;

    for (const int *p = arreglo; p < fin; p++)
    {
        if (*p >= limite_inf && *p <= limite_sup)
        {
            (*coincidencias)++;
        }
    }

    return true;
}