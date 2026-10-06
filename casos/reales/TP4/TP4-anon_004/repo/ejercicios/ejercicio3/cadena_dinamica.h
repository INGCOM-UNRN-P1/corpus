
#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stddef.h>



/**
 * @brief Duplica una cadena con una reserva exacta en memoria dinámica.
 *
 * @pre origen debe ser NULL o una cadena terminada en '\0'.
 * @post Retorna una copia independiente sin modificar la cadena original.
 *
 * @param origen Cadena original.
 * @return Nueva cadena en heap o NULL ante error.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en una nueva reserva de memoria dinámica.
 *
 * @pre primera y segunda deben ser cadenas terminadas en '\0'.
 * @post Retorna una nueva cadena sin modificar las cadenas originales.
 *
 * @param primera Primera cadena.
 * @param segunda Segunda cadena.
 * @return Nueva cadena concatenada en heap o NULL ante error.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
