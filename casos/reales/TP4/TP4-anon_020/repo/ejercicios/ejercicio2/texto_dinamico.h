#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stddef.h>
#include "cadenas.h"

/**
 * @brief Recorta espacios iniciales y finales de una cadena.
 * @param origen Cadena de texto de entrada.
 * @pre origen no es NULL.
 * @post Se devuelve una nueva cadena sin espacios al inicio ni al final.
 * @note La memoria resultante la debe liberar el llamador con cadena_liberar_segura(&puntero).
 * @returns Nueva cadena recortada o NULL si la entrada es inválida o solo tiene espacios.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Repite una cadena una cantidad determinada de veces.
 * @param origen Cadena base a repetir.
 * @param veces Cantidad de repeticiones.
 * @pre origen no es NULL.
 * @post Se devuelve una nueva cadena con el patrón repetido.
 * @note Si veces es 0, devuelve una cadena vacía en heap que debe liberarse con cadena_liberar_segura.
 * @returns Nueva cadena repetida o NULL si falla la reserva.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
