/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include "consulta_csv.h"
#include <stdio.h>
#include <stdlib.h>


static int **crear_matriz_contigua(size_t filas, size_t columnas)
{
    if (filas == 0|| columnas == 0) return NULL;
    int **m = (int **)malloc(filas * sizeof(int *));
    int *datos = (int *)calloc(filas * columnas, sizeof(int));
    if (!m || !datos)
    {
        free(m);
        free(datos);
        return NULL;
    }
    for (size_t i = 0; i < filas; i++)
    {
        m[i] = datos + (i * columnas);
    }
    return m;
}

void matriz_liberar(int **matriz)
{
    if (matriz)
    {
        if (matriz[0]) free(matriz[0]);
        free(matriz);
    }
}

int **matriz_cargar_csv(const char *ruta, size_t *out_filas, size_t *out_columnas)
{
    if (!ruta || !out_filas || !out_columnas) return NULL;
    FILE *f = fopen(ruta, "r");
    if (!f) return NULL;

    int f_count = 0, c_count = 0;
    if (fscanf(f, "%d,%d", &f_count, &c_count) != 2)
    {
        fclose(f);
        return NULL;
    }
    int **matriz = crear_matriz_contigua(f_count, c_count);
    if (!matriz)
    {
        fclose(f);
        return NULL;
    }

    for (int i = 0; i < f_count; i++)
    {
        for (int j = 0; j < c_count; j++)
        {
            if (fscanf(f, "%d,", &matriz[i][j]) != 1)
            {
                matriz_liberar(matriz);
                fclose(f);
                return NULL;
            }
        }
    }
    *out_filas = f_count;
    *out_columnas = c_count;
    fclose(f);
    return matriz;
}

int **matriz_filtrar(int **original, size_t filas, size_t columnas, size_t col_filtro, int umbral, size_t *out_filas)
{
    if (!original || !out_filas || col_filtro >= columnas) return NULL;
    size_t filas_validas = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (original[i][col_filtro] > umbral)
        {
            filas_validas++;
        }
    }
    *out_filas = filas_validas;
    if (filas_validas == 0) return NULL;
    int **nueva = crear_matriz_contigua(filas_validas, columnas);
    if (!nueva) return NULL;
    size_t indice_nueva = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (original[i][col_filtro] > umbral)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                nueva[indice_nueva][j] = original[i][j];
            }
            indice_nueva++;
        }
    }
    return nueva;
}

float *matriz_promedio_columnas(int **matriz, size_t filas, size_t columnas)
{
    if (!matriz || filas == 0 || columnas == 0) return NULL;
    float *promedios = (float *)malloc(columnas * sizeof(float));
    if (!promedios) return NULL;
    for (size_t j = 0; j < columnas; j++)
    {
        long suma = 0;
    for (size_t i = 0; i < filas; i++)
    {
        suma += matriz[i][j];
    }
    promedios[j] = (float)suma / filas;
    }
    return promedios;
}

bool matriz_exportar_csv(int **matriz, size_t filas, size_t columnas, const char *ruta)
{
    if (!matriz || !ruta) return false;
    FILE *f = fopen(ruta, "w");
    if (!f) return false;
    fprintf(f, "%zu,%zu\n", filas, columnas);
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            fprintf(f, "%d,", matriz[i][j]);
        }
        fprintf(f, "\n");
    }
    fclose(f);
    return true;
}