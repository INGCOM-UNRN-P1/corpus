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
 * @brief Intercambia los valores apuntados por dos variables enteras.
 *
 * @param primer Puntero a la primera variable que se desea intercambiar.
 * @param segundo Puntero a la segunda variable que se desea intercambiar.
 *
 * @pre Tanto primer como segundo son direcciones válidas de memoria o pueden
 * ser NULL para indicar que la operación debe ser ignorada.
 *
 * @post Si ambos punteros son válidos y distintos, los valores almacenados en
 * las posiciones apuntadas quedan intercambiados. Si alguno es NULL o si ambos
 * apuntan a la misma dirección, la función no modifica el contenido.
 */
void intercambiar(int *primer, int *segundo);

/**
 * @brief Determina el mínimo y máximo de un arreglo de enteros.
 *
 * @param arreglo Arreglo de enteros a recorrer.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param minimo Puntero de salida donde se escribirá el valor mínimo.
 * @param maximo Puntero de salida donde se escribirá el valor máximo.
 *
 * @pre arreglo no es NULL, cantidad > 0 y minimo y maximo son punteros válidos.
 *
 * @returns true si pudo determinar los extremos con éxito, false si algún
 * argumento es inválido o la cantidad es cero.
 *
 * @post Si la ejecución fue exitosa, *minimo contiene el menor valor del
 * arreglo y *maximo contiene el mayor valor del arreglo.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo,
                     int *maximo);

/**
 * @brief Lee valores enteros desde la entrada estándar y los almacena en un arreglo.
 *
 * @param arreglo Puntero al primer elemento del arreglo donde se guardarán los
 * datos.
 * @param cantidad Cantidad de elementos a leer.
 *
 * @pre arreglo no es NULL y cantidad > 0.
 *
 * @post Los primeros `cantidad` elementos del arreglo contienen los valores
 * ingresados por el usuario.
 */
void leer_arreglo_int(int *arreglo, size_t cantidad);

/**
 * @brief Muestra un arreglo de enteros en formato de lista con estilo de depuración.
 *
 * @param arreglo Puntero al primer elemento del arreglo a imprimir.
 * @param cantidad Cantidad de elementos a mostrar.
 *
 * @pre arreglo no es NULL y cantidad > 0.
 *
 * @post Se imprime por salida estándar el contenido del arreglo como una
 * secuencia delimitada por comas.
 */
void mostrar_arreglo_int(const int *arreglo, size_t cantidad);

#endif 
