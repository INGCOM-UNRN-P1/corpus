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
    const int *actual = NULL;
    const int *limite = NULL;
    long long suma = 0LL;

    if (arreglo == NULL || cantidad == 0 || minimo == NULL || maximo == NULL || promedio == NULL)
    {
        return false;
    }

    if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
    {
        return false;
    }

    actual = arreglo;
    limite = arreglo + cantidad;

    while (actual < limite)
    {
        suma += *actual;
        actual++;
    }

    *promedio = (double)suma / (double)cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    const int *actual = NULL;
    const int *limite = NULL;
    size_t contador = 0;

    if (arreglo == NULL || coincidencias == NULL || limite_inf > limite_sup)
    {
        return false;
    }

    actual = arreglo;
    limite = arreglo + cantidad;

    while (actual < limite)
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
