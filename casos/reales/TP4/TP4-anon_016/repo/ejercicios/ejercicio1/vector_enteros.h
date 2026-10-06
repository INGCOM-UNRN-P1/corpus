#ifndef VECTOR_ENTEROS_H
#define VECTOR_ENTEROS_H

#include <stdbool.h>
#include <stddef.h>
#include "vector.h"



 
int *clonar_arreglo_enteros(const int *origen, size_t cantidad);
 

int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen,
                           size_t *cantidad_pares);
 
#endif 


