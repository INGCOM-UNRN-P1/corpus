
#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stddef.h>
#include "cadenas.h"



/**
 * @brief Elimina los espacios iniciales y finales de una cadena.
 *
 * @pre origen debe ser NULL o una cadena terminada en '\0'.
 * @post Retorna una nueva cadena sin espacios en los extremos.
 *
 * @param origen Cadena original.
 * @return Nueva cadena en heap o NULL si no queda contenido o ante error.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Repite una cadena una cantidad determinada de veces.
 *
 * @pre origen debe apuntar a una cadena terminada en '\0'.
 * @post Retorna una nueva cadena con el contenido repetido veces veces.
 *
 * @param origen Cadena original.
 * @param veces Cantidad de repeticiones.
 * 
 * @return Nueva cadena en heap o NULL ante error.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
