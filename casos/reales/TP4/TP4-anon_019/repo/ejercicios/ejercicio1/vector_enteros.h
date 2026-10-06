#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Clona un arreglo de enteros reservando memoria en el heap.
 *
 * @param[in] origen Puntero constante al arreglo de origen.
 * @param[in] cantidad Cantidad de elementos a copiar.
 * @return int* Puntero al nuevo arreglo clonado, o NULL en caso de error.
 *
 * #PRE 'origen' no debe ser NULL y 'cantidad' debe ser mayor a 0.
 * #POST Retorna un nuevo bloque en el heap que es una copia de 'origen'.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra los numeros pares de un arreglo y los copia a un nuevo bloque en el heap.
 *
 * @param[in] origen Puntero constante al arreglo de origen.
 * @param[in] cantidad_origen Cantidad de elementos en el arreglo de origen.
 * @param[out] cantidad_pares Puntero de salida donde se almacenara la cantidad de pares encontrados.
 * @return int* Puntero al nuevo bloque con los numeros pares, o NULL en caso de error o arreglo vacio.
 *
 * #PRE 'origen' y 'cantidad_pares' no deben ser NULL. 'cantidad_origen' debe ser mayor a 0.
 * #POST Retorna un bloque en el heap con los valores pares y actualiza 'cantidad_pares'.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 