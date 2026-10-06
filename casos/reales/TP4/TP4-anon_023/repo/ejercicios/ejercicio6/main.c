/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

static void imprimir_matriz(const char *titulo, int **m, size_t filas, size_t columnas)
{
    printf("%s (%zux%zu):\n", titulo, filas, columnas);
    for (size_t i = 0; i < filas; i++)
    {
        printf("  [ ");
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%4d ", *(*(m + i) + j));
        }
        printf("]\n");
    }
}

int main(void)
{
    printf("=== Ejercicio 6: Motor de Consultas y Pipeline CSV Dinamico ===\n\n");

    const char *csv_origen = "ventas_dataset.csv";
    const char *csv_destino = "ventas_filtradas.csv";

    
    FILE *f = fopen(csv_origen, "w");
    if (f != NULL)
    {
        
        fprintf(f, "101,5,250\n");
        fprintf(f, "102,1,50\n");
        fprintf(f, "103,12,600\n");
        fprintf(f, "104,3,150\n");
        fprintf(f, "105,8,400\n");
        fclose(f);
    }

    printf("1. Leyendo dataset CSV en heap desde '%s'...\n", csv_origen);
    size_t filas = 0, columnas = 0;
    int **matriz = cargar_matriz_csv(csv_origen, &filas, &columnas);
    if (matriz != NULL)
    {
        imprimir_matriz("Dataset cargado", matriz, filas, columnas);
    }

    printf("\n2. Calculando promedios por columna...\n");
    float *promedios = calcular_promedios_columnas(matriz, filas, columnas);
    if (promedios != NULL)
    {
        printf("Promedios: [ ");
        for (size_t j = 0; j < columnas; j++)
        {
            printf("%.2f ", *(promedios + j));
        }
        printf("]\n");
    }

    printf("\n3. Filtrando registros donde Facturacion (Columna 2) > 200...\n");
    size_t filas_filtradas = 0;
    int **filtrada = filtrar_filas_matriz(matriz, filas, columnas, 2, 200, &filas_filtradas);
    if (filtrada != NULL)
    {
        imprimir_matriz("Dataset filtrado", filtrada, filas_filtradas, columnas);

        printf("\n4. Exportando matriz reducida a '%s'...\n", csv_destino);
        if (exportar_matriz_csv(csv_destino, filtrada, filas_filtradas, columnas))
        {
            printf("Exportacion completada exitosamente.\n");
        }
    }

    printf("\n5. Liberando toda la memoria dinamica alocada...\n");
    destruir_matriz_contigua(&matriz);
    destruir_matriz_contigua(&filtrada);
    liberar_arreglo_floats(&promedios);

    printf("Puntero matriz base   : %p\n", (void *)matriz);
    printf("Puntero matriz filtro : %p\n", (void *)filtrada);
    printf("Puntero promedios     : %p\n", (void *)promedios);

    remove(csv_origen);
    remove(csv_destino);
    return 0;
}