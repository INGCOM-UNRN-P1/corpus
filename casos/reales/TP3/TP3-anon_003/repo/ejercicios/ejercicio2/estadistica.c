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

    if(arreglo == NULL || minimo ==NULL || maximo == NULL ||promedio == NULL || cantidad == 0){
    return false;
    }
    
    obtener_min_max(arreglo, cantidad, minimo, maximo);
    
    int suma_arreglo = 0;
    const int *ptr = arreglo;
    const int *ptr_fin = arreglo + cantidad;
    while (ptr < ptr_fin){
        suma_arreglo = suma_arreglo + *ptr;
        ptr++;
    }  

    *promedio = (double)suma_arreglo / cantidad;
    
    return true;
}

bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias)
{

    if(arreglo == NULL || coincidencias == NULL){
        return false;
    }
    const int *ptr = arreglo;
    const int *fin_ptr = arreglo + cantidad;
    *coincidencias = 0;
    while(ptr < fin_ptr){
        if (*ptr >= limite_inf && *ptr <=limite_sup){
            (*coincidencias)++;
        }
        ptr++;
    }
    return true;

}
