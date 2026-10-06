/**
 * @file estadistica.c
 * @brief Implementacion de estadisticas y filtrado por rango con punteros.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL || promedio == NULL)
    {
        return false;
    }

    if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
    {
        return false;
    }

    long long suma = 0;
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        suma += *actual;
        actual++;
    }

    *promedio = (double)suma / (double)cantidad;
    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    if (coincidencias == NULL)
    {
        return false;
    }

    if (cantidad == 0)
    {
        *coincidencias = 0;
        return true;
    }

    if (arreglo == NULL)
    {
        return false;
    }

    size_t contador = 0;
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        if (*actual >= limite_inf && *actual <= limite_sup)
        {
            contador++;
        }
        actual++;
    }

    *coincidencias = contador;
    return true;
}
