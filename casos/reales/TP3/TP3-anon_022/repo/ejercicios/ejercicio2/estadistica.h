#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"




/**
 * @brief Calcula el mínimo, máximo y promedio de los elementos de un arreglo.
 *
 * @pre 'arreglo' debe apuntar a un arreglo válido de 'cantidad' elementos.
 *      'minimo', 'maximo' y 'promedio' deben apuntar a variables válidas.
 *      'cantidad' debe ser mayor que 0.
 *
 * @post Si la operación tiene éxito, 'minimo' contiene el menor elemento,
 *       'maximo' contiene el mayor elemento y 'promedio' contiene el promedio
 *       aritmético de los elementos del arreglo.
 *
 * @param arreglo de enteros cuyos valores se desean analizar.
 * @param cantidad de elementos válidos del arreglo.
 * @param minimo Puntero donde se almacenará el valor mínimo.
 * @param maximo Puntero donde se almacenará el valor máximo.
 * @param promedio Puntero donde se almacenará el promedio aritmético.
 *
 * @return true si se calcularon correctamente las estadísticas.
 *         false si algún puntero es NULL o 'cantidad' es 0.
 */
bool calcular_estadisticas(const int *arreglo,
                           size_t cantidad,
                           int *minimo,
                           int *maximo,
                           double *promedio);

/**
 * @brief Cuenta los elementos de un arreglo que pertenecen a un rango cerrado.
 *
 * @pre 'arreglo' debe apuntar a un arreglo válido de 'cantidad' elementos.
 *      'coincidencias' debe apuntar a una variable válida.
 *
 * @post Si la operación tiene éxito, 'coincidencias' contiene la cantidad
 *       de elementos pertenecientes al intervalo cerrado
 *       ['limite_inf', 'limite_sup'].
 *
 * @param arreglo de enteros que se desea recorrer.
 * @param cantidad de elementos válidos del arreglo.
 * @param limite_inf Límite inferior del intervalo.
 * @param limite_sup Límite superior del intervalo.
 * @param coincidencias Puntero donde se almacenará el conteo.
 *
 * @return true si se calculó correctamente el conteo.
 *         false si 'arreglo' o 'coincidencias' es NULL.
 */
bool contar_en_rango(const int *arreglo,
                     size_t cantidad,
                     int limite_inf,
                     int limite_sup,
                     size_t *coincidencias);

#endif 