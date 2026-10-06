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
 * @brief Calcular y retornar la suma algebraica de todos los elementos enteros del
 * arreglo.
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @return la suma de los elementos de la cadena.
 * @pre Si el arreglo es nulo o la cantidad es 0, retorna 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);


/**
 * @brief Localiza el índice en base cero de la primera aparición del número
 * entero buscado dentro del arreglo.
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @param buscado es el elemento que se desea encontrar.
 * @return el índice en base cero del elemento, -1 si no está presente,
 * si el arreglo es nulo o si la cantidad es 0.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Invierte el orden de los elementos del arreglo directamente sobre su misma
 * memoria (in-place).
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @pre Si el arreglo es nulo o la cantidad es menor o igual a 1,
 * no debe realizar ninguna modificación.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);


/**
 * @brief Verifica si los elementos del arreglo se encuentran ordenados de forma
 * ascendente.
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @return true si está ordenado o si cantidad <= 1. false si no está ordenado
 * o si el arreglo es nulo.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/**
 * @brief Cuenta y retorna cuántas veces aparece el número entero buscado dentro
 * del arreglo.
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @param buscado es el elemento a buscar.
 * @return la cantidad de ocurrencias. 0 si el arreglo es nulo o la cantidad es 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Elimina in-place todas las apariciones de un
 * valor entero dentro de un arreglo, compactando los elementos restantes
 * hacia el inicio sin dejar huecos y preservando su orden relativo original.
 * @param arreglo[] es el puntero al inicio de la cadena.
 * @param cantidad es la cantidad de elementos en la cadena.
 * @param valor es el elemento a eliminar de la cadena.
 * @return la cantidad de elementos válidos/largo del nuevo arreglo. Si el arreglo
 * es nulo o cantidad es 0, devuelve 0.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);


/**
 * @brief Dados dos arreglos de enteros previamente ordenados ascendentemente,
 * fusionar sus elementos en un tercer arreglo destino, manteniéndolo
 * ordenado ascendentemente.
 * @param primero[] es el puntero al inicio del primer arreglo.
 * @param segundo[] es el puntero al inicio del segundo arreglo.
 * @param cantidad_uno es la cantidad de elementos del primer arreglo.
 * @param cantidad_dos es la cantidad de elementos del segundo arreglo.
 * @param destino[] es el arreglo resultado de la fusión de los anteriores.
 * @param capacidad es la cantidad de elementos del arreglo destino.
 * @return la cantidad de elementos escritos en el arreglo destino.
 */
size_t arreglo_fusionar(const int primero[], size_t cantidad_uno, const int segundo[], size_t cantidad_dos, int destino[], size_t capacidad);
#endif 
