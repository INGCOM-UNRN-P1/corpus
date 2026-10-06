#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Carga una matriz numerica desde un archivo CSV.
 *
 * @param ruta Ruta del archivo CSV.
 * @param filas Puntero de salida con la cantidad de filas leidas.
 * @param columnas Puntero de salida con la cantidad de columnas leidas.
 * @return int** Matriz dinamica (arreglo de filas), o NULL en caso de error.
 */
int **csv_cargar_matriz(const char *ruta, size_t *filas, size_t *columnas);

/**
 * @brief Filtra filas de una matriz si el valor en una columna supera un umbral.
 *
 * @param matriz Matriz original a evaluar.
 * @param filas Cantidad de filas originales.
 * @param columnas Cantidad de columnas originales.
 * @param col_condicion Indice de la columna (base 0) a evaluar.
 * @param umbral Valor que se debe superar (>) para conservar la fila.
 * @param filas_filtradas Puntero de salida con la cantidad de filas de la nueva matriz.
 * @return int** Nueva matriz filtrada en el heap, o NULL si ninguna fila cumple.
 */
int **csv_filtrar_filas(int **matriz, size_t filas, size_t columnas, size_t col_condicion, int umbral, size_t *filas_filtradas);

/**
 * @brief Calcula el promedio de cada columna de la matriz.
 *
 * @param matriz Matriz a procesar.
 * @param filas Cantidad de filas en la matriz.
 * @param columnas Cantidad de columnas en la matriz.
 * @return float* Arreglo dinamico con los promedios, o NULL en caso de error.
 */
float *csv_calcular_promedios(int **matriz, size_t filas, size_t columnas);

/**
 * @brief Exporta una matriz a un archivo CSV.
 *
 * @param ruta Ruta del archivo CSV a generar.
 * @param matriz Matriz dinamica a exportar.
 * @param filas Cantidad de filas de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 * @return true Si se exporto con exito.
 * @return false Si hubo algun error de escritura.
 */
bool csv_exportar_matriz(const char *ruta, int **matriz, size_t filas, size_t columnas);

/**
 * @brief Libera completamente la memoria de una matriz dinamica.
 *
 * @param matriz Triple puntero a la matriz para asignarle NULL tras liberar.
 * @param filas Cantidad de filas de la matriz.
 */
void csv_liberar_matriz(int ***matriz, size_t filas);

#endif 