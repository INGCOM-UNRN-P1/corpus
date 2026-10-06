/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL || promedio == NULL)
    {
        return false
    }
    int menor = 0;
    int mayor = 0;
    if (!obtener_min_max(arreglo, cantidad, &menor, &mayor))
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

    *minimo = menor;
    *maximo = mayor;
    *promedio = (double)suma / (double)cantidad;
    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }

    size_t total = 0;
    const int *actual = arreglo;
    const int *fin = arreglo + cantidad;

    while (actual < fin)
    {
        if (*actual >= limite_inf && *actual <= limite_sup)
        {
            total++;
        }
        actual++;
    }

    *coincidencias = total;
    return true;
}
