/**
 * @file matriz_dinamica.c
 * @brief Implementación de matrices dinámicas contiguas y carga CSV.
 */

#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

static bool linea_tiene_contenido(const char *linea)
{
    bool tiene_contenido = false;
    size_t indice = 0U;

    if (linea != NULL)
    {
        while ((linea[indice] != '\0') && !tiene_contenido)
        {
            if (!isspace((unsigned char)linea[indice]))
            {
                tiene_contenido = true;
            }
            indice++;
        }
    }

    return tiene_contenido;
}

static bool procesar_linea_csv(const char *linea, int *destino,
                               size_t columnas_esperadas, size_t *cantidad_valores)
{
    bool valida = false;
    bool finalizada = false;
    const char *cursor = NULL;
    char *fin_numero = NULL;
    long valor = 0L;
    size_t cantidad = 0U;

    if ((linea != NULL) && (cantidad_valores != NULL))
    {
        *cantidad_valores = 0U;
        cursor = linea;
        valida = linea_tiene_contenido(linea);
    }

    while (valida && !finalizada)
    {
        while ((*cursor != '\0') && (*cursor != '\n') && (*cursor != '\r') &&
               isspace((unsigned char)*cursor))
        {
            cursor++;
        }

        errno = 0;
        valor = strtol(cursor, &fin_numero, 10);
        if ((fin_numero == cursor) || (errno == ERANGE) ||
            (valor < INT_MIN) || (valor > INT_MAX))
        {
            valida = false;
        }
        else
        {
            if (destino != NULL)
            {
                if (cantidad < columnas_esperadas)
                {
                    destino[cantidad] = (int)valor;
                }
                else
                {
                    valida = false;
                }
            }

            if (valida)
            {
                cantidad++;
                cursor = fin_numero;
                while ((*cursor != '\0') && (*cursor != '\n') && (*cursor != '\r') &&
                       isspace((unsigned char)*cursor))
                {
                    cursor++;
                }

                if (*cursor == ',')
                {
                    cursor++;
                }
                else if ((*cursor == '\0') || (*cursor == '\n') || (*cursor == '\r'))
                {
                    finalizada = true;
                }
                else
                {
                    valida = false;
                }
            }
        }
    }

    if (valida && (columnas_esperadas > 0U) && (cantidad != columnas_esperadas))
    {
        valida = false;
    }

    if (valida)
    {
        *cantidad_valores = cantidad;
    }

    return valida;
}

int **matriz_crear(size_t filas, size_t columnas)
{
    int **matriz = NULL;
    int *datos = NULL;
    size_t fila = 0U;
    bool dimensiones_validas = false;

    dimensiones_validas = (filas > 0U) && (columnas > 0U) &&
                           (filas <= SIZE_MAX / sizeof(int *)) &&
                           (columnas <= SIZE_MAX / sizeof(int)) &&
                           (filas <= SIZE_MAX / columnas);

    if (dimensiones_validas)
    {
        matriz = malloc(filas * sizeof(int *));
        datos = calloc(filas * columnas, sizeof(int));
    }

    if ((matriz != NULL) && (datos != NULL))
    {
        for (fila = 0U; fila < filas; fila++)
        {
            matriz[fila] = datos + (fila * columnas);
        }
    }
    else
    {
        free(datos);
        free(matriz);
        matriz = NULL;
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

int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas)
{
    FILE *archivo = NULL;
    int **matriz = NULL;
    char linea[4096] = {0};
    size_t cantidad_filas = 0U;
    size_t cantidad_columnas = 0U;
    size_t valores_linea = 0U;
    size_t fila_actual = 0U;
    bool archivo_valido = true;

    if (filas != NULL)
    {
        *filas = 0U;
    }
    if (columnas != NULL)
    {
        *columnas = 0U;
    }

    if ((ruta != NULL) && (filas != NULL) && (columnas != NULL))
    {
        archivo = fopen(ruta, "r");
    }

    while ((archivo != NULL) && archivo_valido && (fgets(linea, sizeof(linea), archivo) != NULL))
    {
        if (linea_tiene_contenido(linea))
        {
            valores_linea = 0U;
            if (!procesar_linea_csv(linea, NULL, 0U, &valores_linea))
            {
                archivo_valido = false;
            }
            else if (cantidad_filas == 0U)
            {
                cantidad_columnas = valores_linea;
                cantidad_filas = 1U;
            }
            else if (valores_linea != cantidad_columnas)
            {
                archivo_valido = false;
            }
            else
            {
                cantidad_filas++;
            }
        }
    }

    if ((archivo != NULL) && archivo_valido &&
        (cantidad_filas > 0U) && (cantidad_columnas > 0U))
    {
        matriz = matriz_crear(cantidad_filas, cantidad_columnas);
    }

    if (matriz != NULL)
    {
        rewind(archivo);
        fila_actual = 0U;
        while (archivo_valido && (fila_actual < cantidad_filas) &&
               (fgets(linea, sizeof(linea), archivo) != NULL))
        {
            if (linea_tiene_contenido(linea))
            {
                valores_linea = 0U;
                if (procesar_linea_csv(linea, matriz[fila_actual], cantidad_columnas,
                                       &valores_linea))
                {
                    fila_actual++;
                }
                else
                {
                    archivo_valido = false;
                }
            }
        }

        if (!archivo_valido || (fila_actual != cantidad_filas))
        {
            matriz_destruir(matriz);
            matriz = NULL;
        }
    }

    if (archivo != NULL)
    {
        fclose(archivo);
    }

    if (matriz != NULL)
    {
        *filas = cantidad_filas;
        *columnas = cantidad_columnas;
    }

    return matriz;
}

int *crear_matriz_plana(size_t filas, size_t columnas)
{
    int *matriz = NULL;

    if ((filas > 0U) && (columnas > 0U) &&
        (filas <= SIZE_MAX / columnas) &&
        ((filas * columnas) <= SIZE_MAX / sizeof(int)))
    {
        matriz = calloc(filas * columnas, sizeof(int));
    }

    return matriz;
}

int obtener_celda(const int *matriz, size_t columnas, size_t fila, size_t columna)
{
    int valor = 0;

    if ((matriz != NULL) && (columnas > 0U))
    {
        valor = matriz[(fila * columnas) + columna];
    }

    return valor;
}

void asignar_celda(int *matriz, size_t columnas, size_t fila, size_t columna, int valor)
{
    if ((matriz != NULL) && (columnas > 0U))
    {
        matriz[(fila * columnas) + columna] = valor;
    }
}

void liberar_matriz_plana(int *matriz)
{
    free(matriz);
}
