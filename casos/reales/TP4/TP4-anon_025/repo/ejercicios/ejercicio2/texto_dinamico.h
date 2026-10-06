#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



 /**
  * @brief Elimina espacios iniciales y finales de una cadena, retornando una copia en heap
  * 
  * @param origen Puntero a la cadena original de solo lectura.
  * 
  * @return char* Nueva cadena sin espacios en los extremos o NULL si es invalida
  */
 char *cadena_recortar_espacios(const char *origen);

 /**
  * @brief Repite una cadena una cantidad especifica de veces en un nuevo bloque en heap.
  * 
  * @param origen Puntero a la cadena a repetir.
  * @param veces Cantidad de veces a conectar la cadena original.
  * 
  * @return char* Nueva cadena dinamica o NULL si hay error
  */
 char *cadena_repetir(const char *origen, size_t veces);

#endif 
