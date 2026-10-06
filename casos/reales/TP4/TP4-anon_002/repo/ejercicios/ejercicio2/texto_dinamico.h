#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include "string.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Elimina los espacios iniciales y finales de una cadena.
 *
 * @param origen Cadena de caracteres que se desea recortar.
 *
 * @pre origen debe apuntar a una cadena válida terminada en '\0', o ser NULL.
 *
 * @post Si origen es válido y contiene caracteres distintos de espacios,
 *       retorna una nueva cadena dinámica sin espacios iniciales ni finales.
 *       Si origen es NULL o solo contiene espacios, retorna NULL.
 *
 * @return Puntero a la cadena recortada en memoria dinámica,
 *         o NULL ante un parámetro inválido o si solo contiene espacios.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Repite dinámicamente una cadena una cantidad determinada de veces.
 *
 * @param origen Cadena de caracteres que se desea repetir.
 * @param veces Cantidad de veces que se repetirá la cadena.
 *
 * @pre origen debe apuntar a una cadena válida terminada en '\0', o ser NULL.
 *
 * @post Si la operación es exitosa, retorna una nueva cadena dinámica
 *       que contiene origen repetida veces veces y terminada en '\0'.
 *       Si veces es 0, retorna una cadena vacía en memoria dinámica.
 *
 * @return Puntero a la cadena repetida en memoria dinámica,
 *         o NULL si origen es NULL o falla la reserva.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
