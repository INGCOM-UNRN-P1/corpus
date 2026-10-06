#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Se crea una matriz (2D).
 * @pre Ni 'filas', ni 'columnas' deben ser 0, de lo contrario se rotorna NULL.
 * @post Se devuelve una matriz en 2 dinmensiones compuesta
 *  por filas y columnas.
 * @param filas son la cantidad de filas de la matriz (arreglos).
 * @param columnas son la cantidad de columnas de la matriz.
 * @return Devuelve la direccion de memoria de una matriz.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera la memoria de una matriz contigua.
 * @pre '**matriz' no debe ser NULL.En ese caso no se hara nada.
 * @post Se libera la memoria y si **matriz era NULL no se hace nada.
 * @note Orden de liberacion:
 *      1. Se libera el bloque de datos.
 *      2. Luego el arreglo de punteros a filas.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Realiza una matriz dinamica a partir de los datos de un archivo.
 * @pre Ni 'ruta_archivo', ni 'filas', ni 'columnas' deben ser NULL.
 * @post Genera una matriz con los datos del archivo.
 * @param ruta_archivo Es la direccion o nombre del archivo.
 * @param filas son la cantidad de filas de la matriz (arreglos).
 * @param columnas son la cantidad de columnas de la matriz.
 * @return Devuelve la direccion de memoria de una matriz
 *  creada a partir de un archivo.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas,
                              size_t *columnas);
#endif 
