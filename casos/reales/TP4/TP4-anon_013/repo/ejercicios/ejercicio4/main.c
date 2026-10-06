/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "matriz_dinamica.h"

static void imprimir_matriz(int **matriz, size_t filas, size_t columnas)
{
    for (size_t i = 0; i < filas; i++)
    {
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Ejercicio 4: Matriz Dinámica 2D en Heap\n");

    //______________________________________________________________________________________________________________

    printf("\n===== matriz_crear y matriz_destruir =====\n");

    size_t filas = 3;
    size_t columnas = 4;

    int **matriz = matriz_crear(filas, columnas, NULL);

    if (matriz != NULL)
    {
        printf("Matriz de %zu x %zu creada (inicializada en 0s):\n", filas, columnas);
        imprimir_matriz(matriz, filas, columnas);

        matriz_destruir_v2(&matriz);

        if (matriz == NULL)
        {
            printf("MATRIZ LIBERADA Y PUNTERO ANULADO CON matriz_destruir_v2()\n");
        }
        else
        {
            printf("ERROR AL DESTRUIR LA MATRIZ, algo malio sal\n");
        }
    }
    else
    {
        printf("ERROR AL CREAR LA MATRIZ, algo malio sal\n");
    }

    //______________________________________________________________________________________________________________

    printf("\n===== matriz_cargar_desde_csv =====\n");

    printf("MATRIZ VALIDA\n");
    const char *ruta = "matriz_valida.csv";
    size_t filas2 = 0;
    size_t columnas2 = 0;

    int **matriz2 = matriz_cargar_desde_csv(ruta, &filas2, &columnas2, NULL);

    if (matriz2 != NULL)
    {
        printf("MATRIZ CARGADA DESDE '%s' (%zu filas x %zu columnas):\n", ruta, filas2, columnas2);
        imprimir_matriz(matriz2, filas2, columnas2);

        matriz_destruir_v2(&matriz2);
        if (matriz2 == NULL)
        {
            printf("MATRIZ LIBERADA Y PUNTERO ANULADO CON matriz_destruir_v2()\n");
        }
        else
        {
            printf("ERROR AL DESTRUIR LA MATRIZ, algo malio sal\n");
        }
    }
    else
    {
        printf("NO SE PUDO CARGAR LA MATRIZ DESDE '%s', algo malio sal\n", ruta);
    }

    printf("\nMATRIZ INVALIDA\n");
    ruta = "matriz_invalida.csv";
    filas2 = 0;
    columnas2 = 0;

    matriz2 = matriz_cargar_desde_csv(ruta, &filas2, &columnas2, NULL);

    if (matriz2 != NULL)
    {
        printf("MATRIZ CARGADA DESDE '%s' (%zu filas x %zu columnas):\n", ruta, filas2, columnas2);
        imprimir_matriz(matriz2, filas2, columnas2);

        matriz_destruir_v2(&matriz2);
        if (matriz2 == NULL)
        {
            printf("MATRIZ LIBERADA Y PUNTERO ANULADO CON matriz_destruir_v2()\n");
        }
        else
        {
            printf("ERROR AL DESTRUIR LA MATRIZ, algo malio sal\n");
        }
    }
    else
    {
        printf("NO SE PUDO CARGAR LA MATRIZ DESDE '%s', algo malio sal\n", ruta);
    }

    return 0;
}
