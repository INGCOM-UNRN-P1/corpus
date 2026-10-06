
/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include "consulta_csv.h"
#include "../ejercicio4/matriz_dinamica.h"
#include <stdio.h>
#include <stdlib.h>

static bool matriz_valida(int *const *matriz, size_t filas, size_t columnas)
{
    size_t fila = 0;

    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return false;
    }

    for (fila = 0; fila < filas; fila++)
    {
        if (matriz[fila] == NULL)
        {
            return false;
        }
    }

    return true;
}

int **filtrar_filas_csv(int *const *matriz, size_t filas, size_t columnas,
                        size_t columna, int umbral, size_t *filas_resultado)
{
    int **resultado = NULL;
    size_t cantidad = 0;
    size_t fila = 0;
    size_t columna_copia = 0;
    size_t fila_resultado = 0;

    if (filas_resultado == NULL)
    {
        return NULL;
    }

    *filas_resultado = 0;

    if (!matriz_valida(matriz, filas, columnas) || columna >= columnas)
    {
        return NULL;
    }

    for (fila = 0; fila < filas; fila++)
    {
        if (matriz[fila][columna] > umbral)
        {
            cantidad++;
        }
    }

    if (cantidad == 0)
    {
        return NULL;
    }

    resultado = matriz_crear(cantidad, columnas);

    if (resultado == NULL)
    {
        return NULL;
    }

    for (fila = 0; fila < filas; fila++)
    {
        if (matriz[fila][columna] > umbral)
        {
            for (columna_copia = 0;
                 columna_copia < columnas;
                 columna_copia++)
            {
                resultado[fila_resultado][columna_copia] =
                    matriz[fila][columna_copia];
            }

            fila_resultado++;
        }
    }

    *filas_resultado = cantidad;

    return resultado;
}

float *sumar_columnas_csv(int *const *matriz, size_t filas, size_t columnas)
{
    float *sumas = NULL;
    size_t fila = 0;
    size_t columna = 0;

    if (!matriz_valida(matriz, filas, columnas))
    {
        return NULL;
    }

    sumas = calloc(columnas, sizeof(float));

    if (sumas == NULL)
    {
        return NULL;
    }

    for (columna = 0; columna < columnas; columna++)
    {
        for (fila = 0; fila < filas; fila++)
        {
            sumas[columna] += matriz[fila][columna];
        }
    }

    return sumas;
}

float *promediar_columnas_csv(int *const *matriz, size_t filas,
                              size_t columnas)
{
    float *promedios = NULL;
    size_t columna = 0;

    promedios = sumar_columnas_csv(
        matriz,
        filas,
        columnas
    );

    if (promedios == NULL)
    {
        return NULL;
    }

    for (columna = 0; columna < columnas; columna++)
    {
        promedios[columna] =
            promedios[columna] / (float)filas;
    }

    return promedios;
}

bool exportar_matriz_csv(const char *ruta, int *const *matriz, size_t filas,
                         size_t columnas)
{
    FILE *archivo = NULL;
    size_t fila = 0;
    size_t columna = 0;
    bool resultado = true;

    if (ruta == NULL || columnas == 0)
    {
        return false;
    }

    if (filas > 0 && !matriz_valida(matriz, filas, columnas))
    {
        return false;
    }

    archivo = fopen(ruta, "w");

    if (archivo == NULL)
    {
        return false;
    }

    for (fila = 0; fila < filas && resultado; fila++)
    {
        for (columna = 0; columna < columnas && resultado; columna++)
        {
            if (columna + 1 < columnas)
            {
                resultado =
                    fprintf(archivo, "%d,", matriz[fila][columna]) >= 0;
            }
            else
            {
                resultado =
                    fprintf(archivo, "%d\n", matriz[fila][columna]) >= 0;
            }
        }
    }

    if (fclose(archivo) != 0)
    {
        resultado = false;
    }

    return resultado;
}
