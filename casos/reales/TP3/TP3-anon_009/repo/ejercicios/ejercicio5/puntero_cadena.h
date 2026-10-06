#ifndef PUNTERO_CADENA_H
#define PUNTERO_CADENA_H

#include <stdbool.h>
#include <stddef.h>



 
 bool copiar_con_punteros(char *destino, size_t capacidad, const char *origen);

 
 bool concatenar_con_punteros(char *destino, size_t capacidad, const char *origen);

 #endif 
