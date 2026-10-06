#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Carga una matriz de enteros desde un CSV.
 * @param ruta_archivo Ruta del archivo a cargar.
 * @param filas Puntero de salida con la cantidad de filas.
 * @param columnas Puntero de salida con la cantidad de columnas.
 * @pre ruta_archivo no es NULL, filas y columnas no son NULL.
 * @post Se crea una matriz dinámica de enteros.
 * @note La matriz devuelta debe liberarse con liberar_matriz_int().
 * @returns Matriz cargada o NULL si falla la lectura.
 */
int **cargar_matriz_csv(const char *ruta_archivo, size_t *filas,
                        size_t *columnas);

/**
 * @brief Filtra las filas de una matriz por un umbral de una columna.
 * @param matriz Matriz original (bloque contiguo).
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @param indice_columna Número de columna de comparación.
 * @param umbral Valor límite: se conservan filas con valor > umbral.
 * @param filas_resultado Puntero de salida con la cantidad de filas filtradas.
 * @pre matriz no es NULL y filas_resultado no es NULL.
 * @post Se devuelve una nueva matriz con solo las filas que cumplen el
 *       criterio.
 * @note La matriz resultante debe liberarse con liberar_matriz_int().
 * @returns Matriz filtrada o NULL si no hay coincidencias o falla la reserva.
 */
int **filtrar_matriz_por_columna(const int *matriz, size_t filas,
                                 size_t columnas, size_t indice_columna,
                                 int umbral, size_t *filas_resultado);

/**
 * @brief Calcula el promedio de cada columna de una matriz.
 * @param matriz Matriz de entrada (bloque contiguo).
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @param cantidad Puntero de salida con la cantidad de promedios.
 * @pre matriz no es NULL y cantidad no es NULL.
 * @post Se devuelve un arreglo con el promedio por columna.
 * @note El arreglo resultante debe liberarse con free().
 * @returns Arreglo de flotantes o NULL si falla la operación.
 */
float *estadisticas_columnas(const int *matriz, size_t filas, size_t columnas,
                             size_t *cantidad);

/**
 * @brief Exporta una matriz a un archivo CSV.
 * @param ruta_archivo Ruta del archivo destino.
 * @param matriz Matriz a exportar (bloque contiguo).
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @pre ruta_archivo no es NULL y matriz no es NULL.
 * @post Se escribe la matriz en formato CSV en el archivo indicado.
 * @returns 0 si la exportación es exitosa, distinto de 0 si falla.
 */
int exportar_matriz_csv(const char *ruta_archivo, const int *matriz,
                        size_t filas, size_t columnas);

/**
 * @brief Libera una matriz de enteros en bloque contiguo.
 * @param matriz Matriz dinámica de enteros (arreglo de punteros a filas).
 * @param filas Cantidad de filas.
 * @pre matriz no es NULL.
 * @post Se libera el bloque contiguo de datos y el arreglo de punteros.
 */
void liberar_matriz_int(int **matriz, size_t filas);

#endif 