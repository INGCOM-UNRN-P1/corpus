#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinamico\n\n");

    const char *db_origen = "dataset.csv";
    const char *db_destino = "filtrado.csv";

    FILE *f = fopen(db_origen, "w");
    if (f != NULL)
    {
        fputs("100,50,30\n200,80,10\n150,90,40\n120,40,5\n", f);
        fclose(f);
        printf("Generando dataset de prueba 'dataset.csv'...\n");
    }

    size_t filas = 0, columnas = 0;
    int **matriz = csv_cargar_matriz(db_origen, &filas, &columnas);

    if (matriz != NULL)
    {
        printf("Dataset cargado (%zux%zu).\n", filas, columnas);

        float *promedios = csv_calcular_promedios(matriz, filas, columnas);
        if (promedios != NULL)
        {
            printf("\nPromedios globales por columna:\n");
            for (size_t j = 0; j < columnas; j++) printf("  Col %zu: %.2f\n", j, promedios[j]);
            free(promedios);
        }

        size_t umbral = 35;
        size_t col_filtro = 1;
        printf("\nFiltrando registros donde la columna %zu sea mayor a %zu...\n", col_filtro, umbral);

        size_t filas_filtradas = 0;
        int **matriz_filtrada = csv_filtrar_filas(matriz, filas, columnas, col_filtro, umbral, &filas_filtradas);

        if (matriz_filtrada != NULL)
        {
            printf("Registros que pasaron el filtro: %zu\n", filas_filtradas);
            
            if (csv_exportar_matriz(db_destino, matriz_filtrada, filas_filtradas, columnas))
            {
                printf("Dataset exportado exitosamente a '%s'.\n", db_destino);
            }
            csv_liberar_matriz(&matriz_filtrada, filas_filtradas);
        }

        csv_liberar_matriz(&matriz, filas);
        printf("\nToda la memoria dinamica liberada sin leaks.\n");
    }

    remove(db_origen);
    return 0;
}