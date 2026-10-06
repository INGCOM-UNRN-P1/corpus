#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



/**
 * @brief Elimina los espacios iniciales y finales de una cadena.
 *
 * @param origen Cadena cuyos espacios iniciales y finales se desean eliminar.
 *
 * @pre 'origen' debe ser una cadena válida terminada en '\0'.
 * @post Si la operación es exitosa, se crea un bloque en heap, de tamaño
 *       exacto, que contiene el texto de 'origen' sin sus espacios iniciales
 *       ni finales, terminado en '\0'. 'origen' no se modifica.
 *
 * @return Puntero hacia la cadena recortada, o NULL si 'origen' es NULL o 
 *         contiene únicamente espacios.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Reserva dinámicamente el espacio necesario para repetir una cadena
 *        una determinada cantidad de veces
 *
 * @param origen Cadena que se desea repetir.
 * @param veces Cantidad de veces que se desea repetir la cadena.
 *
 * @pre 'origen' debe ser una cadena válida terminada en '\0'.
 * @post Si la operación es exitosa, se crea un bloque en heap que contiene
 *       la cadena repetida y terminada en '\0'.
 *
 * @return Puntero hacia la cadena repetida, o NULL si 'origen' es NULL o
 *         no se puede reservar la memoria necesaria.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
