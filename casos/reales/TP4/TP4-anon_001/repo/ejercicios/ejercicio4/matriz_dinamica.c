/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stdlib.h>
#include <stdio.h>

int **matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    int *datos = malloc(filas * columnas * sizeof(int));
    if (datos == NULL)
    {
        return NULL;
    }
    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL)
    {
        free(datos);
        return NULL;
    }
    for (size_t f = 0; f < filas; f++)
    {
        matriz[f] = datos + (f * columnas);
    }
    return matriz;
}

void matriz_destruir(int **matriz)
{
    if (matriz == NULL)
    {
        return;
    }

    free(matriz[0]);
    free(matriz);
}


int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas,
                              size_t *columnas)
{
    if (ruta_archivo == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }

    FILE *f = fopen(ruta_archivo, "r");
    if (f == NULL)
    {
        return NULL;
    }
    if (fscanf(f, "%zu,%zu", filas, columnas) != 2)
    {
        fclose(f);
        return NULL;
    }
    int **matriz = matriz_crear(*filas, *columnas);
    if (matriz == NULL)
    {
        fclose(f);
        return NULL;
    }

    for (size_t i = 0; i < *filas; i++)
    {
        for (size_t j = 0; j < *columnas; j++)
        {
            if (fscanf(f, " %d,", &matriz[i][j]) != 1)
            {
                matriz_destruir(matriz);
                fclose(f);
                return NULL;
            }
        }
    }
    fclose(f);
    return matriz;
}
