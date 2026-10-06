/**
 * @file consulta_csv.h
 * @brief Ejercicio 6: Pipeline de Datos Matricial sin Structs.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una matriz dinamica 2D de enteros en bloque contiguo en el heap.
 *
 * @param[in] filas Cantidad de filas.
 * @param[in] columnas Cantidad de columnas.
 *
 * @return Puntero int** a las filas de la matriz, o NULL si las dimensiones o la memoria fallan.
 */
int **crear_matriz_contigua(size_t filas, size_t columnas);

/**
 * @brief Libera una matriz dinamica de bloque contiguo y setea el puntero a NULL.
 *
 * @param[in, out] matriz Puntero a la variable int** de la matriz.
 */
void destruir_matriz_contigua(int ***matriz);

/**
 * @brief Carga una matriz numerica desde un archivo CSV.
 *
 * @param[in] ruta_archivo Ruta del archivo CSV.
 * @param[out] filas Puntero donde se almacena la cantidad de filas leidas.
 * @param[out] columnas Puntero donde se almacena la cantidad de columnas leidas.
 *
 * @return Puntero int** a la matriz cargada en heap, o NULL ante error.
 */
int **cargar_matriz_csv(const char *ruta_archivo, size_t *filas, size_t *columnas);

/**
 * @brief Filtra filas de la matriz donde el valor en una columna especifica supera un umbral.
 *
 * Reserva una nueva matriz contigua en el heap con las filas coincidentes.
 *
 * @param[in] matriz Matriz fuente.
 * @param[in] filas Cantidad de filas de la matriz fuente.
 * @param[in] columnas Cantidad de columnas de la matriz.
 * @param[in] col_filtro Indice de la columna a evaluar (0-indexada).
 * @param[in] umbral Valor minimo excluyente que debe superar la celda.
 * @param[out] filas_filtradas Puntero donde se almacena el numero de filas de la nueva matriz.
 *
 * @return Puntero int** a la nueva matriz en heap, o NULL si no hay coincidencias o ante error.
 */
int **filtrar_filas_matriz(int **matriz, size_t filas, size_t columnas,
                           size_t col_filtro, int umbral, size_t *filas_filtradas);

/**
 * @brief Calcula el promedio de cada columna y lo almacena en un arreglo dinamico de floats.
 *
 * @param[in] matriz Matriz numerica fuente.
 * @param[in] filas Cantidad de filas.
 * @param[in] columnas Cantidad de columnas.
 *
 * @return Puntero float* en heap con un promedio por columna, o NULL ante error.
 */
float *calcular_promedios_columnas(int **matriz, size_t filas, size_t columnas);

/**
 * @brief Exporta una matriz numerica a un archivo CSV en disco.
 *
 * @param[in] ruta_archivo Nombre o ruta del archivo de salida.
 * @param[in] matriz Matriz a persistir.
 * @param[in] filas Cantidad de filas.
 * @param[in] columnas Cantidad de columnas.
 *
 * @return true si la escritura fue exitosa, false en caso contrario.
 */
bool exportar_matriz_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas);

/**
 * @brief Libera un arreglo dinamico de floats y anula el puntero.
 *
 * @param[in, out] arreglo Puntero a la variable float*.
 */
void liberar_arreglo_floats(float **arreglo);

#endif 
