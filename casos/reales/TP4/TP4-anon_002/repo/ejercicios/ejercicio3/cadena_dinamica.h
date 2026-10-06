#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Crea una copia dinámica de una cadena.
 *
 * @param origen Cadena de caracteres que se desea clonar.
 *
 * @pre origen debe apuntar a una cadena válida terminada en '\0', o ser NULL.
 *
 * @post Si origen es válido y la reserva tiene éxito, retorna una nueva
 *       cadena en heap con una copia exacta de origen.Si origen es NULL
 *       o falla la reserva, retorna NULL.
 *
 * @return Puntero a la copia dinámica de la cadena, o NULL ante error.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Une dos cadenas en una nueva cadena dinámica.
 *
 * @param primera Primera cadena que se desea concatenar.
 * @param segunda Segunda cadena que se desea concatenar.
 *
 * @pre primera y segunda deben apuntar a cadenas válidas terminadas en '\0',
 *      o alguna de ellas puede ser NULL para indicar un parámetro inválido.
 *
 * @post Si ambas cadenas son válidas y la reserva tiene éxito, retorna una
 *       nueva cadena en heap que contiene primera seguida de segunda.
 *       Si alguna cadena es NULL o falla la reserva, retorna NULL.
 *
 * @return Puntero a la cadena concatenada en memoria dinámica,
 *         o NULL ante error.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
