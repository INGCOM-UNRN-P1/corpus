#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una matriz dinamica 2D con un bloque de memoria contiguo.
 *
 * @param[in] filas Cantidad de filas de la matriz.
 * @param[in] columnas Cantidad de columnas de la matriz.
 * @return int** Puntero al arreglo de filas, o NULL en caso de error.
 * 
 * #PRE 'filas' y 'columnas' deben ser mayores a 0. Su producto no debe exceder SIZE_MAX.
 * #POST Retorna un arreglo de punteros donde cada uno apunta al inicio de su fila respectiva dentro de un unico bloque contiguo en el heap.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera la memoria de una matriz dinamica y previene punteros colgantes.
 *
 * @param[in, out] matriz Doble puntero por referencia (int ***) a la matriz.
 * 
 * #PRE 'matriz' no debe ser NULL.
 * #POST Libera el bloque contiguo de datos, luego el arreglo de punteros, y asigna NULL al puntero original.
 */
void matriz_destruir(int ***matriz);

/**
 * @brief Carga una matriz desde un archivo CSV deduciendo sus dimensiones.
 *
 * @param[in] ruta Ruta del archivo CSV a leer.
 * @param[out] filas Puntero donde se almacenara la cantidad de filas leidas.
 * @param[out] columnas Puntero donde se almacenara la cantidad de columnas leidas.
 * @return int** Matriz cargada en el heap, o NULL en caso de error.
 * 
 * #PRE 'ruta', 'filas' y 'columnas' no deben ser NULL.
 * #POST Retorna una matriz dinamica generada con matriz_crear() e inicializada con los valores del CSV.
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas);

#endif 