/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 *
 * Uso: ./programa [archivo.csv]
 */

#include <stdio.h>
#include "matriz_dinamica.h"

#define FILAS_DEMO 3
#define COLUMNAS_DEMO 4

static void mostrar_matriz(int **matriz, size_t filas, size_t columnas);

int main(int argc, char **argv)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");

    printf("Matriz plana %dx%d (i * 10 + j):\n", FILAS_DEMO, COLUMNAS_DEMO);
    int *plana = crear_matriz_plana(FILAS_DEMO, COLUMNAS_DEMO);
    if (plana == NULL)
    {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    for (size_t i = 0; i < FILAS_DEMO; i++)
    {
        for (size_t j = 0; j < COLUMNAS_DEMO; j++)
        {
            asignar_celda(plana, COLUMNAS_DEMO, i, j, (int)(i * 10 + j));
            printf("%4d", obtener_celda(plana, COLUMNAS_DEMO, i, j));
        }
        printf("\n");
    }
    liberar_matriz_plana(plana);
    plana = NULL;

    printf("Matriz con punteros a fila (identidad):\n");
    int **matriz = matriz_crear(FILAS_DEMO, FILAS_DEMO);
    if (matriz == NULL)
    {
        fprintf(stderr, "Error de memoria\n");
        return 1;
    }
    for (size_t i = 0; i < FILAS_DEMO; i++)
    {
        matriz[i][i] = 1;
    }
    mostrar_matriz(matriz, FILAS_DEMO, FILAS_DEMO);
    matriz_destruir(matriz);
    matriz = NULL;

    if (argc > 1)
    {
        size_t filas = 0;
        size_t columnas = 0;
        int **cargada = matriz_cargar_desde_csv(argv[1], &filas, &columnas);
        if (cargada == NULL)
        {
            fprintf(stderr, "No se pudo cargar %s\n", argv[1]);
            return 1;
        }
        printf("Matriz cargada de %s (%zux%zu):\n", argv[1], filas,
               columnas);
        mostrar_matriz(cargada, filas, columnas);
        matriz_destruir(cargada);
        cargada = NULL;
    }
    return 0;
}

/**
 * @brief Muestra una matriz por salida estándar.
 * @param matriz matriz con punteros a fila.
 * @param filas cantidad de filas.
 * @param columnas cantidad de columnas.
 */
static void mostrar_matriz(int **matriz, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}
