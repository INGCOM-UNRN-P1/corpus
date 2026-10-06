/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

int **matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    int **matriz = (int **)malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }
    int *datos = (int *)calloc(filas * columnas, sizeof(*datos));
    if (datos == NULL)
    {
        free(matriz);
        matriz = NULL;
        return NULL;
    }
    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = datos + i * columnas;
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

int **matriz_cargar_desde_csv(const char *ruta, size_t *filas,
                              size_t *columnas)
{
    if (ruta == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    unsigned long leidas_filas = 0;
    unsigned long leidas_columnas = 0;
    int **matriz = NULL;
    if (fscanf(archivo, "%lu,%lu", &leidas_filas, &leidas_columnas) == 2)
    {
        matriz = matriz_crear(leidas_filas, leidas_columnas);
    }

    bool sin_error = matriz != NULL;
    size_t total = leidas_filas * leidas_columnas;
    for (size_t i = 0; i < total && sin_error == true; i++)
    {
        
        sin_error = fscanf(archivo, "%d,", &matriz[0][i]) == 1;
    }

    if (sin_error == false)
    {
        matriz_destruir(matriz);
        matriz = NULL;
    }
    else
    {
        *filas = leidas_filas;
        *columnas = leidas_columnas;
    }
    fclose(archivo);
    return matriz;
}

int *crear_matriz_plana(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    int *m = (int *)calloc(filas * columnas, sizeof(*m));
    return m;
}

int obtener_celda(const int *m, size_t columnas, size_t fila, size_t col)
{
    return m[fila * columnas + col];
}

bool asignar_celda(int *m, size_t columnas, size_t fila, size_t col,
                   int valor)
{
    if (m == NULL || col >= columnas)
    {
        return false;
    }
    m[fila * columnas + col] = valor;
    return true;
}

void liberar_matriz_plana(int *m)
{
    free(m);
}
