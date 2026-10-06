/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */

#include <errno.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"
 
/**
 * @brief Lee un archivo de texto completo en un bloque del heap terminado en '\0'.
 *
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
    if (texto == NULL) {
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
 *
 * Una fila por línea, valores separados por coma, espacios/tabulaciones tolerados,
 * líneas en blanco ignoradas. Todas las filas deben tener igual cantidad de valores.
 *
 * @param texto Texto CSV terminado en '\0'.
 * @param[out] filas Recibe la cantidad de filas (solo si el análisis es válido).
 * @param[out] columnas Recibe la cantidad de columnas (solo si el análisis es válido).
 * @param datos Si no es NULL, recibe los valores fila por fila; debe tener espacio
 *        para filas * columnas enteros.
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
 
/**
 * @brief Suma los elementos de una columna acumulando en double.
 *
 * @param matriz Matriz de entrada (no debe ser NULL).
 * @param filas Cantidad de filas.
 * @param columnas Cantidad de columnas.
 * @param columna Índice de la columna a sumar (menor que @p columnas).
 * @return Suma de la columna.
 */
static double sumar_columna(const int *matriz, size_t filas, size_t columnas, size_t columna)
{
    double suma = 0.0;
    for (size_t i = 0; i < filas; ++i) 
    {
        suma += matriz[i * columnas + columna];
    }
    return suma;
}
 
int *cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas)
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
    int *matriz = NULL;
    if (analizar_csv(texto, &cant_filas, &cant_columnas, NULL)) 
    {
        size_t total = cant_filas * cant_columnas;
        if (total <= SIZE_MAX / sizeof(int)) 
        {
            matriz = malloc(total * sizeof(int));
        }
        if (matriz != NULL) 
        {
            analizar_csv(texto, &cant_filas, &cant_columnas, matriz);
            *filas = cant_filas;
            *columnas = cant_columnas;
        }
    }
    free(texto);
    return matriz;
}
 
int *filtrar_filas_mayor_que(const int *matriz, size_t filas, size_t columnas,
                             size_t columna, int umbral, size_t *filas_resultado)
{
    if (filas_resultado == NULL) 
    {
        return NULL;
    }
    *filas_resultado = 0;
    if (matriz == NULL || filas == 0 || columnas == 0 || columna >= columnas) 
    {
        return NULL;
    }
 
    size_t cumplen = 0;
    for (size_t i = 0; i < filas; ++i) 
    {
        if (matriz[i * columnas + columna] > umbral) 
        {
            ++cumplen;
        }
    }
    if (cumplen == 0) 
    {
        return NULL;
    }
 
    int *filtrada = malloc(cumplen * columnas * sizeof(int));
    if (filtrada == NULL) 
    {
        return NULL;
    }
    size_t destino = 0;
    for (size_t i = 0; i < filas; ++i) 
    {
        if (matriz[i * columnas + columna] > umbral) 
        {
            for (size_t j = 0; j < columnas; ++j) 
            {
                filtrada[destino * columnas + j] = matriz[i * columnas + j];
            }
            ++destino;
        }
    }
    *filas_resultado = cumplen;
    return filtrada;
}
 
float *calcular_sumas_columnas(const int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0 || columnas > SIZE_MAX / sizeof(float)) 
    {
        return NULL;
    }
 
    float *sumas = malloc(columnas * sizeof(float));
    if (sumas == NULL) 
    {
        return NULL;
    }
    for (size_t j = 0; j < columnas; ++j) 
    {
        sumas[j] = (float)sumar_columna(matriz, filas, columnas, j);
    }
    return sumas;
}
 
float *calcular_promedios_columnas(const int *matriz, size_t filas, size_t columnas)
{
    if (matriz == NULL || filas == 0 || columnas == 0 || columnas > SIZE_MAX / sizeof(float)) 
    {
        return NULL;
    }
 
    float *promedios = malloc(columnas * sizeof(float));
    if (promedios == NULL) 
    {
        return NULL;
    }
    for (size_t j = 0; j < columnas; ++j) 
    {
        promedios[j] = (float)(sumar_columna(matriz, filas, columnas, j) / (double)filas);
    }
    return promedios;
}
 
bool exportar_matriz_csv(const char *ruta, const int *matriz, size_t filas, size_t columnas)
{
    if (ruta == NULL || matriz == NULL || filas == 0 || columnas == 0) 
    {
        return false;
    }
 
    FILE *archivo = fopen(ruta, "w");
    if (archivo == NULL) 
    {
        return false;
    }
 
    bool correcto = true;
    for (size_t i = 0; i < filas && correcto; ++i) 
    {
        for (size_t j = 0; j < columnas && correcto; ++j) 
        {
            if (j > 0 && fputc(',', archivo) == EOF) 
            {
                correcto = false;
            }
            if (correcto && fprintf(archivo, "%d", matriz[i * columnas + j]) < 0) 
            {
                correcto = false;
            }
        }
        if (correcto && fputc('\n', archivo) == EOF) 
        {
            correcto = false;
        }
    }
    if (fclose(archivo) != 0) 
    {
        correcto = false;
    }
    return correcto;
}