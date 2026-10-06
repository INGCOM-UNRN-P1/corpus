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
 * @brief se intercambian los contenidos en las variables.
 * @pre 'primero' y 'segundo' no pueden ser NULL.
 * Si ambos apuntan a la misma direccion de memoria debe preservarse el valor.
 * @post Se devuelven las variables cambiadas.
 * @param primer es la primera variable.
 * @param segundo es la segunda variable.
 * @return Se devuelven las variables intercambiadas o no,
 * depende de la precondicion.
 */
void intercambiar(int *primer, int *segundo);


/**
 * @brief determina el valor minimo y maximo del arreglo.
 * @pre 'arreglo', 'minimo', 'maximo' no pueden ser NULL.
 * 'Cantidad' no puede ser 0.
 * @post se devuelve true si se obtuvieron el minimo y maximo,
 * y false sino o falla alguna precondicion.
 * @param arreglo es el arreglo.
 * @param cantidad son la cantidad de elementos del arreglo.
 * @param minimo es el valor minimo que se busca.
 * @param maximo es el valor maximo que se busca.
 * @return se devuelve true si se obtuvieron el minimo y maximo,
 * y false sino o falla alguna precondicion.
 */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
