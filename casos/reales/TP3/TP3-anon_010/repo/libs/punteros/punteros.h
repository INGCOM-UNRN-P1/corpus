/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmética de punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda manipulación de secuencias o arreglos debe resolverse estrictamente
 *   mediante aritmética de punteros (*p, p++, p + offset, fin - inicio),
 *   evitando el operador de indexación arreglo[i].
 * - Uso riguroso de const-correctness (const char*, const int*) en accesos
 *   de solo lectura.
 * - Validación exhaustiva de punteros nulos (NULL).
 *
 * Observación importante de diseño:
 * Recuerden que no está permitido utilizar ALV's (Arreglos de Longitud Variable / VLA),
 * pero también, este ejercicio no está pensado para utilizar memoria dinámica.
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Intercambia los valores de dos variables enteras a través de sus
 * punteros.
 *
 * @param[in, out] primer  Puntero al primer entero. Su contenido es leído y
 * luego sobrescrito con el del segundo.
 * @param[in, out] segundo Puntero al segundo entero. Su contenido es leído y
 * luego sobrescrito con el del primero.
 *
 * @pre Si 'primer' y 'segundo' no son NULL, apuntan a enteros válidos y
 * modificables.
 * @pre 'primer' y 'segundo' pueden apuntar a la misma dirección.
 *
 * @post Si ambos punteros no son NULL y distintos, '*primer' contiene el
 * valor original de '*segundo' y viceversa.
 * @post Si ambos apuntan a la misma dirección, el valor se preserva.
 * @post Si alguno de los punteros es NULL, no se accede a memoria y no se
 * modifica nada.
 * @post No se modifica ninguna otra posición de memoria ni se introducen
 * valores nuevos: solo se intercambian los dos valores originales.
*/
void intercambiar(int *primer, int *segundo);

/**
 * @brief Obtiene el valor mínimo y el máximo de un arreglo de enteros.
 *
 * Recorre el arreglo exclusivamente con aritmética de punteros (sin `[]`).
 *
 * @param[in]  arreglo  Arreglo de enteros a analizar (solo lectura).
 * @param[in]  cantidad Cantidad de elementos del arreglo a considerar.
 * @param[out] minimo   Puntero donde se escribe el valor mínimo. Su valor
 * inicial no es relevante.
 * @param[out] maximo   Puntero donde se escribe el valor máximo. Su valor
 * inicial no es relevante.
 *
 * @pre Si 'arreglo' no es NULL, apunta a al menos 'cantidad' enteros
 * consecutivos y legibles.
 * @pre Si 'minimo' y 'maximo' no son NULL, apuntan a enteros modificables y
 * distintos entre sí.
 *
 * @post Si retorna true, `*minimo` es el menor y `*maximo` el mayor de los
 * primeros 'cantidad' elementos de 'arreglo'.
 * @post Si retorna false, `*minimo` y `*maximo` no se modifican.
 * @post El contenido de 'arreglo' no se modifica y no se escribe en ninguna
 * otra posición de memoria además de `*minimo` y `*maximo`.
 *
 * @return true si pudo determinar ambos valores; false si 'arreglo' es NULL,
 * 'cantidad' es 0, o 'minimo' o 'maximo' es NULL.
*/
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
