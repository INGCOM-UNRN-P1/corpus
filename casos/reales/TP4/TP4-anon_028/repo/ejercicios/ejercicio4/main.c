/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

int main(void)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");
    
    size_t filas = 3;
    size_t columnas = 4;

    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL) {
        printf("Error al crear la matriz.\n");
        return 1;
    }

    int contador = 1;
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            matriz[i][j] = contador++;
        }
    }

    printf("Matriz %zux%zu:\n", filas, columnas);
    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            printf("%4d ", matriz[i][j]);
        }
        printf("\n");
    }

    matriz_destruir(matriz);
    printf("Matriz liberada correctamente.\n");

    return 0;
}
