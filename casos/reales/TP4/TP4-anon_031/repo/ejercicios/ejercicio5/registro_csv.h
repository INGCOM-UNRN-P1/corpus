#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Divide una línea en campos separados por un delimitador.
 * @param linea Línea a dividir.
 * @param delimitador Carácter separador.
 * @param cantidad_tokens Parámetro de salida con la cantidad de campos.
 * @return Arreglo dinámico de cadenas independientes o NULL ante error.
 */
char **dividir_linea_csv(const char *linea, char delimitador, size_t *cantidad_tokens);

/**
 * @brief Libera cada cadena de un arreglo y luego el arreglo.
 * @param puntero_arreglo Dirección del arreglo dinámico.
 * @param cantidad Cantidad de cadenas almacenadas.
 */
void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);

/**
 * @brief Crea una lista dinámica vacía de cadenas.
 * @return NULL, representación elegida para la lista vacía.
 */
char **lista_cadenas_crear(void);

/**
 * @brief Duplica una cadena y la agrega al final de una lista dinámica.
 * @param lista Dirección del arreglo de punteros.
 * @param cantidad Dirección de la cantidad actual de elementos.
 * @param cadena Cadena a duplicar y agregar.
 * @return true ante éxito; false ante parámetros inválidos o falta de memoria.
 */
bool lista_cadenas_agregar(char ***lista, size_t *cantidad, const char *cadena);

/**
 * @brief Libera todas las cadenas y el arreglo que las contiene.
 * @param lista Lista a destruir.
 * @param cantidad Cantidad de cadenas almacenadas.
 */
void lista_cadenas_destruir(char **lista, size_t cantidad);

#endif 
