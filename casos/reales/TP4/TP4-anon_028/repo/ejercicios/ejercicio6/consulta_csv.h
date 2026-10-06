#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Carga una matriz numérica desde un archivo CSV.
 */
int **consulta_cargar_csv(const char *ruta_archivo, size_t *filas, size_t *columnas);

/**
 * @brief Filtra filas de la matriz donde el valor en la columna especificada sea estrictamente mayor al umbral.
 */
int **consulta_filtrar_mayor(int **matriz_origen, size_t filas_origen, size_t columnas, size_t col_filtro, int umbral, size_t *filas_destino);

/**
 * @brief Calcula el promedio de cada columna y lo guarda en un arreglo de floats en el heap.
 */
float *consulta_promedios_por_columna(int **matriz, size_t filas, size_t columnas);

/**
 * @brief Exporta una matriz numérica a un archivo CSV.
 */
bool consulta_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas);

/**
 * @brief Libera la memoria de una matriz dinámica contigua.
 */
void consulta_liberar_matriz(int **matriz);

#endif 
