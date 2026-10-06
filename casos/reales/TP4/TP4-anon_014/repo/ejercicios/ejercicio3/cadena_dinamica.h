#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Duplica una cadena en un bloque de heap de tamaño exacto.
 * @param origen cadena a duplicar.
 * @returns la copia, o NULL si origen es NULL o falla malloc.
 * @post el llamador libera la copia con free.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en un bloque nuevo de tamaño exacto.
 * @param primera primera cadena.
 * @param segunda segunda cadena.
 * @returns la concatenación, o NULL si alguna es NULL o falla malloc.
 * @post el llamador libera el resultado con free.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

/**
 * @brief Genera en heap una cadena con los caracteres de origen invertidos.
 * @param origen cadena a invertir (no se modifica).
 * @returns la cadena invertida, o NULL si origen es NULL o falla malloc.
 * @post el llamador libera el resultado con free.
 */
char *invertir_cadena_dinamico(const char *origen);

/**
 * @brief Separa una cadena en tokens según un delimitador.
 *
 * Los tokens vacíos se conservan: "a,,b" da "a", "" y "b".
 *
 * @param cadena cadena a separar.
 * @param delimitador carácter separador.
 * @param cantidad salida: cantidad de tokens (0 ante error).
 * @returns arreglo en heap de tokens en heap, o NULL si algún puntero es
 *          NULL o falla la memoria.
 * @post el llamador libera el resultado con liberar_tokens.
 */
char **partir_por_delimitador(const char *cadena, char delimitador,
                              size_t *cantidad);

/**
 * @brief Libera cada token, luego el arreglo, y deja el puntero en NULL.
 * @param tokens dirección del arreglo de tokens (acepta NULL).
 * @param cantidad cantidad de tokens del arreglo.
 * @post *tokens vale NULL.
 */
void liberar_tokens(char ***tokens, size_t cantidad);

#endif 
