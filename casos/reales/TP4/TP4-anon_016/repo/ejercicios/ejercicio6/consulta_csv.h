#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H

#include <stdbool.h>
#include <stddef.h>


 

int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas,
                                 size_t columna_filtro, int umbral,
                                 size_t *filas_resultado);
 

float *matriz_sumar_columnas(int **matriz, size_t filas, size_t columnas);
 

float *matriz_promediar_columnas(int **matriz, size_t filas, size_t columnas);
 

void liberar_arreglo_floats(float **puntero_arreglo);
 

bool matriz_exportar_csv(const char *ruta, int **matriz, size_t filas,
                         size_t columnas);
 
#endif 
 
