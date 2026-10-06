#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include "cadenas.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


/**
 * @brief Divide la cadena en campos (tokes) segun un delimitador.
 *      Se reserva memoria dinamica en el heap, para un arreglo de cadenas
 *      (char**), donde cada posicion tiene una copia de la subacadena contida
 *      por los delimitadores.Y asigna la cantidad de tokens encontrados al
 *      puntero de salida para poder devolver mas de un valor (sin structs).
 * @pre 'linea' no debe ser NULL y debe terminar en '\0'.
 * @pre 'cantidad_tokens' no debe ser NULL.
 * @post Si es exitoso, asigna en '*cantidad_tokens' el numero de campos,
 *       reserva memoria para el arreglo y retorna el puntero doble.
 *       Si hay error o falla de memoria, asigna 0 en '*cantidad_tokens'
 *       y retorna NULL sin generar fugas de memoria.
 * @param linea Cadena de texto a trabajar.
 * @param delimitador Caracter utilizado para separar los campos.
 * @param cantidad_tokens Puntero de salida donde se guarda
 *  el numero de tokens.
 * @return char **Puntero al arreglo de cadenas en el heap, o NULL si falla.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);

/**
 * @brief  Libera primero cada cadena individual con free,
 *  luego libera el arreglo de punteros, y asigna *puntero_arreglo = NULL.
 * @pre ni 'puntero_arreglo' ni '*puntero_arreglo' deben ser NULL.
 * @post se liberara la memoria.
 * @param puntero_arreglo es el puntero que apunta al bloque que tiene
 *  las cadenas a liberar.
 * @param cantidad Son la cantidad de cadenas.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);
#endif 
