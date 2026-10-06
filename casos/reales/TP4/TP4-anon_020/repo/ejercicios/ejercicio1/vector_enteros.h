#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stddef.h>
#include "vector.h"

/**
 * @brief Clona un bloque de enteros en un nuevo arreglo dinámico.
 * @param origen Puntero al bloque de entrada.
 * @param cantidad Cantidad de elementos del bloque de entrada.
 * @pre origen no es NULL y cantidad es mayor que cero.
 * @post Se devuelve un nuevo bloque con los mismos elementos en el heap.
 * @note La memoria devuelta debe liberarse con liberar_bloque_enteros(&puntero)
 *       o con free() sobre el puntero recibido.
 * @returns Un puntero a la copia en heap o NULL si los datos son inválidos o
 *          falla la reserva.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los valores pares de un bloque y devuelve un nuevo bloque.
 * @param origen Puntero al bloque de entrada.
 * @param cantidad_origen Cantidad de elementos del bloque de entrada.
 * @param cantidad_pares Puntero de salida con la cantidad de elementos pares.
 * @pre origen no es NULL, cantidad_origen es mayor que cero y cantidad_pares
 *      no es NULL.
 * @post Si existen pares, se devuelve un nuevo bloque con solo los valores pares.
 * @note El arreglo resultante debe liberarse de la misma forma que cualquier bloque
 *       dinámico de enteros: liberar_bloque_enteros(&puntero) o free().
 * @returns Un nuevo bloque de enteros con los pares o NULL si no hay pares,
 *          si los datos son inválidos o si falla la reserva.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

#endif 
