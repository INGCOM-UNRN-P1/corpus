/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

int main(void)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n\n");

    
    size_t filas = 2;
    size_t columnas = 3;

    int **matriz = matriz_crear(filas, columnas);

    if (matriz == NULL) {
        printf("No se pudo crear la matriz.\n");
        return 1;
    }

    
    int valor = 1;

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            matriz[i][j] = valor;
            valor++;
        }
    }

    printf("Matriz creada manualmente:\n");

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    
    matriz_destruir(matriz);
    matriz = NULL;


    
    printf("\nMatriz cargada desde CSV:\n");

    matriz = matriz_cargar_desde_csv(
        "matriz.csv",
        &filas,
        &columnas
    );

    if (matriz == NULL) {
        printf("No se pudo cargar la matriz desde el archivo.\n");
        return 1;
    }

    for (size_t i = 0; i < filas; i++) {
        for (size_t j = 0; j < columnas; j++) {
            printf("%d ", matriz[i][j]);
        }

        printf("\n");
    }

    matriz_destruir(matriz);
    matriz = NULL;

    return 0;
}