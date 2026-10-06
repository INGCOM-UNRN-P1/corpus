#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Copia una cadena origen a destino de manera segura utilizando aritmética de punteros.
 *
 * @param destino Puntero al buffer de destino.
 * @param capacidad Capacidad total del buffer de destino (incluyendo '\0').
 * @param origen Puntero a la cadena de origen.
 * @return true si la cadena se copió completamente.
 * @return false si los parámetros son inválidos, capacidad es 0 o si se truncó la cadena.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

/**
 * @brief Concatena la cadena origen al final de la cadena destino utilizando aritmética de punteros.
 *
 * @param destino Puntero al buffer de destino que contiene una cadena terminada en '\0'.
 * @param capacidad Capacidad total del buffer de destino.
 * @param origen Puntero a la cadena de origen a anexar.
 * @return true si se concatenó completamente.
 * @return false si los parámetros son inválidos, no cabe o se truncó la cadena.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
