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
#include <stdio.h>


/**
 * @brief Evalua los valores ingresados y realiza un intercambio en memoria.
 *          los parametros ingresados no deben ser igual a NULL.
 * @param primer elemento.
 * @param segundo elemento.
 * @return intercambia los elementos ingresados.
 */
void intercambiar(int *primer, int *segundo);


/**
 * @brief Evalua los valores ingresados y realiza un intercambio en memoria.
 *          los parametros ingresados no deben ser igual a NULL.
 * @param arreglo[int] arreglo de enteros.
 * @param cantidad[size_t] cantidad de elementos en el arreglo.
 * @param minimo[in] puntero a entero para almacenar el valor minimo del arreglo.
 * @param maximo[in] puntero a entero para almacenar el valor maximo del arreglo.
 * @return true si se pudo determinar ambos valores.
 *         false si los parametros son NULL o cantidad es 0.
 *         minimo[out] valor minimo del arreglo.
 *         maximo[out] valor maximo del arreglo.    
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);


/**
 * @brief Funcion que imprime por consola los valores desreferenciados de un arreglo.
 *         El arreglo no puede ser NULL y Cantidad no puede ser 0 o menor a 0.
 * @param arreglo[int] arreglo de enteros.
 * @param cantidad[size_t] cantidad de elementos en el arreglo.
 * @return Toma de parametros solo en lectura, no devuelve nada.    
 */
void imprimir_arreglo(const int *arreglo, size_t cantidad);

#endif 
