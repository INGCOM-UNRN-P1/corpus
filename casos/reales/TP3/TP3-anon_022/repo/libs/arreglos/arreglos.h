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
 * @brief Calcula y retorna la suma de todos los elementos enteros del arreglo.
 * @param arreglo cuyos elementos se desean sumar.
 * @param cantidad Número de elementos válidos del arreglo.
 *
 * @return La suma de los elementos, o 0 si arreglo es nulo o la cantidad es 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);



/**
 * @brief Busca la primera aparición de un valor entero en el arreglo.
 *
 * @param arreglo donde se realizará la búsqueda.
 * @param cantidad Número de elementos válidos del arreglo.
 * @param buscado Valor entero que se desea buscar.
 *
 * @return El índice en base cero de la primera aparición del valor buscado,
 *         o -1 si el arreglo es nulo, está vacío o el valor no se encuentra.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);



/**
 * @brief Invierte el orden de los elementos de un arreglo sobre su misma memoria.
 *
 * @param arreglo cuyo orden de elementos se desea invertir.
 * @param cantidad Número de elementos válidos del arreglo.
 *
 * @post El arreglo queda con sus elementos en orden inverso al original.
 *       No se modifica si es nulo o contiene uno o ningún elemento.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);



/**
 * @brief Comprueba si los elementos de un arreglo se encuentran ordenados
 *        de forma ascendente.
 *
 * @param arreglo cuyo orden de elementos se desea verificar.
 * @param cantidad Número de elementos del arreglo.
 *
 * @return true si el arreglo está ordenado de forma ascendente o contiene
 *         uno o ningún elemento.
 *         false si el arreglo es nulo o contiene elementos fuera de orden.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);



/**
 * @brief Cuenta cuántas veces aparece un número entero dentro del arreglo.
 *
 * @param arreglo donde se buscará el número entero.
 * @param cantidad Cantidad de elementos válidos del arreglo.
 * @param buscado Número entero cuya cantidad de apariciones se desea contar.
 *
 * @return Cantidad de veces que aparece el valor buscado en el arreglo.
 *         Retorna 0 si el arreglo es nulo o si la cantidad es 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);



/**
 * @brief Elimina todas las apariciones de un valor entero dentro de un arreglo,
 *        compactando el resto de sus elementos hacia el inicio y preservando
 *        su orden original.
 *
 * @param arreglo cuyos elementos se desean compactar.
 * @param cantidad Número de elementos válidos del arreglo.
 * @param valor Entero que se desea eliminar del arreglo.
 *
 * @return Nueva cantidad de elementos válidos del arreglo después de eliminar
 *         todas las apariciones de valor. Retorna 0 si el arreglo es nulo.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



#endif 
