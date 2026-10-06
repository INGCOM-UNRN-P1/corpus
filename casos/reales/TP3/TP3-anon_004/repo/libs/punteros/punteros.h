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
 * @brief Intercambia los contenidos de dos variables enteras recibidas por referencia.
 *
 * @pre primer y segundo deben apuntar a direcciones de memoria validas (o ser NULL).
 * @post Los valores de *primer y *segundo quedan intercambiados; si alguno es NULL o apuntan a la misma direccion, no produce modificaciones.
 *
 * @param primer Puntero al primer valor entero a intercambiar.
 * @param segundo Puntero al segundo valor entero a intercambiar.
 */
void intercambiar(int *primer, int *segundo);



/**
 * @brief Determina el minimo y maximo de un arreglo recorriendolo estrictamente con punteros.
 *
 * @pre arreglo apunta a una secuencia contigua de al menos cantidad enteros, y minimo y maximo son punteros validos.
 * @post Escribe en *minimo y *maximo los valores extremos hallados y retorna true; retorna false si arreglo, minimo o maximo son NULL, o cantidad es 0.
 *
 * @param arreglo Puntero de solo lectura al inicio de la secuencia de enteros.
 * @param cantidad Cantidad de elementos a evaluar en el arreglo.
 * @param minimo Puntero de salida donde se almacenara el valor minimo encontrado.
 * @param maximo Puntero de salida donde se almacenara el valor maximo encontrado.
 *
 * @return bool true si se obtuvieron los extremos exitosamente, false ante parametros invalidos.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
