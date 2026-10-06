/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"

static void mostrar_matriz(int **matriz, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; ++i) 
    {
        for (size_t j = 0; j < columnas; ++j) 
        {
            printf("%5d", matriz[i][j]);
        }
        printf("\n");
    }
}
 
int main(int conteo_args, char **argumentos)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");

    size_t filas = 3;
    size_t columnas = 4;
    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL) 
    {
        fprintf(stderr, "Error: no se pudo crear la matriz\n");
        return 1;
    }

    for (size_t i = 0; i < filas; ++i) 
    {
        for (size_t j = 0; j < columnas; ++j) 
        {
            matriz[i][j] = (int)((i + 1) * (j + 1));
        }
    }
 

    printf("Matriz %zux%zu:\n", filas, columnas);
    mostrar_matriz(matriz, filas, columnas);
 

    matriz_destruir(matriz);
    matriz = NULL;
 
    if (conteo_args > 1) 
    {
        size_t filas_csv = 0;
        size_t columnas_csv = 0;
        int **desde_csv = matriz_cargar_desde_csv(argumentos[1], &filas_csv, &columnas_csv);
        if (desde_csv == NULL) 
        {
            fprintf(stderr, "Error: no se pudo cargar el CSV '%s'\n", argumentos[1]);
            return 1;
        }
        printf("Matriz %zux%zu cargada desde '%s':\n", filas_csv, columnas_csv, argumentos[1]);
        mostrar_matriz(desde_csv, filas_csv, columnas_csv);
        matriz_destruir(desde_csv);
    }
    return 0;
}
