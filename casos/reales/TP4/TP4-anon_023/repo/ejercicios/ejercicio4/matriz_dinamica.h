/**
 * @file matriz_dinamica.h
 * @brief Ejercicio 4: Matriz Dinamica Bidimensional con Bloque Contiguo.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una matriz 2D con un unico bloque contiguo de datos en el heap.
 *
 * Asigna memoria contigua para (filas * columnas) enteros inicializados en cero,
 * y un arreglo de punteros (int *) donde cada elemento apunta al inicio de cada fila.
 *
 * @param[in] filas Cantidad de filas (mayor a 0).
 * @param[in] columnas Cantidad de columnas (mayor a 0).
 *
 * @return Puntero int** a las filas de la matriz, o NULL si fallan las dimensiones o la memoria.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Destruye una matriz dinamica de bloque contiguo y anula su referencia.
 *
 * Libera primero el bloque de datos contiguo y posteriormente el arreglo de punteros,
 * asignando NULL al puntero del llamador para prevenir punteros colgantes.
 *
 * @param[in, out] matriz Puntero a la variable int** de la matriz.
 */
void matriz_destruir(int ***matriz);

/**
 * @brief Carga una matriz dinamica desde un archivo de texto en formato CSV.
 *
 * Lee el archivo, detecta la cantidad de filas y columnas, asigna la matriz contigua
 * y parsea los numeros enteros separados por comas.
 *
 * @param[in] ruta_archivo Ruta al archivo .csv.
 * @param[out] filas_out Puntero donde se almacenara la cantidad de filas leidas.
 * @param[out] columnas_out Puntero donde se almacenara la cantidad de columnas leidas.
 *
 * @return Puntero int** a la matriz cargada, o NULL ante error de lectura o asignacion.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas_out, size_t *columnas_out);

#endif 
