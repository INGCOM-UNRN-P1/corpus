#ifndef CADENAS_H
#define CADENAS_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Duplica una cadena en el heap calculando su longitud de forma segura.
 * 
 * @param[in] origen Cadena original a duplicar.
 * @param[in] capacidad_max Maximo de caracteres a revisar por seguridad.
 * @return char* Puntero a la nueva cadena en heap, o NULL en caso de error.
 * 
 * #PRE 'origen' no debe ser NULL y 'capacidad_max' debe ser mayor a 0.
 * #POST Retorna un puntero a una nueva cadena en el heap, que es una copia de 'origen' (hasta 'capacidad_max'), garantizando el '\0'.
 */
char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);

/**
 * @brief Une dos cadenas en una nueva cadena creada en el heap.
 * 
 * @param[in] primera Primera cadena.
 * @param[in] cap_primera Capacidad maxima de revision para la primera cadena.
 * @param[in] segunda Segunda cadena a anexar.
 * @param[in] cap_segunda Capacidad maxima de revision para la segunda cadena.
 * @return char* Puntero a la nueva cadena concatenada en heap, o NULL en error.
 * 
 * #PRE Punteros no deben ser NULL, capacidades > 0, y la suma de longitudes no debe superar SIZE_MAX.
 * #POST Retorna una nueva cadena en el heap que contiene 'primera' seguida de 'segunda', con su respectivo '\0'.
 */
char *cadena_unir_dinamica(const char *primera, size_t cap_primera, const char *segunda, size_t cap_segunda);

/**
 * @brief Libera la memoria de una cadena y previene punteros colgantes.
 * 
 * @param[in, out] puntero_cadena Doble puntero a la cadena dinamica (char **).
 * 
 * #PRE 'puntero_cadena' no debe ser NULL.
 * #POST La memoria es liberada (si no era NULL) y el puntero original se establece en NULL.
 */
void cadena_liberar_segura(char **puntero_cadena);

/**
 * @brief Extrae una subcadena dinamica a partir de un indice especifico.
 * 
 * @param[in] origen Cadena de texto base.
 * @param[in] capacidad_max Limite maximo de revision de seguridad sobre 'origen'.
 * @param[in] inicio Indice (base 0) desde donde comienza la extraccion.
 * @param[in] cantidad Numero maximo de caracteres a extraer.
 * @return char* Puntero a la nueva subcadena en heap, o NULL en caso de error.
 * 
 * #PRE 'origen' no debe ser NULL y 'capacidad_max' debe ser mayor a 0.
 * #POST Retorna una nueva cadena en el heap con los caracteres extraidos. Si 'inicio' esta fuera de rango, retorna una cadena vacia ("").
 */
char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max, size_t inicio, size_t cantidad);

/**
 * @brief Genera una copia en heap de la cadena original, pero invertida.
 * 
 * @param[in] origen Cadena de texto base.
 * @param[in] capacidad_max Limite maximo de revision de seguridad sobre 'origen'.
 * @return char* Puntero a la nueva cadena invertida en heap, o NULL en error.
 * 
 * #PRE 'origen' no debe ser NULL y 'capacidad_max' debe ser mayor a 0.
 * #POST Retorna una nueva cadena en el heap con los caracteres en orden inverso, terminada en '\0'.
 */
char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 