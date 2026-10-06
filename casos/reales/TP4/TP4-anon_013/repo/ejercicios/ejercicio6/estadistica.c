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
        return false;
    }
    else
    {
        obtener_min_max(arreglo, cantidad, minimo, maximo);

        long long suma = 0;
        const int *inicio = arreglo;
        const int *fin = arreglo + cantidad;
        while (inicio < fin)
        {
            suma = suma + *inicio;
            inicio++;
        }
        *promedio = (double)suma / (double)cantidad;
        return true;
    }
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL)
    {
        return false;
    }
    else
    {
        *coincidencias = 0;
        for (size_t i = 0; i < cantidad; i++)
        {
            if (*(arreglo + i) >= limite_inf && *(arreglo + i) <= limite_sup)
            {
                (*coincidencias)++;     // Acá se me rompía porque faltaban paréntesis, sin paréntesis el ++ afecta al puntero, no al valor que contiene.
            }
        }
        return true;
    }
}
