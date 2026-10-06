#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"


/**
 * @brief Se utiliza la funcion obtener_min_max para obtener los extremos y
 * calcular el promedio mediante acumulacion arigmetica.
 * @pre 'arreglo', 'minimo', 'maximo' y 'promedio' no peuden ser NULL,
 * o 'capacidad' no puede ser 0.
 * @post Se calcula el promedio y los extremos de los elementos del arreglo.
 * @param arreglo es el arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param minimo es el elemento minimo del arreglo.
 * @param maximo es el elemento maximo del arreglo.
 * @param promedio es el promedio de los elementos dell arreglo.
 * @return Devuelve true si se calculo el promedio y se obtuvieron el minimo y
 * maximo, y false si no se cumple alguna precondicion.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo,
     int *maximo, double *promedio);
/**
 * @brief Se utiliza para contar cuantos elementos pertenecen al intervalo.
 * @pre 'arreglo', 'coincidencias' no pueden ser NULL. 'Capacidad' no
 *  debe ser 0. 'limite_inf' no puede ser mayor a 'limite_sup'.
 * @post Se devuelve true si se calculo el conteo, false si arreglo
 *  o coincidencias son NULL.
 * @param arreglo Es el arreglo.
 * @param cantidad Es la cantidad de elementos del arrelgo.
 * @param limite_inf Es el limite inferior del rango.
 * @param limite_sup Es el limite superior del rango.
 * @param coincidencias Cuantos elementos hay en el rango
 * @return Retorna true si calculó el conteo, o false si arreglo
 *  o coincidencias son NULL.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 