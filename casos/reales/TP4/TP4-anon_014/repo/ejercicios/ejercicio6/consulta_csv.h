#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>







/**
 * @brief Carga una matriz plana desde un archivo CSV.
 * @param ruta ruta del archivo.
 * @param filas salida: cantidad de filas leídas.
 * @param columnas salida: cantidad de columnas leídas.
 * @returns la matriz, o NULL si algún puntero es NULL, no se puede abrir el
 *          archivo, el formato es inválido o falla la memoria.
 * @post el llamador libera la matriz con free.
 */
int *csv_cargar_matriz(const char *ruta, size_t *filas, size_t *columnas);

/**
 * @brief Copia en una matriz nueva las filas cuyo valor en 'columna' es
 *        mayor a 'umbral'.
 * @param m matriz de origen.
 * @param filas cantidad de filas de m.
 * @param columnas cantidad de columnas de m.
 * @param columna columna usada como condición.
 * @param umbral valor que debe superarse.
 * @param filas_resultado salida: cantidad de filas que cumplen (0 si
 *        ninguna o ante error).
 * @returns la matriz filtrada, o NULL si ninguna fila cumple, algún puntero
 *          es NULL, columna >= columnas o falla la memoria.
 * @post el llamador libera la matriz con free.
 */
int *csv_filtrar_filas(const int *m, size_t filas, size_t columnas,
                       size_t columna, int umbral, size_t *filas_resultado);

/**
 * @brief Calcula la suma de cada columna.
 * @param m matriz de origen.
 * @param filas cantidad de filas de m.
 * @param columnas cantidad de columnas de m.
 * @returns arreglo de 'columnas' sumas, o NULL si m es NULL, columnas es 0
 *          o falla la memoria.
 * @post el llamador libera el arreglo con free.
 */
float *csv_sumas_columnas(const int *m, size_t filas, size_t columnas);

/**
 * @brief Calcula el promedio de cada columna.
 * @param m matriz de origen.
 * @param filas cantidad de filas de m.
 * @param columnas cantidad de columnas de m.
 * @returns arreglo de 'columnas' promedios, o NULL si m es NULL, alguna
 *          dimensión es 0 o falla la memoria.
 * @post el llamador libera el arreglo con free.
 */
float *csv_promedios_columnas(const int *m, size_t filas, size_t columnas);

/**
 * @brief Escribe una matriz plana en un archivo CSV.
 * @param ruta ruta del archivo a crear o sobrescribir.
 * @param m matriz a exportar.
 * @param filas cantidad de filas de m.
 * @param columnas cantidad de columnas de m.
 * @returns true si se escribió todo; false si algún puntero es NULL, no se
 *          puede abrir el archivo o falla la escritura.
 */
bool csv_exportar_matriz(const char *ruta, const int *m, size_t filas,
                         size_t columnas);



/**
 * @brief Lee todas las líneas de un flujo y las guarda en heap.
 *
 * Se lee con fgets en un buffer fijo; el '\n' final se descarta. Una línea
 * más larga que el buffer queda partida en varias.
 *
 * @param entrada flujo abierto para lectura (por ejemplo stdin).
 * @param cantidad salida: cantidad de líneas leídas (0 ante error).
 * @returns arreglo de líneas, o NULL si no hay líneas, algún puntero es
 *          NULL o falla la memoria.
 * @post el llamador libera el resultado con liberar_lineas.
 */
char **leer_lineas(FILE *entrada, size_t *cantidad);

/**
 * @brief Copia en un arreglo nuevo las líneas que contienen 'subcadena'.
 * @param lineas arreglo de líneas (no se modifica).
 * @param cantidad cantidad de líneas.
 * @param subcadena texto a buscar.
 * @param cantidad_filtradas salida: cantidad de líneas copiadas.
 * @returns arreglo de copias, o NULL si ninguna coincide, algún puntero es
 *          NULL o falla la memoria.
 * @post el llamador libera el resultado con liberar_lineas.
 */
char **filtrar_lineas(char *const *lineas, size_t cantidad,
                      const char *subcadena, size_t *cantidad_filtradas);

/**
 * @brief Libera cada línea, luego el arreglo, y deja el puntero en NULL.
 * @param lineas dirección del arreglo (acepta NULL).
 * @param cantidad cantidad de líneas.
 * @post *lineas vale NULL.
 */
void liberar_lineas(char ***lineas, size_t cantidad);

#endif 
