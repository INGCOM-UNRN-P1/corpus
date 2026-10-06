/**
 * @file matriz_dinamica.h
 * @brief Biblioteca para gestionar matrices planas dinámicas en heap.
 *
 * Trabajo Práctico 4 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación.
 */

#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stddef.h>

/**
 * @brief Crea una matriz plana dinámica inicializada en cero.
 *
 * La matriz se almacena en un único bloque contiguo de memoria.
 *
 * @param filas Cantidad de filas de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 *
 * @pre filas y columnas deben ser mayores que cero.
 *
 * @post Si la creación es exitosa, se retorna un bloque contiguo de
 *       filas * columnas enteros inicializados en cero.
 *
 * @return Puntero al bloque reservado o NULL si las dimensiones son
 *         inválidas o falla la reserva de memoria.
 */
int *crear_matriz_plana(size_t filas, size_t columnas);

/**
 * @brief Obtiene el valor de una celda de la matriz.
 *
 * @param matriz Puntero al bloque contiguo de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 * @param fila Índice de la fila que se desea consultar.
 * @param columna Índice de la columna que se desea consultar.
 *
 * @pre matriz debe ser válida, columnas debe ser mayor que cero y fila y
 *      columna deben corresponder a una posición válida de la matriz.
 *
 * @post Retorna el valor almacenado en la celda indicada.
 *
 * @return Valor entero almacenado en la celda.
 */
int obtener_celda(const int *matriz, size_t columnas, size_t fila,
                  size_t columna);

/**
 * @brief Asigna un valor a una celda de la matriz.
 *
 * @param matriz Puntero al bloque contiguo de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 * @param fila Índice de la fila que se desea modificar.
 * @param columna Índice de la columna que se desea modificar.
 * @param valor Valor que se almacenará en la celda.
 *
 * @pre matriz debe ser válida, columnas debe ser mayor que cero y fila y
 *      columna deben corresponder a una posición válida de la matriz.
 *
 * @post La celda indicada contiene el valor recibido.
 */
void asignar_celda(int *matriz, size_t columnas, size_t fila, size_t columna,
                   int valor);

/**
 * @brief Libera la memoria ocupada por una matriz plana.
 *
 * @param matriz Puntero al bloque dinámico de la matriz.
 *
 * @pre matriz debe ser NULL o apuntar a memoria reservada dinámicamente.
 *
 * @post La memoria asociada a la matriz es liberada.
 */
void liberar_matriz_plana(int *matriz);

#endif 
