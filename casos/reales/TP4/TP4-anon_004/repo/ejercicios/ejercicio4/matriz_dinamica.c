/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include "matriz_dinamica.h"

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **matriz_crear(size_t filas, size_t columnas)
{
    int **matriz = NULL;
    int *datos = NULL;
    size_t fila = 0;

    if (filas == 0 || columnas == 0 || filas > SIZE_MAX / sizeof(int *) ||
        columnas > SIZE_MAX / sizeof(int) / filas)
    {
        return NULL;
    }

    matriz = malloc(filas * sizeof(int *));

    if (matriz == NULL)
    {
        return NULL;
    }

    datos = calloc(filas * columnas, sizeof(int));

    if (datos == NULL)
    {
        free(matriz);
        return NULL;
    }

    for (fila = 0; fila < filas; fila++)
    {
        matriz[fila] = datos + fila * columnas;
    }

    return matriz;
}

void matriz_destruir(int **matriz)
{
    if (matriz != NULL)
    {
        free(matriz[0]);
        free(matriz);
    }
}

static char *leer_linea(FILE *archivo, bool *error)
{
    char buffer[256] = {0};
    char *linea = NULL;
    char *temporal = NULL;
    size_t longitud = 0;
    size_t fragmento = 0;
    bool completa = false;

    while (!completa && !*error &&
           fgets(buffer, sizeof(buffer), archivo) != NULL)
    {
        fragmento = strlen(buffer);

        if (fragmento > SIZE_MAX - longitud - 1)
        {
            *error = true;
        }
        else
        {
            temporal = realloc(linea, longitud + fragmento + 1);

            if (temporal == NULL)
            {
                *error = true;
            }
            else
            {
                linea = temporal;
                memcpy(linea + longitud, buffer, fragmento + 1);
                longitud += fragmento;
                completa = longitud != 0 && linea[longitud - 1] == '\n';
            }
        }
    }

    if (ferror(archivo))
    {
        *error = true;
    }

    if (*error)
    {
        free(linea);
        linea = NULL;
    }

    return linea;
}

static bool convertir_entero(const char *texto, int *resultado)
{
    char *fin_conversion = NULL;
    long valor = 0;

    errno = 0;
    valor = strtol(texto, &fin_conversion, 10);

    if (fin_conversion == texto || errno == ERANGE)
    {
        return false;
    }

    if (valor < INT_MIN || valor > INT_MAX)
    {
        return false;
    }

    while (isspace((unsigned char)*fin_conversion))
    {
        fin_conversion++;
    }

    if (*fin_conversion != '\0')
    {
        return false;
    }

    *resultado = (int)valor;

    return true;
}

static size_t contar_columnas(const char *linea)
{
    size_t columnas = 1;
    size_t indice = 0;

    while (linea[indice] != '\0')
    {
        if (linea[indice] == ',')
        {
            if (columnas == SIZE_MAX)
            {
                return 0;
            }

            columnas++;
        }

        indice++;
    }

    return columnas;
}

static bool agregar_fila(int **datos, size_t filas, size_t columnas,
                         char *linea)
{
    int *temporal = NULL;
    char *campo = linea;
    char *separador = NULL;
    size_t columna = 0;
    bool valido = true;

    if (filas == SIZE_MAX || columnas > SIZE_MAX / sizeof(int) / (filas + 1))
    {
        return false;
    }

    temporal = realloc(*datos, (filas + 1) * columnas * sizeof(int));

    if (temporal == NULL)
    {
        return false;
    }

    *datos = temporal;

    while (columna < columnas && valido)
    {
        separador = strchr(campo, ',');

        if (separador != NULL)
        {
            *separador = '\0';
        }

        valido = convertir_entero(campo,
                                  &(*datos)[filas * columnas + columna]);

        if (separador != NULL)
        {
            campo = separador + 1;
        }

        columna++;
    }

    return valido;
}

static int *cargar_datos(FILE *archivo, size_t *filas, size_t *columnas)
{
    char *linea = NULL;
    int *datos = NULL;
    size_t cantidad_campos = 0;
    bool error = false;

    linea = leer_linea(archivo, &error);

    while (linea != NULL && !error)
    {
        cantidad_campos = contar_columnas(linea);

        if (*filas == 0)
        {
            *columnas = cantidad_campos;
        }

        error = cantidad_campos == 0 || cantidad_campos != *columnas;

        if (!error)
        {
            error = !agregar_fila(&datos, *filas, *columnas, linea);
        }

        if (!error)
        {
            (*filas)++;
        }

        free(linea);
        linea = NULL;

        if (!error)
        {
            linea = leer_linea(archivo, &error);
        }
    }

    if (error)
    {
        free(datos);
        datos = NULL;
    }

    return datos;
}

int **matriz_cargar_desde_csv(const char *ruta, size_t *filas,
                              size_t *columnas)
{
    FILE *archivo = NULL;
    int *datos = NULL;
    int **matriz = NULL;
    size_t cantidad_filas = 0;
    size_t cantidad_columnas = 0;
    bool error = false;

    if (filas != NULL)
    {
        *filas = 0;
    }

    if (columnas != NULL)
    {
        *columnas = 0;
    }

    if (ruta == NULL || filas == NULL || columnas == NULL)
    {
        return NULL;
    }

    if (filas == columnas)
    {
        return NULL;
    }

    archivo = fopen(ruta, "r");

    if (archivo == NULL)
    {
        return NULL;
    }

    datos = cargar_datos(archivo, &cantidad_filas, &cantidad_columnas);

    error = fclose(archivo) != 0;

    if (datos != NULL && !error)
    {
        matriz = matriz_crear(cantidad_filas, cantidad_columnas);

        if (matriz != NULL)
        {
            memcpy(matriz[0], datos,
                   cantidad_filas * cantidad_columnas * sizeof(int));

            *filas = cantidad_filas;
            *columnas = cantidad_columnas;
        }
    }

    free(datos);

    return matriz;
}