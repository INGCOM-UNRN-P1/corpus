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
* @brief Suma todos los elementos de un arreglo.
*
* @param arreglo Arreglo de enteros.
* @param cantidad Cantidad de elementos del arreglo.
*
* @return La suma de los elementos, o 0 si el arreglo es NULL o cantidad es 0.
*/
long long arreglo_sumar(const int arreglo[], size_t cantidad);



 /**
 * @brief Busca un valor en un arreglo.
 *
 * @param arreglo Arreglo de enteros donde se busca.
 * @param cantidad Cantidad de elementos del arreglo.
 * @param buscado Valor a buscar.
 *
 * @return La posición de la primera aparición de buscado, o -1 si no está o 
 *         si arreglo es NULL o cantidad es 0.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);



 /**
 * @brief Invierte el orden de los elementos de un arreglo.
 *
 * @param arreeglo Arreglo de enteros a invertir.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @note Si arreglo es NULL o cantidad es 0 o 1, no hace nada.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);



 /**
 * @brief Indica si un arreglo está ordenado de menor a mayor.
 *
 * @param arreglo Arreglo de enteros a verificar.
 * @param cantidad Cantidad de elementos del arreglo.
 *
 * @return true si el arreglo está ordenado ascendentemente, o si tiene 0 o 1 elementos.
 * @return false si algún elemento es mayor que el siguiente, o si arreglo es NULL.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);



/**
* @brief Cuenta cuántas veces aparece un valor en un arreglo.
*
* @param arreglo Arreglo de enteros donde se cuenta.
* @param cantidad Cantidad de elementos del arreglo.
* @param buscado Valor a contar.
*
* @return La cantidad de veces que aparece buscad, o 0 si no aparece
*         o si arreglo es NULL o cantidad es 0.
*/
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);



/**
* @brief Elimina de un arreglo todas las apariciones de un valor.
*
* @param arreglo Arreglo de enteros a compactar.
* @param cantidad Cantidad de elementos del arreglo.
* @param valor Valor que se quiere eliminar.
*
* @return La nueva cantidad de elementos validos del arreglo, o 0 si arreglo es
*         NULL o cantidad es 0.
* @note Las posiciones a partir de la nueva cantidad quedan con valores
*       sin importancia, y no se usan.
*/
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



/**
* @brief Fusiona dos arreglos ordenados en un tercero, tambien ordenado.
*
* @param primero Arreglo ordenado ascendentemente.
* @param cantidad_uno Cantidad de elementos de primero.
* @param segundo Arreglo ordenado ascendendemente.
* @param cantidad_dos Cantidad de elementos de segundo.
* @param destino Arreglo donde se guarda el resultado.
* @param capacidad Cantidad máxima de elementos que entran en destino.
*
* @return Cantidad de elementos guardados en destino. Devuelve 0 si destino es NULL,
*         si capacidad es 0 o si un arreglo con elementos es
*/

size_t arreglo_fusionar(const int primero [], size_t cantidad_uno, const int segundo [], size_t cantidad_dos,int destino [], size_t capacidad);
#endif 
