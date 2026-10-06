/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo,
                          int *maximo, double *promedio)
{
    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL ||
        promedio == NULL)
    {
        return false;
    }

    int valor_minimo = 0;
    int valor_maximo = 0;
    long long suma = 0;
    const int *cursor = arreglo;
    const int *fin = arreglo + cantidad;

    if (!obtener_min_max(arreglo, cantidad, &valor_minimo, &valor_maximo))
    {
        return false;
    }

    while (cursor < fin)
    {
        suma += *cursor;
        cursor++;
    }

    *minimo = valor_minimo;
    *maximo = valor_maximo;
    *promedio = (double)suma / (double)cantidad;
    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf,
                     int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }

    size_t total = 0;
    const int *cursor = arreglo;
    const int *fin = arreglo + cantidad;

    while (cursor < fin)
    {
        if (*cursor >= limite_inf && *cursor <= limite_sup)
        {
            total++;
        }
        cursor++;
    }

    *coincidencias = total;
    return true;
}
