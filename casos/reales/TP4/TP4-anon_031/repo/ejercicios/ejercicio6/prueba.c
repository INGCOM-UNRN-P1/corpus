/**
 * @file prueba.c
 * @brief Pruebas unitarias del Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "p1_files.h"
#include "consulta_csv.h"

TEST(prueba_pipeline_csv_numerico)
{
    const char *ruta_entrada = "consulta_entrada.csv";
    const char *ruta_salida = "consulta_salida.csv";
    FILE *archivo = fopen(ruta_entrada, "w");
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t filas_filtradas = 0U;
    int **matriz = NULL;
    int **filtrada = NULL;
    float *promedios = NULL;

    ASSERT_PTR_NOT_NULL(archivo);
    if (archivo != NULL)
    {
        fputs("1,2,3\n4,5,6\n7,8,9\n", archivo);
        fclose(archivo);
    }

    matriz = cargar_matriz_csv(ruta_entrada, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_UINT_EQ(3U, filas);
    ASSERT_UINT_EQ(3U, columnas);
    ASSERT_INT_EQ(5, matriz[1][1]);

    filtrada = filtrar_filas_por_umbral((const int *const *)matriz,
                                        filas, columnas, 1U, 4,
                                        &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_UINT_EQ(2U, filas_filtradas);
    ASSERT_INT_EQ(4, filtrada[0][0]);
    ASSERT_INT_EQ(8, filtrada[1][1]);

    promedios = calcular_promedios_columnas((const int *const *)matriz,
                                            filas, columnas);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_DOUBLE_EQ(4.0, (double)promedios[0], 0.0001);
    ASSERT_DOUBLE_EQ(5.0, (double)promedios[1], 0.0001);
    ASSERT_DOUBLE_EQ(6.0, (double)promedios[2], 0.0001);

    ASSERT_TRUE(exportar_matriz_csv(ruta_salida,
                                    (const int *const *)filtrada,
                                    filas_filtradas, columnas));
    ASSERT_FILE_EXISTS(ruta_salida);
    ASSERT_FILE_CONTAINS(ruta_salida, "4,5,6");
    ASSERT_FILE_CONTAINS(ruta_salida, "7,8,9");

    free(promedios);
    liberar_matriz_csv(&filtrada);
    liberar_matriz_csv(&matriz);
    ASSERT_PTR_NULL(filtrada);
    ASSERT_PTR_NULL(matriz);

    remove(ruta_entrada);
    remove(ruta_salida);
}

TEST(prueba_filtro_sin_resultados)
{
    int datos[] = {1, 2, 3, 4};
    int *filas_datos[] = {&datos[0], &datos[2]};
    size_t cantidad = 99U;
    int **filtrada = filtrar_filas_por_umbral((const int *const *)filas_datos,
                                              2U, 2U, 1U, 100, &cantidad);

    ASSERT_PTR_NULL(filtrada);
    ASSERT_UINT_EQ(0U, cantidad);
}

TEST(prueba_texto_multilinea)
{
    FILE *entrada = tmpfile();
    char **lineas = NULL;
    char **filtradas = NULL;
    size_t cantidad_lineas = 0U;
    size_t cantidad_filtradas = 0U;

    ASSERT_PTR_NOT_NULL(entrada);
    if (entrada != NULL)
    {
        fputs("memoria dinamica\n", entrada);
        fputs("punteros\n", entrada);
        fputs("memoria en heap\n", entrada);
        rewind(entrada);

        lineas = leer_lineas_dinamicas(entrada, &cantidad_lineas);
        fclose(entrada);
    }

    ASSERT_PTR_NOT_NULL(lineas);
    ASSERT_UINT_EQ(3U, cantidad_lineas);
    ASSERT_STR_EQ("punteros\n", lineas[1]);

    filtradas = filtrar_lineas_por_subcadena(lineas, cantidad_lineas,
                                             "memoria", &cantidad_filtradas);
    ASSERT_PTR_NOT_NULL(filtradas);
    ASSERT_UINT_EQ(2U, cantidad_filtradas);
    ASSERT_STR_EQ("memoria dinamica\n", filtradas[0]);
    ASSERT_STR_EQ("memoria en heap\n", filtradas[1]);

    liberar_lineas_dinamicas(&filtradas, cantidad_filtradas);
    liberar_lineas_dinamicas(&lineas, cantidad_lineas);
    ASSERT_PTR_NULL(filtradas);
    ASSERT_PTR_NULL(lineas);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_pipeline_csv_numerico);
    RUN_TEST(prueba_filtro_sin_resultados);
    RUN_TEST(prueba_texto_multilinea);
    return TEST_REPORT();
}
