#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"



/**
 * @brief Calcula de un arreglo, el valor minimo, maximo y el promedio de todos los elementos.
 *          los parametros ingresados no deben ser igual a NULL.
 * @param arreglo[int] arreglo de enteros.
 * @param cantidad[size_t] cantidad de elementos en el arreglo.
 * @param minimo[in] entero que marca el valor mas bajo al que buscar coincidencias.
 * @param maximo[in] entero que marca el valor mas alto al que buscar coincidencias
 * @param promedio[in] puntero al que se le da el valor total de coincidencias
 * @return true si se pudo realizar todas las estadisticas.
 *         false si los parametros son NULL, cantidad es 0.
 *          minimo[out], maximo[out], promedio[out] resultados de los calculos mediante su direccion
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);
/**
 * @brief Evalua los valores ingresados y realiza un intercambio en memoria.
 *          los parametros ingresados no deben ser igual a NULL.
 * @param arreglo[int] arreglo de enteros.
 * @param cantidad[size_t] cantidad de elementos en el arreglo.
 * @param limite_inf entero que marca el valor mas bajo al que buscar coincidencias.
 * @param limite_sup entero que marca el valor mas alto al que buscar coincidencias
 * @param coincidencias puntero al que se le da el valor total de coincidencias
 * @return true si se pudo realizar un conteo de coincidencias.
 *         false si los parametros son NULL, cantidad es 0 o si no se encontraron coincidencias.
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);
#endif 
