/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad,
                           int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL || cantidad == 0 ||
        minimo == NULL || maximo == NULL || promedio == NULL)
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
        suma = suma + *actual;
        actual++;
    }

    *promedio = (double)suma / cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad,
                     int limite_inf, int limite_sup,
                     size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }

    *coincidencias = 0;

    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        if (*actual >= limite_inf && *actual <= limite_sup)
        {
            (*coincidencias)++;
        }

        actual++;
    }

    return true;
}
