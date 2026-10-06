/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

int main(void)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");
    
    printf("=============================================\n\n");

    size_t filas = 3;
    size_t columnas = 4;

    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL)
    {
        printf("Error: no se pudo reservar memoria.\n");
        return 1;
    }

    printf("[Modo bidimensional]\n");
    printf("Escribiendo matriz de %zux%zu:\n", filas, columnas);
    int contador = 1;

    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            matriz[i][j] = contador++;
            printf("%4d ", matriz[i][j]);
        }
    }
    printf("\n");

    printf("\n[Modo lineal oculto]\n");
    printf("Accediendo al bloque subyacente contiguo con matriz[0]:\n");

    for (size_t k = 0; k < (filas * columnas); k++)
    {
        printf("%d ", matriz[0][k]);
    }
    printf("\n\n");
    matriz_destruir(matriz);
    matriz = NULL;
    printf("Memoria del heap liberada exitosamente, sin fuga.\n");
    return 0;
}