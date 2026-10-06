#ifndef CADENA_DINAMICA_H
#define CADENA_DINAMICA_H

#include <stddef.h>

/**
 * @brief Duplica una cadena en un bloque exacto del heap.
 * @param origen Cadena original.
 * @return Copia dinámica o NULL si origen es NULL o falla la reserva.
 */
char *clonar_cadena(const char *origen);

/**
 * @brief Concatena dos cadenas en una nueva cadena dinámica.
 * @param primera Primera cadena.
 * @param segunda Segunda cadena.
 * @return Cadena concatenada o NULL ante parámetros inválidos o fallo de memoria.
 */
char *unir_cadenas_dinamicas(const char *primera, const char *segunda);

/**
 * @brief Genera una nueva cadena con los caracteres en orden inverso.
 * @param origen Cadena original.
 * @return Cadena invertida en heap o NULL ante error.
 */
char *invertir_cadena_dinamico(const char *origen);

/**
 * @brief Divide una cadena por un delimitador conservando también campos vacíos.
 * @param origen Cadena a dividir.
 * @param delimitador Carácter separador.
 * @param cantidad_tokens Parámetro de salida con la cantidad de cadenas generadas.
 * @return Arreglo dinámico de cadenas independientes o NULL ante error.
 */
char **partir_por_delimitador(const char *origen, char delimitador,
                             size_t *cantidad_tokens);

/**
 * @brief Libera un arreglo de cadenas generado por partir_por_delimitador.
 * @param puntero_partes Dirección del arreglo de cadenas.
 * @param cantidad Cantidad de cadenas almacenadas.
 */
void liberar_partes_cadena(char ***puntero_partes, size_t cantidad);

#endif 
