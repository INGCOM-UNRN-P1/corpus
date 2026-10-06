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
    bool es_valido = false;
    if (arreglo != NULL && cantidad > 0)
    {
        if (promedio != NULL && minimo != NULL && maximo != NULL)
        {
            *minimo = 0;
            *maximo = 0;
            *promedio = 0;
            obtener_min_max(arreglo, cantidad, minimo, maximo);
            const int *inicio = arreglo;
            const int *fin = arreglo + cantidad;
            while(inicio < fin)
            {
                *promedio += *inicio;
                inicio++;
            }
            *promedio = *promedio / cantidad;
            es_valido = true;
        }
    }
    else if (cantidad == 0 && promedio != NULL && minimo != NULL && maximo != NULL)
    {
        *promedio = 0;
        *minimo = 0;
        *maximo = 0;
        es_valido = false;
    }
    return es_valido;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool es_valido = false;
    if (arreglo != NULL && cantidad > 0 && coincidencias != NULL)
    {
        *coincidencias = 0;
        const int *inicio = arreglo;
        const int *fin = arreglo + cantidad;
        while (inicio < fin)
        {
            if (*inicio >= limite_inf && *inicio <= limite_sup)
            {
                (*coincidencias)++;
            }
            inicio++;
        }
        if (*coincidencias >= 0)
        {
            es_valido = true;
        }   
    }
    return es_valido;
}
