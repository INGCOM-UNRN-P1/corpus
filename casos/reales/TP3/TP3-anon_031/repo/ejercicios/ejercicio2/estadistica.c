/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * No se utilizan ALV ni memoria dinámica.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    bool operacion_exitosa = false;

    if (arreglo != NULL && cantidad > 0 && minimo != NULL && maximo != NULL && promedio != NULL)
    {
        if (obtener_min_max(arreglo, cantidad, minimo, maximo))
        {
            const int *actual = arreglo;
            const int *fin = arreglo + cantidad;
            long long suma = 0;

            while (actual < fin)
            {
                suma += *actual;
                actual++;
            }

            *promedio = (double)suma / (double)cantidad;
            operacion_exitosa = true;
        }
    }

    return operacion_exitosa;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool operacion_exitosa = false;

    if (arreglo != NULL && coincidencias != NULL)
    {
        const int *actual = arreglo;
        const int *fin = arreglo + cantidad;
        size_t total = 0;

        while (actual < fin)
        {
            if (*actual >= limite_inf && *actual <= limite_sup)
            {
                total++;
            }

            actual++;
        }

        *coincidencias = total;
        operacion_exitosa = true;
    }

    return operacion_exitosa;
}
