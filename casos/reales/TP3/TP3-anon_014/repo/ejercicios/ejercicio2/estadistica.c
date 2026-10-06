/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 */

#include "estadistica.h"

bool calcular_estadisticas(const int *arreglo, size_t cantidad,
                           int *minimo, int *maximo, double *promedio)
{
    // Se valida antes de llamar a obtener_min_max para no dejar el mínimo y
    // el máximo escritos cuando la función igual va a fallar.
    if (promedio == NULL)
    {
        return false;
    }
    if (obtener_min_max(arreglo, cantidad, minimo, maximo) == false)
    {
        return false;
    }

    long long suma = 0;
    const int *fin = arreglo + cantidad;
    for (const int *actual = arreglo; actual < fin; actual++)
    {
        suma = suma + *actual;
    }

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

    size_t contador = 0;
    const int *fin = arreglo + cantidad;
    for (const int *actual = arreglo; actual < fin; actual++)
    {
        if (*actual >= limite_inf && *actual <= limite_sup)
        {
            contador++;
        }
    }

    *coincidencias = contador;
    return true;
}
