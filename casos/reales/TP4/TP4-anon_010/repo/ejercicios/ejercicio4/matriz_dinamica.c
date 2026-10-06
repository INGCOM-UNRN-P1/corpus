/**
 * @file matriz_dinamica.c
 * @brief Implementación para Ejercicio 4 (Matrices Dinámicas).
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"
 
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
 

static bool leer_valores(FILE *archivo, int **matriz, size_t filas, size_t columnas)
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
                } else {
                    matriz[fila][col] = (int)valor;
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
 
int **matriz_crear(size_t filas, size_t columnas)
{
    int **matriz = NULL;
 
    if (filas > 0 && columnas > 0) {
        int *datos = calloc(filas * columnas, sizeof(int));
        int **punteros = malloc(filas * sizeof(int *));
 
        if (datos != NULL && punteros != NULL) {
            for (size_t i = 0; i < filas; ++i) {
                punteros[i] = datos + i * columnas;
            }
            matriz = punteros;
        } else {
            free(datos);
            free(punteros);
        }
    }
    return matriz;
}
 
void matriz_destruir(int **matriz)
{
    if (matriz != NULL) {
        free(matriz[0]);
        free(matriz);
    }
}
 
int **matriz_cargar_desde_csv(const char *ruta, size_t *filas, size_t *columnas)
{
    int **matriz = NULL;
 
    if (ruta != NULL && filas != NULL && columnas != NULL) {
        *filas = 0;
        *columnas = 0;
 
        FILE *archivo = fopen(ruta, "r");
        if (archivo != NULL) {
            size_t total_filas = 0;
            size_t total_columnas = 0;
 
            if (medir_csv(archivo, &total_filas, &total_columnas)) {
                matriz = matriz_crear(total_filas, total_columnas);
                if (matriz != NULL) {
                    rewind(archivo);
                    if (leer_valores(archivo, matriz, total_filas, total_columnas)) {
                        *filas = total_filas;
                        *columnas = total_columnas;
                    } else {
                        matriz_destruir(matriz);
                        matriz = NULL;
                    }
                }
            }
            fclose(archivo);
        }
    }
    return matriz;
}