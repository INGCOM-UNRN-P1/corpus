#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"
 
/**
 * @brief Clona un arreglo de enteros en un nuevo bloque de heap.
 *
 * @param origen Arreglo de enteros a clonar.
 * @param cantidad Cantidad de elementos de 'origen'.
 *
 * @pre Si 'origen' no es NULL, debe ser legible en 'cantidad' posiciones.
 * @post 'origen' no se modifica. El nuevo bloque contiene una copia exacta de
 *       'origen' y el llamador es responsable de liberarlo.
 *
 * @return Puntero al bloque clonado, o NULL si 'origen' es NULL, 'cantidad' es 0
 *         o falla la reserva de memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
 
/**
 * @brief Crea en el heap un nuevo arreglo solo con los elementos pares de 'origen'.
 *
 * @param origen Arreglo de enteros a filtrar.
 * @param cantidad_origen Cantidad de elementos de 'origen'.
 * @param cantidad_pares Dirección donde se almacena la cantidad de pares encontrados.
 *
 * @pre Si 'origen' no es NULL, debe ser legible en 'cantidad_origen' posiciones.
 *      'cantidad_pares' no debe ser NULL.
 * @post 'origen' no se modifica. '*cantidad_pares' queda en 0 si no se devuelve
 *       un bloque; en caso contrario contiene la cantidad de elementos del bloque,
 *       que tiene tamaño exacto y debe ser liberado por el llamador.
 *
 * @return Puntero al nuevo bloque con los pares (en su orden original), o NULL si
 *         'origen' o 'cantidad_pares' son NULL, si no hay pares o si falla la
 *         reserva de memoria.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
