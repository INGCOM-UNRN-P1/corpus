#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Divide una línea en campos separados por un delimitador, cada uno en heap.
 *
 * Cada delimitador separa dos campos, por lo que una línea con N delimitadores
 * produce N + 1 campos. Los campos vacíos se conservan (por ejemplo, "a,,b" produce
 * "a", "" y "b"), y una línea vacía produce un único campo vacío.
 *
 * @param linea Línea de texto a dividir.
 * @param delimitador Carácter que separa los campos.
 * @param cantidad_tokens Dirección donde se almacena la cantidad de campos obtenidos.
 *
 * @pre 'linea' debe estar terminada en '\0' y 'cantidad_tokens' no debe ser NULL.
 * @post 'linea' no se modifica. Si retorna un puntero no nulo, '*cantidad_tokens' es
 *       la cantidad de campos, cada campo es una cadena independiente en heap terminada
 *       en '\0', y el llamador es responsable de liberar todo con liberar_arreglo_cadenas.
 *       En caso contrario, '*cantidad_tokens' queda en 0 y no queda memoria reservada.
 *
 * @return Arreglo de punteros a los campos, o NULL si 'linea' o 'cantidad_tokens' son
 *         NULL o si falla la reserva de memoria.
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);
 
/**
 * @brief Libera un arreglo de cadenas en heap y deja el puntero del llamador en NULL.
 *
 * @param puntero_arreglo Dirección del puntero al arreglo de cadenas a liberar.
 * @param cantidad Cantidad de cadenas que contiene el arreglo.
 *
 * @pre Si '*puntero_arreglo' no es NULL, debe apuntar a un arreglo de 'cantidad' cadenas
 *      en heap (por ejemplo, el obtenido con dividir_linea_csv) que no haya sido liberado.
 * @post Cada cadena y el arreglo quedan liberados, y '*puntero_arreglo' es NULL. Si
 *       'puntero_arreglo' o '*puntero_arreglo' eran NULL, no se realiza ninguna acción.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 
