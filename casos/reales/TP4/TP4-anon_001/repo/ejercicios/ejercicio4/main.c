/**
 * @file main.c
 * @brief Programa principal del Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include <stdio.h>

int main(void)
{
    size_t filas = 0, columnas = 0;

    // 1. Pedir dimensiones al usuario.
    printf("=== CREACIÓN DE MATRIZ DINÁMICA ===\n");
    printf("Ingrese cantidad de filas: ");
    if (scanf("%zu", &filas) != 1 || filas == 0)
    {
        printf("Error: Filas inválidas.\n");
        return 1;
    }

    printf("Ingrese cantidad de columnas: ");
    if (scanf("%zu", &columnas) != 1 || columnas == 0)
    {
        printf("Error: Columnas inválidas.\n");
        return 1;
    }

    // 2. Crear la matriz con la función del módulo
    int **matriz = matriz_crear(filas, columnas);
    if (matriz == NULL)
    {
        printf("Error: No se pudo reservar memoria para la matriz.\n");
        return 1;
    }
    printf("\nMatriz creada exitosamente en el heap.\n\n");

    // 3. Llenado interactivo por consola
    printf("=== CARGA DE DATOS ===\n");
    for (size_t f = 0; f < filas; f++)
    {
        for (size_t c = 0; c < columnas; c++)
        {
            printf("Matriz[%zu][%zu]: ", f, c);
            scanf("%d", &matriz[f][c]);
        }
    }

    // 4. Muestra de la matriz en formato tabla
    printf("\n=== MUESTRA DE LA MATRIZ ===\n");
    for (size_t f = 0; f < filas; f++)
    {
        for (size_t c = 0; c < columnas; c++)
        {
            printf("%4d ", matriz[f][c]);
        }
        printf("\n");
    }

    // 5. Destrucción y liberación de memoria
    matriz_destruir(matriz);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
