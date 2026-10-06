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
 * @brief Calcula la suma algebraica de todos los elementos de un arreglo.
 *
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad total de elementos en el arreglo.
 *
 * @pre Si 'cantidad' > 0, 'arreglo' no debe ser NULL.
 * @post El contenido del arreglo no se modifica.
 *
 * @return long long Suma total de los elementos, o 0 si 'arreglo' es NULL o 'cantidad' es 0.
 */
long long arreglo_sumar(const int arreglo[], size_t cantidad);


/**
 * @brief Localiza el índice en base cero de la primera aparición de un valor.
 *
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad total de elementos en el arreglo.
 * @param buscado Número entero que se desea localizar.
 *
 * @pre Si 'cantidad' > 0, 'arreglo' no debe ser NULL.
 * @post El contenido del arreglo no se modifica.
 *
 * @return int Índice base cero del elemento buscado, o -1 si no se encuentra,
 *             si 'arreglo' es NULL o si 'cantidad' es 0.
 */
int arreglo_buscar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Invierte el orden de los elementos del arreglo directamente sobre su memoria.
 *
 * @param arreglo Arreglo mutable de enteros a modificar in-place.
 * @param cantidad Cantidad total de elementos en el arreglo.
 *
 * @pre Si 'cantidad' > 1, 'arreglo' no debe ser NULL.
 * @post Los elementos del arreglo quedan reflejados en orden inverso.
 */
void arreglo_invertir(int arreglo[], size_t cantidad);


/**
 * @brief Verifica si los elementos se encuentran ordenados de forma ascendente.
 *
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad total de elementos en el arreglo.
 *
 * @pre Si 'cantidad' > 1, 'arreglo' no debe ser NULL.
 * @post El contenido del arreglo no se modifica.
 *
 * @return bool 'true' si está ordenado o si 'cantidad' <= 1.
 *              'false' si está desordenado o si 'arreglo' es NULL.
 */
bool arreglo_ordenado(const int arreglo[], size_t cantidad);


/**
 * @brief Cuenta cuántas veces aparece un número entero dentro del arreglo.
 *
 * @param arreglo Arreglo de enteros de solo lectura.
 * @param cantidad Cantidad total de elementos en el arreglo.
 * @param buscado Número entero del cual se cuentan las ocurrencias.
 *
 * @pre Si 'cantidad' > 0, 'arreglo' no debe ser NULL.
 * @post El contenido del arreglo no se modifica.
 *
 * @return size_t Cantidad de coincidencias halladas, o 0 si 'arreglo' es NULL o 'cantidad' es 0.
 */
size_t arreglo_contar(const int arreglo[], size_t cantidad, int buscado);


/**
 * @brief Elimina in-place todas las apariciones de un valor dentro del arreglo.
 *
 * Compacta los elementos restantes hacia la izquierda sin dejar huecos.
 *
 * @param arreglo Arreglo mutable de enteros a modificar in-place.
 * @param cantidad Cantidad total de elementos iniciales.
 * @param valor Valor entero a eliminar.
 *
 * @pre Si 'cantidad' > 0, 'arreglo' no debe ser NULL.
 * @post Los elementos válidos quedan reubicados al inicio conservando su orden relativo.
 *
 * @return size_t Cantidad de elementos válidos restantes tras la compactación.
 */
size_t arreglo_compactar(int arreglo[], size_t cantidad, int valor);



#endif 
