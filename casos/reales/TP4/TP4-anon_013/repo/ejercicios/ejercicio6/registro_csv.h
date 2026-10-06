#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "cadenas.h"
#define MAX_LINEA 1024
#define SIN_ERROR 0
#define ERROR_PUNTERO_NULO -1
#define ERROR_CAPACIDAD -2
#define ERROR_SIN_TERMINADOR -3
#define ERROR_MEMORIA -4
#define ERROR_SIN_CARACTER_VALIDO -5


/**
 * @brief recibe un puntero a una línea de caracteres, la fragmenta de acuerdo a un caracter
 * delimitador y guarda cada fragmento en en un bloque en el heap finalizado con caractter nulo '\0'
 * mediante cadena_duplicar_segura(), crea un arreglo de punteros donde cada elemento apunta a un
 * fragmento de texto en el heap.
 * @param linea es el puntero a la linea de caracteres.
 * @param delimitador es el caracter que que separa los fragmentos de texto.
 * @param cantidad_tokens es la cantidad de fragmentos de texto.
 * @param errror es una variable que maneja codigos de error
 * 
 * @pre 'linea' debe ser válido y accesible. 'delimitador' debe ser válido. El texto debe contener
 * al caracteres diferentes a 'delimitador' para que haga la partición del texto en el heap.
 * 
 * @post crea en el heap bloques que contienen los fragmenos de texto, y un arreglo de caracteres
 * cuyos elementos apuntan a los fragmentos de texto. Actualiza 'cantidad_tokens' a la cantidad
 * de particiones que se hicieron.
 * 
 * @return el puntero al arreglo de punteros. NULL ante parámetros inválidos (salvo 'error')
 * 
 * Se podríaa ver de inclupir las funciones del ejercicio2 para que se eliminen los espacios al inicio
 * y al final de la linea si se quisiera.
 */
char **dividir_linea_csv (const char *linea, char delimitador, size_t *cantidad_tokens, int *error);

/**
 * @brief recibe un puntero a un arreglo de punteros que apuntan al heap. Itera sobre los índices
 * para ir liberando los bloques de memoria. Una vez terminado, libera el blque del arreglo y le
 * asigna NULL al puntero.
 * @param puntero_arreglo es el puntero al arreglo de punteros.
 * @param cantidad es la cantidad de elementos del arreglo.
 * 
 * @post libera los bloques de memoria a los que apuntan los punteros del arreglo, libera
 * el bloque del arreglo y asigna NULL al puntero.
 * 
 * Esta es como la matriz_destruir_v2 del ejercicio 4
 */
void liberar_arreglo_cadenas (char ***puntero_arreglo, size_t cantidad);

#endif 