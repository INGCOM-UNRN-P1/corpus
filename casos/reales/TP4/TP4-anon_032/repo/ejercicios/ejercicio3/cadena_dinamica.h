#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "cadenas.h"
#include "vector.h"


/**
 * @brief Crea un bloque en heap con la copia invertida de una cadena.
 *
 * @param cadena La cadena a invertir
 * @param capacidad La capacidad de la cadena
 * @param pre Cadena no debe ser nula y capacidad no debe ser cero.
 * @param post Se crea una copia en heap de la cadena sin modificar la cadena original.
 * @return Devuelve un puntero a la cadena en heap o nulo en caso de error.
 */
char *invertir_cadena_dinamico(const char *cadena, size_t capacidad);

/**
 * @brief Divide una cadena en tokens usando un caracter delimitador.
 *
 * @param cadena La cadena a partir.
 * @param capacidad La capacidad de la cadena.
 * @param caracter El caracter delimitador
 * @param cantidad La cantidad de tokens.
 * @pre Cadena y cantidad no deben ser nulos y capacidad no debe ser cero.
 * @post Crea un arreglo de punteros a bloques que contienen cada token sin modificar
 * la cadena original.
 * @return Retorna un arreglo de punteros a las cadenas de cada token o nulo en caso de error.
 */
char **partir_por_delimitador(const char *cadena, size_t capacidad, char caracter, size_t *cantidad);

#endif 
