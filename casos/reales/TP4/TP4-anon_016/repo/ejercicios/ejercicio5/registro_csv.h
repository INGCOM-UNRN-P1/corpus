#ifndef REGISTRO_CSV_H
#define REGISTRO_CSV_H

#include <stdbool.h>
#include <stddef.h>
#include "cadenas.h"


 

char **dividir_linea_csv(const char *linea, char delimitador,
                         size_t *cantidad_tokens);
 

void liberar_arreglo_cadenas(char ***puntero_arreglo, size_t cantidad);
 
#endif 
 