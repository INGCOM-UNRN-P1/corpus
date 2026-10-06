/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap sin structs.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Reserva un bloque continuo de memoria en el heap inicializado en cero.
 *
 * @param[in] cantidad Cantidad de enteros a alojar.
 *
 * @return Puntero al bloque asignado (int *), o NULL si cantidad es 0 o si falla la reserva.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Libera un bloque de memoria dinamica y anula el puntero original.
 *
 * Previene el error de puntero colgante (dangling pointer) estableciendo *puntero_bloque en NULL.
 *
 * @param[in, out] puntero_bloque Direccion de la variable puntero que apunta al bloque (int **).
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Redimensiona un bloque de enteros existente en el heap de manera segura.
 *
 * Emplea un puntero temporal para preservar el bloque original en caso de fallo de realloc.
 * Si nueva_cantidad es 0, se libera el bloque y se retorna NULL.
 *
 * @param[in] bloque Puntero al bloque existente en el heap (puede ser NULL).
 * @param[in] nueva_cantidad Nueva cantidad de enteros deseada.
 *
 * @return Puntero a la nueva direccion del bloque redimensionado, o NULL si fallo realloc o si nueva_cantidad es 0.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);

/**
 * @brief Fusiona y concatena dos bloques contiguos de enteros en un nuevo bloque en heap.
 *
 * Reserva el espacio exacto (cant_primero + cant_segundo) y copia secuencialmente
 * los elementos de ambos bloques.
 *
 * @param[in] primero Puntero al primer bloque de enteros (puede ser NULL si cant_primero es 0).
 * @param[in] cant_primero Cantidad de elementos del primer bloque.
 * @param[in] segundo Puntero al segundo bloque de enteros (puede ser NULL si cant_segundo es 0).
 * @param[in] cant_segundo Cantidad de elementos del segundo bloque.
 *
 * @return Puntero al nuevo bloque contiguo fusionado en el heap, o NULL ante error o si la suma total es 0.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);

/**
 * @brief Agrega un valor entero al final de un bloque dinamico actualizando su tamano y direccion.
 *
 * Redimensiona el bloque a (*cantidad + 1) enteros. Si realloc mueve la memoria,
 * actualiza *puntero_bloque de forma segura.
 *
 * @param[in, out] puntero_bloque Direccion del puntero al bloque en heap (int **). No debe ser NULL.
 * @param[in, out] cantidad Direccion de la variable que almacena la cantidad actual (size_t *).
 * @param[in] valor Entero a insertar al final del bloque.
 *
 * @return true si la insercion y redimension fueron exitosas, false ante error de memoria o parametros nulos.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 