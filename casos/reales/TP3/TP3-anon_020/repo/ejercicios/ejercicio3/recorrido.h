#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>
#include "punteros.h"

/**
 * @brief Copia una cantidad de enteros desde un arreglo origen a otro destino.
 *
 * @param origen Puntero al primer elemento del arreglo fuente.
 * @param destino Puntero al primer elemento del arreglo destino.
 * @param cantidad Cantidad de elementos a copiar.
 *
 * @return true si se copiaron todos los elementos; false si origen o destino
 *         son NULL.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief Invierte in-place los elementos de un arreglo de enteros.
 *
 * @param arreglo Puntero al inicio del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @return true si la inversión fue exitosa; false si arreglo es NULL.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
