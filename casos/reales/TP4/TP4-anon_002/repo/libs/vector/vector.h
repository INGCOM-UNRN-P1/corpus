/**
 * @file vector.h
 * @brief Biblioteca libvector: manejo de bloques contiguos de enteros en heap
 * sin structs.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda asignación dinámica con malloc/calloc/realloc debe validarse contra
 * NULL.
 * - Toda memoria reservada debe liberarse indefectiblemente con free.
 * - No se emplean estructuras (structs); la gestión se realiza mediante
 * punteros directos (int*), dobles punteros (int**) y tamaños pasados por
 * parámetro.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea un bloque dinámico de enteros inicializado en cero.
 *
 * @param cantidad Cantidad de enteros que tendrá el bloque.
 *
 * @pre cantidad debe ser mayor que cero para realizar la reserva.
 *
 * @return Un puntero al bloque reservado e inicializado en cero, o NULL
 *          si cantidad es cero o si calloc falla.
 *
 * @post Si la reserva es exitosa, se devuelve un bloque contiguo de
 *       cantidad enteros inicializados en cero.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Libera un bloque dinámico de enteros y anula el puntero.
 *
 * @param puntero_bloque Doble puntero al bloque de memoria que se desea
 * liberar.
 *
 * @pre puntero_bloque puede ser NULL.Si no lo es, *puntero_bloque puede
 *      ser NULL o apuntar a memoria reservada dinámicamente.
 *
 * @post Si el bloque existe, su memoria es liberada y *puntero_bloque
 *       queda establecido en NULL.
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Redimensiona un bloque dinámico de enteros.
 *
 * @param bloque Puntero al bloque de memoria que se desea redimensionar.
 * @param nueva_cantidad Nueva cantidad de enteros que tendrá el bloque.
 *
 * @pre bloque debe apuntar a memoria reservada dinámicamente o ser NULL.
 * @pre nueva_cantidad puede ser cero.
 *
 * @return Un puntero al bloque redimensionado si la operación es exitosa,
 *          o NULL si nueva_cantidad es cero o realloc falla.
 *
 * @post Si realloc falla, el bloque original permanece válido y no se pierde.
 * @post Si nueva_cantidad es cero, el bloque original es liberado.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);

/**
 * @brief Fusiona dos bloques de enteros en un nuevo bloque dinámico.
 *
 * @param primero Puntero al primer bloque de enteros.
 * @param cant_primero Cantidad de elementos del primer bloque.
 * @param segundo Puntero al segundo bloque de enteros.
 * @param cant_segundo Cantidad de elementos del segundo bloque.
 *
 * @pre Los bloques deben corresponder con las cantidades indicadas cuando
 *      sus cantidades sean mayores que cero.
 *
 * @returns Un nuevo bloque que contiene primero los elementos de primero
 *          y luego los elementos de segundo, o NULL si ambos bloques son
 *          NULL o si falla la reserva de memoria.
 *
 * @post Si la operación es exitosa, se devuelve un bloque nuevo de
 *       cant_primero + cant_segundo elementos.
 * @post Los bloques originales no son modificados.
 */

int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);

/**
 * @brief Agrega un entero al final de un bloque dinámico.
 *
 * @param puntero_bloque Doble puntero al bloque que se desea ampliar.
 * @param cantidad Puntero a la cantidad actual de elementos del bloque.
 * @param valor Valor entero que se agregará al final del bloque.
 *
 * @pre puntero_bloque y cantidad no deben ser NULL.
 *
 * @returns true si el bloque fue redimensionado y el valor agregado
 *          correctamente, o false si alguno de los parámetros es NULL
 *          o si falla la redimensión de memoria.
 *
 * @post Si la operación es exitosa, *puntero_bloque apunta al bloque
 *       actualizado y *cantidad aumenta en uno.
 * @post El nuevo valor queda almacenado en la última posición del bloque.
 * @post Si la operación falla, el bloque y la cantidad conservan su estado.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);

#endif 
