/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

TEST(prueba_pipeline_csv_dinamico)
{
    SUBCASE("Carga, filtrado y promedios");
    {
        FILE *f = fopen("test_ej6.csv", "w");
        if (f)
        {
            fputs("10,20\n30,40\n5,10\n", f);
            fclose(f);
        }

        size_t filas = 0, cols = 0;
        int **mat = csv_cargar_matriz("test_ej6.csv", &filas, &cols);
        ASSERT_PTR_NOT_NULL(mat);
        ASSERT_INT_EQ(3, (int)filas);
        ASSERT_INT_EQ(2, (int)cols);

        float *promedios = csv_calcular_promedios(mat, filas, cols);
        ASSERT_PTR_NOT_NULL(promedios);
        ASSERT_INT_EQ(15, (int)promedios[0]);
        ASSERT_INT_EQ(23, (int)promedios[1]); 
        free(promedios);

        size_t filas_filtro = 0;
        int **mat_f = csv_filtrar_filas(mat, filas, cols, 0, 15, &filas_filtro);
        ASSERT_PTR_NOT_NULL(mat_f);
        ASSERT_INT_EQ(1, (int)filas_filtro);
        ASSERT_INT_EQ(30, mat_f[0][0]);
        ASSERT_INT_EQ(40, mat_f[0][1]);

        csv_liberar_matriz(&mat_f, filas_filtro);
        csv_liberar_matriz(&mat, filas);
        
        remove("test_ej6.csv");
    }

    SUBCASE("Parametros invalidos y errores controlados");
    {
        size_t f = 0, c = 0, ff = 0;
        ASSERT_PTR_NULL(csv_cargar_matriz("no_existe.csv", &f, &c));
        ASSERT_PTR_NULL(csv_filtrar_filas(NULL, 10, 10, 0, 5, &ff));
        ASSERT_PTR_NULL(csv_calcular_promedios(NULL, 10, 10));
        ASSERT_FALSE(csv_exportar_matriz(NULL, NULL, 10, 10));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_pipeline_csv_dinamico);
    return TEST_REPORT();
}