#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Crea una matriz dinámica 2D representada mediante un bloque contiguo de datos en el heap.
 *
 * @param filas Número de filas (debe ser > 0).
 * @param columnas Número de columnas (debe ser > 0).
 * @return Puntero int** a las filas de la matriz, o NULL en caso de error o parámetros inválidos.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera la memoria reservada para la matriz creada con matriz_crear.
 *
 * @param matriz Puntero a la matriz a liberar.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Carga una matriz desde un archivo CSV con valores enteros.
 *
 * @param ruta_archivo Ruta del archivo CSV a leer.
 * @param filas_out Puntero donde se almacenará la cantidad de filas leídas.
 * @param columnas_out Puntero donde se almacenará la cantidad de columnas leídas.
 * @return Puntero int** a la matriz creada y cargada, o NULL en caso de error.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas_out, size_t *columnas_out);
#endif 
