/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include <errno.h>
#include <limits.h>
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
 
    int *datos = calloc(filas * columnas, sizeof(int));
    if (datos == NULL) 
    {
        return NULL;
    }
 
    int **matriz = calloc(filas, sizeof(int *));
    if (matriz == NULL) 
    {
        free(datos);
        return NULL;
    }
    for (size_t i = 0; i < filas; ++i) 
    {
        matriz[i] = datos + i * columnas;
    }
    return matriz;
}
 
void matriz_destruir(int **matriz)
{
    if (matriz == NULL) 
    {
        return;
    }
    free(matriz[0]); 
    free(matriz);    
}
 
/**
 * @brief Lee un archivo de texto completo en un bloque del heap terminado en '\0'.
 * @param ruta Ruta del archivo.
 * @return Puntero al texto en heap, o NULL si no se puede abrir/leer o falla malloc.
 */
static char *leer_archivo(const char *ruta)
{
    FILE *archivo = fopen(ruta, "r");
    if (archivo == NULL) 
    {
        return NULL;
    }
 
    if (fseek(archivo, 0, SEEK_END) != 0) 
    {
        fclose(archivo);
        return NULL;
    }
    long tamano = ftell(archivo);
    if (tamano < 0 || fseek(archivo, 0, SEEK_SET) != 0) 
    {
        fclose(archivo);
        return NULL;
    }
 
    char *texto = malloc((size_t)tamano + 1);
    if (texto == NULL) 
    {
        fclose(archivo);
        return NULL;
    }
    size_t leidos = fread(texto, 1, (size_t)tamano, archivo);
    fclose(archivo);
    texto[leidos] = '\0';
    return texto;
}
 
/**
 * @brief Analiza un texto CSV de enteros y, opcionalmente, vuelca sus valores.
 * Una fila por línea, valores separados por coma, espacios/tabulaciones tolerados,
 * líneas en blanco ignoradas. Todas las filas deben tener igual cantidad de valores.
 * @param texto Texto CSV terminado en '\0'.
 * @param[out] filas Recibe la cantidad de filas (solo si el análisis es válido).
 * @param[out] columnas Recibe la cantidad de columnas (solo si el análisis es válido).
 * @param datos Si no es NULL, recibe los valores fila por fila; debe tener espacio para filas * columnas enteros.
 * @return true si el CSV es válido y no está vacío; false en caso contrario.
 */
static bool analizar_csv(const char *texto, size_t *filas, size_t *columnas, int *datos)
{
    size_t cant_filas = 0;
    size_t cant_columnas = 0;
    size_t siguiente = 0;
    const char *actual = texto;
 
    while (*actual != '\0') 
    {
        size_t valores = 0;
        bool espera_valor = false;
 
        for (;;) 
        {
            while (*actual == ' ' || *actual == '\t') 
            {
                ++actual;
            }
            if (*actual == '\n' || *actual == '\r' || *actual == '\0') 
            {
                break;
            }
 
            char *fin = NULL;
            errno = 0;
            long valor = strtol(actual, &fin, 10);
            if (fin == actual || errno == ERANGE || valor < INT_MIN || valor > INT_MAX) 
            {
                return false;
            }
            if (datos != NULL) 
            {
                datos[siguiente] = (int)valor;
            }
            ++siguiente;
            ++valores;
            actual = fin;
            espera_valor = false;
 
            while (*actual == ' ' || *actual == '\t') 
            {
                ++actual;
            }
            if (*actual == ',') 
            {
                ++actual;
                espera_valor = true;
            } else if (*actual != '\n' && *actual != '\r' && *actual != '\0') 
            {
                return false;
            }
        }
        if (espera_valor) 
        {
            return false; 
        }
 
        if (valores > 0) 
        {
            if (cant_filas == 0) 
            {
                cant_columnas = valores;
            } else if (valores != cant_columnas) 
            {
                return false;
            }
            ++cant_filas;
        }
        while (*actual == '\n' || *actual == '\r') 
        {
            ++actual;
        }
    }
 
    if (cant_filas == 0) 
    {
        return false;
    }
    *filas = cant_filas;
    *columnas = cant_columnas;
    return true;
}
 
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas)
{
    if (filas == NULL || columnas == NULL) 
    {
        return NULL;
    }
    *filas = 0;
    *columnas = 0;
    if (ruta == NULL) 
    {
        return NULL;
    }
 
    char *texto = leer_archivo(ruta);
    if (texto == NULL) 
    {
        return NULL;
    }
 
    size_t cant_filas = 0;
    size_t cant_columnas = 0;
    int **matriz = NULL;
    if (analizar_csv(texto, &cant_filas, &cant_columnas, NULL)) 
    {
        matriz = matriz_crear(cant_filas, cant_columnas);
        if (matriz != NULL) 
        {
            analizar_csv(texto, &cant_filas, &cant_columnas, matriz[0]);
            *filas = cant_filas;
            *columnas = cant_columnas;
        }
    }
    free(texto);
    return matriz;
}
