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
 * @brief Intercambiar los contenidos de dos variables enteras recibidas por
 * referencia a través de punteros (int *primer, int *segundo).
 * @param primer
 * @param segundo
 * @pre 
 * @post
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Determinar el valor mínimo y el valor máximo de un arreglo de enteros,
 * escribiendo los resultados en las variables apuntadas por 'minimo' y 'maximo'.
 * @param arreglo
 * @param cantidad
 * @param minimo
 * @param maximo
 * @pre
 * @post
 * @returns Retorna false si 'arreglo' es NULL, si 'cantidad' es 0, o si alguno de los
 * punteros de salida
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
