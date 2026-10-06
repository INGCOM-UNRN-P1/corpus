/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

int main(void){
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n\n");

    size_t filas = 3;
    size_t columnas = 4;

    printf("MATRIZ\n", filas, columnas);
    int **matriz = matriz_crear(filas, columnas);

    if (matriz == NULL) {
        printf("ERROR EN MALLOC\n");
        return 0;
    }

    int i = 1;
    for (size_t a = 0; a < filas; a++) {
        for (size_t c = 0; c < columnas; c++) {
            matriz[a][c] = i++;
        }
    }

    printf("SEEK N DESTROY.\n");
    matriz_destruir(matriz);


    return 0;
}