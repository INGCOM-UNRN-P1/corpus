#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula mínimo, máximo y promedio de un arreglo utilizando punteros.
 *
 * @param arreglo Puntero al arreglo de enteros.
 * @param cantidad Número de elementos en el arreglo.
 * @param minimo Puntero de salida donde se guardará el valor mínimo.
 * @param maximo Puntero de salida donde se guardará el valor máximo.
 * @param promedio Puntero de salida donde se guardará el promedio.
 * @return true si tuvo éxito, false si algún puntero es NULL o cantidad == 0.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta los elementos dentro del intervalo cerrado [limite_inf, limite_sup].
 *
 * @param arreglo Puntero al arreglo.
 * @param cantidad Número de elementos.
 * @param limite_inf Límite inferior del rango inclusive.
 * @param limite_sup Límite superior del rango inclusive.
 * @param coincidencias Puntero de salida donde se guardará el conteo.
 * @return true si calculó el conteo, false si arreglo o coincidencias son NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
