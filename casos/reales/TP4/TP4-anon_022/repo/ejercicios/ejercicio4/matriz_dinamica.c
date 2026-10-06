/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

int **matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0) {
        return NULL;
    }

    int *datos = malloc(filas * columnas * sizeof(int));
    if (datos == NULL) {
        return NULL;
    }

    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL) {
        free(datos);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++) {
        matriz[i] = datos + i * columnas;
    }

    return matriz;
}

void matriz_destruir(int **matriz)
{
    if (matriz == NULL) {
        return;
    }

    free(matriz[0]);
    free(matriz);
}

int **matriz_cargar_desde_csv(const char *ruta,
                              size_t *filas,
                              size_t *columnas)
{
    if (ruta == NULL || filas == NULL || columnas == NULL) {
        return NULL;
    }

    FILE *archivo = fopen(ruta, "r");

    if (archivo == NULL) {
        return NULL;
    }

    char linea[1024];

    *filas = 0;
    *columnas = 0;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {

        if (*filas == 0) {
            *columnas = 1;

            for (size_t i = 0; linea[i] != '\0'; i++) {
                if (linea[i] == ',') {
                    (*columnas)++;
                }
            }
        }

        (*filas)++;
    }

    if (*filas == 0) {
        fclose(archivo);
        return NULL;
    }

    rewind(archivo);

    int **matriz = matriz_crear(*filas, *columnas);

    if (matriz == NULL) {
        fclose(archivo);
        return NULL;
    }

    for (size_t i = 0; i < *filas; i++) {

        for (size_t j = 0; j < *columnas; j++) {

            if (fscanf(archivo, "%d", &matriz[i][j]) != 1) {
                matriz_destruir(matriz);
                fclose(archivo);
                return NULL;
            }

            if (j < *columnas - 1) {
                fgetc(archivo);
            }
        }
    }

    fclose(archivo);

    return matriz;
}