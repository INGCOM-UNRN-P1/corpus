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
* @brief Intercambia los contenidos de dos variables enteras recibidas por referencia. Modifica directamente el contenido de las posiciones de memoria apuntadas 
* por 'primer' y 'segundo'. Si alguno de los punteros es NULL o si ambos 
* apuntan a la misma dirección de memoria, no produce ningún efecto. 
* 
* @param primer Puntero a la primera variable entera (lectura y escritura). 
* @param segundo Puntero a la segunda variable entera (lectura y escritura). 
* 
* @pre Si 'primer' != NULL y 'segundo' != NULL, ambos deben apuntar a bloques de memoria válidos. 
* @post Los valores almacenados en las direcciones apuntadas quedan intercambiados. 
*/ 
 void intercambiar(int *primer, int *segundo);



/**
* @brief Obtiene los valores mínimo y máximo de un arreglo de enteros mediante punteros. * Recorre el arreglo utilizando estrictamente aritmética de punteros y
*
* @param arreglo Puntero al primer elemento del arreglo de enteros (lectura exclusivamente). 
* @param cantidad Cantidad de elementos válidos en el arreglo. 
* @param minimo Puntero donde se almacenará el valor mínimo encontrado (salida). 
* @param maximo Puntero donde se almacenará el valor máximo encontrado (salida). 
* 
* @pre Si 'cantidad' > 0 y 'arreglo' != NULL, 'arreglo' debe apuntar a un bloque de memoria válido. 
* @pre Si retorna true, 'minimo' y 'maximo' deben apuntar a posiciones de memoria válidas. 
* @post Si retorna true, *minimo contendrá el menor elemento y *maximo el mayor elemento. 
* 
* @return true si se determinaron correctamente el mínimo y el máximo, 
* false si 'arreglo', 'minimo' o 'maximo' son NULL, o si 'cantidad' es 0. 
*/ 
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
