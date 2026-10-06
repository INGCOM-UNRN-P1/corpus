/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

#define RUTA_ENTRADA "consulta_csv_entrada_tmp.csv"
#define RUTA_SALIDA "consulta_csv_salida_tmp.csv"

static void preparar_csv(const char *ruta, const char *contenido)
{
    FILE *archivo = fopen(ruta, "w");
    if (archivo != NULL)
    {
        fprintf(archivo, "%s", contenido);
        fclose(archivo);
    }
}

TEST(prueba_cargar_matriz_csv)
{
    SUBCASE("Carga de matriz correcta");
    size_t filas = 0U;
    size_t columnas = 0U;
    int **matriz = NULL;

    preparar_csv(RUTA_ENTRADA, "1,2,3\n4,5,6\n7,8,9\n");
    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(9, matriz[2][2]);
    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cargar_matriz_csv(NULL, &filas, &columnas));
    ASSERT_PTR_NULL(cargar_matriz_csv(RUTA_ENTRADA, NULL, &columnas));
    ASSERT_PTR_NULL(cargar_matriz_csv(RUTA_ENTRADA, &filas, NULL));
}

TEST(prueba_filtrar_matriz_por_columna)
{
    SUBCASE("Filtro con resultados");
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t filas_filtradas = 0U;
    int **matriz = NULL;
    int **filtrada = NULL;

    preparar_csv(RUTA_ENTRADA, "1,2,3\n4,5,6\n7,8,9\n");
    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);

    filtrada = filtrar_matriz_por_columna((const int *)matriz[0], filas,
                                          columnas, 2U, 5, &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(2, (int)filas_filtradas);
    ASSERT_INT_EQ(6, filtrada[0][2]);
    ASSERT_INT_EQ(9, filtrada[1][2]);

    liberar_matriz_int(filtrada, filas_filtradas);
    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);

    SUBCASE("Filtro sin resultados");
    preparar_csv(RUTA_ENTRADA, "1,2,3\n4,5,6\n");
    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    filtrada = filtrar_matriz_por_columna((const int *)matriz[0], filas,
                                          columnas, 2U, 100, &filas_filtradas);
    ASSERT_PTR_NULL(filtrada);
    ASSERT_INT_EQ(0, (int)filas_filtradas);
    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);

    SUBCASE("Casos invalidos");
    ASSERT_PTR_NULL(filtrar_matriz_por_columna(NULL, 3, 3, 0U, 0,
                                               &filas_filtradas));
}

TEST(prueba_estadisticas_columnas)
{
    SUBCASE("Promedio de columnas");
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t cantidad = 0U;
    int **matriz = NULL;
    float *promedios = NULL;

    preparar_csv(RUTA_ENTRADA, "1,2,3\n4,5,6\n7,8,9\n");
    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);

    promedios = estadisticas_columnas((const int *)matriz[0], filas, columnas,
                                      &cantidad);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_INT_EQ(4, (int)promedios[0]);
    ASSERT_INT_EQ(5, (int)promedios[1]);
    ASSERT_INT_EQ(6, (int)promedios[2]);

    free(promedios);
    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);

    SUBCASE("Casos invalidos");
    ASSERT_PTR_NULL(estadisticas_columnas(NULL, 3, 3, &cantidad));
    ASSERT_PTR_NULL(estadisticas_columnas(NULL, 0, 3, &cantidad));
}

TEST(prueba_exportar_matriz_csv)
{
    SUBCASE("Exportacion y relectura");
    size_t filas = 0U;
    size_t columnas = 0U;
    size_t filas_releidas = 0U;
    size_t columnas_releidas = 0U;
    int **matriz = NULL;
    int **releida = NULL;
    int resultado = 0;

    preparar_csv(RUTA_ENTRADA, "1,2,3\n4,5,6\n");
    matriz = cargar_matriz_csv(RUTA_ENTRADA, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);

    resultado = exportar_matriz_csv(RUTA_SALIDA, (const int *)matriz[0],
                                    filas, columnas);
    ASSERT_INT_EQ(0, resultado);

    releida = cargar_matriz_csv(RUTA_SALIDA, &filas_releidas,
                                &columnas_releidas);
    ASSERT_PTR_NOT_NULL(releida);
    ASSERT_INT_EQ((int)filas, (int)filas_releidas);
    ASSERT_INT_EQ((int)columnas, (int)columnas_releidas);
    ASSERT_INT_EQ(1, releida[0][0]);
    ASSERT_INT_EQ(6, releida[1][2]);

    liberar_matriz_int(releida, filas_releidas);
    liberar_matriz_int(matriz, filas);
    remove(RUTA_ENTRADA);
    remove(RUTA_SALIDA);

    SUBCASE("Argumentos invalidos");
    ASSERT_INT_EQ(1, exportar_matriz_csv(NULL, NULL, 0U, 0U));
    ASSERT_INT_EQ(1, exportar_matriz_csv("/ruta/inexistente/x.csv", NULL,
                                         0U, 0U));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);
    RUN_TEST(prueba_cargar_matriz_csv);
    RUN_TEST(prueba_filtrar_matriz_por_columna);
    RUN_TEST(prueba_estadisticas_columnas);
    RUN_TEST(prueba_exportar_matriz_csv);
    return TEST_REPORT();
}