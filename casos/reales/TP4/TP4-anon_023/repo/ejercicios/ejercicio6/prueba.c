/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

TEST(test_pipeline_crear_y_destruir)
{
    int **m = crear_matriz_contigua(4, 5);
    ASSERT_TRUE(m != NULL);
    ASSERT_TRUE(*m != NULL);

    destruir_matriz_contigua(&m);
    ASSERT_TRUE(m == NULL);
}

TEST(test_pipeline_filtrado_filas)
{
    int **m = crear_matriz_contigua(3, 2);
    ASSERT_TRUE(m != NULL);

    
    *(*(m + 0) + 0) = 10;
    *(*(m + 0) + 1) = 50;
    
    *(*(m + 1) + 0) = 20;
    *(*(m + 1) + 1) = 10;
    
    *(*(m + 2) + 0) = 30;
    *(*(m + 2) + 1) = 80;

    size_t filas_res = 0;
    
    int **filtrada = filtrar_filas_matriz(m, 3, 2, 1, 40, &filas_res);

    ASSERT_TRUE(filtrada != NULL);
    ASSERT_TRUE(filas_res == 2);
    ASSERT_TRUE(*(*(filtrada + 0) + 0) == 10);
    ASSERT_TRUE(*(*(filtrada + 1) + 0) == 30);

    destruir_matriz_contigua(&m);
    destruir_matriz_contigua(&filtrada);
}

TEST(test_pipeline_promedios_columnas)
{
    int **m = crear_matriz_contigua(2, 2);
    *(*(m + 0) + 0) = 10;
    *(*(m + 0) + 1) = 20;
    *(*(m + 1) + 0) = 30;
    *(*(m + 1) + 1) = 40;

    float *prom = calcular_promedios_columnas(m, 2, 2);
    ASSERT_TRUE(prom != NULL);
    ASSERT_TRUE(*(prom + 0) == 20.0f);
    ASSERT_TRUE(*(prom + 1) == 30.0f);

    liberar_arreglo_floats(&prom);
    ASSERT_TRUE(prom == NULL);
    destruir_matriz_contigua(&m);
}

TEST(test_pipeline_exportar_y_cargar_csv)
{
    const char *csv_temp = "test_export.csv";
    int **m = crear_matriz_contigua(2, 3);
    *(*(m + 0) + 0) = 1;
    *(*(m + 0) + 1) = 2;
    *(*(m + 0) + 2) = 3;
    *(*(m + 1) + 0) = 4;
    *(*(m + 1) + 1) = 5;
    *(*(m + 1) + 2) = 6;

    bool export_ok = exportar_matriz_csv(csv_temp, m, 2, 3);
    ASSERT_TRUE(export_ok);

    size_t f = 0, c = 0;
    int **leida = cargar_matriz_csv(csv_temp, &f, &c);
    ASSERT_TRUE(leida != NULL);
    ASSERT_TRUE(f == 2);
    ASSERT_TRUE(c == 3);
    ASSERT_TRUE(*(*(leida + 1) + 1) == 5);

    destruir_matriz_contigua(&m);
    destruir_matriz_contigua(&leida);
    remove(csv_temp);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(test_pipeline_crear_y_destruir);
    RUN_TEST(test_pipeline_filtrado_filas);
    RUN_TEST(test_pipeline_promedios_columnas);
    RUN_TEST(test_pipeline_exportar_y_cargar_csv);
    return TEST_REPORT();
}
