#ifndef TEXTO_DINAMICO_H
#define TEXTO_DINAMICO_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"



 
char *cadena_recortar_espacios(const char *origen);
 

char *cadena_repetir(const char *origen, size_t veces);

#endif 
