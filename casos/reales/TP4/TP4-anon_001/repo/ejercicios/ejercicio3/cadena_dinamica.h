#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Duplica una cadena de caracteres en memoria dinámica.
 *
 * Calcula la longitud exacta de la cadena fuente 'origen', reserva
 * el espacio necesario en el heap utilizando malloc (incluyendo el
 * carácter nulo de terminación '\0') y realiza una copia exacta.
 *
 * @param origen Cadena de caracteres a duplicar.
 *
 * @return Puntero a la nueva cadena reservada en el heap,
 *         o NULL si 'origen' es NULL o falla la asignación de memoria.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Une dos cadenas de caracteres en una nueva reserva de memoria
 * dinámica.
 *
 * Calcula la longitud combinada de 'primera' y 'segunda', reserva la memoria
 * exacta necesaria en el heap (incluyendo el terminador nulo '\0') y retorna
 * una nueva cadena con la concatenación de ambas.
 *
 * @param primera cadena a concatenar.
 * @param segunda cadena a concatenar.
 *
 * @return Puntero a la nueva cadena reservada en el heap,
 *         o NULL si 'primera' es NULL, 'segunda' es NULL o falla la reserva de
 * memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

#endif 
