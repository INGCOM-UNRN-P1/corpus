#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Divide una línea CSV en tokens dinámicos.
 * @param linea Cadena con la línea a tokenizar.
 * @param delimitador Carácter separador.
 * @param cantidad_tokens Puntero de salida con la cantidad de elementos.
 * @pre linea no es NULL y cantidad_tokens no es NULL.
 * @post Se crea un arreglo dinámico de cadenas con cada token.
 * @note La memoria devuelta debe destruirse con
 *       liberar_arreglo_cadenas(&arreglo, cantidad).
 * @returns Arreglo de cadenas o NULL si falla la reserva o la entrada
 *          es inválida.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);

/**
 * @brief Libera un arreglo dinámico de cadenas y deja el puntero en NULL.
 * @param puntero_arreglo Dirección del arreglo de cadenas.
 * @param cantidad Cantidad de elementos del arreglo.
 * @pre puntero_arreglo no es NULL.
 * @post Cada cadena se libera y luego el arreglo de punteros.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

/**
 * @brief Crea una lista dinámica de cadenas vacía.
 * @returns NULL, que representa la lista vacía. La lista se construye
 *          agregando elementos con lista_cadenas_agregar().
 */
char **lista_cadenas_crear(void);

/**
 * @brief Agrega una copia dinámica de una cadena al final de la lista.
 * @param lista Dirección del arreglo de cadenas.
 * @param cantidad Puntero a la cantidad actual de elementos.
 * @param cadena Cadena a copiar y agregar.
 * @pre lista, cantidad y cadena no son NULL.
 * @post La lista crece en 1 elemento. La nueva cadena es una copia
 *       independiente en el heap.
 * @note La lista debe destruirse con lista_cadenas_destruir().
 * @returns true si la operación tuvo éxito, false si falla la reserva.
 */
bool lista_cadenas_agregar(char ***lista, size_t *cantidad,
                           const char *cadena);

/**
 * @brief Libera una lista dinámica de cadenas y todos sus elementos.
 * @param lista Arreglo dinámico de cadenas.
 * @param cantidad Cantidad de elementos.
 * @pre lista puede ser NULL si cantidad es cero.
 * @post Se libera cada cadena y luego el arreglo de punteros.
 */
void lista_cadenas_destruir(char **lista, size_t cantidad);

#endif 