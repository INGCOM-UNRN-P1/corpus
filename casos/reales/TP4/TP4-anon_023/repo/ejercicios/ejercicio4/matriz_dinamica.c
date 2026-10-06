/**
 * @file matriz_dinamica.c
 * @brief Implementacion para Ejercicio 4 (Matrices Dinamicas en Bloque Contiguo).
 */

#include "matriz_dinamica.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matriz_crear(size_t filas, size_t columnas)
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

void matriz_destruir(int ***matriz)
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

int **matriz_cargar_desde_csv(const char *ruta_archivo, size_t *filas_out, size_t *columnas_out)
{
    if (filas_out != NULL)
    {
        *filas_out = 0;
    }
    if (columnas_out != NULL)
    {
        *columnas_out = 0;
    }

    if (ruta_archivo == NULL || filas_out == NULL || columnas_out == NULL)
    {
        return NULL;
    }

    FILE *archivo = fopen(ruta_archivo, "r");
    if (archivo == NULL)
    {
        return NULL;
    }

    
    size_t filas = 0;
    size_t columnas = 0;
    char linea[1024];

    while (fgets(linea, sizeof(linea), archivo) != NULL)
    {
        if (filas == 0)
        {
            
            size_t comas = 0;
            for (size_t i = 0; linea[i] != '\0' && linea[i] != '\n' && linea[i] != '\r'; i++)
            {
                if (linea[i] == ',')
                {
                    comas++;
                }
            }
            columnas = comas + 1;
        }
        
        if (linea[0] != '\n' && linea[0] != '\r' && linea[0] != '\0')
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
    while (fgets(linea, sizeof(linea), archivo) != NULL && f < filas)
    {
        if (linea[0] == '\n' || linea[0] == '\r' || linea[0] == '\0')
        {
            continue;
        }

        char *token = strtok(linea, ",\r\n");
        size_t c = 0;
        while (token != NULL && c < columnas)
        {
            *(*(matriz + f) + c) = atoi(token);
            c++;
            token = strtok(NULL, ",\r\n");
        }
        f++;
    }

    fclose(archivo);
    *filas_out = filas;
    *columnas_out = columnas;
    return matriz;
}
