#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include "cadenas.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * @brief recibe una cadena, calcula su longitud y la copia en el heap con
 * terminador
 * '\0'.
 * @param origen es el puntero a la cadena origen.
 *
 * @pre el puntero debe ser válido y accesible.La cadena debe finalizar con el
 * caracter terminador '\0'.
 *
 * @return el puntero al bloque en el heap que contiene la copia.NULL si
 * es inválido o falla la memoria.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief recibe dos cadenas, calcula la longitud de ambas, reserva un bloque en
 * el heap y las concatena.
 * @param primera es el puntero a la primera cadena.
 * @param segunda es el puntero a la segunda cadena
 *
 * @pre ambos punteros deben ser válidos y accesibles.Las cadenas deben contener
 * el caracter terminador '\0'.
 *
 * @return el puntero al bloque en el heap que contiene la concatenación de
 * ambas cadenas. NULL si algun puntero es NULL o falla la memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
