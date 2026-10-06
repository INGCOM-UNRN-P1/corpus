#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Busca el puntero al elemento con valor mínimo en un rango [inicio, fin).
 *
 * @param inicio Puntero al comienzo del rango.
 * @param fin Puntero al final del rango (exclusivo).
 * @return const int* Puntero al elemento mínimo, o NULL si el rango/punteros son inválidos.
 */
const int *buscar_puntero_minimo(const int *inicio, const int *fin);

/**
 * @brief Ordena ascendentemente un arreglo de enteros utilizando el algoritmo de selección.
 * No utiliza el operador [] de indexación.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos en el arreglo.
 * @return true si el ordenamiento se realizó exitosamente, false en caso de parámetros inválidos.
 */
bool ordenar_seleccion_punteros(int *arreglo, size_t cantidad);

#endif 
