/**
 * @file matrices.h
 * @brief Biblioteca para manejo de matrices bidimensionales dinámicas en C11.
 *
 * Trabajo Práctico 7 - Programación 1
 * Universidad Nacional de Río Negro - Ingeniería en Computación
 */

#ifndef MATRICES_H
#define MATRICES_H

#include <stdbool.h>
#include <stddef.h>


typedef struct matriz {
    int **filas;          
    int *datos;           
    size_t cant_filas;    
    size_t cant_columnas; 
} matriz_t;


bool matriz_crear(matriz_t *matriz, size_t filas, size_t columnas);
void matriz_destruir(matriz_t *matriz);
bool matriz_obtener(const matriz_t *matriz, size_t fila, size_t columna, int *valor);
bool matriz_asignar(matriz_t *matriz, size_t fila, size_t columna, int valor);

#endif 
