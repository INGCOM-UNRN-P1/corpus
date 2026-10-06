#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



 /**
 * @brief Elimina los espacios iniciales y finales de una cadena y la guarda en heap.
 * 
 * @param origen Cadena constante de entrada.
 * @return char* Puntero al nuevo bloque en heap, o NULL si origen es NULL o si la cadena contiene únicamente espacios/caracteres invisibles.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Reserva espacio exacto en heap para repetir la cadena 'veces' veces.
 * 
 * @param origen Cadena constante de entrada.
 * @param veces Cantidad de repeticiones.
 * @return char* Puntero al nuevo bloque en heap, "" (cadena vacía en heap) si veces es 0, o NULL en caso de error o si origen es NULL.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
