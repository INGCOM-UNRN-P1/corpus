#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula el mínimo, máximo y promedio de un arreglo de enteros.
 * 
 * @pre 'arreglo' no debe ser NULL. 'cantidad' debe ser mayor a 0.
 *      Los punteros 'minimo', 'maximo' y 'promedio' no deben ser NULL.
 * @post 'minimo' y 'maximo' se actualizan usando obtener_min_max. 
 *       'promedio' almacena la media aritmética exacta del arreglo.
 * 
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos válidos a evaluar.
 * @param minimo Puntero a la variable donde se guardará el valor mínimo.
 * @param maximo Puntero a la variable donde se guardará el valor máximo.
 * @param promedio Puntero a la variable donde se guardará el promedio (double).
 * @return true si las estadísticas se calcularon con éxito.
 * @return false si falla alguna precondición (punteros NULL o cantidad 0).
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Cuenta cuántos elementos caen dentro de un rango inclusivo cerrado.
 * 
 * @pre 'arreglo' y 'coincidencias' no deben ser NULL.
 * @post 'coincidencias' almacena el total de elementos en el intervalo [limite_inf, limite_sup].
 * 
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Cantidad total de elementos a procesar.
 * @param limite_inf Límite inferior del rango (inclusivo).
 * @param limite_sup Límite superior del rango (inclusivo).
 * @param coincidencias Puntero a la variable que guardará el conteo final.
 * @return true si la operación finalizó exitosamente.
 * @return false si 'arreglo' o 'coincidencias' son nulos.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 