#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Caulcula el minima, maximo y promedio de un arreglo.
 * 
 * @param arreglo_fuente Puntero de solo lectura al inicio del arreglo.
 * @param cantidad_elementos Cantidad de elementos del arreglo.
 * @param puntero_minimo Puntero donde se almacenara el valor minimo.
 * @param puntero_maximo Puntero donde se almacenara el valor maximo.
 * @param puntero_promedio Puntero donde se almacenara el promedio.
 * 
 * @return true Si se calcularon correctamente.
 * @return false Si algun puntero es NULL o la cantidad de elementos es 0.
 */
bool calcular_estadisticas(const int *arreglo_fuente, size_t cantidad_elementos, int *puntero_minimo, int *puntero_maximo, double *puntero_promedio);

/**
 * @brief Cuenta cuantos elementos del arreglo se encuentran dentro de un rango.
 * 
 * @param arreglo_fuente Puntero de solo lectura al inicio del arreglo.
 * @param cantidad_elementos Cantidad de elementos a evaluar en el arreglo.
 * @param limite_inferior Valor minimo del rango.
 * @param limite_superior Valor maximo del rango.
 * @param puntero_coincidencias Puntero donde se almacena la cantidad de elementos encontrados.
 * 
 * @return ture Si se pudo realizar el conteo.
 * @return false Si el arreglo o el puntero de coicidencias son NULL.
 */
bool contador_en_rango(const int *arreglo_fuerte, size_t cantidad_elementos, int limite_inferior, int limite_superior, size_t *puntero_coicidencias);

#endif 
