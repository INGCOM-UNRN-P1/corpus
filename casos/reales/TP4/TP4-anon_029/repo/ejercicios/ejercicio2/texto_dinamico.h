#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include "cadenas.h"
#include "cadenas_tp2.h"
#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Elimina los espacios inciales y finales, copiando la cadena desde
 *  el primer caracter hasta el ultimo.
 * @pre 'origen' no debe ser NULL.
 * @pre la nueva cadeena no puede contener espacios
 *  ni al principio, ni al final.
 * @post se devolvera a un nuevo bloque limpio.
 * @param origen Es la cadena original.
 * @return Retorna char *al nuevo bloque o NULL si origen es NULL
 *  o solo contiene espacios.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Se repite una cadena 'veces' vecees en el heeap.
 * @pre 'origen' no debe ser NULL.
 * @post si 'veces' es 0 retorna una cadena vacia,
 *  sino las cadenas repetidas.
 * @param origen es la cadena original.
 * @param veces son la cantidad de veces que se repetira
 *  a origen en el heap.
 * @return Retorna el puntero char *o si veces es 0,
 *  retorna una cadena vacia en heap ("") o NULL segun error.
 */
char *cadena_repetir(const char *origen, size_t veces);
#endif 
