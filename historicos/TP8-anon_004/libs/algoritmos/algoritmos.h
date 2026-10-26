/**
 * @file algoritmos.h
 * @brief Biblioteca de Algoritmos Fundamentales: Ordenamiento, Multiplicación de Matrices y Recursión.
 *
 * Trabajo Práctico 8 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 *
 * Convención de tipos y estructuras:
 * - Toda definición con typedef debe utilizar nombres en minúsculas con sufijo '_t'.
 */

#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Ordena un arreglo de enteros de forma ascendente utilizando el algoritmo Bubble Sort (Burbuja).
 *
 * @param arreglo Puntero al inicio del bloque de enteros.
 * @param n Cantidad de elementos del arreglo.
 */
void ordenar_burbuja(int *arreglo, size_t n);

/**
 * @brief Ordena un arreglo de enteros de forma ascendente utilizando el algoritmo Insertion Sort (Inserción).
 *
 * @param arreglo Puntero al inicio del bloque de enteros.
 * @param n Cantidad de elementos del arreglo.
 */
void ordenar_insercion(int *arreglo, size_t n);

/**
 * @brief Ordena un arreglo de enteros de forma ascendente utilizando el algoritmo Selection Sort (Selección).
 *
 * @param arreglo Puntero al inicio del bloque de enteros.
 * @param n Cantidad de elementos del arreglo.
 */
void ordenar_seleccion(int *arreglo, size_t n);



/**
 * @brief Multiplica dos matrices contiguas en memoria (A de f_a x c_a y B de c_a x c_b).
 *
 * Almacena el resultado en la matriz destino C (de f_a x c_b).
 * Todas las matrices se representan como bloques contiguos de enteros (row-major order).
 *
 * @param a Puntero al bloque contiguo de la matriz A.
 * @param f_a Filas de A.
 * @param c_a Columnas de A (y filas de B).
 * @param b Puntero al bloque contiguo de la matriz B.
 * @param c_b Columnas de B.
 * @param c Puntero al bloque contiguo de destino donde se escribirá el producto.
 * @return true si la operación se realizó con éxito, o false si algún puntero es NULL o las dimensiones son 0.
 */
bool multiplicar_matrices_bloque(const int *a, size_t f_a, size_t c_a,
                                 const int *b, size_t c_b,
                                 int *c);



/**
 * @brief Busca un elemento en un arreglo ordenado ascendentemente mediante Búsqueda Binaria recursiva.
 *
 * @param arreglo Puntero al arreglo ordenado.
 * @param inicio Índice inferior del subarreglo.
 * @param fin Índice superior del subarreglo.
 * @param buscado Valor entero a localizar.
 * @return Índice del elemento si fue hallado, o -1 si no existe en el rango dado.
 */
long busqueda_binaria_recursiva(const int *arreglo, size_t inicio, size_t fin, int buscado);



#endif 
