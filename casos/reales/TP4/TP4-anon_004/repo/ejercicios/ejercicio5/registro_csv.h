#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stddef.h>



/** @brief Separa una linea por un delimitador simple (sin comillas CSV).
 * 
 * @pre linea termina en cero; cantidad_tokens es un puntero escribible.
 * @post Conserva campos vacios; cada token y el arreglo tienen reserva propia.
 * 
 * @param linea Texto de solo lectura; una linea vacia produce un token vacio.
 * @param delimitador Separador distinto de cero.
 * @param cantidad_tokens Cantidad de tokens; queda cero ante error.
 * 
 * @return Arreglo propio o NULL ante error; usar liberar_arreglo_cadenas.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);

/** @brief Libera todos los tokens, el arreglo y anula su puntero.
 * 
 * @pre El arreglo tiene cantidad tokens propios o es NULL.
 * @post *puntero_arreglo queda NULL; argumento NULL se ignora.
 * 
 * @param puntero_arreglo Direccion del arreglo propietario.
 * @param cantidad Numero de tokens a liberar.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 