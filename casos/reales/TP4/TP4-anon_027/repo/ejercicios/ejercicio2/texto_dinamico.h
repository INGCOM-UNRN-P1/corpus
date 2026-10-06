#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"

 
 /** 
 * @brief recibe const char *origen.Elimina los espacios iniciales y finales 
 * (trimming), reserva un bloque exacto en heap con malloc y copia el texto 
 * limpio con su '\0'.
 *
 * @param origen puntero que apunta a un arreglo a ser examinado.
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free` y debe contar con terminador nulo '\0'.
 * 
 * @return char* al nuevo bloque o NULL si origen es NULL o solo 
 * contiene espacios.
 *
 * @post la función debe retornar un bloque en heap con el texto copiado 
 * sin espacios con su terminador nulo. 
 *
 * @invariant 'origen'
*/
 char *cadena_recortar_espacios(const char *origen);
 
 
 


 
 /** 
 * @brief Reserva dinámicamente en el heap el espacio exacto para 
 * repetir la cadena'veces' veces y retorna el puntero char*.
 *
 * @param origen puntero que apunta a un arreglo a ser examinado.
 * @param veces define la cantidad de veces que se va a repetir
 * 'origen' en el heap.
 * 
 * @pre toda asignación con `malloc`/`calloc`/`realloc` 
 * debe liberarse con `free`.
 * 
 * @return una cadena vacía en heap ("") si veces es 0
 * o NULL según error.
 *
 * @post debe retornar n cantidad de veces la cadena 'origen'
 * repetida en el heap.
 *
 * @invariant 'origen'
*/
char *cadena_repetir(const char *origen, size_t veces);

#endif 
