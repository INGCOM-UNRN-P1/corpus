

#ifndef STRING_H
#define STRING_H

#include <stdbool.h>
#include <stddef.h>



char *cadena_duplicar_segura(const char *origen, size_t capacidad_max);



char *cadena_unir_dinamica(const char *primera, size_t cap_primera,
                           const char *segunda, size_t cap_segunda);



void cadena_liberar_segura(char **puntero_cadena);



char *cadena_subcadena_dinamica(const char *origen, size_t capacidad_max,
                                size_t inicio, size_t cantidad);



char *cadena_invertir_dinamica(const char *origen, size_t capacidad_max);

#endif 
