#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stddef.h>
#include "cadenas.h"

/**
 * @brief Elimina espacios en blanco al principio y al final de una cadena.
 * @param origen Cadena original.
 * @return Cadena recortada en heap o NULL si es inválida, queda vacía o falla malloc.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Repite una cadena una cantidad dada de veces.
 * @param origen Cadena original.
 * @param veces Cantidad de repeticiones.
 * @return Cadena repetida en heap; para cero repeticiones retorna "" en heap.
 */
char *cadena_repetir(const char *origen, size_t veces);

/**
 * @brief Alias compatible con la consigna general para recortar espacios.
 * @param origen Cadena original.
 * @return Cadena recortada en heap o NULL ante error.
 */
char *recortar_espacios_dinamico(const char *origen);

/**
 * @brief Crea una copia dinámica de una cadena convertida a mayúsculas.
 * @param origen Cadena original.
 * @return Copia en mayúsculas o NULL ante error.
 */
char *normalizar_mayusculas_dinamico(const char *origen);

#endif 
