#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "vector.h"


/**
 * @brief Crea una matriz plana en heap.
 *
 * @param filas La cantidad de filas que va a tener la matriz.
 * @param columnas La cantidad de columnas que va a tener la matriz
 * @pre La suma de filas y columbnas no debe ser cero
 * @post Se crea una matriz plana en heap inicializada a cero.
 * @return Devuelve un puntero a una matriz en heap o nulo en caso de error.
 */
int *crear_matriz_plana(size_t filas, size_t columnas);


/**
 * @brief Obtiene el valor que contiene una celda en una matriz plana.
 *
 * @param m La matriz de la que se va a sacar el valor.
 * @param columnas La cantidad de columnas que tiene la matriz.
 * @param fila La fila de donde se va a sacar el valor.
 * @param col La columna de donde se va a sacar el valor.
 * @param valor Un puntero a un int donde se va a guardar el valor.
 * @pre m y valor no deben ser nulos. Columnas debe representar la cantidad de 
 * columnas en la matriz de forma acertada y fila y col no deben sobrepasar las
 * dimensiones de la matriz.
 * @post Se calculara el valor del elemento apuntado por fila y col sin modificar
 * ningun valor. El valor se devuelve por el parametro int *valor.
 * @return Devuelve true si la operacion se completo en exito o false en caso contrario.
 */
bool obtener_celda(const int *m, size_t columnas, size_t fila, size_t col, int *valor);

/**
 * @brief Asigna un valor a una celda en una matriz plana.
 *
 * @param m La matriz de la que se va a guardar el valor.
 * @param columnas La cantidad de columnas que tiene la matriz.
 * @param fila La fila de donde se va a guardar el valor.
 * @param col La columna de donde se va a guardar el valor.
 * @param valor El valor a guardar en la posicion apuntada por fila y col.
 * @pre m no debe ser nulo. Columnas debe representar la cantidad de 
 * columnas en la matriz de forma acertada y fila y col no deben sobrepasar las
 * dimensiones de la matriz.
 * @post Se escribira el valor en la posicion apuntada por fila y col sin modificar 
 * ningun otro valor.
 * @return Devuelve true si la operacion se completo en exito o false en caso contrario.
 */
bool asignar_celda(int *m, size_t columnas, size_t fila, size_t col, int valor);


/**
 * @brief Libera una matriz de forma segura.
 *
 * @param m La matriz a liberar
 * @pre m no debe ser nulo.
 * @post Se liberara m sin dejar punteros colgantes.
 */
void liberar_matriz_plana(int **m);

#endif 
