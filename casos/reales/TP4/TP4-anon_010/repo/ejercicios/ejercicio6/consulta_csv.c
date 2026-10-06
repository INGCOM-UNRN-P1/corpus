/**
 * @file consulta_csv.c
 * @brief Implementación para Ejercicio 6 (Motor de Consulta y Exportación CSV).
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "consulta_csv.h"
 
#define TAM_LINEA 1024
 
static bool medir_csv(FILE *archivo, size_t *filas, size_t *columnas)
{
    char linea[TAM_LINEA];
    bool valido = true;
    size_t total_filas = 0;
    size_t total_columnas = 0;
 
    while (valido && fgets(linea, sizeof(linea), archivo) != NULL) {
        if (linea[0] != '\n' && linea[0] != '\r') {
            size_t cuenta = 1;
            for (size_t i = 0; linea[i] != '\0'; ++i) {
                if (linea[i] == ',') {
                    cuenta++;
                }
            }
 
            if (total_filas == 0) {
                total_columnas = cuenta;
            } 
            else if (cuenta != total_columnas) {
                valido = false;
            }
            total_filas++;
        }
    }
 
    if (total_filas == 0) {
        valido = false;
    }
    *filas = total_filas;
    *columnas = total_columnas;
    return valido;
}
 

static bool leer_valores(FILE *archivo, int *matriz, size_t filas, size_t columnas)
{
    char linea[TAM_LINEA];
    bool valido = true;
    size_t fila = 0;
 
    while (valido && fila < filas && fgets(linea, sizeof(linea), archivo) != NULL) {
        if (linea[0] != '\n' && linea[0] != '\r') {
            char *cursor = linea;
 
            for (size_t col = 0; valido && col < columnas; ++col) {
                char *fin = cursor;
                long valor = strtol(cursor, &fin, 10);
 
                if (fin == cursor) {
                    valido = false;
                } 
                else {
                    matriz[fila * columnas + col] = (int)valor;
                    cursor = fin;
                    while (*cursor == ' ' || *cursor == '\t') {
                        cursor++;
                    }
                    if (col + 1 < columnas) {
                        if (*cursor == ',') {
                            cursor++;
                        } 
                        else {
                            valido = false;
                        }
                    }
                }
            }
            fila++;
        }
    }
    return valido;
}
 
int *cargar_matriz_csv(const char *ruta, size_t *filas, size_t *columnas)
{
    int *matriz = NULL;
 
    if (ruta != NULL && filas != NULL && columnas != NULL) {
        *filas = 0;
        *columnas = 0;
 
        FILE *archivo = fopen(ruta, "r");
        if (archivo != NULL) {
            size_t total_filas = 0;
            size_t total_columnas = 0;
 
            if (medir_csv(archivo, &total_filas, &total_columnas)) {
                matriz = malloc(total_filas * total_columnas * sizeof(int));
                if (matriz != NULL) {
                    rewind(archivo);
                    if (leer_valores(archivo, matriz, total_filas, total_columnas)) {
                        *filas = total_filas;
                        *columnas = total_columnas;
                    } 
                    else {
                        free(matriz);
                        matriz = NULL;
                    }
                }
            }
            fclose(archivo);
        }
    }
    return matriz;
}
 
int *filtrar_filas_mayores(const int *matriz, size_t filas, size_t columnas, size_t columna, int umbral, size_t *filas_filtradas)
{
    int *filtrada = NULL;
 
    if (matriz != NULL && filas_filtradas != NULL) {
        *filas_filtradas = 0;
 
        if (columna < columnas) {
            size_t cuenta = 0;
            for (size_t i = 0; i < filas; ++i) {
                if (matriz[i * columnas + columna] > umbral) {
                    cuenta++;
                }
            }
 
            if (cuenta > 0) {
                filtrada = malloc(cuenta * columnas * sizeof(int));
                if (filtrada != NULL) {
                    size_t destino = 0;
                    for (size_t i = 0; i < filas; ++i) {
                        if (matriz[i * columnas + columna] > umbral) {
                            memcpy(filtrada + destino * columnas, matriz + i * columnas,
                                   columnas * sizeof(int));
                            destino++;
                        }
                    }
                    *filas_filtradas = cuenta;
                }
            }
        }
    }
    return filtrada;
}
 
float *sumar_columnas(const int *matriz, size_t filas, size_t columnas)
{
    float *sumas = NULL;
 
    if (matriz != NULL && filas > 0 && columnas > 0) {
        sumas = calloc(columnas, sizeof(float));
        if (sumas != NULL) {
            for (size_t i = 0; i < filas; ++i) {
                for (size_t j = 0; j < columnas; ++j) {
                    sumas[j] += (float)matriz[i * columnas + j];
                }
            }
        }
    }
    return sumas;
}
 
float *promediar_columnas(const int *matriz, size_t filas, size_t columnas)
{
    float *promedios = sumar_columnas(matriz, filas, columnas);
 
    if (promedios != NULL) {
        for (size_t j = 0; j < columnas; ++j) {
            promedios[j] /= (float)filas;
        }
    }
    return promedios;
}
 
bool exportar_matriz_csv(const int *matriz, size_t filas, size_t columnas, const char *ruta)
{
    bool exportado = false;
 
    if (matriz != NULL && filas > 0 && columnas > 0 && ruta != NULL) {
        FILE *archivo = fopen(ruta, "w");
        if (archivo != NULL) {
            for (size_t i = 0; i < filas; ++i) {
                for (size_t j = 0; j < columnas; ++j) {
                    fprintf(archivo, "%d", matriz[i * columnas + j]);
                    if (j + 1 < columnas) {
                        fputc(',', archivo);
                    }
                }
                fputc('\n', archivo);
            }
 
            exportado = (ferror(archivo) == 0);
            if (fclose(archivo) != 0) {
                exportado = false;
            }
        }
    }
    return exportado;
}