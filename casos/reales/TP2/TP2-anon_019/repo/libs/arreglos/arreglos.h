/**
 * @file arreglos.h
 * @brief Biblioteca de manipulación y procesamiento de arreglos de enteros (int).
 *
 * Trabajo Práctico 2 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convenciones de Estilo y Seguridad:
 * - Nombres de variables y parámetros descriptivos, de hasta dos palabras,
 *   sin abreviaturas y con un máximo de 12 caracteres.
 * - Todo arreglo viene acompañado por su cantidad de elementos válidos (size_t cantidad).
 * - Arreglos de solo lectura (const int arreglo[]) para funciones que no modifican datos.
 * - Arreglos mutables (int arreglo[]) para funciones que modifican contenido in-place.
 */

#ifndef ARREGLOS_H
#define ARREGLOS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Calcula la suma algebraica de todos los elementos enteros del arreglo.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post El arreglo de origen no se modifica.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos validos en el arreglo.
 * @return long long Suma total de los elementos. Retorna 0 si arreglo es nulo o cantidad es 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);

/**
 * @brief Localiza el indice de la primera aparicion de un numero en el arreglo.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post El arreglo de origen no se modifica.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos validos en el arreglo.
 * @param buscado Numero entero que se desea localizar.
 * @return int Indice en base cero de la primera ocurrencia. Retorna -1 si no se encuentra, 
 *         si el arreglo es nulo o si la cantidad es 0.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Invierte in-place el orden de los elementos del arreglo.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post Los elementos del arreglo quedan ordenados de manera simetricamente opuesta.
 * 
 * @param arreglo Arreglo de enteros mutable a invertir.
 * @param cantidad Cantidad de elementos validos en el arreglo.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);

/**
 * @brief Verifica si los elementos del arreglo estan ordenados de forma ascendente.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post El arreglo de origen no se modifica.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos validos en el arreglo.
 * @return bool true si esta ordenado ascendentemente o cantidad <= 1, false si 
 *         esta desordenado o el arreglo es nulo.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);

/**
 * @brief Cuenta cuantas veces aparece un numero entero dentro del arreglo.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post El arreglo de origen no se modifica.
 * 
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad de elementos validos en el arreglo.
 * @param buscado Numero entero a buscar y contar.
 * @return size_t Cantidad de coincidencias encontradas. Retorna 0 si arreglo es nulo o cantidad es 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Elimina in-place todas las apariciones de un valor, compactando el arreglo.
 *
 * @pre El puntero al arreglo no debe ser nulo (NULL).
 * @post Los elementos conservan su orden relativo original y se desplazan hacia el inicio.
 * 
 * @param arreglo Arreglo de enteros mutable.
 * @param cantidad Cantidad original de elementos validos en el arreglo.
 * @param valor Numero entero que se desea eliminar del arreglo.
 * @return size_t Nueva cantidad de elementos validos tras la compactacion.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);

#endif 