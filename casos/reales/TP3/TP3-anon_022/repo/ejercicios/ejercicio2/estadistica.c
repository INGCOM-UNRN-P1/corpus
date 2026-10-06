/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo,
                           size_t cantidad,
                           int *minimo,
                           int *maximo,
                           double *promedio)
{
    if (arreglo == NULL ||
        cantidad == 0 ||
        minimo == NULL ||
        maximo == NULL ||
        promedio == NULL)
    {
        return false;
    }

    if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
    {
        return false;
    }

    long long suma = 0;
    const int *puntero = arreglo;

    for (size_t i = 0; i < cantidad; i++)
    {
        suma += *puntero;
        puntero++;
    }

    *promedio = (double)suma / cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo,
                     size_t cantidad,
                     int limite_inf,
                     int limite_sup,
                     size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }

    *coincidencias = 0;

    const int *puntero = arreglo;

    for (size_t i = 0; i < cantidad; i++)
    {
        if (*puntero >= limite_inf && *puntero <= limite_sup)
        {
            (*coincidencias)++;
        }

        puntero++;
    }

    return true;
}