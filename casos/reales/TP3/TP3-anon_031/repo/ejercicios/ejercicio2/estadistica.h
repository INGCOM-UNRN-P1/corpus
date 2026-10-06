#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula el mínimo, máximo y promedio de un arreglo de enteros.
 *
 * Obtiene los valores mínimo y máximo utilizando obtener_min_max de
 * libpunteros y calcula el promedio recorriendo el arreglo mediante
 * aritmética de punteros.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero donde se almacenará el valor mínimo.
 * @param maximo Puntero donde se almacenará el valor máximo.
 * @param promedio Puntero donde se almacenará el promedio.
 *
 * @return true si la operación se realizó correctamente.
 * @return false si arreglo es NULL, cantidad es 0 o alguno de los
 * punteros de salida es NULL.
 *
 * @pre arreglo debe apuntar a una secuencia válida de al menos cantidad
 * elementos cuando cantidad sea mayor que cero.
 *
 * @post Ante éxito, *minimo contiene el menor valor, *maximo el mayor
 * y *promedio el promedio aritmético de los elementos.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta cuántos elementos de un arreglo pertenecen a un rango cerrado.
 *
 * Recorre el arreglo mediante aritmética de punteros y cuenta los valores
 * comprendidos entre limite_inf y limite_sup, inclusive.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param limite_inf Límite inferior del rango.
 * @param limite_sup Límite superior del rango.
 * @param coincidencias Puntero donde se almacenará la cantidad de coincidencias.
 *
 * @return true si la operación se realizó correctamente.
 * @return false si arreglo o coincidencias son NULL.
 *
 * @pre Si cantidad es mayor que cero, arreglo debe apuntar a una secuencia
 * válida de al menos cantidad elementos.
 *
 * @post Ante éxito, *coincidencias contiene la cantidad de elementos
 * pertenecientes al intervalo cerrado [limite_inf, limite_sup].
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
