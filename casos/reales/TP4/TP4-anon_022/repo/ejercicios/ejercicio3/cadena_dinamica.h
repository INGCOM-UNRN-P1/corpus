#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



/**
 * @brief Reserva memoria dinámica para almacenar una copia de una cadena.
 *
 * @param origen Cadena que se desea copiar.
 *
 * @pre Si 'origen' no es NULL, debe apuntar a una cadena válida terminada
 *      en '\0'.
 *
 * @post Si la asignación es exitosa, se retorna una nueva cadena almacenada
 *       en el heap con el mismo contenido que 'origen'. La cadena original
 *       permanece sin modificaciones.
 *
 * @return Puntero a la nueva cadena, o NULL si 'origen' es NULL o falla
 *         la asignación de memoria.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Reserva memoria dinámica para almacenar la concatenación de dos 
 *        cadenas.
 *
 * @param primera Cadena que ocupará la primera parte del resultado.
 * @param segunda Cadena que se anexará a continuación de 'primera'.
 *
 * @pre Si 'primera' y 'segunda' no son NULL, deben apuntar a cadenas válidas
 *      terminadas en '\0'.
 *
 * @post Si la asignación es exitosa, se retorna una nueva cadena almacenada
 *       en el heap que contiene 'primera' seguida de 'segunda'. Las cadenas
 *       originales permanecen sin modificaciones.
 *
 * @return Puntero a la cadena concatenada, o NULL si alguna de las cadenas
 *         es NULL o falla la asignación de memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
