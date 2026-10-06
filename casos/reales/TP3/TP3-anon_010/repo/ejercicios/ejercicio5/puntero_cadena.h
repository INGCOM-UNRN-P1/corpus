#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>




/**
 * @brief Calcula la longitud de una cadena, sin exceder su capacidad física.
 *
 * Recorre la cadena exclusivamente con aritmética de punteros (sin `[]`).
 *
 * @param[in] cadena    Cadena de solo lectura a medir.
 * @param[in] capacidad Capacidad total del búfer 'cadena' (cantidad máxima
 * de bytes a inspeccionar, incluyendo el lugar del '\0').
 *
 * @pre Ninguna; la función es segura ante 'cadena' NULL.
 *
 * @post La cadena no es modificada.
 *
 * @return La cantidad de caracteres antes del primer '\0' encontrado dentro
 * de los primeros 'capacidad' bytes. Retorna 'capacidad' si no se encuentra
 * ningún '\0' en ese rango, o si 'cadena' es NULL.
 */
size_t longitud_con_punteros(const char *cadena, size_t capacidad);


/**
 * @brief Copia una cadena de origen a un búfer destino, sin desbordar su
 * capacidad, garantizando terminación nula.
 *
 * Recorre ambas cadenas exclusivamente con aritmética de punteros
 * (`*dst++ = *src++`, sin `[]`).
 *
 * @param[out] destino   Búfer mutable donde se copia el resultado.
 * @param[in]  capacidad Capacidad total de 'destino' en bytes (incluyendo el
 * lugar del '\0').
 * @param[in]  origen    Cadena de solo lectura a copiar.
 *
 * @pre 'origen' debe estar correctamente terminada en '\0' dentro de un
 * rango razonable de memoria.
 *
 * @post 'destino' queda terminado en '\0' dentro de sus límites válidos,
 * conteniendo como máximo 'capacidad' - 1 caracteres de 'origen'.
 *
 * @return true si 'origen' se copió completo; false si el texto se truncó
 * por falta de capacidad, o si 'destino' es NULL, 'origen' es NULL, o
 * 'capacidad' es 0.
 */
bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);


/**
 * @brief Concatena una cadena de origen al final del texto ya existente en
 * un búfer destino, sin desbordar su capacidad.
 *
 * Avanza un puntero auxiliar hasta el terminador '\0' de 'destino' y a
 * continuación copia los caracteres de 'origen' con aritmética de punteros,
 * respetando la capacidad máxima.
 *
 * @param[in, out] destino   Búfer mutable que ya contiene una cadena segura,
 * al cual se le anexa 'origen'.
 * @param[in]      capacidad Capacidad total de 'destino' en bytes (incluyendo
 * el lugar del '\0').
 * @param[in]      origen    Cadena de solo lectura a anexar.
 *
 * @pre 'destino' debe estar correctamente terminado en '\0' dentro de
 * 'capacidad' (invariante de cadena segura). 'origen' debe estar
 * correctamente terminada en '\0'.
 *
 * @post 'destino' queda terminado en '\0' dentro de sus límites válidos, con
 * tanto de 'origen' anexado como haya entrado sin exceder 'capacidad' - 1
 * caracteres totales.
 *
 * @return true si 'origen' se anexó completo; false si el texto se truncó
 * por falta de capacidad, o si 'destino' es NULL, 'origen' es NULL, o
 * 'capacidad' es 0.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

#endif 
