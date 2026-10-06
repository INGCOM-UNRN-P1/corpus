
/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include "matriz_dinamica.h"
#include <stdlib.h>

#define FILAS_DEMO 3
#define COLUMNAS_DEMO 4

static void llenar_demostracion(int **matriz, size_t filas, size_t columnas)
{
    size_t fila = 0;
    size_t columna = 0;

    for (fila = 0; fila < filas; fila++)
    {
        for (columna = 0; columna < columnas; columna++)
        {
            matriz[fila][columna] =
                (int)(fila * columnas + columna + 1);
        }
    }
}

static void mostrar_matriz(int *const *matriz, size_t filas,
                           size_t columnas)
{
    size_t fila = 0;
    size_t columna = 0;

    for (fila = 0; fila < filas; fila++)
    {
        for (columna = 0; columna < columnas; columna++)
        {
            printf("%6d ", matriz[fila][columna]);
        }

        printf("\n");
    }
}

int main(int conteo_args, char **argumentos)
{
    size_t filas = FILAS_DEMO;
    size_t columnas = COLUMNAS_DEMO;
    int **matriz = NULL;

    if (conteo_args > 2)
    {
        fprintf(stderr, "Uso: %s [archivo.csv]\n", argumentos[0]);
        return 1;
    }

    if (conteo_args == 2)
    {
        matriz = matriz_cargar_desde_csv(
            argumentos[1],
            &filas,
            &columnas
        );
    }
    else
    {
        matriz = matriz_crear(
            filas,
            columnas
        );

        if (matriz != NULL)
        {
            llenar_demostracion(
                matriz,
                filas,
                columnas
            );
        }
    }

    if (matriz == NULL)
    {
        fprintf(
            stderr,
            "No se pudo crear o cargar la matriz.\n"
        );

        return 1;
    }

    printf(
        "=== Ejercicio 4: Matriz dinamica (%zu x %zu) ===\n",
        filas,
        columnas
    );

    mostrar_matriz(
        matriz,
        filas,
        columnas
    );

    matriz_destruir(matriz);
    matriz = NULL;

    return 0;
}
