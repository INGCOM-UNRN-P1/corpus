#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Divide una línea en campos y almacena cada uno como una cadena
 *        independiente en el heap.
 *
 * @param linea Cadena que se desea dividir.
 * @param delimitador Carácter utilizado para separar los campos.
 * @param cantidad_tokens Puntero donde se almacena la cantidad de campos
 *                        obtenidos.
 *
 * @pre Si 'linea' no es NULL, debe estar terminada en '\0'.
 *
 * @post Si la operación es exitosa, '*cantidad_tokens' contiene la cantidad
 *       de cadenas almacenadas en el arreglo retornado.
 *       Si la operación falla, '*cantidad_tokens' queda establecido en 0.
 *
 * @return Puntero al arreglo dinámico de cadenas obtenido.
 *         Retorna NULL si 'linea' o 'cantidad_tokens' son NULL, o si falla
 *         alguna asignación de memoria.
 */
char **dividir_linea_csv(const char *linea,
                         char delimitador,
                         size_t *cantidad_tokens);

/**
 * @brief Libera un arreglo dinámico de cadenas y anula su puntero.
 *
 * @param puntero_arreglo Dirección del puntero que referencia al arreglo
 *                        de cadenas.
 * @param cantidad Cantidad de cadenas que deben liberarse.
 *
 * @post Si 'puntero_arreglo' y '*puntero_arreglo' son válidos, se liberan
 *       las cadenas contenidas, se libera el arreglo y '*puntero_arreglo'
 *       queda establecido en NULL.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo,
                             size_t cantidad);

                             
#endif 
