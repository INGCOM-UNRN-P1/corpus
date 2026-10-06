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
 * @brief Intercambia los contenidos de dos variables enteras recibidas 
 * por referencia a través de punteros.
 *
 * @param primer puntero que intercambia el primer valor entero.
 * @param segundo puntero que cambia el segundo valor entero.
 * 
 * @pre la función no debe producir ningún efecto ni intentar 
 *      desreferenciar memoria si alguno de los punteros es NULL. 
 *      el valor debe preservarse intacto si ambos punteros apuntan 
 *      a la misma dirección de memoria. 
 * 
 * @return el intercambio de dos enteros recibidos por '*primero' 
 *         y '*segundo'.
 *
 * @post el resultado es lo mismo que decir *primer = *segundo y  
 *       *segundo = aux. aux es una variable entera que permite 
 *       irtercambiar el valor ce cada puntero entre ellos.
 *
 * @invariant ----------------------------------------------------
*/
void intercambiar(int *primer, int *segundo);












 /** 
 * @brief Determina el valor mínimo y el valor máximo de un arreglo de enteros,
 * escribiendo los resultados en las variables apuntadas por 'minimo' y 'maximo'.
 
 * @param arreglo puntero de 'arreglo' a ser examinado.
 * @param cantidad define la cantidad de elementos dentro de 'arreglo'.
 * @param minimo puntero que escribe el valor mínimo de 'arreglo'.
 * @param maximo puntero que escribe el valor máximo de 'arreglo'.
 * 
 * @pre El recorrido del arreglo debe realizarse estrictamente mediante
 *   aritmética de punteros (sin usar el operador []). Por último, no se debe 
 * utilizar memoria dinámica.
 * 
 * @return 'true' si pudo determinar ambos valores con éxito.
 *         'false' si 'arreglo' es NULL, si 'cantidad' es 0, o si alguno de 
 *          los punteros de salida ('minimo' o 'maximo') es NULL, sin provocar 
 *          accesos inválidos a memoria.
 * 
 * @post el resultado es igual a recorrer el arreglo y verificar en que momento
 * 'arreglo[i] > *maximo para sobreescribir el nuevo valor. Lo contrario con
 * el puntero minimo.
 *
 * @invariant 'arreglo'
*/
bool obtener_min_max(const int *arreglo, size_t cantidad, int *minimo, int *maximo);

#endif 
