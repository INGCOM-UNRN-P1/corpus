/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "consulta_csv.h"
#include <stdlib.h>

int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
    
    printf("================================================\n\n");
    const char *origen = "sensor_data.csv";
    const char *detino = "sensor_alertas.csv";

    FILE *f = fopen(origen, "w");
    if (f)
    {
        fprintf(f, "4,3\n");
        fprintf(f, "101,22,5,\n");
        fprintf(f, "102,35,12,\n");
        fprintf(f, "103,18,8,\n");
        fprintf(f, "104,32,15,\n");
        fclose(f);
    }
    size_t f_orig = 0, c_orig = 0;
    int **matriz = matriz_cargar_csv(origen, &f_orig, &c_orig);
    printf("[1] Detaset cargado: %zu filas, %zu columnas.\n", f_orig, c_orig);
    size_t f_filt = 0;
    int **alertas = matriz_filtrar(matriz, f_orig, c_orig, 1, 30, &f_filt);
    printf("[2] Filtro aplicado (Temp > 30). Filas resultantes: %zu.\n", f_filt);
    float *promedios = matriz_promedio_columnas(alertas, f_filt, c_orig);
    if (promedios)
    {
        printf("[3] Promedio de las alertas:\n");
        printf("    - Temperatura media: %.2f\n", promedios[1]);
        printf("    - Humedad media: %.2f\n", promedios[2]);
    }
    const char *destino = "sensor_alertas.csv";
    if (matriz_exportar_csv(alertas, f_filt, c_orig, destino))
    {
        printf("[4] Matriz de alertas exportada a '%s'.\n", destino);
    }
    free(promedios);
    matriz_liberar(alertas);
    matriz_liberar(matriz);
    printf("\nPipeline finalizado. Memoria del heap liberada al 100%.\n");
    return 0;
}
