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
 * @param primer Puntero a la primera variable entera.
 * @param segundo Puntero a la segunda variable entera.
 *
 * @pre Ninguna.
 *
 * @post Si 'primer' o 'segundo' es NULL, no se modifica ningún valor.
 *       Si ambos punteros son válidos, los valores apuntados se intercambian.
 *       Si 'primer' y 'segundo' apuntan a la misma dirección, el valor se preserva.
 */
void intercambiar(int *primer, int *segundo);



/**
 * @brief Determina el valor mínimo y el valor máximo de un arreglo de enteros.
 *
 * @param arreglo Puntero constante al primer elemento del arreglo.
 * @param cantidad Cantidad de elementos en el arreglo.
 * @param minimo Puntero de salida donde se almacenará el valor mínimo hallado.
 * @param maximo Puntero de salida donde se almacenará el valor máximo hallado.
 *
 * @pre Si 'cantidad' es mayor que 0, 'arreglo' debe apuntar a una secuencia
 *      válida de al menos 'cantidad' elementos.
 *
 * @post Si retorna true, '*minimo' y '*maximo' contienen los valores mínimo
 *       y máximo del arreglo, y el arreglo original no es modificado.
 *       Si retorna false, no se garantiza ningún valor en '*minimo' ni '*maximo'.
 *
 * @return true si los valores extremos se determinaron con éxito.
 *         false si 'arreglo' es NULL, 'cantidad' es 0, 'minimo' es NULL
 *         o 'maximo' es NULL.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
