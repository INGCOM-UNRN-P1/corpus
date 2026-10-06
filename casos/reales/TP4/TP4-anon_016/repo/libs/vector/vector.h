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




int *crear_bloque_enteros(size_t cantidad);




void liberar_bloque_enteros(int **puntero_bloque);




int *redimensionar_bloque_enteros(int *bloque, size_t nueva_cantidad);




int *fusionar_bloques_enteros(const int *primero, size_t cant_primero,
                               const int *segundo, size_t cant_segundo);




bool agregar_al_bloque_enteros(int **puntero_bloque, size_t *cantidad, int valor);

#endif 