#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stddef.h>

/**
 * @brief Duplica una cadena de caracteres en el heap.
 *
 * @param[in] origen Puntero constante a la cadena original.
 * @return char* Puntero a la nueva cadena clonada, o NULL en caso de error.
 *
 * #PRE 'origen' no debe ser NULL.
 * #POST Retorna un bloque en el heap con una copia exacta de 'origen'.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en un nuevo bloque de memoria en el heap.
 *
 * @param[in] primera Puntero constante a la primera cadena.
 * @param[in] segunda Puntero constante a la segunda cadena.
 * @return char* Puntero a la nueva cadena unida, o NULL en caso de error.
 *
 * #PRE 'primera' y 'segunda' no deben ser NULL.
 * #POST Retorna un bloque en el heap que contiene 'primera' seguida por 'segunda'.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 