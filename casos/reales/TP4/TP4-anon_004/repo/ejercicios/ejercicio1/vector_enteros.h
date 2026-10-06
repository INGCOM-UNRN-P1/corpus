
#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



/**
 * @brief Clona un arreglo de enteros en memoria dinámica.
 *
 * @pre origen es válido y cantidad es mayor que cero.
 * @post Se retorna una copia independiente del arreglo original.
 *
 * @param origen Arreglo original.
 * @param cantidad Cantidad de elementos.
 * 
 * @return Copia en heap o NULL ante error.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Copia solo los enteros pares, conservando el orden.
 *
 * @pre origen y cantidad_pares son válidos.
 * @post cantidad_pares contiene la cantidad de pares encontrados.
 *
 * @param origen Arreglo original.
 * @param cantidad_origen Cantidad de elementos originales.
 * @param cantidad_pares Cantidad de elementos del resultado.
 * 
 * @return Bloque independiente o NULL si no hay pares o ante error.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);

#endif 
