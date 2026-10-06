/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta_csv.h"

int **cargar_matriz_csv(const char *ruta_archivo, size_t *filas,
                        size_t *columnas)
{
    FILE *archivo = NULL;
    char linea[256];
    char *token = NULL;
    int **matriz = NULL;
    int *bloque = NULL;
    size_t filas_total = 0U;
    size_t columnas_total = 0U;
    size_t f = 0U;
    size_t c = 0U;

    if (ruta_archivo == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }

    archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    if (fgets(linea, sizeof(linea), archivo) == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    columnas_total = 1U;
    for (c = 0U; linea[c] != '\0'; ++c)
    {
        if (linea[c] == ',')
        {
            ++columnas_total;
        }
    }

    filas_total = 1U;
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (linea[0] != '\n' && linea[0] != '\0')
        {
            ++filas_total;
        }
    }

    rewind(archivo);
    matriz = malloc(filas_total * sizeof(*matriz));
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    bloque = calloc(filas_total * columnas_total, sizeof(*bloque));
    if (bloque == NULL)
    {
        free(matriz);
        fclose(archivo);
        return NULL;
    }

    for (f = 0U; f < filas_total; ++f)
    {
        matriz[f] = bloque + (f * columnas_total);
    }

    f = 0U;
    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (linea[0] == '\n' || linea[0] == '\0')
        {
            continue;
        }

        c = 0U;
        token = strtok(linea, ",\n");
        while (token != NULL && c < columnas_total)
        {
            matriz[f][c] = atoi(token);
            ++c;
            token = strtok(NULL, ",\n");
        }

        if (c != columnas_total || token != NULL)
        {
            
            liberar_matriz_int(matriz, filas_total);
            fclose(archivo);
            return NULL;
        }

        ++f;
    }

    fclose(archivo);
    *filas = filas_total;
    *columnas = columnas_total;
    return matriz;
}

int **filtrar_matriz_por_columna(const int *matriz, size_t filas,
                                size_t columnas, size_t indice_columna,
                                int umbral, size_t *filas_resultado)
{
    int **resultado = NULL;
    int *bloque = NULL;
    size_t filas_filtradas = 0U;
    size_t i = 0U;
    size_t j = 0U;
    size_t k = 0U;

    if (matriz == NULL || filas_resultado == NULL || columnas <= indice_columna)
    {
        return NULL;
    }

    for (i = 0U; i < filas; ++i)
    {
        if (matriz[i * columnas + indice_columna] > umbral)
        {
            ++filas_filtradas;
        }
    }

    if (filas_filtradas == 0U)
    {
        *filas_resultado = 0U;
        return NULL;
    }

    resultado = malloc(filas_filtradas * sizeof(*resultado));
    if (resultado == NULL)
    {
        *filas_resultado = 0U;
        return NULL;
    }

    bloque = calloc(filas_filtradas * columnas, sizeof(*bloque));
    if (bloque == NULL)
    {
        free(resultado);
        *filas_resultado = 0U;
        return NULL;
    }

    for (k = 0U; k < filas_filtradas; ++k)
    {
        resultado[k] = bloque + (k * columnas);
    }

    k = 0U;
    for (i = 0U; i < filas; ++i)
    {
        if (matriz[i * columnas + indice_columna] > umbral)
        {
            for (j = 0U; j < columnas; ++j)
            {
                resultado[k][j] = matriz[i * columnas + j];
            }
            ++k;
        }
    }

    *filas_resultado = filas_filtradas;
    return resultado;
}

float *estadisticas_columnas(const int *matriz, size_t filas, size_t columnas,
                            size_t *cantidad)
{
    float *estadisticas;
    size_t c;
    size_t f;

    if (matriz == NULL || cantidad == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    }

    estadisticas = malloc(columnas * sizeof(*estadisticas));
    if (estadisticas == NULL)
    {
        return NULL;
    }

    for (c = 0; c < columnas; ++c)
    {
        float suma = 0.0F;

        for (f = 0; f < filas; ++f)
        {
            suma += (float)matriz[f * columnas + c];
        }
        estadisticas[c] = suma / (float)filas;
    }

    *cantidad = columnas;
    return estadisticas;
}

int exportar_matriz_csv(const char *ruta_archivo, const int *matriz,
                        size_t filas, size_t columnas)
{
    FILE *archivo = NULL;
    size_t i = 0U;
    size_t j = 0U;

    if (ruta_archivo == NULL || matriz == NULL)
    {
        return 1;
    }

    archivo = fopen(ruta_archivo, "w");
    if (archivo == NULL)
    {
        return 1;
    }

    for (i = 0U; i < filas; ++i)
    {
        for (j = 0U; j < columnas; ++j)
        {
            fprintf(archivo, "%d", matriz[i * columnas + j]);
            if (j + 1U < columnas)
            {
                fputc(',', archivo);
            }
        }
        fputc('\n', archivo);
    }

    fclose(archivo);
    return 0;
}

void liberar_matriz_int(int **matriz, size_t filas)
{
    if (matriz == NULL || filas == 0U)
    {
        return;
    }

    free(matriz[0]);
    free(matriz);
}
