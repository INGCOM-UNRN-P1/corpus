#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Se unen dos cadenas con un separador entre medio.
 * @pre destino no puede ser NULL.
 * @pre primero no puede ser NULL.
 * @pre segundo no puede ser NULL.
 * @pre separador no puede ser NULL.
 * @pre capacidad no debe ser 0.
 * @post Se obtendra una nueva cadena resultante de la union de
 * las otras dos mas la separacion.
 * @param destino es la cadena resultante de dicha union.
 * @param capacidad es el espacio en la memoria disponicle desde 0 hasta '\0'.
 * @param primero es la primera cadena que formara parte de la nueva cadena.
 * @param segundo es la segunda cadena que formara parte de la nueva cadena.
 * @param separador es el caracter que separara a las dos cadenas
 * originalees en la nueva.
 * @return devuelve true si la nueva cadena,
 * logro cumplir con todas las condiciones, de otra manera devuelve false.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
