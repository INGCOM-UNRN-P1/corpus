#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>



/**
* @brief une dos cadenas colocando un separador entre ambas.
*
* @param destino Donde se guarda el resultado.
* @param capacidad Tamaño total de destino (incluye el '\0').
* @param primero Cadena que va al principio.
* @param segundo Cadena que va al final.
* @param separador Cadena que va entre las dos.
*
* @return true si se pudo unir todo.
* @return false si algún puntero es NULL, si capacidad es 0 o si
*         el resultado no entra en destino.
*/

bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
