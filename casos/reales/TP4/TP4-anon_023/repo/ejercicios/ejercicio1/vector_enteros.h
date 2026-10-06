/**
 * @file vector_enteros.h
 * @brief Ejercicio 1: Gestion de arreglos dinamicos de enteros sin structs.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"

/**
 * @brief Clona un arreglo de enteros reservando memoria dinamica en el heap.
 *
 * @param[in] origen Puntero al arreglo de enteros fuente.
 * @param[in] cantidad Cantidad de elementos a clonar.
 *
 * @return Puntero al nuevo bloque en heap (int *), o NULL si origen es NULL,
 *         cantidad es 0 o falla la reserva de memoria.
 */
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);

/**
 * @brief Filtra y extrae todos los numeros pares de un arreglo en un nuevo bloque en heap.
 *
 * Cuenta la cantidad exacta de elementos pares, reserva el bloque justo en heap
 * y asigna dicha cantidad en el parametro de salida.
 *
 * @param[in] origen Puntero al arreglo de enteros a filtrar.
 * @param[in] cantidad_origen Cantidad de elementos del arreglo fuente.
 * @param[out] cantidad_pares Puntero donde se almacenara la cantidad de pares encontrados.
 *
 * @return Puntero al nuevo bloque en heap con los elementos pares, o NULL si no hay pares,
 *         si los parametros son invalidos o si falla la memoria.
 */
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares);

#endif 
