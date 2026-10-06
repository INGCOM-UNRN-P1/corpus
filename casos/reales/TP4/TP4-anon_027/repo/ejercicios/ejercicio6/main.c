/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "consulta_csv.h"
#include <stdlib.h>

int main()
{
    printf("||||Ejercicio 6: Motor de Consultas y Pipeline CSV Dinamico||||\n");
    
    char ruta_entrada[256];
    char ruta_salida[256];
    char delimitador = ',';
    size_t col_filtro = 0;
    int umbral = 0;

    printf("Ingrese la ruta del archivo CSV origen: ");

    if (scanf("%255s", ruta_entrada) != 1)
    {
        return 1;
    } 

    size_t filas = 0; 
    size_t columnas = 0;

    int **matriz = matriz_cargar_desde_csv(ruta_entrada, delimitador, &filas, &columnas);

    if (matriz == NULL) 
    {
        printf("[Error] No se pudo cargar el archivo CSV o la matriz esta vacia.\n");
        return 1;
    }

    printf("\n[OK] CSV cargado exitosamente (%zu filas x %zu columnas).\n", filas, columnas);

    // Mostrar promedios iniciales
    float *promedios = matriz_calcular_promedios_columnas(matriz, filas, columnas);
    if (promedios != NULL) 
    {
        printf("\nPromedios por columna origen:\n");
        for (size_t j = 0; j < columnas; j++) 
        {
            printf("  Columna [%zu]: %.2f\n", j, promedios[j]);
        }
        free(promedios);
    }

    // Solicitud de parametros de filtrado
    printf("\n--- Filtrado de Datos ---\n");
    printf("Ingrese el indice de la columna a filtrar (0 a %zu): ", columnas - 1);
    
    if ((scanf("%zu", &col_filtro) != 1) || (col_filtro >= columnas)) 
    {
        printf("[Error] Indice de columna invalido.\n");
        matriz_liberar(&matriz, filas);
        return 1;
    }

    printf("Ingrese el valor umbral minimo (se conservaran filas con valor > umbral): ");
    if (scanf("%d", &umbral) != 1) 
    {
        matriz_liberar(&matriz, filas);
        return 1;
    }

    size_t filas_filtradas = 0;
    int **matriz_filtrada = matriz_filtrar_por_columna(matriz, filas, columnas, col_filtro, umbral, &filas_filtradas);

    printf("\n[OK] Filtrado completado: %zu filas conservadas de %zu.\n", filas_filtradas, filas);

    if (matriz_filtrada != NULL) 
    {
        printf("Ingrese la ruta del archivo CSV de salida para exportar: ");
        if (scanf("%255s", ruta_salida) == 1) 
        {
            if (matriz_exportar_csv(ruta_salida, matriz_filtrada, filas_filtradas, columnas, delimitador) == 0) 
            {
                printf("[OK] Archivo exportado exitosamente a '%s'.\n", ruta_salida);
            } 
            
            else 
            {
                printf("[Error] No se pudo guardar el archivo de salida.\n");
                return 1;
            }
        }
        matriz_liberar(&matriz_filtrada, filas_filtradas);
    }

    // Limpieza de memoria
    matriz_liberar(&matriz, filas);

    if ((matriz == NULL) && (matriz_filtrada == NULL)) 
    {
        printf("\n[OK] Memoria liberada sin fugas (*matriz == NULL).\n");
    }
    
    return 0;
}
