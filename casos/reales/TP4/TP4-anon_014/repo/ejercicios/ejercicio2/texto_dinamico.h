#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



/**
 * @brief Copia en heap la cadena sin espacios iniciales ni finales.
 * @param origen cadena a recortar.
 * @returns la cadena recortada, o NULL si origen es NULL, solo contiene
 *          espacios o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Construye en heap la cadena origen repetida 'veces' veces.
 * @param origen cadena a repetir.
 * @param veces cantidad de repeticiones.
 * @returns la cadena repetida ("" si veces es 0), o NULL si origen es NULL
 *          o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *cadena_repetir(const char *origen, size_t veces);

/**
 * @brief Copia en heap la cadena sin espacios iniciales ni finales
 *        (versión del README: una cadena solo de espacios da "").
 * @param origen cadena a recortar.
 * @returns la cadena recortada, o NULL si origen es NULL o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *recortar_espacios_dinamico(const char *origen);

/**
 * @brief Copia en heap la cadena con todas sus letras en mayúsculas.
 * @param origen cadena a normalizar.
 * @returns la cadena en mayúsculas, o NULL si origen es NULL o falla malloc.
 * @post el llamador libera el resultado con cadena_liberar_segura.
 */
char *normalizar_mayusculas_dinamico(const char *origen);

#endif 
