#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia los elementos de un arreglo origen a un arreglo destino.
 *
 * @param origen Puntero al primer elemento del arreglo origen.
 * @param destino Puntero al primer elemento del arreglo destino.
 * @param cantidad Cantidad de elementos a copiar.
 *
 * @pre origen y destino no deben ser NULL.
 * @post destino contiene una copia de los elementos de origen.
 *
 * @return true si la copia se realizo correctamente.
 * @return false si origen o destino son NULL.
 */
bool copiar_arreglo(const int *origen, int *destino, size_t cantidad);

/**
 * @brief Invierte los elementos de un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre arreglo no debe ser NULL.
 * @post Los elementos quedan almacenados en orden inverso.
 *
 * @return true si la inversion se realizo correctamente.
 * @return false si arreglo es NULL.
 */
bool invertir_arreglo(int *arreglo, size_t cantidad);

#endif 