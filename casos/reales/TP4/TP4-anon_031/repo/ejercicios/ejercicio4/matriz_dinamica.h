#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una matriz int** usando un único bloque contiguo para los datos.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @return Matriz inicializada en cero o NULL ante error.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera una matriz creada con matriz_crear.
 * @param matriz Matriz a liberar.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Carga una matriz rectangular de enteros desde un archivo CSV.
 * @param ruta Ruta del archivo CSV.
 * @param filas Parámetro de salida para la cantidad de filas.
 * @param columnas Parámetro de salida para la cantidad de columnas.
 * @return Matriz cargada o NULL si el archivo o su contenido son inválidos.
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas);

/**
 * @brief Reserva una matriz plana de filas por columnas inicializada en cero.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @return Bloque plano o NULL ante error.
 */
int *crear_matriz_plana(size_t filas, size_t columnas);

/**
 * @brief Obtiene una celda de una matriz plana.
 * @param matriz Bloque plano.
 * @param columnas Cantidad de columnas.
 * @param fila Fila a consultar.
 * @param columna Columna a consultar.
 * @return Valor almacenado; retorna 0 si el puntero es NULL o columnas es cero.
 */
int obtener_celda(const int *matriz, size_t columnas, size_t fila, size_t columna);

/**
 * @brief Asigna una celda de una matriz plana.
 * @param matriz Bloque plano.
 * @param columnas Cantidad de columnas.
 * @param fila Fila a modificar.
 * @param columna Columna a modificar.
 * @param valor Valor a almacenar.
 */
void asignar_celda(int *matriz, size_t columnas, size_t fila, size_t columna, int valor);

/**
 * @brief Libera una matriz plana.
 * @param matriz Bloque a liberar.
 */
void liberar_matriz_plana(int *matriz);

#endif 
