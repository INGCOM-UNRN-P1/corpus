#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Clona una cadena en un nuevo bloque del heap de tamaño exacto.
 *
 * Calcula la longitud de @p origen, reserva con malloc longitud + 1 bytes y copia
 * la cadena junto con su terminador '\0'.
 *
 * @pre @p origen es NULL o apunta a una cadena válida terminada en '\0'.
 * @post Si retorna un puntero no NULL, este apunta a un bloque del heap de
 *       longitud + 1 bytes con una copia idéntica de @p origen, terminada en '\0',
 *       independiente de la cadena original. @p origen no se modifica.
 *
 * @param origen Cadena a clonar.
 * @return Puntero al clon en heap, o NULL si @p origen es NULL o falla malloc.
 *
 * @note El llamador es responsable de liberar el resultado con free().
 */
char *clonar_cadena(const char *origen);
 
/**
 * @brief Une dos cadenas en un nuevo bloque del heap de tamaño exacto.
 *
 * Calcula la longitud combinada, reserva con malloc longitud1 + longitud2 + 1 bytes
 * y construye la concatenación de @p primera seguida de @p segunda.
 *
 * @pre @p primera y @p segunda son NULL o apuntan a cadenas válidas terminadas en '\0'.
 * @post Si retorna un puntero no NULL, este apunta a un bloque del heap con la
 *       concatenación de ambas cadenas, terminada en '\0'. Las cadenas de
 *       entrada no se modifican.
 *
 * @param primera Cadena que queda al principio del resultado.
 * @param segunda Cadena que queda al final del resultado.
 * @return Puntero a la cadena unida en heap, o NULL si alguna entrada es NULL,
 *         la longitud total desborda size_t o falla malloc.
 *
 * @note El llamador es responsable de liberar el resultado con free().
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
