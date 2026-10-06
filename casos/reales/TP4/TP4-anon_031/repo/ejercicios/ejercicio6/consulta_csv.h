#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

/**
 * @brief Carga una matriz rectangular de enteros desde un CSV.
 * @param ruta Ruta del archivo.
 * @param filas Parámetro de salida con la cantidad de filas.
 * @param columnas Parámetro de salida con la cantidad de columnas.
 * @return Matriz dinámica contigua o NULL ante error.
 */
int **cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas);

/**
 * @brief Libera una matriz de consulta y deja el puntero en NULL.
 * @param puntero_matriz Dirección de la matriz.
 */
void liberar_matriz_csv(int ***puntero_matriz);

/**
 * @brief Filtra filas cuyo valor en una columna sea mayor que un umbral.
 * @param matriz Matriz original.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @param columna_filtro Índice de la columna usada para filtrar.
 * @param umbral Valor que debe superarse.
 * @param filas_resultantes Parámetro de salida con la cantidad de filas seleccionadas.
 * @return Nueva matriz dinámica con las filas seleccionadas o NULL si ninguna coincide o ante error.
 */
int **filtrar_filas_por_umbral(const int *const *matriz, size_t filas,
                               size_t columnas, size_t columna_filtro,
                               int umbral, size_t *filas_resultantes);

/**
 * @brief Calcula el promedio de cada columna.
 * @param matriz Matriz de origen.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @return Arreglo dinámico de promedios o NULL ante parámetros inválidos o error.
 */
float *calcular_promedios_columnas(const int *const *matriz, size_t filas,
                                   size_t columnas);

/**
 * @brief Exporta una matriz numérica a CSV.
 * @param ruta Archivo de salida.
 * @param matriz Matriz a exportar.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @return true si la escritura fue exitosa; false en caso contrario.
 */
bool exportar_matriz_csv(const char *ruta, const int *const *matriz,
                         size_t filas, size_t columnas);

/**
 * @brief Lee todas las líneas de un flujo y las guarda en un char** dinámico.
 * @param entrada Flujo de entrada abierto para lectura.
 * @param cantidad_lineas Parámetro de salida con la cantidad de líneas.
 * @return Arreglo dinámico de líneas o NULL si no hay líneas o ante error.
 */
char **leer_lineas_dinamicas(FILE *entrada, size_t *cantidad_lineas);

/**
 * @brief Filtra líneas que contienen una subcadena y devuelve copias independientes.
 * @param lineas Arreglo original de líneas.
 * @param cantidad Cantidad de líneas originales.
 * @param subcadena Texto a buscar.
 * @param cantidad_filtrada Parámetro de salida con la cantidad de coincidencias.
 * @return Nuevo arreglo de cadenas o NULL si no hay coincidencias o ante error.
 */
char **filtrar_lineas_por_subcadena(char *const *lineas, size_t cantidad,
                                    const char *subcadena, size_t *cantidad_filtrada);

/**
 * @brief Libera un arreglo dinámico de líneas y deja el puntero en NULL.
 * @param lineas Dirección del arreglo.
 * @param cantidad Cantidad de cadenas almacenadas.
 */
void liberar_lineas_dinamicas(char ***lineas, size_t cantidad);

#endif 
