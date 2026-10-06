#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas con un separador en un búfer seguro.
 *
 * @param destino Búfer donde se escribirá la cadena resultante.
 * @param capacidad Tamaño total en bytes del búfer `destino` (incluye el
 *                  terminador '\0').
 * @param primero Primera cadena a copiar.
 * @param segundo Segunda cadena a concatenar.
 * @param separador Cadena que se inserta entre `primero` y `segundo`.
 * @return `true` si la unión se realizó sin truncamiento; `false` si hubo
 *         truncamiento o si algún parámetro es inválido.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
