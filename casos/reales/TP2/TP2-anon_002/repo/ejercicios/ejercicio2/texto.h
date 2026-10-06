#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Une dos cadenas intercalando un separador.
 *
 * @param destino Búfer donde se almacena el resultado.
 * @param capacidad Capacidad del búfer destino, incluyendo el espacio
 *                  necesario para el carácter '\0'.
 * @param primero Primera cadena que se copia al destino.
 * @param segundo Segunda cadena que se concatena al destino.
 * @param separador Cadena que se intercala entre 'primero' y 'segundo'.
 *
 * @pre Si 'capacidad' es mayor que 0, 'destino' debe apuntar a un búfer
 *      válido con espacio para 'capacidad' caracteres.
 * @returns true si la cadena completa pudo construirse en 'destino';
 *          false si algún parámetro es NULL, 'capacidad' es 0 o no hay
 *          espacio suficiente.
 * @post Si retorna true, 'destino' contiene 'primero', seguido de
 *       'separador' y 'segundo', terminado en '\0'.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
