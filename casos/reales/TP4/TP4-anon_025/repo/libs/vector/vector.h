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
  * @brief Reserva memoria en el heap para un bloque contiguo de enteros iniciados en 0.
  * 
  * @param cantidad Numeros neteros a reservar.
  * 
  * @return int* Puntero al nuevo bloque, o NULL si canntidad es 0 o falla la mememoria.
  */
int *crear_bloque_enteros(size_t cantidad);



 /**
  * @brief Libera un bloque de memoria dinamica y anula el puntero colgante.
  * 
  * @param puntero_bloque Doble puntero al bloque a liberar.
  */
void liberar_bloque_enteros(int **puntero_bloque);



 /**
  * @brief Redimensiona un bloque de memoria dinamica existente de forma segura.
  * 
  * @param bloque Puntero al bloque origen.
  * @param nueva_cantidad Nuevo tamaño en cantidad de enteros.
  * 
  * @return int* Puntero al bloque redimensionado, o NULL si falla.
  */
int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);



 /**
  * @brief Fusiona dos bloques dinamicos contiguos en uno nuevo en heap.
  * 
  * @param primero Puntero al primer bloque.
  * @param cant_primero Cantidad de elementos del primer bloque.
  * @param segundo Puntero al segundo bloque.
  * @param cant_segundo Cantidad de elementos del segundo bloque.
  * 
  * @return int* Nuevo bloque fusionado o NULL si hay error o si los dos son NULL.
  */
 int *fusionar_bloques_enteros(const int *primero, size_t cant_primero, const int *segundo, size_t cant_segundo);



 /**
  * @brief Agrega un elemento al final de un bloque, redimensionandolo automaticamente.
  * 
  * @param puntero_bloque Doble puntero al bloque dinamico.
  * @param cantidad Puntero a la cantidad actual de elementos.
  * @param valor El entero a insertar.
  * 
  * @return true Si se interto exitosamente, false si falla.
  */
 bool afregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 
