/**
 * @file main.c
 * @brief Demostración del Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

int main(void)
{
    const char *ruta_entrada = "datos_demo.csv";
    const char *ruta_salida = "datos_demo_filtrados.csv";
    FILE *archivo = fopen(ruta_entrada, "w");
    FILE *texto = NULL;
    int **matriz = NULL;
    int **filtrada = NULL;
    float *promedios = NULL;
    char **lineas = NULL;
    char **lineas_filtradas = NULL;
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t filas_filtradas = 0U;
    size_t cantidad_lineas = 0U;
    size_t cantidad_lineas_filtradas = 0U;
    size_t indice = 0U;

    printf("Ejercicio 6: Motor de Consultas y Texto Dinamico\n");

    if (archivo != NULL)
    {
        fputs("10,3,7\n20,8,4\n30,12,9\n", archivo);
        fclose(archivo);
        archivo = NULL;
    }

    matriz = cargar_matriz_csv(ruta_entrada, &filas, &columnas);
    if (matriz != NULL)
    {
        filtrada = filtrar_filas_por_umbral((const int *const *)matriz,
                                            filas, columnas, 1U, 5,
                                            &filas_filtradas);
        promedios = calcular_promedios_columnas((const int *const *)matriz,
                                                filas, columnas);

        if (promedios != NULL)
        {
            printf("Promedios por columna: ");
            for (indice = 0U; indice < columnas; indice++)
            {
                printf("%.2f ", promedios[indice]);
            }
            printf("\n");
        }

        if (filtrada != NULL)
        {
            exportar_matriz_csv(ruta_salida, (const int *const *)filtrada,
                                filas_filtradas, columnas);
            printf("Filas filtradas: %zu\n", filas_filtradas);
        }
    }

    texto = tmpfile();
    if (texto != NULL)
    {
        fputs("primera linea\n", texto);
        fputs("linea con heap\n", texto);
        fputs("otra linea con heap\n", texto);
        rewind(texto);
        lineas = leer_lineas_dinamicas(texto, &cantidad_lineas);
        fclose(texto);
        texto = NULL;
    }

    if (lineas != NULL)
    {
        lineas_filtradas = filtrar_lineas_por_subcadena(lineas, cantidad_lineas,
                                                        "heap",
                                                        &cantidad_lineas_filtradas);
    }

    if (lineas_filtradas != NULL)
    {
        printf("Lineas que contienen 'heap':\n");
        for (indice = 0U; indice < cantidad_lineas_filtradas; indice++)
        {
            printf("%s", lineas_filtradas[indice]);
        }
    }

    free(promedios);
    liberar_matriz_csv(&filtrada);
    liberar_matriz_csv(&matriz);
    liberar_lineas_dinamicas(&lineas_filtradas, cantidad_lineas_filtradas);
    liberar_lineas_dinamicas(&lineas, cantidad_lineas);
    remove(ruta_entrada);
    remove(ruta_salida);

    return 0;
}
