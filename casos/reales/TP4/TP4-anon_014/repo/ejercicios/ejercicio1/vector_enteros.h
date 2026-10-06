#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 * @brief Copia un arreglo de enteros en un bloque nuevo en heap.
 * @param origen arreglo a copiar.
 * @param cantidad cantidad de elementos de origen.
 * @pre origen tiene al menos 'cantidad' elementos.
 * @returns el bloque nuevo, o NULL si origen es NULL, cantidad es 0 o falla
 *          la memoria.
 * @post el llamador libera el bloque con liberar_bloque_enteros.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Copia los elementos pares de origen en un bloque de tamaño exacto.
 * @param origen arreglo a filtrar.
 * @param cantidad_origen cantidad de elementos de origen.
 * @param cantidad_pares salida: cantidad de pares copiados (0 si no hay).
 * @pre origen tiene al menos cantidad_origen elementos.
 * @returns el bloque nuevo, o NULL si no hay pares, algún puntero es NULL o
 *          falla la memoria.
 * @post el llamador libera el bloque con liberar_bloque_enteros.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

/**
 * @brief Copia un bloque de enteros en heap (nombre usado en el README).
 * @param origen bloque a copiar.
 * @param n cantidad de elementos de origen.
 * @returns el bloque nuevo, o NULL si origen es NULL, n es 0 o falla la
 *          memoria.
 * @post el llamador libera el bloque con liberar_bloque_enteros.
 */
int *clonar_bloque(const int *origen, size_t n);

/**
 * @brief Copia los elementos mayores a cero en un bloque de tamaño exacto.
 * @param origen bloque a filtrar.
 * @param n cantidad de elementos de origen.
 * @param cantidad_positivos salida: cantidad de positivos copiados.
 * @returns el bloque nuevo, o NULL si no hay positivos, algún puntero es
 *          NULL o falla la memoria.
 * @post el llamador libera el bloque con liberar_bloque_enteros.
 */
int *filtrar_bloque_positivos(const int *origen, size_t n,
                              size_t *cantidad_positivos);

#endif 
