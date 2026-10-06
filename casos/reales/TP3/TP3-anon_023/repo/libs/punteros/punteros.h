/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmetica de punteros.
 *
 * Trabajo Practico 3 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Intercambia los contenidos de dos variables enteras recibidas por referencia.
 *
 * Realiza una modificacion in-place de los valores en sus respectivas celdas de memoria.
 *
 * @pre Los punteros deben apuntar a bloques de memoria modificables si no son NULL.
 * @post Si ambos punteros son validos y diferentes, sus contenidos quedan permutados.
 *       Si alguno es NULL o ambos apuntan a la misma direccion, los datos quedan inalterados.
 *
 * @param[in, out] primer Puntero a la primera variable entera.
 * @param[in, out] segundo Puntero a la segunda variable entera.
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Determina el valor minimo y el valor maximo de un arreglo de enteros.
 *
 * Recorre la secuencia en memoria contigua utilizando exclusivamente aritmetica de punteros.
 * Escribe los extremos hallados en las variables referenciadas por los parametros de salida.
 *
 * @pre El puntero `arreglo` debe apuntar a un bloque contiguo de al menos `cantidad` enteros.
 * @pre Los punteros de salida `minimo` y `maximo` deben referenciar posiciones de memoria validas y modificables.
 * @post No modifica los elementos contenidos en `arreglo`.
 *
 * @param[in] arreglo Puntero al inicio del arreglo de enteros (solo lectura).
 * @param[in] cantidad Cantidad de elementos validos en el arreglo.
 * @param[out] minimo Puntero donde se almacenara el valor numerico minimo hallado.
 * @param[out] maximo Puntero donde se almacenara el valor numerico maximo hallado.
 *
 * @return true si se determinaron y escribieron los extremos con exito, false si `arreglo` es NULL,
 *         `cantidad` es 0 o si alguno de los punteros de salida es NULL.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
