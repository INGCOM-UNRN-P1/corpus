#ifndef ESTADISTICA_H
#define ESTADISTICA_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * Calcula el mínimo, máximo y promedio de un arreglo de enteros.
 * 
 * Se apoya en la función obtener_min_max de libpunteros para determinar los extremos
 * y calcula el promedio acumulando los valores mediante aritmética de punteros.
 * 
 * @param arreglo Puntero constante al primer elemento del arreglo (solo lectura).
 * @param cantidad Número de elementos que contiene el arreglo.
 * @param minimo Puntero donde se almacenará el valor mínimo encontrado.
 * @param maximo Puntero donde se almacenará el valor máximo encontrado.
 * @param promedio Puntero donde se almacenará el valor promedio calculado (tipo double).
 * 
 * @return true Si las estadísticas se calcularon con éxito.
 * @return false Si 'arreglo', 'minimo', 'maximo' o 'promedio' son NULL, o si cantidad == 0.
 * 
 */
bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);

/**
 * Cuenta cuántos elementos de un arreglo se encuentran dentro de un intervalo cerrado.
 * 
 * Recorre el arreglo estrictamente mediante aritmética de punteros evaluando
 * si cada elemento cumple con la condición del rango [limite_inf, limite_sup].
 * 
 * @param arreglo Puntero constante al primer elemento del arreglo (solo lectura).
 * @param cantidad Número de elementos que contiene el arreglo.
 * @param limite_inf Límite inferior del intervalo (inclusive).
 * @param limite_sup Límite superior del intervalo (inclusive).
 * @param coincidencias Puntero donde se almacenará la cantidad de elementos hallados en el rango.
 * 
 * @return true Si el conteo se efectuó con éxito.
 * @return false Si 'arreglo' o 'coincidencias' son NULL.
 * 
 */
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

#endif 
