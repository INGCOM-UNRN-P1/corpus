#ifndef TEXTO_H
#define TEXTO_H

#include <stdbool.h>
#include <stddef.h>


/**
 * @brief Une dos cadenas de texto intercalando un separador en un búfer destino
 * seguro de tamaño acotado por 'capacidad', utilizando las funciones de
 * copia y concatenación provistas por libcadenas.
 * @param destino es el puntero al inicio de la cadena destino.
 * @param capacidad es la cantidad de elementos de la cadena destino.
 * @param primero es el puntero al inicio de la primera cadena.
 * @param segundo es el puntero al inicio de la segunda cadena.
 * @param separador es el puntero al inicio de la cadena separadora.
 * @return true si las cadenas fueron unidas exitosamente, false casoc ontrario
 * o si los punteros son nulos o capacidad = 0.
 */
bool unir_con_separador(char destino[],
                        size_t capacidad,
                        const char primero[],
                        const char segundo[],
                        const char separador[]);

#endif
