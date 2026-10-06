
#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stddef.h>



/**
 * @brief Reserva una matriz dinámica de enteros inicializada en cero.
 *
 * @pre filas y columnas deben ser mayores que cero.
 * @post Retorna una matriz con un bloque contiguo de datos.
 *
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @return Matriz creada o NULL ante error.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera una matriz dinámica.
 *
 * @pre matriz debe ser NULL o haber sido creada por matriz_crear.
 * @post Se libera la memoria ocupada por la matriz.
 *
 * @param matriz Matriz a liberar.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Carga una matriz de enteros desde un archivo CSV.
 *
 * @pre ruta, filas y columnas deben ser punteros válidos.
 * @post Retorna la matriz cargada y actualiza sus dimensiones.
 *
 * @param ruta Ruta del archivo CSV.
 * @param filas Cantidad de filas leídas.
 * @param columnas Cantidad de columnas leídas.
 * 
 * @return Matriz cargada o NULL ante error.
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas,
                              size_t *columnas);

#endif 
