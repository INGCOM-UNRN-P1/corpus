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
 * @brief Calcula la suma algebraica de todos los elementos de un arreglo de 
 * enteros. 
 * @param arreglo El arreglo a calcular.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @pre arreglo no debe ser nulo.
 * @post El arreglo devuelve la sumatoria de los elementos en el arreglo, si 
 * cantidad 
 * es cero devuelve 0.
 * @returns Retorna 0 si el arreglo es nulo, de contrario retorna el valor de la
 * sumatoria.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);

/**
 * @brief Localiza el indice de la primera aparicion de un numero entero dentro 
 * del arreglo.
 * @param arreglo El arreglo en el que se buscara el entero.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @param buscado El numero entero que se desea buscar.
 * @pre arreglo no debe ser nulo y cantidad debe ser mayor a cero.
 * @post De encontrarse el numero entero en el arreglo se devolverá su posicion.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Invierte el odren de los elementos de un arreglo.
 * @param arreglo El arreglo al que se le modificara el orden de sus elementos.
 * @param cantidad La cantidad de elementos que tiene el arreglo.
 * @pre Si el arreglo es nulo o cantidad es menor o igual a 1 no se modifica el
 * arreglo
 * @post Se devuelve un arreglo la posicion de sus elementos invertida.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);

/**
 * @brief Verifica de manera segura que un arreglo este ordenado de mayor a menor.
 * @param arreglo El arreglo que se verificara.
 * @param cantidad La cantidad de elementos que tiene el arreglo.
 * @pre El arreglo no debe ser nulo y cantidad debe ser mayor a 0;
 * @post Se devolvera un valor booleano que indica si el arreglo esta ordenado.
 * @returns True si el arreglo esta ordenado ascendentemente o false si no lo esta.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);

/**
* @brief Cuenta y retorna cuántas veces aparece el un numero entero dentro del arreglo.
* @param arreglo El arreglo del que se contaran las ocurrencias.
* @param cantidad La cantidad de elementos que tiene el arreglo.
* @param buscado El numero entero que se buscara en el arreglo.
* @pre Cantidad debe ser de tipo size_t y debe ser mayor a 0, arreglo no debe ser nulo.
* @post Se devolvera un size_t con la cantidad de ocurrencias de un entero dentro del arreglo.
* @returns Retorna la cantidad de ocurrencias o 0 si el arreglo es nulo.
*/
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);

/**
 * @brief Elimina todas las apariciones de un valor entero dentro del arreglo, 
 * compactando los elementos restantes hacia la izquierda preservando su orden 
 * relativo original. 
 * @param arreglo El areglo que se compactara.
 * @param cantidad La cantidad de elementos en el arreglo.
 * @param valor El valor que se eliminara del arreglo.
 * @pre arreglo no debe ser nulo, cantidad debe ser mayor a 1.
 * @post Se modificara el arreglo eliminando las ocurrencias de valor y moviendo
 * los elementos en posiciones subsequentes a la izquierda.
 * @returns Retorna la cantidad de elementos eliminados.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);

/**
 * @brief Fusiona dos arreglos de enteros usando el algoritmo sort-merge. 
 * @param primero El primer arreglo que se fusionara.
 * @param cantidad_uno La cantidad de elementos del primer arreglo
 * @param segundo El segundo arreglo que se fusionara
 * @param candidad_segundo La cantidad de elementos del segundo arreglo.
 * @param destino El arreglo que se escribira con los elementos fusionados
 * @param capacidad La capacidad de destino
 * @pre Ninguno de los arreglos debe ser nulo y la capacidad de destino debe ser 
 * mayor o igual a la suma de elementos de primero y segundo.
 * @post Se modificara destino a partir del algoritmo sort-merge usando primero y segundo.
 * @returns Retorna la cantidad de elementos que se escribieron en destino.
 */
size_t arreglo_fusionar(
    const int primero[], 
    size_t cantidad_uno, 
    const int segundo[], 
    size_t cantidad_dos, 
    int destino[], 
    size_t capacidad);

#endif 
