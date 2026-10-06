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
 * @brief Reserva un bloque de memoria contigua en el heap para almacenar 'cantidad'
 * enteros
 *
 * @param cantidad Descripción del parámetro cantidad.
 * @pre
 * @post
 * @return Retorna el puntero int* al bloque asignado, o NULL si la cantidad es 0 o
 * si calloc falla.
 */
int *crear_bloque_enteros(size_t cantidad);

/**
 * @brief Recibe un doble puntero (int **puntero_bloque), libera la memoria a la que
 * apunta (*puntero_bloque) con free, y asigna *puntero_bloque = NULL para
 * eliminar de forma segura el puntero colgante (dangling pointer).
 *
 * @param puntero_bloque Descripción del parámetro puntero_bloque.
 * @pre
 * @post
 * Si puntero_bloque es NULL o *puntero_bloque ya es NULL, no realiza ninguna acción.
 */
void liberar_bloque_enteros(int **puntero_bloque);

/**
 * @brief Redimensiona el bloque apuntado por 'bloque' a 'nueva_cantidad' enteros
 * mediante realloc.
 * Si nueva_cantidad es 0, libera la memoria y retorna NULL.
 * Si realloc falla, no debe perderse el bloque original y la función retorna NULL.
 * Ante éxito, retorna el puntero a la nueva dirección de memoria.
 * 
 * @param bloque Descripción del parámetro bloque.
 * @param nueva_cantidad Descripción del parámetro nueva_cantidad.
 * @pre
 * @post
 * @return Descripción del valor de retorno.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);
/**
 * @brief Reserva un nuevo bloque en heap para la suma exacta de elementos, copia los
 * elementos del primer bloque seguidos de los del segundo bloque y 
 *
 * @param primero Descripción del parámetro primero.
 * @param cant_primero Descripción del parámetro cant_primero.
 * @param segundo Descripción del parámetro segundo.
 * @param cant_segundo Descripción del parámetro cant_segundo.
 * @pre
 * @post
 * @return retorna el
 * puntero int* al nuevo bloque.
 * Retorna NULL si ambos son nulos o si falla la memoria.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);

/**
 * @brief Redimensiona el bloque en el heap para (*cantidad + 1) elementos, asigna
 * el nuevo valor en la última posición,
 * 
 * @param puntero_bloque Descripción del parámetro puntero_bloque.
 * @param cantidad Descripción del parámetro cantidad.
 * @param valor Descripción del parámetro valor.
 * @pre
 * @post   *  actualiza (*cantidad)++ y actualiza
 * *puntero_bloque con la nueva dirección si realloc cambió la ubicación física.
 * @return
 * Retorna true ante éxito o false si falla realloc (preservando el bloque original).
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
