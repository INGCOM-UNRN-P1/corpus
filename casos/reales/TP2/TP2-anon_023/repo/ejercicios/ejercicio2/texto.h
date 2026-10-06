#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas de texto intercalando un separador dentro de un buffer acotado.
 *
 * Utiliza de forma segura las operaciones de copia y concatenacion provistas por libcadenas.
 * Garantiza la terminacion en caracter nulo ('\0') en el buffer destino.
 *
 * @pre `destino` debe apuntar a un bufer valido de al menos `capacidad` bytes.
 * @pre `primero`, `segundo` y `separador` deben ser cadenas terminadas en '\0'.
 * @post Si la operacion es exitosa, `destino` contendra la concatenacion completa
 *       "primero + separador + segundo\0". Si el espacio es insuficiente, se truncara
 *       garantizando el '\0' final.
 *
 * @param destino Bufer donde se almacena el texto resultante.
 * @param capacidad Tamano maximo en bytes disponible en `destino`.
 * @param primero Primera subcadena a colocar.
 * @param segundo Segunda subcadena a colocar al final.
 * @param separador Cadena intermedia a intercalar entre la primera y la segunda.
 *
 * @return true si las cadenas y el separador entraron completos sin truncar,
 *         false si alguno de los punteros es NULL, capacidad es 0 o si el contenido
 *         tuvo que ser truncado por falta de espacio.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
