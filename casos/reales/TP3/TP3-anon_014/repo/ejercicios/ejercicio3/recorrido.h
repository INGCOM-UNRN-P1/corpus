#ifndef RECORRIDO_H
#define RECORRIDO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Copia 'cantidad' enteros desde 'origen' hacia 'destino' avanzando ambos
 * punteros, sin usar el operador [].
 *
 * @param destino  Puntero al primer elemento del arreglo destino.
 * @param origen   Puntero al primer elemento del arreglo origen (solo
 *                 lectura).
 * @param cantidad Cantidad de elementos a copiar.
 *
 * @pre 'destino' tiene lugar para al menos 'cantidad' elementos.
 * @pre 'origen' tiene al menos 'cantidad' elementos.
 * @pre Los arreglos no se superponen en memoria.
 *
 * @returns true si realizó la copia; false si destino u origen son NULL.
 *
 * @post Si retorna true, los primeros 'cantidad' elementos de destino son
 *       iguales a los de origen. El origen no se modifica.
 */
bool copiar_arreglo(int *destino, const int *origen, size_t cantidad);

/**
 * Invierte in-place un arreglo de enteros con dos punteros que avanzan
 * desde los extremos hacia el centro, usando intercambiar().
 *
 * @param arreglo  Puntero al primer elemento del arreglo. Puede ser NULL.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @post Si arreglo no es NULL, el elemento que estaba en la posición k
 *       queda en la posición cantidad - 1 - k. Si es NULL, no hace nada.
 */
void invertir_arreglo(int *arreglo, size_t cantidad);

#endif 
