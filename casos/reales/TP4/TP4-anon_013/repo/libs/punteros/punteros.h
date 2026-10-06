/**
 * @file punteros.h
 * @brief Biblioteca de operaciones fundamentales con punteros y aritmética de
 * punteros.
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
 * Recuerden que no está permitido utilizar ALV's (Arreglos de Longitud Variable
 * / VLA), pero también, este ejercicio no está pensado para utilizar memoria
 * dinámica.
 */

#ifndef PUNTEROS_H
#define PUNTEROS_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Intercambia los contenidos de dos variables enteras recibidas por
 * referencia a través de punteros.
 * @param primer es el puntero al primer valor.
 * @param segundo es el puntero al segundo valor.
 * @post si algun puntero es NULL o apuntan a la misma dirección de memoria,
 * no opera.
 */
void intercambiar(int *primer, int *segundo);


/**
 * @brief Determina el valor mínimo y el valor máximo de un arreglo de enteros,
 * escribiendo los resultados en las variables apuntadas por 'minimo' y
 * 'maximo'.
 *
 * @param arreglo es el puntero al inicio del arreglo.
 * @param cantidad es el tamaño del arreglo.
 * @param minimo es el puntero a la variable que guarda el valor minimo.
 * @param maximo es el puntero a la variable que guarda el valor maximo.
 *
 * @pre si los punteros no son NULL, deben apuntar a enteros accesibles.
 * @pre si el arreglo no es NULL debe apuntar al menos a 'cantidad' elementos
 * validos.
 *
 * @post si return = true, 'minimo' contiene el menor valor del arreglo y
 * 'maximo' el mayor.
 * @post si return = false, no se modifica ninguna variable apuntada.
 *
 * @return true si se pudieron determinar un maximo y un minimo.false caso
 * contratio.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo,
                     int *maximo);

#endif 
