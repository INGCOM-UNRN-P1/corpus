/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"



bool calcular_estadisticas(const int *arreglo_fuente, size_t cantidad_elementos, int *puntero_minimo, int *puntero_maximo, double *puntero_promedio)
{
    if (arreglo_fuente == NULL || puntero_minimo == NULL || puntero_maximo == NULL || puntero_promedio == NULL || cantidad_elementos == 0)
    {
        return false;
    }

    if (!obtener_min_max(arreglo_fuente, cantidad_elementos, puntero_minimo, puntero_maximo))
    {
        return false;
    }

    long long suma_total = 0;
    const int *cursor_actual = arreglo_fuente; 

    for (size_t elementos_procesados = 0; elementos_procesados < cantidad_elementos; elementos_procesados++)
    {
    suma_total += *cursor_actual;
    cursor_actual++;
    }

    *puntero_promedio = (double)suma_total / cantidad_elementos;
    
    return true;

}

bool contar_en_rango(const int *arreglo_fuente, size_t cantidad_elementos, int limite_inferior, int limite_superior, size_t *puntero_coincidencias)
{
    if (arreglo_fuente == NULL || puntero_coincidencias == NULL)
    {
        return false;
    }

    *puntero_coincidencias = 0;

    const int *cursor_actual = arreglo_fuente;

    for (size_t elementos_procesados = 0; elementos_procesados < cantidad_elementos; elementos_procesados++)
    {
        if (*cursor_actual >= limite_inferior && *cursor_actual <= limite_superior)
        {
            (*puntero_coincidencias)++;
        }
        cursor_actual++;
    }
    return false;
}