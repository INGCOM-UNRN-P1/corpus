/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "consola.h"
#include "consulta_csv.h"

#define RUTA_ENTRADA "datos.csv"
#define RUTA_SALIDA "filtrada.csv"

int main(void)
{
    FILE *archivo = NULL;
    size_t filas = 0U;
    size_t columnas = 0U;
    int **matriz = NULL;
    float *promedios = NULL;
    size_t cantidad = 0U;
    int umbral = 0;
    size_t filas_filtradas = 0U;
    int **filtrada = NULL;
    size_t i = 0U;
    size_t j = 0U;
    int resultado_export = 0;

    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");

    archivo = fopen(RUTA_ENTRADA, "w");
    if (archivo != NULL)
    {
        fprintf(archivo, "1,2,3\n4,5,6\n7,8,9\n");
        fclose(archivo);
    }

    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    if (matriz == NULL)
    {
        printf("No se pudieron cargar los datos.\n");
        return 1;
    }
    printf("Matriz cargada: %zu filas x %zu columnas\n", filas, columnas);

    promedios = estadisticas_columnas((const int *)matriz[0], filas, columnas,
                                      &cantidad);
    if (promedios != NULL)
    {
        printf("Promedios por columna:\n");
        for (i = 0U; i < cantidad; ++i)
        {
            printf("  Columna %zu: %.2f\n", i, promedios[i]);
        }
        free(promedios);
    }

    umbral = leer_entero("Ingrese umbral para filtrar la columna 1");
    filtrada = filtrar_matriz_por_columna((const int *)matriz[0], filas,
                                          columnas, 1U, umbral,
                                          &filas_filtradas);
    if (filtrada != NULL)
    {
        printf("Filas con valor > %d en columna 1:\n", umbral);
        for (i = 0U; i < filas_filtradas; ++i)
        {
            printf("  Fila %zu: ", i);
            for (j = 0U; j < columnas; ++j)
            {
                printf("%d%s", filtrada[i][j],
                       (j + 1U < columnas) ? " " : "\n");
            }
        }

        resultado_export = exportar_matriz_csv(RUTA_SALIDA,
                                               (const int *)filtrada[0],
                                               filas_filtradas, columnas);
        if (resultado_export == 0)
        {
            printf("Resultado exportado en '%s'\n", RUTA_SALIDA);
        }
        else
        {
            printf("No se pudo exportar el resultado.\n");
        }

        liberar_matriz_int(filtrada, filas_filtradas);
    }
    else
    {
        printf("No hay filas que cumplan el criterio.\n");
    }

    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);
    return 0;
}