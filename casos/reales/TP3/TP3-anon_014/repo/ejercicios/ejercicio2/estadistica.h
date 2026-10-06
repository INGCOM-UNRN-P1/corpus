#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h" 

/**
 * Calcula el mínimo, el máximo y el promedio de un arreglo de enteros.
 * Los extremos se obtienen con obtener_min_max() y el promedio acumulando
 * con aritmética de punteros.
 *
 * @param arreglo  Puntero al primer elemento del arreglo (solo lectura).
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo   Parámetro de salida para el menor valor.
 * @param maximo   Parámetro de salida para el mayor valor.
 * @param promedio Parámetro de salida para el promedio.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @returns true si calculó las tres estadísticas; false si algún puntero es
 *          NULL o si cantidad es 0.
 *
 * @post Si retorna true, las tres salidas quedan cargadas. Si retorna false,
 *       no se modifica ninguna salida.
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad,
                           int *minimo, int *maximo, double *promedio);

/**
 * Cuenta cuántos elementos del arreglo pertenecen al intervalo cerrado
 * [limite_inf, limite_sup].
 *
 * @param arreglo       Puntero al primer elemento del arreglo (solo lectura).
 * @param cantidad      Cantidad de elementos del arreglo.
 * @param limite_inf    Límite inferior del intervalo (incluido).
 * @param limite_sup    Límite superior del intervalo (incluido).
 * @param coincidencias Parámetro de salida para la cantidad encontrada.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @returns true si calculó el conteo; false si arreglo o coincidencias son
 *          NULL.
 *
 * @post Si retorna true, *coincidencias tiene la cantidad de elementos
 *       dentro del intervalo (0 si limite_inf > limite_sup).
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf,
                     int limite_sup, size_t *coincidencias);

#endif 
