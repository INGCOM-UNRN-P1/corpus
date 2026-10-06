/**
 * @file consulta_csv.c
 * @brief Implementacion para Ejercicio 6 (Motor de Consulta y Exportacion CSV).
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "consulta_csv.h"

int **crear_matriz_contigua(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }

    if (filas > SIZE_MAX / columnas)
    {
        return NULL;
    }

    size_t total_elementos = filas * columnas;
    if (total_elementos > SIZE_MAX / sizeof(int))
    {
        return NULL;
    }

    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }

    int *datos = calloc(total_elementos, sizeof(*datos));
    if (datos == NULL)
    {
        free(matriz);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        *(matriz + i) = datos + (i * columnas);
    }

    return matriz;
}

void destruir_matriz_contigua(int ***matriz)
{
    if (matriz != NULL && *matriz != NULL)
    {
        if (**matriz != NULL)
        {
            free(**matriz);
            **matriz = NULL;
        }
        free(*matriz);
        *matriz = NULL;
    }
}

int **cargar_matriz_csv(const char *ruta_archivo, size_t *filas, size_t *columnas)
{
    if (filas != NULL)
    {
        *filas = 0;
    }
    if (columnas != NULL)
    {
        *columnas = 0;
    }

    if (ruta_archivo == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    size_t cant_filas = 0;
    size_t cant_columnas = 0;
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        if (cant_filas == 0)
        {
            size_t comas = 0;
            for (size_t i = 0; buffer[i] != '\0' && buffer[i] != '\n' && buffer[i] != '\r'; i++)
            {
                if (buffer[i] == ',')
                {
                    comas++;
                }
            }
            cant_columnas = comas + 1;
        }

        if (buffer[0] != '\n' && buffer[0] != '\r' && buffer[0] != '\0')
        {
            cant_filas++;
        }
    }

    if (cant_filas == 0 || cant_columnas == 0)
    {
        fclose(archivo);
        return NULL;
    }

    int **matriz = crear_matriz_contigua(cant_filas, cant_columnas);
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    rewind(archivo);
    size_t f = 0;
    while (fgets(buffer, sizeof(buffer), archivo) != NULL && f < cant_filas)
    {
        if (buffer[0] == '\n' || buffer[0] == '\r' || buffer[0] == '\0')
        {
            continue;
        }

        char *token = strtok(buffer, ",\r\n");
        size_t c = 0;
        while (token != NULL && c < cant_columnas)
        {
            *(*(matriz + f) + c) = atoi(token);
            c++;
            token = strtok(NULL, ",\r\n");
        }
        f++;
    }

    fclose(archivo);
    *filas = cant_filas;
    *columnas = cant_columnas;
    return matriz;
}

int **filtrar_filas_matriz(int **matriz, size_t filas, size_t columnas,
                           size_t col_filtro, int umbral, size_t *filas_filtradas)
{
    if (filas_filtradas != NULL)
    {
        *filas_filtradas = 0;
    }

    if (matriz == NULL || filas == 0 || columnas == 0 ||
        col_filtro >= columnas || filas_filtradas == NULL)
    {
        return NULL;
    }

    size_t coinciden = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (*(*(matriz + i) + col_filtro) > umbral)
        {
            coinciden++;
        }
    }

    if (coinciden == 0)
    {
        return NULL;
    }

    int **filtrada = crear_matriz_contigua(coinciden, columnas);
    if (filtrada == NULL)
    {
        return NULL;
    }

    size_t f_dest = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (*(*(matriz + i) + col_filtro) > umbral)
        {
            for (size_t j = 0; j < columnas; j++)
            {
                *(*(filtrada + f_dest) + j) = *(*(matriz + i) + j);
            }
            f_dest++;
        }
    }

    *filas_filtradas = coinciden;
    return filtrada;
}

float *calcular_promedios_columnas(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    }

    if (columnas > SIZE_MAX / sizeof(float))
    {
        return NULL;
    }

    float *promedios = malloc(columnas * sizeof(*promedios));
    if (promedios == NULL)
    {
        return NULL;
    }

    for (size_t j = 0; j < columnas; j++)
    {
        long long suma = 0;
        for (size_t i = 0; i < filas; i++)
        {
            suma += *(*(matriz + i) + j);
        }
        *(promedios + j) = (float)suma / (float)filas;
    }

    return promedios;
}

bool exportar_matriz_csv(const char *ruta_archivo, int **matriz, size_t filas, size_t columnas)
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

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            if (j > 0)
            {
                fprintf(archivo, ",");
            }
            fprintf(archivo, "%d", *(*(matriz + i) + j));
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    return true;
}

void liberar_arreglo_floats(float **arreglo)
{
    if (arreglo != NULL && *arreglo != NULL)
    {
        free(*arreglo);
        *arreglo = NULL;
    }
}