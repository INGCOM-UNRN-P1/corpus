/**
 * @file cadena_dinamica.h
 * @brief Ejercicio 3: Duplicacion y Concatenacion Dinamica de Cadenas.
 *
 * Trabajo Practico 4 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Clona una cadena de caracteres en un nuevo bloque de memoria en el heap.
 *
 * Mide la longitud exacta de la cadena fuente, reserva la cantidad de memoria
 * requerida (longitud + 1 byte para el terminador nulo) y copia el contenido.
 *
 * @param[in] origen Cadena de caracteres a clonar.
 *
 * @return Puntero a la nueva cadena alojada en heap (char *), o NULL si origen es NULL
 *         o si falla la asignacion de memoria.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas de caracteres en un nuevo bloque dinamico en heap.
 *
 * Calcula la longitud total combinada, reserva exactamente el espacio en heap
 * y genera una nueva cadena con la union de ambas finalizada en '\0'.
 *
 * @param[in] primera Primera cadena a unir.
 * @param[in] segunda Segunda cadena a unir.
 *
 * @return Puntero a la cadena concatenada en heap (char *), o NULL si alguna entrada es NULL
 *         o si ocurre un error de memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
