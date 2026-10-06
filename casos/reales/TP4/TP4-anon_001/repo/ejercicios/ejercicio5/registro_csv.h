#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Divide una cadena en formato CSV en sus componentes (tokens) usando un
 * delimitador.
 *
 * Analiza la cadena recibida, cuenta los campos separados por el delimitador
 * especificado, reserva en el heap un arreglo de punteros a cadena (char **) y
 * asigna memoria en el heap para cada una de las palabras duplicadas con su
 * terminador nulo '\0'.
 *
 * @pre `linea != NULL` y `cantidad_tokens != NULL`.
 * @post Si la tokenización es exitosa, se asigna memoria en el heap para el
 * arreglo de punteros y para cada cadena individual.El valor apuntado por
 * `cantidad_tokens` se actualiza.Si falla la asignación de memoria o la línea
 * es NULL, retorna NULL y libera memoria parcial.
 *
 * @param linea Cadena de texto de entrada a dividir.
 * @param delimitador que separa los campos (por ejemplo, ',').
 * @param cantidad_tokens Puntero a size_t donde se guardará la cantidad de
 * tokens encontrados.
 *
 * @return Puntero char **al arreglo de cadenas en el heap, o NULL ante error o
 * entrada inválida.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);

                         /**
 * @brief Libera la memoria asignada a un arreglo dinámico de cadenas y sus elementos.
 * 
 * @param arreglo Puntero al arreglo dinámico de cadenas (char ***).
 * @param cantidad cadenas guardadas en el arreglo.
 */
void liberar_arreglo_cadenas(char ***arreglo, size_t cantidad);

#endif 
