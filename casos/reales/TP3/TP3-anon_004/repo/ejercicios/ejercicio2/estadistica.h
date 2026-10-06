#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Determina extremos y promedio aritmetico de un arreglo usando punteros y libpunteros.
 *
 * @pre arreglo apunta a una secuencia de enteros valida, minimo, maximo y promedio son punteros no nulos.
 * @post Almacena los extremos y el promedio en sus respectivos punteros y retorna true; retorna false ante parametros invalidos o cantidad 0.
 *
 * @param arreglo  Puntero de solo lectura a la secuencia de enteros.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero de salida para el valor minimo.
 * @param maximo Puntero de salida para el valor maximo.
 * @param promedio Puntero de salida para el promedio aritmetico.
 *
 * @return bool true si se calcularon los estadisticos, false ante error.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta los elementos de un arreglo contenidos en un intervalo cerrado usando punteros.
 *
 * @pre arreglo apunta a una secuencia valida, coincidencias es no nulo y limite_inf <= limite_sup.
 * @post Almacena la cantidad de elementos en rango dentro de *coincidencias y retorna true; false ante punteros nulos o limites invertidos.
 *
 * @param arreglo Puntero de solo lectura a la secuencia de enteros.
 * @param cantidad Cantidad de elementos a evaluar.
 * @param limite_inf Limite inferior inclusivo del rango.
 * @param limite_sup Limite superior inclusivo del rango.
 * @param coincidencias Puntero de salida donde se guardara el total de coincidencias.
 *
 * @return bool true si se contaron coincidencias exitosamente, false en caso contrario.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
