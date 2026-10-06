
/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 */

#include <stdio.h>
#include "consulta_csv.h"
#include "../ejercicio4/matriz_dinamica.h"
#include <stdlib.h>

#define CAPACIDAD_RUTA 256

int main(void)
{
    char entrada[CAPACIDAD_RUTA] = {0};
    char salida[CAPACIDAD_RUTA] = {0};

    size_t filas = 0;
    size_t columnas = 0;
    size_t columna = 0;
    size_t seleccionadas = 0;
    size_t posicion = 0;

    int umbral = 0;

    int **matriz = NULL;
    int **filtrada = NULL;

    float *sumas = NULL;
    float *promedios = NULL;

    printf("=== Ejercicio 6: Consultas y exportacion CSV ===\n");

    printf("Archivo de entrada: ");
    scanf("%255s", entrada);

    printf("Archivo de salida: ");
    scanf("%255s", salida);

    printf("Columna a filtrar: ");
    scanf("%zu", &columna);

    printf("Umbral: ");
    scanf("%d", &umbral);

    matriz = matriz_cargar_desde_csv(
        entrada,
        &filas,
        &columnas
    );

    if (matriz == NULL)
    {
        fprintf(stderr, "No se pudo cargar la matriz.\n");
        return 1;
    }

    if (columna >= columnas)
    {
        fprintf(stderr, "La columna indicada no existe.\n");

        matriz_destruir(matriz);

        return 1;
    }

    filtrada = filtrar_filas_csv(
        matriz,
        filas,
        columnas,
        columna,
        umbral,
        &seleccionadas
    );

    printf(
        "Filas originales: %zu\n",
        filas
    );

    printf(
        "Filas seleccionadas: %zu\n",
        seleccionadas
    );

    if (filtrada != NULL)
    {
        sumas = sumar_columnas_csv(
            filtrada,
            seleccionadas,
            columnas
        );

        promedios = promediar_columnas_csv(
            filtrada,
            seleccionadas,
            columnas
        );

        if (sumas != NULL && promedios != NULL)
        {
            for (posicion = 0;
                 posicion < columnas;
                 posicion++)
            {
                printf(
                    "Columna %zu: suma %.2f; promedio %.2f\n",
                    posicion,
                    sumas[posicion],
                    promedios[posicion]
                );
            }
        }
    }

    if (!exportar_matriz_csv(
            salida,
            filtrada,
            seleccionadas,
            columnas))
    {
        fprintf(
            stderr,
            "No se pudo exportar la matriz.\n"
        );
    }
    else
    {
        printf("Exportacion completada.\n");
    }

    free(sumas);
    free(promedios);

    matriz_destruir(filtrada);
    matriz_destruir(matriz);

    return 0;
}
