/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"
#include "vector.h"

int main(void)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");

    int filas_leidas = 0;
    int columnas_leidas = 0;
 
    printf("Ejercicio 4: Matriz Dinamica 2D en Heap\n");
    printf("Cantidad de filas: ");
    int leidos = scanf("%d", &filas_leidas);
    printf("Cantidad de columnas: ");
    leidos += scanf("%d", &columnas_leidas);
 
    if (leidos == 2 && filas_leidas > 0 && columnas_leidas > 0)
    {
        size_t filas = (size_t)filas_leidas;
        size_t columnas = (size_t)columnas_leidas;
 
      
        int **matriz = matriz_crear(filas, columnas);
 
        if (matriz != NULL)
        {
        
            for (size_t fila = 0; fila < filas; fila++)
            {
                for (size_t columna = 0; columna < columnas; columna++)
                {
                    printf("Valor [%zu][%zu]: ", fila, columna);
                    leidos = scanf("%d", &matriz[fila][columna]);
                    if (leidos != 1)
                    {
                        printf("Entrada invalida, se toma 0.\n");
                    }
                }
            }
 
           
            printf("Matriz de %zu x %zu:\n", filas, columnas);
            for (size_t fila = 0; fila < filas; fila++)
            {
                for (size_t columna = 0; columna < columnas; columna++)
                {
                    printf("%6d", matriz[fila][columna]);
                }
                printf("\n");
            }
 
           
            matriz_destruir(matriz);
        }
        else
        {
            printf("No hay memoria disponible.\n");
        }
    }
    else
    {
        printf("Dimensiones invalidas.\n");
    }
 
  return 0;
}
