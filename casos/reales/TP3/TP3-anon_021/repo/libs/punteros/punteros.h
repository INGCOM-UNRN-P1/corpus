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
 * @brief Intercambia los contenidos de dos variables enteras por referencia.
 * 
 * Recibe dos punteros a enteros y efectúa un intercambio seguro de sus valores 
 * utilizando una variable temporal auxiliar.
 * 
 * @param  primer Puntero a la primera variable entera a intercambiar.
 * @param segundo Puntero a la segunda variable entera a intercambiar.
 * 
 * @invariant Si alguno de los punteros es NULL, la función no realiza ninguna acción 
 *       ni intenta desreferenciar memoria. Si ambos punteros apuntan a la misma 
 *       dirección, el valor se preserva intacto de forma segura.
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Determina el valor mínimo y máximo de un arreglo de enteros.
 * 
 * Recorre un arreglo estricto de elementos utilizando exclusivamente aritmética 
 * de punteros (sin usar el operador de indexación []), evaluando y escribiendo 
 * los resultados en los parámetros de salida correspondientes.
 * 
 * @param arreglo Puntero constante al primer elemento del arreglo de enteros (solo lectura).
 * @param cantidad Número de elementos que contiene el arreglo.
 * @param minimo Puntero donde se almacenará el valor mínimo encontrado.
 * @param maximo Puntero donde se almacenará el valor máximo encontrado.
 * 
 * @return true Si el recorrido y la obtención de extremos se completaron con éxito.
 * @return false Si 'arreglo' es NULL, 'cantidad' es 0, o si alguno de los punteros 
 *         de salida ('minimo' o 'maximo') es NULL.
 * 
 * @invariant No se permite el uso de Arreglos de Longitud Variable (ALV) ni memoria dinámica.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
