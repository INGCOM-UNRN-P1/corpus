#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * @brief Se reserva en el heap un espacio en memoria justo para poder
 *  clonar a la cadena 'origen'.
 * @pre 'origen' no debe ser NULL.
 * @post retorna un puntero que apunta al clon de origen.
 * @param origen es la cadena original.
 * @return Retorna el puntero char * (que apunta al clon).
 *  Si origen es NULL o falla la asignación, retorna NULL.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Se unen ambas cadenas en el heap.
 * @pre ni 'primera', ni 'segunda' puedeen ser NULL.
 * @post Devuelve una nueva cadena formada por la union de primera y seegunda.
 * @param primera es la primera cadena.
 * @param segunda es la segunda cadena.
 * @return Devuelve la direccion de memoria de la nueva cadena.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);
#endif 
