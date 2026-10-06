#ifndef CONSULTA_CSV_H
#define CONSULTA_CSV_H
 
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>



int *matriz_filtrar_por_columna(const int *matriz, size_t filas, size_t columnas,
                                 size_t columna_criterio, int umbral,
                                 size_t *out_filas);


float *matriz_calcular_promedios_columna(const int *matriz, size_t filas, size_t columnas);


int matriz_exportar_csv(const char *ruta_archivo, const int *matriz, size_t filas, size_t columnas);

#endif 
