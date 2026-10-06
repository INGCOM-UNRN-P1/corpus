#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>



 /**
 * @brief Divide una línea de texto en campos separados por un delimitador.
 *
 * Reserva en el heap un arreglo de punteros a cadena y, por cada campo, una
 * copia independiente terminada en '\0'. La cantidad de campos es siempre la
 * cantidad de delimitadores más uno: los campos vacíos se conservan como cadenas
 * vacías ("a,,c" produce "a", "" y "c"; "" produce un único campo vacío). No se
 * recortan espacios ni se interpretan comillas; si la línea proviene de fgets, el
 * llamador debe quitarle antes el salto de línea final.
 *
 * @pre @p linea es NULL o apunta a una cadena válida terminada en '\0';
 *      @p cantidad_tokens es un puntero válido.
 * @post Si retorna un puntero no NULL, este apunta a un arreglo de
 *       *@p cantidad_tokens (>= 1) punteros, cada uno a una cadena en heap
 *       independiente de @p linea. Si retorna NULL, no queda memoria reservada y
 *       *@p cantidad_tokens vale 0. @p linea no se modifica.
 *
 * @param linea Línea a dividir.
 * @param delimitador Carácter que separa los campos.
 * @param[out] cantidad_tokens Recibe la cantidad de campos obtenidos.
 * @return Arreglo de cadenas en heap, o NULL si @p linea o @p cantidad_tokens es NULL
 *         o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con liberar_arreglo_cadenas().
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);
 
/**
 * @brief Libera un arreglo de cadenas del heap y deja el puntero del llamador en NULL.
 *
 * Libera con free cada una de las @p cantidad cadenas, luego el arreglo de
 * punteros y finalmente asigna NULL a @c *puntero_arreglo.
 *
 * @pre @p puntero_arreglo es NULL o apunta a un arreglo obtenido de
 *      dividir_linea_csv() (o equivalente) con exactamente @p cantidad elementos,
 *      cada uno NULL o una cadena del heap.
 * @post Toda la memoria del arreglo queda liberada y @c *puntero_arreglo vale NULL.
 *
 * @param puntero_arreglo Dirección del puntero al arreglo. Si es NULL, o si
 *        @c *puntero_arreglo ya es NULL, no se realiza ninguna acción.
 * @param cantidad Cantidad de cadenas del arreglo.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 
