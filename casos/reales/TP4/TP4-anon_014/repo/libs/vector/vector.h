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
 * @brief Reserva un bloque de enteros en heap inicializado en cero.
 * @param cantidad cantidad de enteros a reservar.
 * @returns puntero al bloque, o NULL si cantidad es 0 o falla calloc.
 * @post el llamador es dueño del bloque y debe liberarlo con
 *       liberar_bloque_enteros.
 */
int *crear_bloque_enteros(size_t cantidad);


/**
 * @brief Libera un bloque de enteros y deja el puntero en NULL.
 * @param puntero_bloque dirección del puntero al bloque (acepta NULL).
 * @pre el bloque fue reservado en heap o es NULL.
 * @post *puntero_bloque vale NULL.
 */
void liberar_bloque_enteros(int **puntero_bloque);


/**
 * @brief Cambia el tamaño de un bloque de enteros con realloc.
 * @param bloque bloque en heap (o NULL para reservar uno nuevo).
 * @param nueva_cantidad nueva cantidad de enteros.
 * @pre bloque fue reservado en heap o es NULL.
 * @returns el bloque redimensionado; NULL si nueva_cantidad es 0 (el bloque
 *          se libera) o si realloc falla (el bloque original sigue válido).
 * @post el llamador es dueño del bloque retornado.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);





/**
 * @brief Concatena dos bloques de enteros en uno nuevo de tamaño exacto.
 * @param primero primer bloque (puede ser NULL).
 * @param cant_primero cantidad de elementos de primero.
 * @param segundo segundo bloque (puede ser NULL).
 * @param cant_segundo cantidad de elementos de segundo.
 * @pre cada bloque no nulo tiene al menos su cantidad de elementos.
 * @returns nuevo bloque con primero seguido de segundo, o NULL si ambos son
 *          NULL, el total es 0 o falla la memoria.
 * @post el llamador debe liberar el bloque con liberar_bloque_enteros.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);

/**
 * @brief Agrega un valor al final de un bloque, agrandándolo en uno.
 * @param puntero_bloque dirección del puntero al bloque (el bloque puede
 *        ser NULL si *cantidad es 0).
 * @param cantidad cantidad actual de elementos; se incrementa ante éxito.
 * @param valor valor a agregar.
 * @pre puntero_bloque y cantidad no son NULL.
 * @returns true ante éxito; false si los argumentos son NULL o falla realloc
 *          (el bloque original queda intacto).
 * @post ante éxito, *puntero_bloque apunta al bloque actualizado.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);

#endif 
