#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stddef.h>

/**
 * @brief Crea una matriz de enteros en memoria contigua.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @pre filas y columnas son mayores que cero.
 * @post Se reserva un bloque contiguo para la matriz completa.
 * @note La memoria devuelta la libera el llamador con liberar_matriz_plana().
 * @returns Puntero a la matriz plana en heap o NULL si falla la reserva.
 */
int *crear_matriz_plana(size_t filas, size_t columnas);

/**
 * @brief Obtiene el valor de una celda de una matriz plana.
 * @param matriz_plana Puntero a la matriz plana.
 * @param columnas Cantidad de columnas de la matriz.
 * @param fila Índice de fila.
 * @param col Índice de columna.
 * @pre matriz_plana no es NULL y fila, col están dentro de rango.
 * @returns Valor almacenado en la celda indicada.
 */
int obtener_celda(const int *matriz_plana, size_t columnas, size_t fila,
                  size_t col);

/**
 * @brief Asigna un valor en una celda de una matriz plana.
 * @param matriz_plana Puntero a la matriz plana.
 * @param columnas Cantidad de columnas de la matriz.
 * @param fila Índice de fila.
 * @param col Índice de columna.
 * @param valor Valor a guardar.
 * @pre matriz_plana no es NULL y fila, col están dentro de rango.
 * @post La celda indicada queda actualizada con valor.
 */
void asignar_celda(int *matriz_plana, size_t columnas, size_t fila, size_t col,
                  int valor);

/**
 * @brief Libera una matriz plana creada con crear_matriz_plana().
 * @param matriz_plana Puntero a la matriz plana en heap.
 * @pre matriz_plana puede ser NULL.
 * @post La memoria reservada para la matriz se libera y queda invalida.
 */
void liberar_matriz_plana(int *matriz_plana);

/**
 * @brief Crea una matriz de punteros por filas.
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @pre filas y columnas son mayores que cero.
 * @post Se crea una matriz de punteros con filas independientes en heap.
 * @note Debe destruirse con matriz_destruir(matriz, filas).
 * @returns Puntero a la matriz por filas o NULL si falla la reserva.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera una matriz de punteros creada por matriz_crear().
 * @param matriz Puntero a la matriz por filas.
 * @param filas Cantidad de filas a liberar.
 * @pre matriz no es NULL.
 * @post Se libera el bloque contiguo de datos y el arreglo de punteros
 *       a filas.
 */
void matriz_destruir(int **matriz, size_t filas);

/**
 * @brief Carga una matriz desde un archivo CSV.
 * @param ruta_csv Ruta del archivo CSV.
 * @param filas Puntero de salida con la cantidad de filas leídas.
 * @param columnas Puntero de salida con la cantidad de columnas.
 * @pre ruta_csv no es NULL, filas y columnas no son NULL.
 * @post Se crea una matriz dinámica con los datos del archivo.
 * @note La matriz devuelta debe liberarse con matriz_destruir(matriz, filas).
 * @returns Matriz cargada en heap o NULL si falla la lectura.
 */
int **matriz_cargar_desde_csv(const char *ruta_csv, size_t *filas,
                              size_t *columnas);

#endif 
