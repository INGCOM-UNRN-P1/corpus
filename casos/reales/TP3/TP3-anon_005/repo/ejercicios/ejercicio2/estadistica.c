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
    if (arreglo == NULL || minimo == NULL || maximo == NULL || promedio == NULL || cantidad == 0)
    {
        return false;
    }

    if (!obtener_min_max(arreglo, cantidad, minimo, maximo))
    {
        return false;
    }

    const int *p = arreglo;
    const int *fin = arreglo + cantidad;
    double suma = 0;
    
    while (p != fin)
    {
        suma += *p; 
        p++;
    }

    *promedio = suma / cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    (void)arreglo;
    (void)cantidad;
    (void)limite_inf;
    (void)limite_sup;
    (void)coincidencias;
    if (arreglo == NULL || limite_inf == NULL || limite_sup == NULL || cantidad == 0)
    {
        return false;
    }
    return false;
}
