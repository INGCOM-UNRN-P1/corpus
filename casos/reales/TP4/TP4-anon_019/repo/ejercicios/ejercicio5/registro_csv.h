#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Divide una linea de texto CSV en tokens individuales dinamicos.
 *
 * @param linea Cadena constante que representa una linea del CSV.
 * @param delimitador Caracter utilizado para separar los campos.
 * @param cantidad_tokens Puntero de salida donde se guardara la cantidad de campos extraidos.
 * @return char** Arreglo dinamico de cadenas en heap, o NULL en caso de error.
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);

/**
 * @brief Libera un arreglo dinamico de cadenas y previene punteros colgantes.
 *
 * @param puntero_arreglo Triple puntero a la base del arreglo de cadenas.
 * @param cantidad Cantidad de elementos contenidos en el arreglo.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 