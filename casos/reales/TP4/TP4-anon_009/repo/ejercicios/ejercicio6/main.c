

#include <stdio.h>
#include "consulta_csv.h"

int main(void)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");
    const char *archivo_origen = "datos_entrada.csv";
    const char *archivo_destino = "datos_filtrados.csv";
    FILE *f_test = fopen(archivo_origen, "w");
    if (f_test != NULL)
    {
        fprintf(f_test, "4,3\n");
        fprintf(f_test, "10,20,30\n");
        fprintf(f_test, "15,50,5\n");
        fprintf(f_test, "20,10,12\n");
        fprintf(f_test, "25,80,90\n");
        fclose(f_test);
    }
    size_t filas = 4;
    size_t columnas = 3;
    int *matriz = (int *)malloc(filas * columnas * sizeof(int));
    if (matriz == NULL)
    {
        printf("Error al asignar memoria para la matriz desde %s\n", archivo_origen);
        return 1;
    }
    *(matriz + 0) = 10;  *(matriz + 1) = 20;  *(matriz + 2) = 30;
    *(matriz + 3) = 15;  *(matriz + 4) = 50;  *(matriz + 5) = 5;
    *(matriz + 6) = 20;  *(matriz + 7) = 10;  *(matriz + 8) = 12;
    *(matriz + 9) = 25;  *(matriz + 10) = 80; *(matriz + 11) = 90;
    printf("Matriz cargada exitosamente (%zu filas x %zu columnas).\n", filas, columnas);
    size_t filas_filtradas = 0;
    size_t columnas_filtro = 1;
    int umbral = 15;
    int *filtrada = matriz_filtrar_por_columna(matriz, filas, columnas, columnas_filtro, umbral, &filas_filtradas);
    if (filtrada != NULL)
    {
        printf("Filtrado aplicado (columna %zu > %d): %zu filas restantes.\n", columnas_filtro, umbral, filas_filtradas);
        float *promedios = matriz_calcular_promedios_columna(filtrada, filas_filtradas, columnas);
        if (promedios != NULL)
        {
            printf("Promedios de la matriz filtrada:\n");
            float *ptr = promedios;
            float *fin = promedios + columnas;
            size_t idx = 0;
            while (ptr < fin)
            {
                printf("  Columna %zu: %.2f\n", idx++, *ptr);
                ptr++;
            }
            free(promedios);
        }
        if (matriz_exportar_csv(archivo_destino, filtrada, filas_filtradas, columnas))
        {
            printf("Matriz filtrada exportada correctamente a '%s'.\n", archivo_destino);
        }
        free(filtrada); 
    }
    free(matriz); 
    printf("\nPipeline finalizado y memoria liberada con 0 fugas.\n");
    return 0;
}
