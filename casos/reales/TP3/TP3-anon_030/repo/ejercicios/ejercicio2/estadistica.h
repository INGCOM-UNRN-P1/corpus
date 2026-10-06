#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula el minimo, maximo y promedio de un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero donde se guarda el valor minimo.
 * @param maximo Puntero donde se guarda el valor maximo.
 * @param promedio Puntero donde se guarda el promedio.
 *
 * @pre arreglo, minimo, maximo y promedio no deben ser NULL.
 * @pre cantidad debe ser mayor que cero.
 * @post minimo, maximo y promedio contienen los valores calculados.
 *
 * @return true si se pudieron calcular las estadisticas.
 * @return false si algun puntero es NULL o cantidad es cero.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad,
                           int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta cuantos elementos se encuentran dentro de un rango.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param limite_inf Limite inferior del rango.
 * @param limite_sup Limite superior del rango.
 * @param coincidencias Puntero donde se guarda la cantidad de coincidencias.
 *
 * @pre arreglo y coincidencias no deben ser NULL.
 * @post coincidencias contiene la cantidad de valores dentro del rango.
 *
 * @return true si el conteo se realizo correctamente.
 * @return false si arreglo o coincidencias son NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad,
                     int limite_inf, int limite_sup,
                     size_t *coincidencias);

#endif 