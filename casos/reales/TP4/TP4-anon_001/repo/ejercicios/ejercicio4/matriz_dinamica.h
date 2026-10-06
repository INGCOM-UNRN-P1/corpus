#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Crea una matriz dinámica bidimensional alojando un único bloque de
 * datos contiguo
 *
 * Reserva en el heap un arreglo de punteros a filas y un único bloque contiguo
 * de memoria para almacenar todos los elementos enteros.Conecta cada puntero de
 * fila con el inicio de su tramo correspondiente dentro de la tira de datos.
 *
 * @pre `filas > 0` y `columnas > 0`.
 * @post Si la función tiene éxito, se asigna memoria en el heap para la matriz
 * y sus datos.Si falla o las dimensiones son 0, la memoria no es asignada y
 * retorna NULL.
 *
 * @param filas de la matriz.
 * @param columnas de la matriz.
 *
 * @return Puntero int **a la matriz lista para usar mediante matriz[f][c],
 *         o NULL si las dimensiones son inválidas o falla malloc.
 */
int **matriz_crear(size_t filas, size_t columnas);

/**
 * @brief Libera la memoria asignada a una matriz dinámica contigua.
 *
 * Libera el bloque contiguo de datos (apuntado por la primera fila matriz[0])
 * y el arreglo de punteros a filas, previniendo fugas de memoria.
 *
 * @pre Ninguna (acepta `matriz == NULL` de forma segura).
 * @post Toda la memoria en el heap asociada a la matriz queda liberada y no
 * debe volver a usarse.
 *
 * @param matriz Puntero doble a la matriz a liberar.
 */
void matriz_destruir(int **matriz);

/**
 * @brief Carga e inicializa una matriz dinámica desde un archivo CSV.
 *
 * Abre el archivo especificado, lee las dimensiones guardadas en la primera
 * línea, reserva la memoria mediante matriz_crear y llena la matriz con los
 * valores del archivo.
 *
 * @pre `ruta_archivo != NULL`, `filas != NULL` y `columnas != NULL`.
 *      El archivo debe existir en disco y tener formato CSV compatible.
 * @post Si la carga es exitosa, se modifican los valores apuntados por `filas`
 * y `columnas` con las dimensiones leídas y se retorna la matriz con los datos
 * cargados.En caso de error, `*filas` y `*columnas` pueden no ser válidos y la
 * función retorna NULL.
 *
 * @param ruta_archivo Cadena con la ruta o nombre del archivo CSV.
 * @param filas Puntero a size_t donde se almacenará la cantidad de filas
 * leídas.
 * @param columnas Puntero a size_t donde se almacenará la cantidad de columnas
 * leídas.
 *
 * @return Puntero int **a la matriz cargada, o NULL ante cualquier error de
 * apertura, formato o reserva de memoria.
 */
int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas,
                              size_t *columnas);

#endif 
