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
 * @brief Realiza una sumatoria de todos los elementos de un arreglo mediante un bucle for.
 *          El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return Suma de todos los arreglos o 0 si no se cumplen las precondiciones.
 */

long long arreglo_sumar(const int arreglo[], size_t cantidad);


/**
 * @brief Busca un valor entero dentro de un arreglo mediante un bucle for 
 *   El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @param buscado el elemento a buscar dentro del arreglo.
 * @return Posicion del valor buscado o -1 si no se encuentra o si no se cumplen las precondiciones.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Invierte el orden de los elementos en un arreglo in-place utlizando las caracteristicas
 *      de los arreglos para modificar utilizando la direccion dada.
 *   El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int][in] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return arreglo[out] con los elementos invertidos o el arreglo sin modificar.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);


/**
 * @brief Verifica si los elementos de un arreglo están ordenados de forma ascendente.
 *   El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @return true si el arreglo está ordenado,
 *          false si las precondiciones no se cumplen o si el arreglo no esta ordenado.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/**
 * @brief Busca un valor dado dentro de un arreglo y realiza un conteo de cuantas veces
 *  aparece en el mismo arreglo.
 *   El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @param buscado el elemento a buscar dentro del arreglo.
 * @return Cantidad de veces que aparece el valor buscado o 0 si no se encuentra o si no se dan las precondiciones.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Busca un valor entero dentro de un arreglo mediante un bucle for 
 *      ese valor es "eliminado" del arreglo y los elementos restantes se compactan hacia el inicio
 *      preservando su orden relativo original.
 *   El arreglo no debe ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 * @param arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad[size_t] de elementos en el arreglo.
 * @param valor a eliminar.
 * @return nueva cantidad size_t correspondiente a los elementos restantes o 0 si no se cumplen las precondiciones.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);

/**
 * @brief Busca un valor entero dentro de un arreglo mediante un bucle for 
 *   Los arreglos no deben ser NULL y la cantidad de elementos debe ser mayor o igual a 0.
 *   la capacidad del arreglo destino debe ser mayor o igual a la suma de las capacidades de los arreglos origen.
 *   los arreglos origen deben estar ordenados de forma ascendente.
 * @param primer_arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad_uno[size_t] de elementos en el primer arreglo.
 * @param segundo_arreglo[int] direccion a un arreglo de enteros.
 * @param cantidad_dos[size_t] de elementos en el segundo arreglo.
 * @param destino[int][in] direccion a un arreglo de enteros.
 * @param capacidad_destino[size_t] de elementos que puede contener el arreglo destino.
 * @return Nueva capacidad destino resultado del conteo de elementos o 0 si no se cumplen las precondiciones.
 * @return destino[out] con los elementos de los arreglos origen fusionados y en orden ascendente
 *           o el arreglo destino vacio.
 */

size_t arreglo_concatenar(const int primer_arreglo[], size_t capacidad_primero,
                         const int segundo_arreglo[], size_t capacidad_segundo,
                         int destino[], size_t capacidad_destino);
#endif 
