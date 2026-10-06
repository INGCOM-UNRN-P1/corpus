/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stdio.h>
#include <stdlib.h>


int **matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0) return NULL;

    int **matriz = (int **)malloc(filas * sizeof(int *));
    if (matriz == NULL) return NULL;

    int *datos = (int *)calloc(filas * columnas, sizeof(int));
    if (datos == NULL)
    {
        free(matriz);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = datos + (i * columnas);
    }
    return matriz;
}

void matriz_destruir(int **matriz)
{
    if (matriz[0] != NULL)
    {
        free(matriz[0]);
    }
    free(matriz);
}

int **matriz_cargar_desde_csv(const char *ruta, size_t *out_filas, size_t *out_columnas)
{
    if (ruta == NULL || out_filas == NULL || out_columnas == NULL) return NULL;

    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL) return NULL;

    size_t filas = 0, columnas = 0;
    if (fscanf(archivo, "%zu, %zu", &filas, &columnas) != 2)
    {
        fclose(archivo);
        return NULL;
    }

    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            if (fscanf(archivo, "%d,", &matriz[i][j]) != 1)
            {
                matriz_destruir(matriz);
                fclose(archivo);
                return NULL;
            }
        }
    }

    *out_filas = filas;
    *out_columnas = columnas;
    fclose(archivo);
    return matriz;
}