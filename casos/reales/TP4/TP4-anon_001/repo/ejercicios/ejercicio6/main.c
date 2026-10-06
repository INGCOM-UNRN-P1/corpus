/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include "consulta_csv.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    printf("=== Demo Pipeline de Consulta CSV ===\n\n");

    // 1. Crear matriz dinamica de prueba (3 filas x 3 columnas)
    size_t filas = 3;
    size_t columnas = 3;

    int **matriz = malloc(filas * sizeof(int *));
    if (matriz == NULL)
    {
        printf("Error al asignar memoria inicial.\n");
        return 1;
    }

    size_t i = 0;
    while (i < filas)
    {
        matriz[i] = malloc(columnas * sizeof(int));
        i++;
    }

    // Carga de datos de ejemplo.
    matriz[0][0] = 10;
    matriz[0][1] = 20;
    matriz[0][2] = 30;
    matriz[1][0] = 5;
    matriz[1][1] = 50;
    matriz[1][2] = 15;
    matriz[2][0] = 40;
    matriz[2][1] = 10;
    matriz[2][2] = 60;

    printf("Matriz original (%zu x %zu):\n", filas, columnas);
    i = 0;
    while (i < filas)
    {
        size_t j = 0;
        while (j < columnas)
        {
            printf("%d\t", matriz[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

    // 2. Interaccion con el usuario para filtrado
    size_t col_filtro = 0;
    int umbral = 0;

    printf("\nIngrese el indice de columna a filtrar (0 a %zu): ",
           columnas - 1);
    scanf("%zu", &col_filtro);
    printf("Ingrese el umbral de corte: ");
    scanf("%d", &umbral);

    // 3. Ejecutar filtrado.
    size_t filas_filtradas = 0;
    int **filtrada = matriz_filtrar_por_columna(
        matriz, filas, columnas, col_filtro, umbral, &filas_filtradas);

    if (filtrada != NULL)
    {
        printf("\n--- Resultados del Filtrado (%zu filas) ---\n",
               filas_filtradas);
        i = 0;
        while (i < filas_filtradas)
        {
            size_t j = 0;
            while (j < columnas)
            {
                printf("%d\t", filtrada[i][j]);
                j++;
            }
            printf("\n");
            i++;
        }

        // 4. Calcular y mostrar promedios por columna
        float *promedios =
            matriz_calcular_promedios(filtrada, filas_filtradas, columnas);
        if (promedios != NULL)
        {
            printf("\nPromedios de la matriz filtrada:\n");
            size_t j = 0;
            while (j < columnas)
            {
                printf("Columna %zu: %.2f\n", j, promedios[j]);
                j++;
            }
            free(promedios);
        }

        // 5. Exportar a CSV
        if (matriz_exportar_csv("resultado.csv", filtrada, filas_filtradas,
                                columnas))
        {
            printf("\nMatriz filtrada exportada correctamente a "
                   "'resultado.csv'.\n");
        }

        // Liberar matriz filtrada
        i = 0;
        while (i < filas_filtradas)
        {
            free(filtrada[i]);
            i++;
        }
        free(filtrada);
    }
    else
    {
        printf("\nNinguna fila supero el umbral ingresado.\n");
    }

    // Liberar matriz original
    i = 0;
    while (i < filas)
    {
        free(matriz[i]);
        i++;
    }
    free(matriz);

    return 0;
}
