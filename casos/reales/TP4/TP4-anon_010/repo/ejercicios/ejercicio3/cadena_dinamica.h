#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Clona una cadena en un nuevo bloque de heap de tamaño exacto.
 *
 * @param origen Cadena a clonar.
 *
 * @pre Si 'origen' no es NULL, debe estar terminada en '\0'.
 * @post 'origen' no se modifica. La copia ocupa exactamente longitud + 1 bytes,
 *       está terminada en '\0' y el llamador es responsable de liberarla con free.
 *
 * @return Puntero a la copia en heap, o NULL si 'origen' es NULL o falla la reserva
 *         de memoria.
 */
char *clonar_cadena(const char *origen);
 
/**
 * @brief Concatena dos cadenas en un nuevo bloque de heap de tamaño exacto.
 *
 * @param primera Cadena que queda al principio del resultado.
 * @param segunda Cadena que queda al final del resultado.
 *
 * @pre Si 'primera' y 'segunda' no son NULL, deben estar terminadas en '\0'.
 * @post 'primera' y 'segunda' no se modifican. El resultado ocupa exactamente
 *       longitud1 + longitud2 + 1 bytes, está terminado en '\0' y el llamador es
 *       responsable de liberarlo con free.
 *
 * @return Puntero a la cadena concatenada en heap, o NULL si alguna entrada es NULL
 *         o falla la reserva de memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
