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
    if (matriz != NULL)
    {
        printf("Matriz de %zu x %zu creada con exito.\n", filas, columnas);
        int **p_fila = matriz;
        int contador = 1;
        while (p_fila < matriz + filas)
        {
            int *p_col = *p_fila;
            while (p_col < *p_fila + columnas)
            {
                *p_col = contador++;
                p_col++;
            }
            p_fila++;
        }
        printf("\nContenido de la matriz:\n");
        p_fila = matriz;
        while (p_fila < matriz + filas)
        {
            int *p_col = *p_fila;
            while (p_col < *p_fila + columnas)
            {
                printf("%3d ", *p_col);
                p_col++;
            }
            printf("\n");
            p_fila++;
        }
        matriz_destruir(matriz);
        matriz = NULL;
        printf("\nMatriz destruida correctamente.\n");
    }
    return 0;
}
