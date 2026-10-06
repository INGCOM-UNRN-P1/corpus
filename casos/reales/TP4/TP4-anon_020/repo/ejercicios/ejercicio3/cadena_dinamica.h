#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stddef.h>

/**
 * @brief Duplica una cadena en memoria dinámica.
 * @param origen Cadena fuente a copiar.
 * @pre origen no es NULL.
 * @post Se devuelve una nueva cadena terminada en '\0' en el heap.
 * @note La memoria devuelta debe liberarse con free() por parte del llamador.
 * @returns Puntero a la copia nueva o NULL si la entrada es inválida o falla
 *          la reserva.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en una nueva cadena dinámica.
 * @param primera Primera cadena.
 * @param segunda Segunda cadena.
 * @pre primera y segunda no son NULL.
 * @post Se devuelve una nueva cadena con la concatenación de ambas.
 * @note La memoria resultante la debe liberar el llamador con free().
 * @returns Nueva cadena concatenada o NULL si falla la reserva.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 