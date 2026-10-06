#include "consulta_csv.h"
#include "vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *cargar_csv(const char *ruta,
                size_t *filas,
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

    int *matriz = NULL;
    size_t cantidad = 0;

    *filas = 0;
    *columnas = 0;

    char linea[1024];

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        size_t columnas_fila = 0;

        char *token = strtok(linea, ",");

        while (token != NULL)
        {
            int valor = atoi(token);

            if (!agregar_al_bloque_enteros(
                    &matriz,
                    &cantidad,
                    valor))
            {
                liberar_bloque_enteros(&matriz);
                fclose(archivo);
                return NULL;
            }

            columnas_fila++;

            token = strtok(NULL, ",");
        }

        if (*filas == 0)
        {
            *columnas = columnas_fila;
        }
        else if (columnas_fila != *columnas)
        {
            liberar_bloque_enteros(&matriz);
            fclose(archivo);
            return NULL;
        }

        (*filas)++;
    }

    fclose(archivo);

    return matriz;
}


int *filtrar_filas(const int *matriz,
                   size_t filas,
                   size_t columnas,
                   size_t columna_filtro,
                   int umbral,
                   size_t *filas_resultado)
{
    if (matriz == NULL ||
        filas_resultado == NULL ||
        columna_filtro >= columnas)
    {
        return NULL;
    }

    size_t cantidad_filtradas = 0;

    for (size_t fila = 0; fila < filas; fila++)
    {
        if (matriz[fila * columnas + columna_filtro] > umbral)
        {
            cantidad_filtradas++;
        }
    }

    if (cantidad_filtradas == 0)
    {
        *filas_resultado = 0;
        return NULL;
    }

    int *filtrada =
        crear_bloque_enteros(cantidad_filtradas * columnas);

    if (filtrada == NULL)
    {
        return NULL;
    }

    size_t fila_destino = 0;

    for (size_t fila = 0; fila < filas; fila++)
    {
        if (matriz[fila * columnas + columna_filtro] > umbral)
        {
            for (size_t columna = 0; columna < columnas; columna++)
            {
                filtrada[fila_destino * columnas + columna] =
                    matriz[fila * columnas + columna];
            }

            fila_destino++;
        }
    }

    *filas_resultado = cantidad_filtradas;

    return filtrada;
}


float *calcular_sumas_columnas(const int *matriz,
                               size_t filas,
                               size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0)
    {
        return NULL;
    }

    float *sumas = calloc(columnas, sizeof(float));

    if (sumas == NULL)
    {
        return NULL;
    }

    for (size_t fila = 0; fila < filas; fila++)
    {
        for (size_t columna = 0; columna < columnas; columna++)
        {
            sumas[columna] += matriz[fila * columnas + columna];
        }
    }

    return sumas;
}


float *calcular_promedios_columnas(const int *matriz,
                                   size_t filas,
                                   size_t columnas)
{
    float *promedios =
        calcular_sumas_columnas(matriz, filas, columnas);

    if (promedios == NULL)
    {
        return NULL;
    }

    for (size_t columna = 0; columna < columnas; columna++)
    {
        promedios[columna] /= filas;
    }

    return promedios;
}


bool exportar_csv(const char *ruta,
                  const int *matriz,
                  size_t filas,
                  size_t columnas)
{
    if (ruta == NULL || matriz == NULL)
    {
        return false;
    }

    FILE *archivo = fopen(ruta, "w");

    if (archivo == NULL)
    {
        return false;
    }

    for (size_t fila = 0; fila < filas; fila++)
    {
        for (size_t columna = 0; columna < columnas; columna++)
        {
            fprintf(
                archivo,
                "%d",
                matriz[fila * columnas + columna]
            );

            if (columna + 1 < columnas)
            {
                fprintf(archivo, ",");
            }
        }

        fprintf(archivo, "\n");
    }

    fclose(archivo);

    return true;
}


void liberar_matriz(int **matriz)
{
    liberar_bloque_enteros(matriz);
}