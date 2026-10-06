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
 * @brief Intercambia los valores de dos variables enteras pasadas por referencia.
 *
 * @details Si alguno de los punteros es nulo o si ambos apuntan a la misma 
 *          dirección de memoria, la función no realiza ninguna modificación 
 *          en la memoria.
 *
 * @param primer  Puntero al primer entero a intercambiar.
 * @param segundo Puntero al segundo entero a intercambiar.
 *
 * @pre Los punteros deben apuntar a direcciones de memoria válidas o ser NULL.
 * @post Si los punteros son válidos y distintos, se intercambian los valores 
 *       almacenados en *primer y *segundo. En cualquier otro caso, el estado 
 *       de la memoria se preserva intacto.
 *
 * @return void (no retorna ningún valor).
 */
void intercambiar(int *primer, int *segundo);


/**
 * @brief Determina el valor min y max de un puntero
 *
 * @param arreglo  Puntero a evaluar.
 * @param cantidad de elementos en el arreglo
 * @param minimo   puntero donde se almacenara valor min.
 * @param maximo   puntero donde se almacenara valor max.
 *
 * @pre *arreglo no debe ser null .
 *      cantidad no debe ser = 0
 * @pre *minimo y *maximo no deben ser null
 *
 * @post retorna true si ejecuto correctamente y pudo modificar los minimos y 
 *       maximos
 * @post retorna false si algun puntero es null , o cantidad == 0
 *
 *
 */

bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
