#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief calcula el mínimo, máximo y promedio de los valores de un arreglo.
 * @param arreglo es el puntero al inicio de arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param minimo es el puntero donde se guararda el valor minimo del arreglo.
 * @param maximo es el puntero donde se guarda el valor maximo del arreglo.
 * @param promedio es el puntero donde se guarda el promedio del arreglo.
 * 
 * @pre los punteros deben ser válidos y accesibles, 'cantidad' debe ser mayor a 0.
 * 
 * @post si los punteros son válidos, 'minimno' contiene el valor mínimo del arreglo,
 * 'maximo' contiene el valor máximo del arreglo, 'promedio' contiene el promedio
 * del arreglo.
 * 
 * @return true si tuvo éxito, false caso contrario.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * @brief Recorre un arreglo contando cuántos elementos pertenecen a un intervalo
 * cerrado dado.
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es la cantidad de elementos del arreglo.
 * @param limite_inf es el inicio del intervalo.
 * @param limite_sup es el fin del intervalo.
 * @param coincidencias es el puntero que guarda el numero de coincidencias.
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * 
 * @post guarda la cantidad de coincidencias en 'coincidencias'.
 * 
 * @return true si la operación fué exitosa, false caso contrario.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
