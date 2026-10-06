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
    bool estado = false;
    if ((arreglo != NULL) && (minimo != NULL) && (maximo != NULL) && (promedio!= NULL) && (cantidad > 0))
    {
        estado = true;
        long long suma = 0;
        obtener_min_max(arreglo, cantidad, minimo, maximo);
        for (size_t i = 0; i < cantidad; i++)
        {
            suma += *(arreglo + i);
        }
        *promedio = (double)suma / cantidad;
    }
    return estado;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    bool estado = false;
    if ((arreglo != NULL) && (coincidencias != NULL))
    {
        size_t contador = 0;
        estado = true;
        for (size_t i = 0; i < cantidad; i++)
        {
            int valor = *(arreglo + i);
            if( (valor >= limite_inf) && (valor <= limite_sup))
            {
                contador ++;
            }
        }
        *coincidencias = contador;
    }
    return estado;
}
