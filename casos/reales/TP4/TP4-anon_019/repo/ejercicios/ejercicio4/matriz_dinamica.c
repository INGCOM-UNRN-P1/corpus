#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

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

    int **matriz = malloc(filas * sizeof(*matriz));
    if (matriz == NULL)
    {
        return NULL;
    }

    int *bloque = calloc(filas * columnas, sizeof(*bloque));
    if (bloque == NULL)
    {
        free(matriz);
        return NULL;
    }

    for (size_t i = 0; i < filas; i++)
    {
        *(matriz + i) = bloque + (i * columnas);
    }

    return matriz;
}

void matriz_destruir(int ***matriz)
{
    if (matriz != NULL && *matriz != NULL)
    {
        if (*(*matriz + 0) != NULL)
        {
            free(*(*matriz + 0));
        }
        
        free(*matriz);
        *matriz = NULL;
    }
}

int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas)
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

    size_t f = 0;
    size_t c = 1;
    int ch;
    int ultimo_ch = EOF;
    bool primera_linea = true;

    while ((ch = fgetc(archivo)) != EOF)
    {
        if (ch == '\n')
        {
            f++;
            primera_linea = false;
        }
        else if (ch == ',' && primera_linea == true)
        {
            c++;
        }
        ultimo_ch = ch;
    }

    if (ultimo_ch != EOF && ultimo_ch != '\n')
    {
        f++;
    }

    if (f == 0)
    {
        fclose(archivo);
        *filas = 0;
        *columnas = 0;
        return NULL;
    }

    rewind(archivo);

    int **matriz = matriz_crear(f, c);
    if (matriz == NULL)
    {
        fclose(archivo);
        return NULL;
    }

    for (size_t i = 0; i < f; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            if (fscanf(archivo, "%d,", *(matriz + i) + j) != 1)
            {
                *(*(matriz + i) + j) = 0;
            }
        }
    }

    fclose(archivo);
    *filas = f;
    *columnas = c;
    return matriz;
}