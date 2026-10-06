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
 * @brief Intercambia los valores almacenados en dos variables enteras mediante punteros.
 *
 * @details Si alguno de los punteros recibidos es NULL, la función no realiza
 *          ningún tipo de operación ni desreferencia memoria. Si ambos punteros
 *          apuntan a la misma dirección de memoria, el valor contenido se preserva.
 *
 * @param[in,out] primer Puntero a la primera variable entera a intercambiar.
 * @param[in,out] segundo Puntero a la segunda variable entera a intercambiar
 *
 * @pre Ambos punteros 'primer' y 'segundo' deben ser válidos o NULL.
 * @post Si los punteros son válidos, el valor apuntado por 'primer' pasa a ser
 *       el valor apuntado por 'segundo', y viceversa. Si alguno es NULL, no se modifica ningún valor.
 *
 * @return Ninguno (void).
 */

void intercambiar(int *primer, int *segundo);



 /**
 * @brief Obtiene el valor mínimo y máximo de un arreglo de enteros mediante aritmética de punteros.
 *
 * @details Recorre el arreglo de enteros apuntado por 'arreglo' utilizando únicamente
 *          aritmética de punteros (sin usar el operador de indexación '[]') para determinar
 *          el elemento de menor y mayor valor, los cuales son escritos en las direcciones
 *          apuntadas por 'minimo' y 'maximo' respectivamente.
 *
 * @param[in] arreglo Puntero constante al primer elemento del arreglo de enteros.
 * @param[in] cantidad de elementos contenidos en el arreglo.
 * @param[out] minimo Puntero a la variable donde se almacenará el valor mínimo encontrado.
 * @param[out] maximo Puntero a la variable donde se almacenará el valor máximo encontrado.
 *
 * @pre El puntero 'arreglo' debe apuntar a un arreglo válido de al menos 'cantidad' elementos.
 * @pre Los punteros 'minimo' y 'maximo' deben apuntar a direcciones de memoria válidas.
 * @post Si la operación es exitosa (retorna true), '*minimo' contendrá el menor elemento
 *       y '*maximo' contendrá el mayor elemento del arreglo.
 *
 * @return 'true' si el arreglo no es NULL, 'cantidad' es mayor a 0 y los punteros 'minimo'
 *         y 'maximo' no son NULL; 'false' en cualquier otro caso.
 */

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
