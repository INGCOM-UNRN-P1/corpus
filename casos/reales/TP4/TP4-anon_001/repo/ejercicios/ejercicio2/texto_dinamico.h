#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>



/**
 * @brief Elimina los espacios en blanco iniciales y finales (trimming) de una
 * cadena.
 *
 * Asigna un nuevo bloque de memoria dinámica en el heap con el tamaño exacto
 * necesario para albergar el contenido limpio y lo finaliza con '\0'.
 *
 * @param origen Cadena fuente a procesar.
 *
 * @return Puntero a la nueva cadena recortada en el heap,
 *         o NULL si 'origen' es NULL, si contiene únicamente espacios en
 * blanco, o si falla la reserva de memoria.
 */
char *cadena_recortar_espacios(const char *origen);

/**
 * @brief Crea una nueva cadena en memoria dinámica repitiendo una cadena
 * origen.
 *
 * Reserva en el heap el espacio exacto de memoria necesario para almacenar la
 * cadena repetida 'veces' veces y la finaliza con el carácter nulo '\0'.
 *
 * @param origen Cadena fuente a repetir.
 * @param veces Número de repeticiones a concatenar.
 *
 * @return Puntero a la nueva cadena reservada en el heap,
 *         o NULL si 'origen' es NULL o falla la reserva de memoria.
 *         Si 'veces' es 0, retorna una cadena vacía reservada en el heap ("").
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
