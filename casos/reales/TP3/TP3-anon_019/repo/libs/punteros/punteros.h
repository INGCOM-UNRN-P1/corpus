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
 * @brief Intercambia los valores de dos variables enteras recibidas por referencia.
 * 
 * @pre Los punteros 'primer' y 'segundo' no deben ser nulos (NULL).
 * @post Los valores almacenados en las direcciones de memoria apuntadas se invierten. 
 *       Si algún puntero es NULL, o si ambos apuntan a la misma dirección, no se produce ningún efecto.
 * 
 * @param primer Puntero a la primera variable entera.
 * @param segundo Puntero a la segunda variable entera.
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Encuentra el valor mínimo y máximo dentro de un arreglo de enteros.
 * 
 * @pre El 'arreglo' no debe ser nulo. La 'cantidad' de elementos debe ser mayor a 0.
 *      Los punteros de salida 'minimo' y 'maximo' no deben ser nulos.
 * @post Las variables apuntadas por 'minimo' y 'maximo' se actualizan con los extremos encontrados.
 *       El arreglo de origen se recorre estrictamente mediante aritmética de punteros.
 * 
 * @param arreglo Puntero al primer elemento del arreglo a evaluar.
 * @param cantidad Número de elementos válidos que contiene el arreglo.
 * @param minimo Puntero a la variable donde se almacenará el valor más chico.
 * @param maximo Puntero a la variable donde se almacenará el valor más grande.
 * @return true si se encontraron y guardaron los extremos exitosamente.
 * @return false si fallan las precondiciones (punteros nulos o cantidad 0).
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 