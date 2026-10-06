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
 * @brief Intercambia los valores contenidos en dos variables enteras
 *        recibidas por referencia.
 * @param primer Puntero a la primera variable entera a intercambiar.
 * @param segundo Puntero a la segunda variable entera a intercambiar.
 * @pre primer y segundo pueden ser NULL o apuntar a memoria valida.
 * @post Si preimer y segundo son distintos de NULL, el valor apuntado por
 *       primer pasa a ser el que originalmente apuntaba segundo, y viceversa.
 * @post Si primer o segundo son NULL, la funcion noi produce ningun efecto.
 * @post Si primer y segundo apuntan a la misma direccion de memoria, el 
 *       valor se preserva intacto.
 * @return void No retorna ningun valor.
*/
void intercambiar(int *primer, int *segundo);



 /**
  * @brief Determina el valor minimo y maximo de un arreglo de enteros,
  *        recorriendolo mediante aritmetica de punteros.
  * @param arreglo Puntero al primer elemento del arreglo de enteros a analizar.
  * @param cantidad Cantidad de elementos que contiene el arreglo.
  * @param minimo Puntero de salida donde se almacenera el valor minimo encontrado.
  * @param maximo Puntero de salida donde se almacenara el valor maximo encontrado.
  * @pre arreglo, minimo y maximo pueden ser NULL.
  * @pre cantidad puede ser 0.
  * @post Si arreglo, minimo y maximo son distintos de NULL, y cantidad es
  *       mayor a 0, *minimo contiene el menor valor del arreglo y *maximo
  *       contien el mayor valor del arreglo.
  * @post Si arreglo, minimo o maximo son NULL, o si cantidad es 0, la funcion
  *       no produce ningun efecto y retorna false.
  * @return true si pudo determinar el minimo y el maximo existosamente.
  * @return false si arreglo, minimo o maximo son NULL, o si cantidad es 0.
  */
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
