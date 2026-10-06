#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Crea una matriz de 'filas' x 'columnas' enteros inicializada en 0.
 *
 * Los datos se guardan en un único bloque contiguo del heap y se reserva además
 * un arreglo de punteros, uno por fila, que apuntan al inicio de cada fila dentro
 * de ese bloque. Se accede a un elemento con notación matriz[fila][columna].
 *
 * @param filas Cantidad de filas de la matriz.
 * @param columnas Cantidad de columnas de la matriz.
 *
 * @pre Ninguna.
 * @post Si retorna un puntero no nulo, 'matriz[0]' apunta al bloque de datos de
 *       'filas' * 'columnas' enteros en 0, y el llamador es responsable de liberarla
 *       con matriz_destruir.
 *
 * @return Puntero a la matriz creada, o NULL si 'filas' o 'columnas' son 0 o si falla
 *         la reserva de memoria.
 */
int **matriz_crear(size_t filas, size_t columnas);
 
/**
 * @brief Libera el bloque de datos y el arreglo de punteros a filas de una matriz.
 *
 * @param matriz Matriz creada con matriz_crear o matriz_cargar_desde_csv.
 *
 * @pre Si 'matriz' no es NULL, debe provenir de matriz_crear o matriz_cargar_desde_csv
 *      y no haber sido liberada.
 * @post La memoria de la matriz queda liberada; el puntero del llamador queda
 *       colgante y no debe volver a usarse. Si 'matriz' es NULL, no hace nada.
 */
void matriz_destruir(int **matriz);
 
/**
 * @brief Crea una matriz en heap cargada con los enteros de un archivo CSV.
 *
 * Cada línea del archivo es una fila y los valores se separan con comas. Las líneas
 * vacías se ignoran. Las dimensiones se determinan leyendo el archivo: la cantidad
 * de filas es la cantidad de líneas con datos y la de columnas es la de valores de
 * la primera línea.
 *
 * @param ruta Ruta del archivo CSV a leer.
 * @param filas Dirección donde se almacena la cantidad de filas leídas.
 * @param columnas Dirección donde se almacena la cantidad de columnas leídas.
 *
 * @pre 'ruta' debe ser una cadena terminada en '\0' y las líneas del archivo no
 *      deben superar los 1023 caracteres.
 * @post Si retorna un puntero no nulo, '*filas' y '*columnas' contienen las dimensiones
 *       y la matriz contiene los valores del archivo; el llamador es responsable de
 *       liberarla con matriz_destruir. En caso contrario, '*filas' y '*columnas' quedan en 0.
 *
 * @return Puntero a la matriz cargada, o NULL si algún parámetro es NULL, si no se puede
 *         abrir el archivo, si está vacío, si alguna fila tiene distinta cantidad de
 *         valores que la primera, si hay valores no numéricos o si falla la reserva
 *         de memoria.
 */
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas);

#endif 
