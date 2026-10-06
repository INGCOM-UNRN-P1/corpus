#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Realiza una concatenación de dos cadenas de caracteres intercalando un separador.
 *          La cadena no debe ser NULL y la cantidad de caracteres debe ser mayor a 0.
 * @param destino[char][in] de la cadena de caracteres a concatenar.
 * @param primero[char] cadena de caracteres.
 * @param segundo[char] cadena de caracteres.
 * @param separador[char] cadena de caracteres.
 * @param capacidad[size_t] limite de caracteres que puede tener una cadena.
 * @return false si la cadena destino es NULL o la capacidad es 0, o si alguna de las cadenas a concatenar es NULL.
 *          true si la cadena se copio completamente con caracter '\0' incluido.
 *          destino[char][out] cadena concatenada con separador incluido y terminada en '\0'.
 */
 bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
