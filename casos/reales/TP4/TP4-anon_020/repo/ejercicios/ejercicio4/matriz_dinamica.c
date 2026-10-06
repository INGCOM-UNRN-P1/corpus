/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz_dinamica.h"

int *crear_matriz_plana(size_t filas, size_t columnas)
{
    size_t total_elementos;
    int *matriz_plana;

    if (filas == 0U || columnas == 0U)
    {
        return NULL;
    }

    total_elementos = filas * columnas;
    matriz_plana = calloc(total_elementos, sizeof(*matriz_plana));
    if (matriz_plana == NULL)
    {
        return NULL;
    }

    return matriz_plana;
}

int obtener_celda(const int *matriz_plana, size_t columnas, size_t fila,
                  size_t col)
{
    if (matriz_plana == NULL)
    {
        return 0;
    }

    return matriz_plana[fila * columnas + col];
}

void asignar_celda(int *matriz_plana, size_t columnas, size_t fila, size_t col,
                  int valor)
{
    if (matriz_plana == NULL)
    {
        return;
    }

    matriz_plana[fila * columnas + col] = valor;
}

void liberar_matriz_plana(int *matriz_plana)
{
    free(matriz_plana);
}

int **matriz_crear(size_t filas, size_t columnas)
{
    int **matriz_filas = NULL;
    int *bloque_filas = NULL;
    size_t indice_fila = 0U;

    if (filas == 0U || columnas == 0U)
    {
        return NULL;
    }

    matriz_filas = malloc(filas * sizeof(*matriz_filas));
    if (matriz_filas == NULL)
    {
        return NULL;
    }

    bloque_filas = crear_matriz_plana(filas, columnas);
    if (bloque_filas == NULL)
    {
        free(matriz_filas);
        return NULL;
    }

    for (indice_fila = 0U; indice_fila < filas; ++indice_fila)
    {
        matriz_filas[indice_fila] = bloque_filas + (indice_fila * columnas);
    }

    return matriz_filas;
}

void matriz_destruir(int **matriz_filas, size_t filas)
{
    if (matriz_filas == NULL || filas == 0U)
    {
        return;
    }

    free(matriz_filas[0]);
    free(matriz_filas);
}

int **matriz_cargar_desde_csv(const char *ruta_csv, size_t *filas,
                              size_t *columnas)
{
    FILE *archivo = NULL;
    char linea[256];
    char *token = NULL;
    int **matriz_cargada = NULL;
    size_t filas_totales = 0U;
    size_t columnas_totales = 0U;
    size_t fila_actual = 0U;
    size_t columna_actual = 0U;

    if (ruta_csv == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }

    archivo = fopen(ruta_csv, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    if (fgets(linea, sizeof(linea), archivo) == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    columnas_totales = 1U;
    for (columna_actual = 0U; linea[columna_actual] != '\0'; ++columna_actual)
    {
        if (linea[columna_actual] == ',')
        {
            ++columnas_totales;
        }
    }

    filas_totales = 1U;
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (linea[0] != '\n' && linea[0] != '\0')
        {
            ++filas_totales;
        }
    }

    rewind(archivo);
    matriz_cargada = matriz_crear(filas_totales, columnas_totales);
    if (matriz_cargada == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    fila_actual = 0U;
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (linea[0] == '\n' || linea[0] == '\0')
        {
            continue;
        }

        columna_actual = 0U;
        token = strtok(linea, ",\n");
        while (token != NULL && columna_actual < columnas_totales)
        {
            matriz_cargada[fila_actual][columna_actual] = atoi(token);
            ++columna_actual;
            token = strtok(NULL, ",\n");
        }

        if (columna_actual != columnas_totales || token != NULL)
        {
            
            matriz_destruir(matriz_cargada, filas_totales);
            fclose(archivo);
            return NULL;
        }

        ++fila_actual;
    }

    fclose(archivo);
    *filas = filas_totales;
    *columnas = columnas_totales;

    return matriz_cargada;
}