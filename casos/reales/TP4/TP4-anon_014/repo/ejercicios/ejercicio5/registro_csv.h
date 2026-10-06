#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>





/**
 * @brief Crea una lista de cadenas vacía.
 * @returns NULL, que representa la lista vacía (cantidad 0).
 * @post la lista se completa con lista_cadenas_agregar.
 */
char **lista_cadenas_crear(void);

/**
 * @brief Duplica una cadena y la agrega al final de la lista.
 * @param lista dirección de la lista (la lista puede ser NULL si está
 *        vacía).
 * @param cantidad cantidad actual de cadenas; se incrementa ante éxito.
 * @param cadena cadena a agregar.
 * @pre lista, cantidad y cadena no son NULL.
 * @returns true ante éxito; false si algún argumento es NULL o falla la
 *          memoria (la lista original queda intacta).
 * @post la lista es dueña de la copia agregada.
 */
bool lista_cadenas_agregar(char ***lista, size_t *cantidad,
                           const char *cadena);

/**
 * @brief Libera cada cadena de la lista y luego el arreglo.
 * @param lista lista a liberar (acepta NULL).
 * @param cantidad cantidad de cadenas de la lista.
 * @post el llamador debe asignar NULL a su puntero.
 */
void lista_cadenas_destruir(char **lista, size_t cantidad);



/**
 * @brief Separa una línea CSV en campos duplicados en heap.
 *
 * Los campos vacíos se conservan: "a,,b" da "a", "" y "b".
 *
 * @param linea línea a separar.
 * @param delimitador carácter separador de campos.
 * @param cantidad_tokens salida: cantidad de campos (0 ante error).
 * @returns arreglo de campos, o NULL si algún puntero es NULL o falla la
 *          memoria.
 * @post el llamador libera el resultado con liberar_arreglo_cadenas.
 */
char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);

/**
 * @brief Libera cada cadena, luego el arreglo, y deja el puntero en NULL.
 * @param puntero_arreglo dirección del arreglo (acepta NULL).
 * @param cantidad cantidad de cadenas del arreglo.
 * @post *puntero_arreglo vale NULL.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

#endif 
