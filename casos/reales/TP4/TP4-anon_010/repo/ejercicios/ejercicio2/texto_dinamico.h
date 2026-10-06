#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"


/**
 * @brief Crea en el heap una copia de 'origen' sin los espacios iniciales ni finales.
 *
 * @param origen Cadena a recortar.
 *
 * @pre Si 'origen' no es NULL, debe estar terminada en '\0'.
 * @post 'origen' no se modifica. El resultado ocupa exactamente longitud_limpia + 1
 *       bytes, está terminado en '\0' y el llamador es responsable de liberarlo.
 *
 * @return Puntero a la cadena recortada en heap, o NULL si 'origen' es NULL, si solo
 *         contiene espacios (o está vacía) o si falla la reserva de memoria.
 */
char *cadena_recortar_espacios(const char *origen);
 
/**
 * @brief Crea en el heap una cadena que repite 'origen' la cantidad de 'veces' indicada.
 *
 * @param origen Cadena a repetir.
 * @param veces Cantidad de repeticiones.
 *
 * @pre Si 'origen' no es NULL, debe estar terminada en '\0'.
 * @post 'origen' no se modifica. El resultado ocupa exactamente
 *       longitud_origen * 'veces' + 1 bytes, está terminado en '\0' y el llamador es
 *       responsable de liberarlo.
 *
 * @return Puntero a la cadena repetida en heap (cadena vacía si 'veces' es 0), o NULL
 *         si 'origen' es NULL o falla la reserva de memoria.
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
