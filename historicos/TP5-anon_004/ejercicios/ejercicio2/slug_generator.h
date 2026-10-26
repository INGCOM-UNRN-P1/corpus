/**
 * @file slug_generator.h
 * @brief Generacion y sanitizacion de slugs utilizando cadenas dinamicas seguras.
 *
 * Trabajo Practico 5 - Programacion 1
 * Universidad Nacional de Rio Negro - Ingenieria en Computacion
 */

#ifndef SLUG_GENERATOR_H
#define SLUG_GENERATOR_H

#include <stdbool.h>
#include <stddef.h>
#include "cadena_segura.h"

/**
 * @brief Transforma un titulo en un slug normalizado en minusculas,
 * reemplazando caracteres no alfanumericos por guiones y eliminando guiones repetidos o en bordes.
 *
 * @param titulo Puntero a la cadena segura de origen.
 * @param slug Puntero a la estructura donde se creara el slug resultante.
 * @return true si se genero correctamente el slug, false en caso de error o parametros invalidos.
 */
bool generar_slug(const cadena_segura_t *titulo, cadena_segura_t *slug);

/**
 * @brief Verifica si una cadena contiene una palabra prohibida o subcadena especifica.
 *
 * @param texto Puntero a la cadena segura a evaluar.
 * @param palabra Subcadena a buscar.
 * @return true si la palabra se encuentra en el texto, false si no o parametros invalidos.
 */
bool contiene_palabra_prohibida(const cadena_segura_t *texto, const char *palabra);

/**
 * @brief Acota la longitud de un slug a un maximo dado, evitando que termine en guion.
 *
 * @param slug Puntero al slug a recortar (se modifica in-situ).
 * @param max_longitud Longitud maxima deseada.
 * @return true si la operacion fue exitosa, false en caso de error o parametros invalidos.
 */
bool acotar_longitud_slug(cadena_segura_t *slug, size_t max_longitud);

#endif 
