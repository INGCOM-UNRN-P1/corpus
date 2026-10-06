#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Busca el menor valor dentro de un rango de enteros.
 *
 * @param inicio Puntero al primer elemento del rango.
 * @param fin Puntero al final del rango, no incluído.
 *
 * @return Puntero al elemento mínimo del rango, o NULL si el rango es inválido.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena un arreglo de enteros con selección usando punteros.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @return true si la ordenación fue exitosa; false si el arreglo es NULL.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
