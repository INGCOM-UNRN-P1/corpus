/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmética de punteros.
 *
 * Trabajo Práctico 3 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Cátedra:
 * - Toda manipulación de secuencias o arreglos se resuelve mediante
 *   aritmética de punteros.
 * - Se utiliza const-correctness en accesos de solo lectura.
 * - Se validan los punteros nulos antes de desreferenciarlos.
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Intercambia los valores almacenados en dos variables enteras.
 *
 * @param primer Puntero a la primera variable entera.
 * @param segundo Puntero a la segunda variable entera.
 *
 * @pre Los punteros pueden ser NULL.
 *
 * @post Si ambos punteros son válidos, los valores apuntados quedan
 * intercambiados. Si alguno es NULL, la función no realiza cambios.
 * Si ambos punteros apuntan a la misma dirección, el valor se conserva.
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Obtiene el valor mínimo y el valor máximo de un arreglo de enteros.
 *
 * Recorre el arreglo exclusivamente mediante aritmética de punteros y
 * almacena los resultados en las variables apuntadas por minimo y maximo.
 *
 * @param arreglo Puntero constante al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero donde se almacenará el valor mínimo.
 * @param maximo Puntero donde se almacenará el valor máximo.
 *
 * @return true si la operación se realizó correctamente.
 * @return false si arreglo es NULL, cantidad es 0, minimo es NULL
 * o maximo es NULL.
 *
 * @pre Si cantidad es mayor que 0, arreglo debe apuntar a una secuencia
 * válida de al menos cantidad elementos enteros.
 *
 * @post Ante éxito, *minimo contiene el menor valor del arreglo y
 * *maximo contiene el mayor.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
