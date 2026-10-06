#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include "vector.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * @brief reserva memoria en el heap mediante calloc/malloc y copia un arreglo.
 * @param origen es el puntero al arreglo origen
 * @param cantidad es la cantidad de lementos del arreglo origen,
 *
 * @pre los punteros deben ser válidos y accesibles.
 *
 * @return el puntero a la copia del arreglo en el heap.NULL si el puntero es
 * inválido, cantidad = 0, o falla malloc/calloc.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief deteremina los elementos pares de un arreglo y los guarda en un
 * arreglo aparte en el heap, además actualiza la variable que cuenta la
 * cantidad de pares en el arreglo.
 * @param origen es el puntero al arreglo origen a analizar.
 * @param cantidad_origen es la cantidad de elementos del arreglo origen.
 * @param cantidad_pares es la cantidad de elementos pares del arreglo.
 *
 * @pre los punteros deben ser válidos y accesibles, cantidad_origen > 0.
 *
 * @return el puntero al nuevo bloque en el heap, NULL ante parámetros
 * inválidos, cantidad_pares = 0 o si falla la memoria.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);
#endif 
