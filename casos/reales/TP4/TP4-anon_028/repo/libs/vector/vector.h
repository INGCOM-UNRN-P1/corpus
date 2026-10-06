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
 * @brief Reserva un bloque de memoria contigua en el heap para almacenar 'cantidad' enteros.
 *
 * Emplea calloc dejando la memoria inicializada en 0.
 *
 * @param cantidad Número de enteros a reservar (debe ser > 0).
 * @return Puntero int* al bloque asignado, o NULL si la cantidad es 0 o si calloc falla.
 */
int *crear_bloque_enteros(size_t cantidad);



/**
 * @brief Libera la memoria apuntada por *puntero_bloque y establece el puntero en NULL.
 *
 * Previene punteros colgantes (dangling pointers). Si puntero_bloque o *puntero_bloque es NULL,
 * no realiza ninguna acción.
 *
 * @param puntero_bloque Doble puntero al bloque de enteros a liberar.
 */
void liberar_bloque_enteros(int **puntero_bloque);



/**
 * @brief Redimensiona un bloque de enteros en heap a 'nueva_cantidad' elementos mediante realloc.
 *
 * @param bloque Puntero al bloque actual.
 * @param nueva_cantidad Nuevo tamaño en número de enteros. Si es 0, libera y retorna NULL.
 * @return Puntero a la nueva dirección de memoria, o NULL ante fallo o nueva_cantidad == 0.
 */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



/**
 * @brief Fusiona y concatena dos bloques de enteros en un nuevo bloque en heap.
 *
 * @param primero Puntero al primer bloque de enteros.
 * @param cant_primero Cantidad de elementos del primer bloque.
 * @param segundo Puntero al segundo bloque de enteros.
 * @param cant_segundo Cantidad de elementos del segundo bloque.
 * @return Puntero al nuevo bloque concatenado, o NULL si ambos son nulos/vacíos o falla la memoria.
 */
int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);



/**
 * @brief Agrega un entero al final de un bloque en heap redimensionándolo automáticamente.
 *
 * @param puntero_bloque Doble puntero al bloque de enteros.
 * @param cantidad Puntero a la cantidad actual de elementos (se incrementa en 1 ante éxito).
 * @param valor Entero a insertar al final.
 * @return true si la inserción fue exitosa, false si falló la reasignación de memoria.
 */
bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
