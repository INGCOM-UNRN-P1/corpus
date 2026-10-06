/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse contra NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante punteros directos
 *   (int*), dobles punteros (int**) y tamaños pasados por parámetro.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea un bloque dinámico de enteros inicializado en cero.
 * @param cantidad Cantidad de elementos a reservar.
 * @pre cantidad es mayor que cero.
 * @post Se reserva un bloque contiguo en heap con memoria validada.
 * @note El bloque devuelto debe liberarse con liberar_bloque_enteros(&puntero)
 *       o con free() sobre el puntero recibido.
 * @returns Puntero al bloque recién creado o NULL si cantidad es cero o falla la reserva.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Libera un bloque dinámico de enteros y deja el puntero en NULL.
 * @param puntero_bloque Dirección del puntero al bloque.
 * @pre puntero_bloque puede ser NULL o apuntar a un bloque válido.
 * @post Si el bloque era válido, se libera y el puntero queda corriendo a NULL.
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Redimensiona un bloque dinámico de enteros.
 * @param bloque Puntero al bloque actual.
 * @param nueva_cantidad Cantidad nueva de elementos.
 * @pre bloque puede ser NULL si se quiere crear un bloque nuevo.
 * @post Si la reasignación tiene éxito, se devuelve la nueva dirección del bloque.
 * @note Si nueva_cantidad es 0, la función libera la memoria y devuelve NULL.
 * @returns Nuevo puntero al bloque o NULL si falla la reserva.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);

/**
 * @brief Fusiona dos bloques contiguos de enteros en un tercero nuevo.
 * @param primero Primer bloque de entrada.
 * @param cant_primero Cantidad de elementos del primer bloque.
 * @param segundo Segundo bloque de entrada.
 * @param cant_segundo Cantidad de elementos del segundo bloque.
 * @pre El primer y segundo bloque pueden ser NULL solo si su cantidad respectiva es 0.
 * @post Se devuelve un bloque nuevo con los elementos concatenados.
 * @note El bloque resultante debe liberarse con liberar_bloque_enteros(&puntero)
 *       o con free().
 * @returns Nuevo bloque concatenado o NULL si falla la reserva.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);

/**
 * @brief Agrega un valor al final de un bloque dinámico.
 * @param puntero_bloque Dirección del puntero al bloque.
 * @param cantidad Puntero a la cantidad actual de elementos.
 * @param valor Valor a insertar al final.
 * @pre puntero_bloque y cantidad no son NULL.
 * @post El bloque crece en 1 elemento y se agrega el valor al final.
 * @note Si la reserva falla, el bloque original se conserva y la función devuelve false.
 * @returns true si la operación tuvo éxito, false si falla la reasignación.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
