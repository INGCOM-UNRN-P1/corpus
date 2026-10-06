#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



 /**
 * @brief Elimina los espacios iniciales y finales de una cadena en un nuevo bloque del heap.
 *
 * Descarta los caracteres ' ' (espacio) del principio y del final de @p origen,
 * reserva un bloque de tamaño exacto en el heap y copia el texto limpio con su
 * terminador '\0'. La cadena origen no se modifica.
 *
 * @param origen Cadena terminada en '\0' a recortar.
 * @return Puntero al texto recortado en heap, o NULL si @p origen es NULL, está
 *         vacía, solo contiene espacios o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */
char *cadena_recortar_espacios(const char *origen);
 
/**
 * @brief Repite una cadena @p veces veces en un nuevo bloque del heap de tamaño exacto.
 *
 * Reserva longitud * @p veces + 1 bytes y copia @p origen consecutivamente
 * @p veces veces, terminando en '\0'. La cadena origen no se modifica.
 *
 * @param origen Cadena terminada en '\0' a repetir.
 * @param veces Cantidad de repeticiones.
 * @return Puntero a la cadena repetida en heap. Si @p veces es 0 (o @p origen es
 *         vacía) retorna una cadena vacía ("") en heap. Retorna NULL si @p origen
 *         es NULL, la longitud total desborda size_t o falla la reserva de memoria.
 *
 * @note El llamador es responsable de liberar el resultado con cadena_liberar_segura().
 */
char *cadena_repetir(const char *origen, size_t veces);

#endif 
