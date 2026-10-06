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
#include <string.h>


/**
 * @brief Reserva un bloque de memoria contigua en el heap para almacenar
 * 'cantidad' enteros usando calloc.
 * @param cantidad es la cantidad de elementos tipo int a reservar.
 *
 * @pre cantidad debe ser > 0.
 * @return el puntero al inicio del bloque en caso de que cantidad sea valido y
 * calloc no falle.Null en caso contrario.
 */
int *crear_bloque_enteros(size_t cantidad);


/**
 * @brief Libera un bloque de memoria con free() y asigna NULL al puntero
 * asociado.
 * @param puntero_bloque es la dirección de memoria del puntero asociado al
 * bloque del heap.
 *
 * @pre si alguno de los punteros en NULL no realiza operaciones.
 */
void liberar_bloque_enteros(int **puntero_bloque);


/**
 * @brief Redimensiona el bloque apuntado por 'bloque' a 'nueva_cantidad'
 * enteros mediante realloc.
 * @param bloque es el puntero al inicio del bloque de memoria.
 * @param nueva_cantidad es el nuevo tamaño del bloque.
 *
 * @post Si nueva_cantidad es 0, libera la memoria y retorna NULL.
 * @post Si realloc falla, no debe perderse el bloque original y la función
 * retorna NULL.
 *
 * @return el puntero a la nueva dirección de memoria si tiene éxito.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);


/**
 * @brief Recibe dos bloques de enteros en memoria dinámica (o buffers
 * contiguos) junto con sus cantidades respectivas.Reserva un nuevo bloque en
 * heap para la suma exacta de elementos, copia los elementos del primer bloque
 * seguidos de los del segundo bloque y retorna el puntero int *al nuevo bloque.
 * @param primero es el puntero al primer bloque en el heap.
 * @param cant_primero es la cantidad de elementos del primer bloque.
 * @param segundo es el puntero al segundo bloque en el heap.
 * @param cant_segundo es la cantidad de elementos del segundo bloque.
 *
 * @pre ambos punteros no deben ser NULL.
 *
 * @return el puntero al nuevo bloque, NULL si no hay espacio en memoria.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);


/**
 * @brief Recibe un doble puntero al bloque de enteros, un puntero a su tamaño
 * actual y el nuevo 'valor' a agregar.Redimensiona el bloque en el heap para
 * que contenga al nuevo elemento, asigna el valor a la ultima posición,
 * actualiza la cantidad y el puntero al bloque.
 * @param puntero_bloque es el puntero al inicio del bloque en el heap.
 * @param cantidad es la cantidad de elementos del bloque.
 * @param valor es el valor a añador al final del bloque.
 *
 * @return true si tuvo éxito, false caso contrario.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);

#endif 
