/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"
 
int main(void)
{
    int estado = 0;
 
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");
 
    size_t filas = 3;
    size_t columnas = 4;
 
    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL) {
        printf("Error: no se pudo crear la matriz\n");
        estado = 1;
    } else {
        for (size_t i = 0; i < filas; ++i) {
            for (size_t j = 0; j < columnas; ++j) {
                matriz[i][j] = (int)((i + 1) * (j + 1));
            }
        }
 
        printf("Matriz de %zu x %zu:\n", filas, columnas);
        for (size_t i = 0; i < filas; ++i) {
            for (size_t j = 0; j < columnas; ++j) {
                printf("%4d", matriz[i][j]);
            }
            printf("\n");
        }
 
        matriz_destruir(matriz);
    }
    return estado;
}