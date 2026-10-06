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



/** @brief Reserva cantidad enteros inicializados en cero.
 * 
 * @pre cantidad es el numero solicitado de enteros.
 * @post Retorna un bloque propio o NULL ante cero, overflow o fallo de memoria.
 * 
 * @param cantidad Numero de elementos.
 * 
 * @return Bloque que el llamador debe liberar.
 */
int *crear_bloque_enteros(size_t cantidad);



/** @brief Libera un bloque y anula su puntero.
 * 
 * @pre El bloque es propio o NULL.
 * @post *puntero_bloque queda NULL; un argumento NULL se ignora.
 * 
 * @param puntero_bloque Direccion del puntero propietario.
 */
void liberar_bloque_enteros(int **puntero_bloque);


/** @brief Cambia la cantidad de enteros mediante realloc.
 * 
 * @pre bloque procede del heap o es NULL.
 * @post Preserva el bloque ante error; cantidad cero lo libera.
 * 
 * @param bloque Bloque original.
 * @param nueva_cantidad Nueva cantidad de elementos.
 * 
 * @return Nuevo puntero o NULL; el llamador debe usar un puntero temporal.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



/** @brief Concatena dos bloques sin modificar sus elementos.
 * 
 * @pre Cada cantidad positiva exige un bloque legible de ese tamano.
 * @post Reserva exactamente la suma de cantidades; no modifica las entradas.
 * 
 * @param primero Primer bloque; NULL permitido si cant_primero es cero.
 * @param cant_primero Cantidad del primer bloque.
 * @param segundo Segundo bloque; NULL permitido si cant_segundo es cero.
 * @param cant_segundo Cantidad del segundo bloque.
 * 
 * @return Bloque propio o NULL ante entradas invalidas, vacias u overflow.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                              const int *segundo, size_t cant_segundo);



/** @brief Agrega un entero al final usando realloc seguro.
 * 
 * @pre El bloque tiene cantidad elementos y pertenece al heap.
 * @post Ante exito actualiza puntero y cantidad; ante fallo no los modifica.
 * 
 * @param puntero_bloque Direccion del bloque propietario.
 * @param cantidad Direccion de la cantidad de elementos.
 * @param valor Entero a agregar.
 * 
 * @return true ante exito; false ante error o overflow.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad,
                               int valor);

#endif 
