/**
 * @file estadistica.c
 * @brief Implementación de estadísticas y filtrado por rango con punteros.
 *
 * Observación:
 * Recuerden que no está permitido utilizar ALV's, pero también, este ejercicio
 * no está pensado para utilizar memoria dinámica.
 */

#include "estadistica.h"
#include "punteros.h"



bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio)
{
    if (arreglo == NULL || minimo == NULL || maximo == NULL || promedio == NULL || cantidad == 0){
        return false;
    }
    int min_val = *arreglo;
    int max_val = *arreglo;
    long long suma = 0;

    const int *puntero_final = arreglo + cantidad;
    for (const int *actual = arreglo; actual < puntero_final; actual++) {
        if (*actual < min_val) {
            min_val = *actual;
        }
        if (*actual > max_val) {
            max_val = *actual;
        }
        suma += *actual;
    }

    *minimo = min_val;
    *maximo = max_val;
    *promedio = (double)suma / cantidad;

    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{
    if (arreglo == NULL || coincidencias == NULL || limite_inf > limite_sup) {
        return false;
    }

    size_t contador = 0;
    const int *puntero_final = arreglo + cantidad;

    for (const int *puntero_actual = arreglo; puntero_actual < puntero_final; puntero_actual++) {
        if (*puntero_actual >= limite_inf && *puntero_actual <= limite_sup) {
            contador++;
        }
    }

    *coincidencias = contador;
    return true;
}
