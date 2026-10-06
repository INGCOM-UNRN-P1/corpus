/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int **matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0) {
        return NULL;
    }

    int **matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        return NULL;
    }

    int *datos = (int *)malloc(filas * columnas * sizeof(int));
    if (datos == NULL) {
        free(matriz);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++) {
        matriz[i] = datos + (i * columnas);
    }

    return matriz;
}

void matriz_destruir(int **matriz)
{
    if (matriz == NULL) {
        return;
    }

    if (matriz[0] != NULL) {
        free(matriz[0]);
    }

    free(matriz);
}

int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas_out, size_t *columnas_out)
{
    if (ruta_archivo == NULL || filas_out == NULL || columnas_out == NULL) {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL) {
        return NULL;
    }

    char linea[1024];
    size_t filas = 0;
    size_t columnas = 0;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        if (linea[0] == '\n' || linea[0] == '\r') {
            continue;
        }

        if (filas == 0) {
            char *token = strtok(linea, ",\r\n");
            while (token != NULL) {
                columnas++;
                token = strtok(NULL, ",\r\n");
            }
        }
        filas++;
    }

    if (filas == 0 || columnas == 0) {
        fclose(archivo);
        return NULL;
    }

    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL) {
        fclose(archivo);
        return NULL;
    }

    rewind(archivo);
    size_t i = 0;

    while (fgets(linea, sizeof(linea), archivo) != NULL && i < filas) {
        if (linea[0] == '\n' || linea[0] == '\r') {
            continue;
        }

        size_t j = 0;
        char *token = strtok(linea, ",\r\n");
        while (token != NULL && j < columnas) {
            matriz[i][j] = atoi(token);
            j++;
            token = strtok(NULL, ",\r\n");
        }
        i++;
    }

    fclose(archivo);

    *filas_out = filas;
    *columnas_out = columnas;

    return matriz;
}