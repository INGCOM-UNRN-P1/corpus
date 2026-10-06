/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include "consulta_csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int **crear_matriz_contigua(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0) {
        return NULL;
    }

    int **filas_ptr = (int **)malloc(filas * sizeof(int *));
    if (filas_ptr == NULL) {
        return NULL;
    }

    int *datos = (int *)malloc(filas * columnas * sizeof(int));
    if (datos == NULL) {
        free(filas_ptr);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++) {
        filas_ptr[i] = datos + (i * columnas);
    }

    return filas_ptr;
}

void consulta_liberar_matriz(int **matriz)
{
    if (matriz != NULL) {
        if (matriz[0] != NULL) {
            free(matriz[0]);
        }
        free(matriz);
    }
}

int **consulta_cargar_csv(const char *ruta_archivo, size_t *filas, size_t *columnas)
{
    if (ruta_archivo == NULL || filas == NULL || columnas == NULL) {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) {
        return NULL;
    }

    size_t lineas = 0;
    size_t cols = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        if (lineas == 0) {
            char *token = strtok(buffer, ",\n\r");
            while (token != NULL) {
                cols++;
                token = strtok(NULL, ",\n\r");
            }
        }
        lineas++;
    }

    if (lineas == 0 || cols == 0) {
        fclose(archivo);
        return NULL;
    }

    rewind(archivo);

    int **matriz = crear_matriz_contigua(lineas, cols);
    if (matriz == NULL) {
        fclose(archivo);
        return NULL;
    }

    size_t f = 0;
    while (fgets(buffer, sizeof(buffer), archivo) != NULL && f < lineas) {
        size_t c = 0;
        char *token = strtok(buffer, ",\n\r");
        while (token != NULL && c < cols) {
            matriz[f][c] = atoi(token);
            c++;
            token = strtok(NULL, ",\n\r");
        }
        f++;
    }

    fclose(archivo);
    *filas = lineas;
    *columnas = cols;
    return matriz;
}

int **consulta_filtrar_mayor(int **matriz_origen, size_t filas_origen, size_t columnas, size_t col_filtro, int umbral, size_t *filas_destino)
{
    if (matriz_origen == NULL || filas_destino == NULL || col_filtro >= columnas) {
        return NULL;
    }

    size_t coincidencias = 0;
    for (size_t i = 0; i < filas_origen; i++) {
        if (matriz_origen[i][col_filtro] > umbral) {
            coincidencias++;
        }
    }

    *filas_destino = coincidencias;
    if (coincidencias == 0) {
        return NULL;
    }

    int **matriz_filtrada = crear_matriz_contigua(coincidencias, columnas);
    if (matriz_filtrada == NULL) {
        return NULL;
    }

    size_t pos_dest = 0;
    for (size_t i = 0; i < filas_origen; i++) {
        if (matriz_origen[i][col_filtro] > umbral) {
            for (size_t j = 0; j < columnas; j++) {
                matriz_filtrada[pos_dest][j] = matriz_origen[i][j];
            }
            pos_dest++;
        }
    }

    return matriz_filtrada;
}

float *consulta_promedios_por_columna(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0) {
        return NULL;
    }

    float *promedios = (float *)malloc(columnas * sizeof(float));
    if (promedios == NULL) {
        return NULL;
    }

    for (size_t j = 0; j < columnas; j++) {
        long suma = 0;
        for (size_t i = 0; i < filas; i++) {
            suma += matriz[i][j];
        }
        promedios[j] = (float)suma / (float)filas;
    }

    return promedios;
}

bool consulta_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas)
{
    if (ruta_archivo == NULL || matriz == NULL || filas == 0 || columnas == 0) {
        return false;
    }

    FILE *archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL) {
        return false;
    }

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            fprintf(archivo, "%d%s", matriz[i][j], (j + 1 < columnas) ? "," : "");
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    return true;
}