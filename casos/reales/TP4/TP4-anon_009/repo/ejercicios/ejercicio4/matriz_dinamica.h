#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

    


int **matriz_crear(size_t filas, size_t columnas);


void matriz_destruir(int **matriz);


int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *out_filas, size_t *out_columnas);

#endif 
