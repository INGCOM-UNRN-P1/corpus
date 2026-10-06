/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int** matriz_crear(size_t filas, size_t columnas)
{
    if (filas == 0 || columnas == 0)
    {
        return NULL;
    }
    int **matriz = (int **)malloc(filas * sizeof(int *));

    if (matriz == NULL)
    {
        return NULL;
    }
    int *datos = (int *)malloc(filas * columnas * sizeof(int));
    if (datos == NULL)
    {
        free(matriz);
        return NULL;
    }
    for (size_t i = 0; i < filas; i++)
    {
        matriz[i] = datos + (i * columnas);
    }
    return matriz;
}


void matriz_destruir(int ***matriz)
{
    if ((matriz != NULL) && (*matriz != NULL))
    {
        free(*matriz[0]); 
        free(*matriz);
        *matriz = NULL;
    }
}


int** matriz_cargar_desde_csv(const char *ruta_archivo, size_t *out_filas, size_t *out_columnas)
{
    if (ruta_archivo == NULL || out_filas == NULL || out_columnas == NULL)
    {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    char buffer[1024];
    size_t filas = 0;
    size_t columnas = 0;

    while (fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        if (filas == 0)
        {
            char copia_linea[1024];
            strcpy(copia_linea, buffer);
            char *tok = strtok(copia_linea, ",\r\n");
            while (tok != NULL)
            {
                columnas++;
                tok = strtok(NULL, ",\r\n");
            }
        }

        if (strlen(buffer) > 1)
        {
            filas++;
        }
    }

    if (filas == 0 || columnas == 0)
    {
        fclose(archivo);
        return NULL;
    }

    int **matriz = matriz_crear(filas, columnas);
    
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    rewind(archivo);

    size_t f = 0;
    while ((fgets(buffer, sizeof(buffer), archivo) != NULL) && (f < filas))
    {
        if (strlen(buffer) <= 1)
        { 
            continue;
        }

        char *tok = strtok(buffer, ",\r\n");
        size_t c = 0;

        while ((tok != NULL) && (c < columnas))
        {
            matriz[f][c] = atoi(tok);
            c++;
            tok = strtok(NULL, ",\r\n");
        }
        
        f++;
    }

    fclose(archivo);

    *out_filas = filas;
    *out_columnas = columnas;

    return matriz;
}