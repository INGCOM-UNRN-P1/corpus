/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
    

    const char *csv_entrada = "datos_demo.csv";
    const char *csv_salida = "filtrado_demo.csv";

    FILE *f = fopen(csv_entrada, "w");
    if (f != NULL) {
        fprintf(f, "10,20,30\n15,50,40\n5,80,10\n");
        fclose(f);
    }

    size_t filas = 0, columnas = 0;
    int **matriz = consulta_cargar_csv(csv_entrada, &filas, &columnas);

    if (matriz != NULL) {
        printf("Matriz cargada (%zu filas, %zu cols).\n", filas, columnas);

        size_t filas_filtradas = 0;
        int **filtrada = consulta_filtrar_mayor(matriz, filas, columnas, 1, 30, &filas_filtradas);

        if (filtrada != NULL) {
            printf("Matriz filtrada (col 1 > 30): %zu filas.\n", filas_filtradas);
            consulta_exportar_csv(csv_salida, filtrada, filas_filtradas, columnas);
            consulta_liberar_matriz(filtrada);
        }

        float *promedios = consulta_promedios_por_columna(matriz, filas, columnas);
        if (promedios != NULL) {
            printf("Promedios por columna: ");
            for (size_t j = 0; j < columnas; j++) {
                printf("%.2f ", promedios[j]);
            }
            printf("\n");
            free(promedios);
        }

        consulta_liberar_matriz(matriz);
    }

    remove(csv_entrada);
    remove(csv_salida);
    
    return 0;
}
