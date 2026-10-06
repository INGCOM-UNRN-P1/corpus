#ifndef CADENAS_H
#define CADENAS_H

#include <stddef.h>

/**
 * @brief Duplica una cadena en memoria dinámica con límite seguro.
 * @param origen Cadena de entrada a copiar.
 * @param capacidad_max Máxima cantidad de caracteres a inspeccionar.
 * @pre origen no es NULL y capacidad_max es mayor que cero.
 * @post Se crea una nueva cadena terminada en '\0' en el heap.
 * @note El bloque devuelto debe liberarse con cadena_liberar_segura(&puntero).
 * @returns Puntero a la copia nueva o NULL si la entrada es inválida o falla la reserva.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * @brief Une dos cadenas en una sola nueva cadena dinámica.
 * @param primera Primera cadena a concatenar.
 * @param cap_primera Cantidad máxima segura de la primera cadena.
 * @param segunda Segunda cadena a concatenar.
 * @param cap_segunda Cantidad máxima segura de la segunda cadena.
 * @pre primera y segunda son no NULL, y ambas capacidades son mayores que cero.
 * @post Se devuelve una nueva cadena con la concatenación de ambas.
 * @note El bloque devuelto debe liberarse con cadena_liberar_segura(&puntero).
 * @returns Nueva cadena concatenada o NULL si hay error.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);

/**
 * @brief Libera una cadena dinámica y deja el puntero en NULL.
 * @param puntero_cadena Dirección del puntero que apunta a la cadena.
 * @pre puntero_cadena puede ser NULL o apuntar a un bloque válido en heap.
 * @post Si el puntero era válido, la memoria se libera y el puntero queda en NULL.
 * @note Esta función es la liberación recomendada para todos los bloques creados por
 *       cadena_duplicar_segura, cadena_unir_dinamica, cadena_subcadena_dinamica y
 *       cadena_invertir_dinamica.
 */
void cadena_liberar_segura(char **puntero_cadena);

/**
 * @brief Extrae una subcadena dinámica.
 * @param origen Cadena fuente.
 * @param capacidad_max Límite seguro de lectura de origen.
 * @param inicio Índice inicial de la extracción.
 * @param cantidad Cantidad máxima de caracteres a copiar.
 * @pre origen no es NULL y capacidad_max es mayor que cero.
 * @post Se devuelve una nueva cadena terminada en '\0' con el fragmento pedido.
 * @note Si inicio supera la longitud de origen, la función devuelve una cadena vacía en heap.
 * @returns Nueva subcadena o NULL si falla la reserva.
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                               size_t inicio, size_t cantidad);

/**
 * @brief Devuelve una nueva cadena invertida.
 * @param origen Cadena original.
 * @param capacidad_max Límite seguro de lectura de origen.
 * @pre origen no es NULL y capacidad_max es mayor que cero.
 * @post Se devuelve una copia invertida de origen en el heap.
 * @note El bloque devuelto debe liberarse con cadena_liberar_segura(&puntero).
 * @returns Cadena invertida o NULL si hay error.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
