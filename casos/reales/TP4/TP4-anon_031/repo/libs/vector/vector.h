/**
 * @file vector.h
 * @brief Biblioteca para manejar bloques dinámicos de enteros sin structs.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Reserva un bloque de enteros inicializado en cero.
 * @param cantidad Cantidad de enteros a reservar.
 * @return Puntero al bloque reservado o NULL si cantidad es cero o falla la reserva.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Libera un bloque dinámico y deja el puntero en NULL.
 * @param puntero_bloque Dirección del puntero al bloque.
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Cambia el tamaño de un bloque de enteros usando realloc.
 * @param bloque Bloque original, que también puede ser NULL.
 * @param nueva_cantidad Nueva cantidad de enteros.
 * @return El bloque redimensionado o NULL si se libera o si falla realloc.
 * @note Ante un fallo de realloc el bloque original sigue siendo válido.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);

/**
 * @brief Concatena dos bloques de enteros en un nuevo bloque dinámico.
 * @param primero Primer bloque.
 * @param cantidad_primero Cantidad de elementos del primer bloque.
 * @param segundo Segundo bloque.
 * @param cantidad_segundo Cantidad de elementos del segundo bloque.
 * @return Nuevo bloque con ambos contenidos o NULL ante parámetros inválidos o fallo de memoria.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cantidad_primero,
                              const int *segundo, size_t cantidad_segundo);

/**
 * @brief Agrega un entero al final de un bloque dinámico.
 * @param puntero_bloque Dirección del puntero al bloque.
 * @param cantidad Dirección de la cantidad actual de elementos.
 * @param valor Valor a agregar.
 * @return true si se pudo agregar; false si los parámetros son inválidos o falla realloc.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
