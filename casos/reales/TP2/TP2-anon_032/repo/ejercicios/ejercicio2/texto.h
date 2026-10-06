#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Une dos cadenas de texto intercalando un separador.
 * @param destino La cadena donde se guardara el texto unido.
 * @param capacidad La capacidad de destino.
 * @param primero La primera cadena a unir.
 * @param segundo La segunda cadena a unir.
 * @param separador El caracter que se usara para separar las cadenas.
 * @pre Las cadenas no deben ser nulas y capacidad debe ser mayor a la suma del largo
 * de primero, segundo y el separador.
 * @post Se uniran las dos cadenas con un separador en el medio sin modificar las cadenas. 
 * Si la capacidad de destino no es suficiente la cadena quedara truncada.
 * @returns Retorna true si la operación se realizó con éxito o false de lo contrario.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
