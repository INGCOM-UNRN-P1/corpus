#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Separa una línea delimitada por un carácter en un arreglo dinámico de cadenas (tokens) en el heap.
 *
 * @param linea Cadena de entrada a dividir.
 * @param delimitador Carácter usado para separar campos (ej. ',').
 * @param cantidad_tokens Puntero de salida donde se guardará el total de tokens obtenidos.
 * @return char** Arreglo de punteros a cadenas clonadas en heap, o NULL en caso de error/entrada NULL.
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);

/**
 * @brief Libera la memoria de cada cadena individual y del arreglo de punteros, dejando el puntero original en NULL.
 *
 * @param puntero_arreglo Puntero triple al arreglo de cadenas (char ***).
 * @param cantidad Cantidad de elementos en el arreglo.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 
