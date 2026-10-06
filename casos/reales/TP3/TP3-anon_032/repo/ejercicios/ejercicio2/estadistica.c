/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"


bool calcular_estadisticas(
    const int *arreglo, size_t cantidad,
    int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL ||
        cantidad == 0 ||
        minimo == NULL ||
        maximo == NULL ||
        promedio == NULL)
    {
        return false;
    }

    obtener_min_max(arreglo, cantidad, minimo, maximo);

    int sumatoria = 0;
    for (size_t i = 0; i < cantidad; i++)
    {
        sumatoria += *(arreglo + i);
    }
    *promedio = sumatoria / cantidad;

    return true;
}


bool contar_en_rango(
    const int *arreglo, size_t cantidad, int limite_inf, int limite_sup,
    size_t *coincidencias)
{
    if (arreglo == NULL ||
        cantidad == 0 ||
        coincidencias == NULL ||
        limite_inf >= limite_sup)
    {
        return false;
    }

    *coincidencias = 0;

    for (size_t i = 0; i < cantidad; i++)
    {
        int elemento = *(arreglo + i);
        if (elemento >= limite_inf && limite_sup >= elemento)
        {
            (*coincidencias)++;
        }
    }

    return true;
}
