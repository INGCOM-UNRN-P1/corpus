/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmética
 *        de punteros.
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
 * Recuerden que no está permitido utilizar ALV's (Arreglos de Longitud
 * Variable / VLA), pero también, este ejercicio no está pensado para utilizar
 * memoria dinámica.
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Intercambia los valores de dos enteros recibidos por referencia.
 *
 * @param primer  Puntero al primer entero. Puede ser NULL.
 * @param segundo Puntero al segundo entero. Puede ser NULL.
 *
 * @pre Ninguna: si alguno de los punteros es NULL la función no hace nada.
 *
 * @post Si ambos punteros son válidos, *primer contiene el valor original de
 *       *segundo y viceversa. Si ambos apuntan a la misma dirección, el valor
 *       se conserva intacto.
 */
void intercambiar(int *primer, int *segundo);

/**
 * Obtiene el valor mínimo y el máximo de un arreglo de enteros,
 * recorriéndolo con aritmética de punteros.
 *
 * @param arreglo  Puntero al primer elemento del arreglo (solo lectura).
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo   Parámetro de salida donde se guarda el menor valor.
 * @param maximo   Parámetro de salida donde se guarda el mayor valor.
 *
 * @pre Si arreglo no es NULL, debe tener al menos 'cantidad' elementos.
 *
 * @returns true si pudo calcular ambos valores; false si arreglo, minimo o
 *          maximo son NULL, o si cantidad es 0.
 *
 * @post Si retorna true, *minimo y *maximo son el menor y el mayor elemento
 *       del arreglo. Si retorna false, no se modifica ninguna salida.
 *       El arreglo nunca se modifica.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad,
                     int *minimo, int *maximo);

#endif 
