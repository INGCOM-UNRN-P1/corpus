/**
 * @file main.c
 * @brief Programa principal del Ejercicio 6.
 *
 * Uso:
 *   ./programa <subcadena> < texto.txt
 *       Lee líneas de stdin y muestra las que contienen la subcadena.
 *   ./programa <entrada.csv> <salida.csv> <columna> <umbral>
 *       Carga la matriz, filtra las filas con columna > umbral, muestra
 *       sumas y promedios por columna y exporta el resultado.
 */

#include <stdio.h>
#include <stdlib.h>
#include "consulta_csv.h"

#define ARGS_MODO_TEXTO 2
#define ARGS_MODO_CSV 5
#define SALIDA_OK 0
#define SALIDA_ERROR 1

static int ejecutar_filtro_texto(const char *subcadena);
static int ejecutar_pipeline_csv(const char *entrada, const char *salida,
                                 const char *texto_columna,
                                 const char *texto_umbral);
static void mostrar_estadisticas(const float *valores, size_t columnas,
                                 const char *titulo);

int main(int argc, char **argv)
{
    printf("Ejercicio 6: Motor de Consultas y Pipeline CSV Dinámico\n");

    int resultado = SALIDA_ERROR;
    if (argc == ARGS_MODO_TEXTO)
    {
        resultado = ejecutar_filtro_texto(argv[1]);
    }
    else if (argc == ARGS_MODO_CSV)
    {
        resultado = ejecutar_pipeline_csv(argv[1], argv[2], argv[3],
                                          argv[4]);
    }
    else
    {
        printf("Uso:\n");
        printf("  %s <subcadena> < texto.txt\n", argv[0]);
        printf("  %s <entrada.csv> <salida.csv> <columna> <umbral>\n",
               argv[0]);
        resultado = SALIDA_OK;
    }
    return resultado;
}

/**
 * @brief Lee stdin y muestra las líneas que contienen 'subcadena'.
 * @param subcadena texto a buscar.
 * @returns SALIDA_OK, o SALIDA_ERROR si falla la memoria.
 */
static int ejecutar_filtro_texto(const char *subcadena)
{
    size_t cantidad = 0;
    char **lineas = leer_lineas(stdin, &cantidad);
    size_t cantidad_filtradas = 0;
    char **filtradas = filtrar_lineas(lineas, cantidad, subcadena,
                                      &cantidad_filtradas);

    printf("%zu de %zu lineas contienen \"%s\":\n", cantidad_filtradas,
           cantidad, subcadena);
    for (size_t i = 0; i < cantidad_filtradas; i++)
    {
        printf("%s\n", filtradas[i]);
    }

    liberar_lineas(&filtradas, cantidad_filtradas);
    liberar_lineas(&lineas, cantidad);
    return SALIDA_OK;
}

/**
 * @brief Ejecuta carga, filtro, estadísticas y exportación de un CSV.
 * @param entrada ruta del CSV de entrada.
 * @param salida ruta del CSV a generar.
 * @param texto_columna columna de la condición, como texto.
 * @param texto_umbral umbral de la condición, como texto.
 * @returns SALIDA_OK, o SALIDA_ERROR ante cualquier fallo.
 */
static int ejecutar_pipeline_csv(const char *entrada, const char *salida,
                                 const char *texto_columna,
                                 const char *texto_umbral)
{
    size_t filas = 0;
    size_t columnas = 0;
    int *matriz = csv_cargar_matriz(entrada, &filas, &columnas);
    if (matriz == NULL)
    {
        fprintf(stderr, "No se pudo cargar %s\n", entrada);
        return SALIDA_ERROR;
    }
    size_t columna = (size_t)strtoul(texto_columna, NULL, 10);
    int umbral = (int)strtol(texto_umbral, NULL, 10);

    size_t filas_filtradas = 0;
    int *filtrada = csv_filtrar_filas(matriz, filas, columnas, columna,
                                      umbral, &filas_filtradas);
    printf("Filas con columna %zu > %d: %zu de %zu\n", columna, umbral,
           filas_filtradas, filas);

    int resultado = SALIDA_OK;
    if (filtrada != NULL)
    {
        float *sumas = csv_sumas_columnas(filtrada, filas_filtradas,
                                          columnas);
        float *promedios = csv_promedios_columnas(filtrada, filas_filtradas,
                                                  columnas);
        mostrar_estadisticas(sumas, columnas, "Sumas");
        mostrar_estadisticas(promedios, columnas, "Promedios");
        if (csv_exportar_matriz(salida, filtrada, filas_filtradas,
                                columnas) == true)
        {
            printf("Resultado exportado a %s\n", salida);
        }
        else
        {
            perror(salida);
            resultado = SALIDA_ERROR;
        }
        free(promedios);
        promedios = NULL;
        free(sumas);
        sumas = NULL;
    }

    free(filtrada);
    filtrada = NULL;
    free(matriz);
    matriz = NULL;
    return resultado;
}

/**
 * @brief Muestra un arreglo de estadísticas por columna.
 * @param valores estadísticas (si es NULL no se muestra nada).
 * @param columnas cantidad de valores.
 * @param titulo texto que precede a los valores.
 */
static void mostrar_estadisticas(const float *valores, size_t columnas,
                                 const char *titulo)
{
    if (valores == NULL)
    {
        return;
    }
    printf("%s:", titulo);
    for (size_t j = 0; j < columnas; j++)
    {
        printf(" %.2f", valores[j]);
    }
    printf("\n");
}
