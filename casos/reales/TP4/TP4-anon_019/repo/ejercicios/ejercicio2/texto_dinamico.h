#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"

/**
 * @brief Elimina los espacios, tabulaciones y saltos de linea iniciales y finales.
 *
 * @param[in] origen Puntero constante a la cadena de origen.
 * @return char* Puntero a la nueva cadena recortada en heap, o NULL si es nula o solo espacios.
 * 
 * #PRE 'origen' no debe ser NULL.
 * #POST Retorna un bloque en el heap con los caracteres recortados y '\0', o NULL si estaba vacia.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Repite una cadena una cantidad especifica de veces reservando memoria exacta.
 *
 * @param[in] origen Puntero constante a la cadena de origen.
 * @param[in] veces Cantidad de veces que se repetira la cadena.
 * @return char* Puntero a la nueva cadena repetida en heap, o NULL en caso de error.
 * 
 * #PRE 'origen' no debe ser NULL. La multiplicacion de su longitud por 'veces' no debe superar SIZE_MAX.
 * #POST Retorna un bloque en el heap con la cadena repetida, o una cadena vacia "" si 'veces' es 0.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 