#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



/**
 * Elimina los espacios iniciales y finales (trimming)
 * reserva un bloque exacto en heap con malloc
 * copia el texto limpio con su '\0'.
 * Retorna char* al nuevo bloque o NULL si origen es NULL o solo contiene espacios.
 */
char *cadena_recortar_espacios(const char *origen, size_t capacidad);

/**
 * Reserva dinámicamente en el heap el espacio exacto para repetir la cadena 'veces' veces
 * retorna el puntero char*. (a el bloque supongo)
 * Si veces es 0, retorna una cadena vacía en heap ("") o NULL según error.
 */
char *cadena_repetir(const char *origen, size_t capacidad, size_t veces);



#endif 
