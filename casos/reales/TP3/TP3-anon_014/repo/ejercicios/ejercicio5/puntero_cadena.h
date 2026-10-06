#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>

/**
 * Copia la cadena 'origen' en 'destino' sin superar su capacidad,
 * avanzando punteros en lugar de usar índices.
 *
 * @param destino   Buffer donde se escribe la copia.
 * @param capacidad Tamaño total del buffer destino, incluido el '\0'.
 * @param origen    Cadena terminada en '\0' a copiar (solo lectura).
 *
 * @pre destino tiene al menos 'capacidad' bytes.
 * @pre destino y origen no se superponen en memoria.
 *
 * @returns true si la cadena entró completa; false si se truncó, si algún
 *          puntero es NULL o si capacidad es 0.
 *
 * @post Si destino no es NULL y capacidad > 0, destino queda terminado en
 *       '\0' dentro de sus primeros 'capacidad' bytes.
 */
bool copiar_con_punteros(char *destino, size_t capacidad,
                         const char *origen);

/**
 * Agrega la cadena 'origen' al final de 'destino' sin superar su
 * capacidad, usando un puntero auxiliar que avanza hasta el '\0' de
 * destino.
 *
 * @param destino   Cadena terminada en '\0' a la que se le agrega origen.
 * @param capacidad Tamaño total del buffer destino, incluido el '\0'.
 * @param origen    Cadena terminada en '\0' a agregar (solo lectura).
 *
 * @pre destino tiene al menos 'capacidad' bytes.
 * @pre destino y origen no se superponen en memoria.
 *
 * @returns true si origen entró completa; false si se truncó, si algún
 *          puntero es NULL, si capacidad es 0 o si destino no tiene '\0'
 *          dentro de su capacidad.
 *
 * @post Si retorna true, destino contiene su texto original seguido de
 *       origen. Si se truncó, destino igual queda terminado en '\0'.
 */
bool concatenar_con_punteros(char *destino, size_t capacidad,
                             const char *origen);

/**
 * Calcula la longitud de una cadena sin leer más allá de 'capacidad'
 * bytes, usando resta de punteros.
 *
 * @param cadena    Cadena a medir (solo lectura).
 * @param capacidad Máxima cantidad de bytes que se pueden leer.
 *
 * @pre Si cadena no es NULL, tiene al menos 'capacidad' bytes accesibles
 *      o un '\0' antes.
 *
 * @returns La cantidad de caracteres antes del '\0', o 'capacidad' si no lo
 *          encuentra dentro de ese límite. Retorna 0 si cadena es NULL.
 */
size_t longitud_con_punteros(const char *cadena, size_t capacidad);

#endif 
