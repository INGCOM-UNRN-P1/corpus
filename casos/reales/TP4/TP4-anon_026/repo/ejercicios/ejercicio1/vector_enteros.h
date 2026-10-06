#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"




 /**
 * @brief Clona un arreglo de enteros en un nuevo bloque del heap.
 *
 * Reserva exactamente @p cantidad enteros y copia en ellos los elementos de
 * @p origen. El arreglo origen no se modifica.
 *
 * @param origen Arreglo de enteros a clonar.
 * @param cantidad Cantidad de elementos de @p origen.
 * @return Puntero al nuevo bloque en heap, o NULL si @p origen es NULL,
 *         @p cantidad es 0 o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con liberar_bloque_enteros().
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los números pares de un arreglo en un nuevo bloque del heap de tamaño exacto.
 *
 * Cuenta los elementos pares de @p origen, reserva exactamente esa cantidad de
 * enteros, copia los pares conservando su orden y actualiza @p cantidad_pares.
 * El arreglo origen no se modifica.
 *
 * @param origen Arreglo de enteros a filtrar.
 * @param cantidad_origen Cantidad de elementos de @p origen.
 * @param[out] cantidad_pares Recibe la cantidad de pares copiados. Vale 0 si
 *             no hay pares o si ocurre un error.
 * @return Puntero al nuevo bloque en heap con los pares, o NULL si @p origen es NULL,
 *         @p cantidad_origen es 0, @p cantidad_pares es NULL, no hay pares o falla
 *         la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con liberar_bloque_enteros().
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
