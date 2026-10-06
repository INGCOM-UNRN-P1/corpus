/**
 * @file vector_enteros.c
 * @brief Implementación de clonación y filtrado dinámico de enteros (sin structs).
 */

#include <stdlib.h>
#include <string.h>
#include "vector_enteros.h"
 
int *clonar_arreglo_enteros(const int *origen, size_t cantidad)
{
    int *copia = NULL;
 
    if (origen != NULL && cantidad > 0) {
        copia = malloc(cantidad * sizeof(int));
        if (copia != NULL) {
            memcpy(copia, origen, cantidad * sizeof(int));
        }
    }
    return copia;
}
 
int *filtrar_arreglo_pares(const int *origen, size_t cantidad_origen, size_t *cantidad_pares)
{
    int *pares = NULL;
 
    if (cantidad_pares != NULL) {
        *cantidad_pares = 0;
 
        if (origen != NULL) {
            size_t total_pares = 0;
            for (size_t i = 0; i < cantidad_origen; ++i) {
                if (origen[i] % 2 == 0) {
                    total_pares++;
                }
            }
 
            if (total_pares > 0) {
                pares = malloc(total_pares * sizeof(int));
                if (pares != NULL) {
                    size_t j = 0;
                    for (size_t i = 0; i < cantidad_origen; ++i) {
                        if (origen[i] % 2 == 0) {
                            pares[j] = origen[i];
                            j++;
                        }
                    }
                    *cantidad_pares = total_pares;
                }
            }
        }
    }
    return pares;
}
