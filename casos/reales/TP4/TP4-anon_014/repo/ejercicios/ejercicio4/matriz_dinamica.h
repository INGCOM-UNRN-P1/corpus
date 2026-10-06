#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>





/**
 * @brief Crea una matriz de enteros en cero con acceso m[i][j].
 *
 * Los datos ocupan un único bloque contiguo; además se reserva un arreglo
 * de punteros donde matriz[i] apunta al inicio de la fila i.
 *
 * @param filas cantidad de filas.
 * @param columnas cantidad de columnas.
 * @returns la matriz, o NULL si alguna dimensión es 0 o falla la memoria.
 * @post el llamador libera la matriz con matriz_destruir y luego asigna
 *       NULL a su puntero.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera el bloque de datos y el arreglo de punteros a fila.
 * @param matriz matriz creada con matriz_crear (acepta NULL).
 * @post la memoria de la matriz queda liberada; el llamador debe asignar
 *       NULL a su puntero.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Carga una matriz desde un archivo CSV.
 *
 * Formato: la primera línea tiene las dimensiones "filas,columnas" y las
 * siguientes 'filas' líneas tienen 'columnas' enteros separados por coma.
 *
 * @param ruta ruta del archivo.
 * @param filas salida: cantidad de filas leídas.
 * @param columnas salida: cantidad de columnas leídas.
 * @returns la matriz cargada, o NULL si algún puntero es NULL, no se puede
 *          abrir el archivo, el formato es inválido o falla la memoria.
 * @post el llamador libera la matriz con matriz_destruir.
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas,
                              size_t *columnas);



/**
 * @brief Reserva una matriz plana de filas x columnas enteros en cero.
 *
 * El elemento (i, j) se ubica en bloque[i * columnas + j].
 *
 * @param filas cantidad de filas.
 * @param columnas cantidad de columnas.
 * @returns el bloque, o NULL si alguna dimensión es 0 o falla calloc.
 * @post el llamador libera el bloque con liberar_matriz_plana.
 */
int *crear_matriz_plana(size_t filas, size_t columnas);

/**
 * @brief Obtiene el valor de la celda (fila, col) de una matriz plana.
 * @param m matriz plana.
 * @param columnas cantidad de columnas de m.
 * @param fila fila de la celda.
 * @param col columna de la celda.
 * @pre m no es NULL, fila es menor a la cantidad de filas y col < columnas.
 * @returns el valor de la celda.
 */
int obtener_celda(const int *m, size_t columnas, size_t fila, size_t col);

/**
 * @brief Escribe un valor en la celda (fila, col) de una matriz plana.
 * @param m matriz plana.
 * @param columnas cantidad de columnas de m.
 * @param fila fila de la celda.
 * @param col columna de la celda.
 * @param valor valor a escribir.
 * @pre fila es menor a la cantidad de filas de m.
 * @returns true si se escribió; false si m es NULL o col >= columnas.
 */
bool asignar_celda(int *m, size_t columnas, size_t fila, size_t col,
                   int valor);

/**
 * @brief Libera una matriz plana.
 * @param m matriz creada con crear_matriz_plana (acepta NULL).
 * @post el llamador debe asignar NULL a su puntero.
 */
void liberar_matriz_plana(int *m);

#endif 
