#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Filtra las filas de una matriz en base al valor de una columna y un
 * umbral.
 *
 * Crea una nueva matriz dinámica en el heap que contiene únicamente aquellas
 * filas de la matriz original cuyo valor en `columna_filtro` sea estrictamente
 * mayor a `umbral`.
 *
 * @pre `matriz != NULL`, `filas > 0`, `columnas > 0`, `columna_filtro <
 * columnas` y `filas_filtradas != NULL`.
 * @post Si hay coincidencias, devuelve una nueva matriz dinámica reducida y
 * guarda la cantidad de filas resultantes en `*filas_filtradas`. Si ninguna
 * fila cumple el criterio o falla la memoria, retorna NULL y asigna 0 a
 * `*filas_filtradas`.
 *
 * @param matriz origen a filtrar.
 * @param filas la matriz original.
 * @param columnas de ambas matrices.
 * @param columna_filtro Índice de la columna a evaluar.
 * @param umbral Valor mínimo de corte (excluyente).
 * @param filas_filtradas Puntero de salida para registrar la cantidad de filas
 * resultantes.
 *
 * @return Puntero int **a la nueva matriz filtrada en el heap, o NULL si no hay
 * resultados/error.
 */
int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas,
                                 size_t columna_filtro, int umbral,
                                 size_t *filas_filtradas);

/**
 * @brief Calcula el promedio aritmético de los elementos de cada columna de una
 * matriz.
 *
 * Recorre la matriz por columnas, suma los valores de cada una y genera un
 * arreglo dinámico en el heap con los resultados de tipo float.
 *
 * @pre `matriz != NULL`, `filas > 0` y `columnas > 0`.
 * @post Retorna un arreglo de floats de tamaño `columnas` reservado en el heap.
 *       Si la matriz es inválida o falla malloc, retorna NULL.
 *
 * @param matriz de datos.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 *
 * @return Puntero float *al arreglo de promedios, o NULL si ocurre un error.
 */
float *matriz_calcular_promedios(int **matriz, size_t filas, size_t columnas);

/**
 * @brief Exporta los datos de una matriz a un archivo de texto en formato CSV.
 *
 * Abre (o crea) el archivo en la ruta especificada y escribe los valores
 * numéricos de la matriz separados por comas, agregando saltos de línea al
 * final de cada fila.
 *
 * @pre `ruta_archivo != NULL`, `matriz != NULL`, `filas > 0` y `columnas > 0`.
 * @post Si la escritura es exitosa, el archivo se guarda en disco y la función
 * retorna true.Si no se puede abrir/crear el archivo o los parámetros son
 * nulos, retorna false.
 *
 * @param ruta_archivo Nombre o ruta del archivo de destino.
 * @param matriz cuyos datos se escribirán.
 * @param filas a exportar.
 * @param columnas Cantidad de columnas a exportar.
 *
 * @return true si se exportó con éxito; false en caso contrario.
 */
bool matriz_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas,
                         size_t columnas);

#endif 
