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

    char ruta[256];
    size_t filas = 0;
    size_t columnas = 0;

    printf("Ingrese la ruta del archivo CSV: ");
    scanf("%255s", ruta);

    int *matriz = cargar_csv(ruta, &filas, &columnas);

    if (matriz == NULL)
    {
        printf("No se pudo cargar el archivo CSV.\n");
        return 1;
    }

    printf("Matriz cargada: %zu filas x %zu columnas\n",
           filas, columnas);

    size_t columna_filtro = 0;
    int umbral = 0;

    printf("Ingrese la columna por la que desea filtrar (0 a %zu): ",
           columnas - 1);
    scanf("%zu", &columna_filtro);

    if (columna_filtro >= columnas)
    {
        printf("La columna ingresada no es valida.\n");
        liberar_matriz(&matriz);
        return 1;
    }

    printf("Ingrese el umbral: ");
    scanf("%d", &umbral);

    size_t filas_filtradas = 0;

    int *matriz_filtrada =
        filtrar_filas(
            matriz,
            filas,
            columnas,
            columna_filtro,
            umbral,
            &filas_filtradas
        );

    if (matriz_filtrada == NULL)
    {
        printf("No se encontraron filas que cumplan la condicion.\n");
        liberar_matriz(&matriz);
        return 0;
    }

    printf("Filas obtenidas: %zu\n", filas_filtradas);

    float *sumas =
        calcular_sumas_columnas(
            matriz_filtrada,
            filas_filtradas,
            columnas
        );

    float *promedios =
        calcular_promedios_columnas(
            matriz_filtrada,
            filas_filtradas,
            columnas
        );

    if (sumas == NULL || promedios == NULL)
    {
        printf("No se pudieron calcular las estadisticas.\n");

        free(sumas);
        free(promedios);

        liberar_matriz(&matriz);
        liberar_matriz(&matriz_filtrada);

        return 1;
    }

    printf("\nEstadisticas por columna:\n");

    for (size_t columna = 0; columna < columnas; columna++)
    {
        printf(
            "Columna %zu: suma = %.2f, promedio = %.2f\n",
            columna,
            sumas[columna],
            promedios[columna]
        );
    }

    if (exportar_csv(
            "filtrado.csv",
            matriz_filtrada,
            filas_filtradas,
            columnas))
    {
        printf("\nMatriz filtrada exportada a filtrado.csv\n");
    }
    else
    {
        printf("\nNo se pudo exportar el archivo.\n");
    }

    free(sumas);
    free(promedios);

    liberar_matriz(&matriz);
    liberar_matriz(&matriz_filtrada);

    return 0;
}