/**
 * @note metí en la carpeta los .h y .c de otros ejercicios que tienen funciones
 * que puedo reutilizar.
 */

#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>
#include "estadistica.h"
#include "matriz_dinamica.h"
#include "registro_csv.h"
#include "recorrido.h"
#include "intercambio.h"
#include "codigos_estadistica.h"



/**
 * @brief Libera un bloque de memoria con free() y asigna NULL al puntero
 * asociado.
 * @param puntero_bloque es la dirección de memoria del puntero asociado al
 * bloque del heap.
 *
 * @pre si alguno de los punteros en NULL no realiza operaciones.
 */
void liberar_bloque_float(float **puntero_bloque);

/**
 * @brief determina si un valor entero es mayor a otro
 * @param valor_columna es el primer valor
 * @param umbral es el segundo valor
 * @return valor_columna > umbral
 */
bool mayor_a_umbral(int valor_columna, int umbral);

/**
 * @brief determina si un valor entero es divisible por otro
 * @param valor_columna es el primer valor
 * @param umbral es el segundo valor
 * @return valor_columna % umbral == 0
 */
bool es_divisible_por(int valor_columna, int umbral);

/**
 * @brief recibe una matriz y filtra las filas en base a si una columna 'n'
 * cumple una condición dada por una función, después crea una nueva matriz
 * en el heap con las filas cuya columna 'n' cumple la condicion.
 * @param matriz es el puntero a la matriz sometida al filtro
 * @param filas es la cantidad de filas de la matriz
 * @param columnas es la cantidad de columnas de la matriz
 * @param columna_n es la columna a ser examinada
 * @param condicion es una función booleana que realiza la comparación del elemento
 * de la columna frente al parámetro 'umbral'
 * @param umbral es un entero con el que se van a comparar los valores de
 * la columna_n.
 * @param filas_filtradas es la cantidad de filas que pasaron el filtro de la condicion
 * (cantidad de filas de la nueva matriz)
 * @return el puntero a la nueva matriz con las filas filtradas, NULL en caso de que
 * haya habido algún error.
 */
int **filtrar_filas_matriz (int **matriz, size_t filas, size_t columnas, 
    size_t columna_n, bool (*condicion)(int, int), int umbral, size_t *filas_filtradas);

/**
 * @brief funcion que calcula la suma de las columnas de una matriz y las guarda
 * en un arreglo.
 * @param matriz es el puntero a la matriz sometida al filtro
 * @param filas es la cantidad de filas de la matriz
 * @param columnas es la cantidad de columnas de la matriz
 * @return el puntero al arreglo float con los resultados, NULL en caso de
 * que haya habido algun error.
 * 
 * @note es la función calcular_estadisticas_columna() donde el parámetro
 * 'operación' fué seteado a "suma".
 */
float *matriz_sumar_columnas (int **matriz, size_t filas, size_t columnas);

/**
 * @brief funcion que calcula el promedio de las columnas de una matriz y las guarda
 * en un arreglo.
 * @param matriz es el puntero a la matriz sometida al filtro
 * @param filas es la cantidad de filas de la matriz
 * @param columnas es la cantidad de columnas de la matriz
 * @return el puntero al arreglo float con los resultados, NULL en caso de
 * que haya habido algun error.
 * 
 * @note es la función calcular_estadisticas_columna() donde el parámetro
 * 'operación' fué seteado a "promedio".
 */
float *matriz_promedio_columnas (int **matriz, size_t filas, size_t columnas);

/**
 * @brief función que exporta una matriz a un archivo csv con formato
 * @param ruta es la ruta del archivo donde se va a guardar la matriz
 * @param matriz es el puntero a la matriz sometida al filtro
 * @param filas es la cantidad de filas de la matriz
 * @param columnas es la cantidad de columnas de la matriz
 * @return true si la exportación tuvo exito, false caso contrario.
 */
bool matriz_exportar_csv(const char *ruta, int **matriz, size_t filas, size_t columnas);

#endif 
