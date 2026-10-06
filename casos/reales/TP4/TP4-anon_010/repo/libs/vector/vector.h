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
 * @brief Reserva un bloque contiguo en heap para 'cantidad' enteros, inicializado en 0.
 *
 * @param cantidad Cantidad de enteros a reservar.
 *
 * @pre Ninguna.
 * @post Si retorna un puntero no nulo, apunta a 'cantidad' enteros con valor 0
 *       y el llamador es responsable de liberarlo.
 *
 * @return Puntero al bloque reservado, o NULL si 'cantidad' es 0 o si calloc falla.
 */
int *crear_bloque_enteros(size_t cantidad);
 
/**
 * @brief Libera un bloque dinámico y deja el puntero del llamador en NULL.
 *
 * @param puntero_bloque Dirección del puntero al bloque a liberar.
 *
 * @pre Si '*puntero_bloque' no es NULL, debe apuntar a memoria obtenida con
 *      malloc, calloc o realloc que no haya sido liberada.
 * @post '*puntero_bloque' es NULL. Si 'puntero_bloque' o '*puntero_bloque'
 *       eran NULL, no se realiza ninguna acción.
 */
void liberar_bloque_enteros(int **puntero_bloque);
 
/**
 * @brief Redimensiona un bloque dinámico a 'nueva_cantidad' enteros usando realloc.
 *
 * @param bloque Bloque a redimensionar (puede ser NULL, en cuyo caso se reserva uno nuevo).
 * @param nueva_cantidad Nueva cantidad de enteros del bloque.
 *
 * @pre Si 'bloque' no es NULL, debe provenir de memoria dinámica vigente.
 * @post Si 'nueva_cantidad' es 0, 'bloque' queda liberado. Si realloc falla,
 *       'bloque' permanece válido y sin cambios. Los elementos previos se
 *       conservan hasta el mínimo entre el tamaño anterior y el nuevo.
 *
 * @return Puntero al bloque redimensionado (puede cambiar de dirección), o NULL
 *         si 'nueva_cantidad' es 0 o si realloc falla.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);
 
/**
 * @brief Concatena dos bloques de enteros en un nuevo bloque de heap de tamaño exacto.
 *
 * @param primero Primer bloque (puede ser NULL solo si 'cant_primero' es 0).
 * @param cant_primero Cantidad de elementos de 'primero'.
 * @param segundo Segundo bloque (puede ser NULL solo si 'cant_segundo' es 0).
 * @param cant_segundo Cantidad de elementos de 'segundo'.
 *
 * @pre 'primero' y 'segundo' deben ser legibles en 'cant_primero' y 'cant_segundo'
 *      posiciones respectivamente.
 * @post Los bloques de entrada no se modifican. El nuevo bloque contiene los
 *       elementos de 'primero' seguidos de los de 'segundo', y el llamador es
 *       responsable de liberarlo.
 *
 * @return Puntero al nuevo bloque de 'cant_primero + cant_segundo' enteros, o NULL
 *         si la suma es 0, si algún puntero es NULL con cantidad mayor a 0, o si
 *         falla la reserva.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);
 
/**
 * @brief Agrega un valor al final de un bloque dinámico, redimensionándolo en 1 elemento.
 *
 * @param puntero_bloque Dirección del puntero al bloque (el bloque puede ser NULL si '*cantidad' es 0).
 * @param cantidad Dirección de la cantidad actual de elementos del bloque.
 * @param valor Valor a agregar en la última posición.
 *
 * @pre 'puntero_bloque' y 'cantidad' no son NULL, y '*puntero_bloque' contiene
 *      '*cantidad' elementos válidos.
 * @post Si tuvo éxito, '*cantidad' aumentó en 1, '*puntero_bloque' apunta al bloque
 *       (posiblemente en otra dirección) y su último elemento es 'valor'. Si falló,
 *       '*puntero_bloque' y '*cantidad' quedan sin cambios.
 *
 * @return true si se agregó el valor, false ante parámetros inválidos o si falla la reserva.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
