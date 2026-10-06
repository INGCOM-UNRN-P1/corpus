/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include "consulta_csv.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


int **matriz_filtrar_por_columna(int **matriz, size_t filas, size_t columnas,
                                 size_t columna_filtro, int umbral,
                                 size_t *filas_filtradas)
{
    if (matriz == NULL || filas == 0 || columnas == 0 ||
        columna_filtro >= columnas || filas_filtradas == NULL)
    {
        if (filas_filtradas != NULL)
        {
            *filas_filtradas = 0;
        }
        return NULL;
    }

    size_t contador = 0;
    size_t i = 0;
    while (i < filas)
    {
        if (matriz[i][columna_filtro] > umbral)
        {
            contador++;
        }
        i++;
    }

    if (contador == 0)
    {
        *filas_filtradas = 0;
        return NULL;
    }

    int **matriz_filtrada = malloc(contador * sizeof(int *));
    if (matriz_filtrada == NULL)
    {
        *filas_filtradas = 0;
        return NULL;
    }
    size_t pos_destino = 0;
    i = 0;
    bool error_memoria = false;

    while (i < filas && !error_memoria)
    {
        if (matriz[i][columna_filtro] > umbral)
        {
            matriz_filtrada[pos_destino] = malloc(columnas * sizeof(int));
            if (matriz_filtrada[pos_destino] == NULL)
            {
                error_memoria = true;
            }
            else
            {
                size_t j = 0;
                while (j < columnas)
                {
                    matriz_filtrada[pos_destino][j] = matriz[i][j];
                    j++;
                }
                pos_destino++;
            }
        }
        i++;
    }
    if (error_memoria)
    {
        size_t k = 0;
        while (k < pos_destino)
        {
            free(matriz_filtrada[k]);
            k++;
        }
        free(matriz_filtrada);
        *filas_filtradas = 0;
        return NULL;
    }

    *filas_filtradas = contador;
    return matriz_filtrada;
}


float *matriz_calcular_promedios(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    }

    float *promedios = malloc(columnas * sizeof(float));
    if (promedios == NULL)
    {
        return NULL;
    }

    size_t j = 0;
    while (j < columnas)
    {
        long suma = 0;
        size_t i = 0;
        while (i < filas)
        {
            suma += matriz[i][j];
            i++;
        }
        promedios[j] = (float)suma / (float)filas;
        j++;
    }

    return promedios;
}


bool matriz_exportar_csv(const char *ruta_archivo, int **matriz, size_t filas,
                         size_t columnas)
{
    if (ruta_archivo == NULL || matriz == NULL || filas == 0 || columnas == 0)
    {
        return false;
    }

    FILE *archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL)
    {
        return false;
    }

    size_t i = 0;
    while (i < filas)
    {
        size_t j = 0;
        while (j < columnas)
        {
            fprintf(archivo, "%d", matriz[i][j]);
            if (j < columnas - 1)
            {
                fprintf(archivo, ",");
            }
            j++;
        }
        fprintf(archivo, "\n");
        i++;
    }

    fclose(archivo);
    return true;
}
