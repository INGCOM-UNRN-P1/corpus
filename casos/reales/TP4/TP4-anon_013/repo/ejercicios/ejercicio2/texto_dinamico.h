#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include "cadenas.h"
#include <stdbool.h>
#include <stddef.h>
#include <string.h>


/**
 * @brief elimina los espacios iniciales y finales de una cadena, reserva un
 * espacio en el heap y la copia en el nuevo bloque con el caracter nulo final.
 * @param origen es el puntero a la cadena origen.
 *
 * @pre el puntero debe ser válido y accesible.La cadena debe contener el
 * terminador '\0'.
 *
 * @return el puntero a la cadena en heap, NULL si el puntero es inválido o solo
 * contiene espacios.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief reserva un bloque en el heap para repetir 'veces' cantidad una cadena
 * 'origen'.
 * @param origen es el puntero a la cadena origen.
 * @param veces es la cantidad de veces que se repite la cadena.
 *
 * @pre el puntero debe ser válido y accesible.La cadena debe contener el
 * terminador '\0'.
 *
 * @return el puntero al bloque en el heap con la cadena repetida, NULL ante
 * parámetro inválido o fallo en la memoria.
 */
char *cadena_repetir(const char *origen, size_t veces);
#endif 
