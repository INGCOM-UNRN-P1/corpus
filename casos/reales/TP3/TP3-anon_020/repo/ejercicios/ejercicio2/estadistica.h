#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Calcula el mínimo, el máximo y el promedio de un arreglo.
 *
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Número de elementos válidos del arreglo.
 * @param minimo Puntero a la variable que recibirá el valor mínimo.
 * @param maximo Puntero a la variable que recibirá el valor máximo.
 * @param promedio Puntero a la variable que recibirá el promedio.
 *
 * @return true si la operación tuvo éxito; false si algún parámetro requerido
 *         es NULL o si la cantidad es cero.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo,
                          int *maximo, double *promedio);

/**
 * @brief Cuenta cuántos elementos de un arreglo caen dentro de un rango.
 *
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Número de elementos del arreglo.
 * @param limite_inf Límite inferior del rango cerrado.
 * @param limite_sup Límite superior del rango cerrado.
 * @param coincidencias Puntero donde se guarda el total de elementos contados.
 *
 * @return true si el conteo se realizó correctamente; false si arreglo o
 *         coincidencias son NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf,
                    int limite_sup, size_t *coincidencias);

#endif 
