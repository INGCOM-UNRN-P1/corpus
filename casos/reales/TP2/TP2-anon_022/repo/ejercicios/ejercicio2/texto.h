#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Une dos cadenas de texto utilizando un separador en un búfer destino.
 *
 * @pre 'destino' no debe ser nulo.
 *      'capacidad' debe ser mayor que 0.
 *      'primero', 'segundo' y 'separador' no deben ser nulos.
 *
 * @post Si devuelve true, 'destino' contiene 'primero', seguido de
 *       'separador' y 'segundo'.
 *       Si devuelve false, alguna operación de copia o concatenación
 *       falló, por lo que el contenido de 'destino' pudo haber sido
 *       modificado parcialmente.
 *
 * @param destino Búfer donde se almacenará la cadena final.
 * @param capacidad Cantidad máxima de bytes disponibles en el búfer
 *                  destino, incluido el terminador '\0'.
 * @param primero Primera cadena que se desea unir.
 * @param segundo Segunda cadena que se desea unir.
 * @param separador Separador con el que se realizará la unión.
 *
 * @return true si las tres operaciones se completaron correctamente.
 *         false si hubo argumentos inválidos o truncamiento en alguna
 *         operación.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
