/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

TEST(prueba_pipeline_completo)
{
    

    const char *nombre_csv = "test_pipeline.csv";
    FILE *f = fopen(nombre_csv, "w");
    ASSERT_PTR_NOT_NULL(f);
    fprintf(f, "10,100,5\n20,200,10\n30,300,15\n");
    fclose(f);

    size_t filas = 0, cols = 0;
    int **matriz = consulta_cargar_csv(nombre_csv, &filas, &cols);

    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(3, (int)cols);

    size_t filas_filtradas = 0;
    int **filtrada = consulta_filtrar_mayor(matriz, filas, cols, 1, 150, &filas_filtradas);

    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(2, (int)filas_filtradas);
    ASSERT_INT_EQ(20, filtrada[0][0]);
    ASSERT_INT_EQ(30, filtrada[1][0]);

    float *promedios = consulta_promedios_por_columna(matriz, filas, cols);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_INT_EQ(20, (int)promedios[0]);
    ASSERT_INT_EQ(200, (int)promedios[1]);

    free(promedios);
    consulta_liberar_matriz(filtrada);
    consulta_liberar_matriz(matriz);
    remove(nombre_csv);
}

TEST(prueba_parametros_invalidos)
{
    size_t f = 0, c = 0;
    ASSERT_PTR_NULL(consulta_cargar_csv(NULL, &f, &c));
    ASSERT_PTR_NULL(consulta_promedios_por_columna(NULL, 0, 0));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_pipeline_completo);
    RUN_TEST(prueba_parametros_invalidos);
    return TEST_REPORT();
}
