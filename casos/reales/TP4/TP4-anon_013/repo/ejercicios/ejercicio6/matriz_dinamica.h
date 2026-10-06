#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vector.h"
#define MAX_LINEA 1024



/**
 * @brief crea un matriz en el heap y un arreglo de punteros a cada fila de la matriz.
 * @param filas es la cantidad de filas de la matriz.
 * @param columnas es la cantidad de columnas de la matriz.
 * 
 * @pre filas y columnas deben ser mayor a 0.
 * 
 * @return el puntero al arreglo que contiene las direciones de memoria (punteros) al
 * inicio de cada fila (EL PRIMERO ES EL DE TODOS EL EL PUNTERO A LA MATRIZ/BLOQUE DE
 * ENTEROS).
 * NULL si los parámetros son inválidos o falla la memoria.
 */
int **matriz_crear (size_t filas, size_t columnas);

/**
 * @brief recibe un arreglo de punteros que apuntan a las filas de una matriz.
 * El primer elemento de ese arreglo (fila 1) coincide con el puntero al bloque
 * de datos. La función libera de forma segura el bloque de datos y luego libera
 * de forma segura el bloque de punteros.
 * @param matriz es el puntero al arreglo de punteros.
 * 
 * @return NULL para ser asignado al puntero de la matriz para que no quede colgando
 */
int **matriz_destruir (int **matriz);

/**
 * @brief recibe por referencia un arreglo de punteros, libera el bloque al que apuntan,
 * y luego libera el arreglo de forma segura por referencia.
 * @param matriz es el puntero ala dirección de memoria .
 * 
 * @post los bloques de datos del heap quedan libres y *matriz queda en NULL.
 */
void matriz_destruir_v2 (int ***matriz);

//_____________________ HECHO CON MUCHA AYUDA DE LA IA _____________________
/**
 * @brief recibe la ruta a un archivo.csv, lo abre y carga los datos a una matriz
 * en el heap.
 * @param ruta es la ruta del archivo.
 * @param filas es el puntero a la cantidad de filas de la matriz (a determinar pero tiene
 * que estar inicializado)
 * @param columnas es el puntero a la cantidad de columnas de la matriz (a determinar pero tiene
 * que estar inicializado)
 * 
 * @pre los punteros deben ser válidos y accesibles.
 * @pre la matriz contenida en el .csv debe ser rectangular con elementos enteros.
 * 
 * @return el puntero a la matriz de enteros creada en el heap. NULL si algún parámetro
 * es inválido o la matriz no es entera rectangular.
 */
int **matriz_cargar_desde_csv (const char *ruta, size_t *filas, size_t *columnas);

#endif 
