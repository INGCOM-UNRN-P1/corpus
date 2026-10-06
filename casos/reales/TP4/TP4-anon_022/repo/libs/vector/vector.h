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
 * @brief Reserva un bloque de memoria para almacenar 'cantidad' enteros
 *        inicializados en cero.
 *
 * @param cantidad Número de enteros a almacenar.
 * @return Puntero que apunta al bloque reservado,
 *         o NULL si 'cantidad' es cero o no se pudo reservar la memoria.
 */
 int *crear_bloque_enteros(size_t cantidad);



/**
 * @brief Libera el bloque de memoria y establece el puntero a NULL.
 *
 * @param puntero_bloque Dirección del puntero que referencia al bloque
 *                       de memoria que se desea liberar.
 *
 * @post El bloque de memoria es liberado y el puntero queda establecido
 *       en NULL.
 */
void liberar_bloque_enteros(int **puntero_bloque);



/**
 * @brief Redimensiona un bloque para almacenar nueva cantidad de enteros.
 *        
 * @param bloque Puntero al bloque de memoria que se desea redimensionar. 
 * @param nueva_cantidad Nuevo número de enteros que podrá almacenar 
 *                       el bloque.
 *
 * @pre 'bloque' debe ser NULL o apuntar a un bloque de memoria válido
 *      reservado dinámicamente.
 * @post Si 'nueva_cantidad' es cero, el bloque es liberado y se retorna NULL.
 *       Si la reasignación es exitosa, se retorna un puntero al bloque
 *       redimensionado.
 *       Si la reasignación falla, el bloque original permanece 
 *       sin modificaciones y se retorna NULL.
 *
 * @return Puntero al bloque redimensionado, o NULL si 'nueva_cantidad'
 *         es cero o si la reasignación falla.
 */
 int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



/**
 * @brief Reserva un nuevo bloque para almacenar la fusión de otros
 *        dos bloques de enteros.
 *
 * @param primero Puntero al primer bloque de elementos.
 * @param cant_primero Cantidad de elementos del primer bloque.
 * @param segundo Puntero al segundo bloque de elementos.
 * @param cant_segundo Cantidad de elementos del segundo bloque.
 *
 * @post Si la asignación es exitosa, el bloque retornado contiene primero
 *       los elementos de 'primero' y luego los elementos de 'segundo'.
 *       Si la asignación falla, retorna NULL.
 *
 * @return Puntero al nuevo bloque con los elementos fusionados,
 *         o NULL si ambos bloques son NULL o si falla la asignación.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);



/**
 * @brief Redimensiona un bloque y agrega un nuevo valor en la última posición.
 *
 * @param puntero_bloque Dirección del puntero que referencia al bloque 
 *                       de enteros que se desea redimensionar.
 * @param cantidad Puntero a la cantidad actual de elementos del bloque.
 * @param valor Valor que se desea agregar al final del bloque.
 *
 * @pre 'puntero_bloque' y 'cantidad' no deben ser NULL.
 * @post Si la reasignación es exitosa, el bloque conserva sus valores 
 *       originales, agrega 'valor' en la última posición y aumenta 
 *       la cantidad de elementos en uno. 
 *       Si la reasignación falla, el bloque y la cantidad permanecen 
 *       sin modificaciones.
 *
 * @return true si el valor se agregó con éxito.
 *         false si falló la reasignación.
 */
 bool agregar_al_bloque_enteros(int **puntero_bloque, 
                               size_t *cantidad, int valor);

#endif 
