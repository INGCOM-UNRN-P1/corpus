#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

int **csv_cargar_matriz(const char *ruta, size_t *filas, size_t *columnas)
{
    if (ruta == NULL || filas == NULL || columnas == NULL) return NULL;

    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL) return NULL;

    size_t f = 0, c = 1;
    int ch, last_ch = 0;
    bool primera_linea = true;

    while ((ch = fgetc(archivo)) != EOF)
    {
        if (ch == '\n')
        {
            f++;
            primera_linea = false;
        }
        else if (ch == ',' && primera_linea)
        {
            c++;
        }
        last_ch = ch;
    }

    if (last_ch != EOF && last_ch != '\n') f++;

    if (f == 0)
    {
        fclose(archivo);
        *filas = 0;
        *columnas = 0;
        return NULL;
    }

    rewind(archivo);

    int **matriz = (int **)malloc(f * sizeof(int *));
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    for (size_t i = 0; i < f; i++)
    {
        matriz[i] = (int *)malloc(c * sizeof(int));
        if (matriz[i] == NULL)
        {
            for (size_t k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            fclose(archivo);
            return NULL;
        }

        for (size_t j = 0; j < c; j++)
        {
            if (fscanf(archivo, "%d", &matriz[i][j]) != 1) matriz[i][j] = 0;
            fgetc(archivo);
        }
    }

    fclose(archivo);
    *filas = f;
    *columnas = c;
    return matriz;
}

int **csv_filtrar_filas(int **matriz, size_t filas, size_t columnas, size_t col_condicion, int umbral, size_t *filas_filtradas)
{
    if (matriz == NULL || filas_filtradas == NULL || col_condicion >= columnas) return NULL;

    size_t contador = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (matriz[i][col_condicion] > umbral) contador++;
    }

    *filas_filtradas = contador;
    if (contador == 0) return NULL;

    int **nueva = (int **)malloc(contador * sizeof(int *));
    if (nueva == NULL) return NULL;

    size_t idx = 0;
    for (size_t i = 0; i < filas; i++)
    {
        if (matriz[i][col_condicion] > umbral)
        {
            nueva[idx] = (int *)malloc(columnas * sizeof(int));
            if (nueva[idx] == NULL)
            {
                for (size_t k = 0; k < idx; k++) free(nueva[k]);
                free(nueva);
                return NULL;
            }
            for (size_t j = 0; j < columnas; j++)
            {
                nueva[idx][j] = matriz[i][j];
            }
            idx++;
        }
    }

    return nueva;
}

float *csv_calcular_promedios(int **matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0) return NULL;

    float *promedios = (float *)malloc(columnas * sizeof(float));
    if (promedios == NULL) return NULL;

    for (size_t j = 0; j < columnas; j++)
    {
        long long suma = 0;
        for (size_t i = 0; i < filas; i++)
        {
            suma += matriz[i][j];
        }
        promedios[j] = (float)suma / (float)filas;
    }

    return promedios;
}

bool csv_exportar_matriz(const char *ruta, int **matriz, size_t filas, size_t columnas)
{
    if (ruta == NULL || matriz == NULL) return false;

    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL) return false;

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            fprintf(archivo, "%d", matriz[i][j]);
            if (j < columnas - 1) fprintf(archivo, ",");
        }
        fprintf(archivo, "\n");
    }

    fclose(archivo);
    return true;
}

void csv_liberar_matriz(int ***matriz, size_t filas)
{
    if (matriz != NULL && *matriz != NULL)
    {
        for (size_t i = 0; i < filas; i++)
        {
            if ((*matriz)[i] != NULL) free((*matriz)[i]);
        }
        free(*matriz);
        *matriz = NULL;
    }
}