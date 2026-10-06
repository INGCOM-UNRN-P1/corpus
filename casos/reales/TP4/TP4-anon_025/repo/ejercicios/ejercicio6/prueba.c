/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "consulta_csv.h"
#include <stdlib.h>

TEST(prueba_pipeline_datos)
{
    
    FILE *f = fopen("dataset_mock.csv", "w");
    ASSERT_PTR_NOT_NULL(f);
    fprintf(f, "3,3\n");
    fprintf(f, "1,18,50,\n");
    fprintf(f, "2,20,90,\n");
    fprintf(f, "3,19,85,\n");
    fclose(f);

    size_t filas = 0, columnas = 0;
    int **matriz = matriz_cargar_csv("dataset_mock.csv", &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(3, (int)filas);
    size_t filas_filtradas = 0;
    int **filtrada = matriz_filtrar(matriz, filas, columnas, 2, 80, &filas_filtradas);
    ASSERT_INT_EQ(2, (int)filas_filtradas);
    float *promedios = matriz_promedio_columnas(filtrada, filas_filtradas, columnas);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_TRUE(promedios[1] > 19.4f && promedios[1] < 19.6f);
    bool exportado = matriz_exportar_csv(filtrada, filas_filtradas, columnas, "dataset_export.csv");
    ASSERT_TRUE(exportado);
    free(promedios);
    matriz_liberar(filtrada);
    matriz_liberar(matriz);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_pipeline_datos);
    return TEST_REPORT();
}
