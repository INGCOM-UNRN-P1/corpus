#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Clona una cadena de caracteres asignando memoria dinámica en el heap.
 *
 * @param origen Cadena a clonar.
 * @return Puntero a la nueva cadena clonada en heap, o NULL si origen es NULL o falla malloc.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en un nuevo bloque de memoria dinámica en el heap.
 *
 * @param primera Primera cadena.
 * @param segunda Segunda cadena.
 * @return Puntero a la nueva cadena concatenada, o NULL si alguna entrada es NULL o falla malloc.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

/**
 * @brief Libera la memoria de una cadena y coloca el puntero en NULL.
 *
 * @param puntero_cadena Dirección del puntero a la cadena.
 */
void cadena_liberar_segura(char **puntero_cadena);

#endif 
