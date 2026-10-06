#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas de texto intercalando un separador entre ellas,
 *        en un búfer destino seguro, reutilizando cadena_copiar y
 *        cadena_concatenar de libcadenas.
 *
 * @param destino Búfer mutable donde se escribe el resultado. Puede ser NULL.
 * @param capacidad Capacidad total de `destino` en bytes (incluyendo el
 *                  lugar del '\0').
 * @param primero Primera cadena de solo lectura a unir. Puede ser NULL.
 * @param segundo Segunda cadena de solo lectura a unir. Puede ser NULL.
 * @param separador Cadena de solo lectura a intercalar entre `primero` y
 *                  `segundo`. Puede ser NULL.
 *
 * @pre `primero`, `segundo` y `separador` deben estar correctamente
 *      terminadas en '\0'.
 * @post Si la operación es exitosa, `destino` contiene la concatenación de
 *       `primero`, `separador` y `segundo`, terminada en '\0' dentro de sus
 *       límites válidos.
 *
 * @return true si las tres partes se copiaron/concatenaron completas sin
 *         truncamiento. Retorna false si alguna de las tres etapas trunca
 *         por falta de capacidad, o si `destino`, `primero`, `segundo` o
 *         `separador` son NULL, o si `capacidad` es 0.
 */
bool unir_con_separador(char destino[], size_t capacidad, const char primero[], const char segundo[], const char separador[]);

#endif
