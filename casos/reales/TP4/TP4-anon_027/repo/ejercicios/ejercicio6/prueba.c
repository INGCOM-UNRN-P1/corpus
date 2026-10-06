/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "consulta_csv.h"

TEST(prueba_pipeline_matricial)
{
    SUBCASE("Reserva, filtrado y promedios en memoria");
    size_t filas = 4;
    size_t cols = 3;
    int **mat = matriz_crear(filas, cols);
    ASSERT_PTR_NOT_NULL(mat);
    // Cargar matriz ficticia
    // Fila 0: [10, 20, 30]
    // Fila 1: [ 5, 50, 15]
    // Fila 2: [12, 10, 20]
    // Fila 3: [ 2, 80, 40]
    mat[0][0] = 10; mat[0][1] = 20; mat[0][2] = 30;
    mat[1][0] = 5;  mat[1][1] = 50; mat[1][2] = 15;
    mat[2][0] = 12; mat[2][1] = 10; mat[2][2] = 20;
    mat[3][0] = 2;  mat[3][1] = 80; mat[3][2] = 40;
    // Validar promedios
    float *proms = matriz_calcular_promedios_columnas(mat, filas, cols);
    ASSERT_PTR_NOT_NULL(proms);
    ASSERT_INT_EQ(7, (int)proms[0]);   // (10+5+12+2)/4 = 7.25 -> int 7
    ASSERT_INT_EQ(40, (int)proms[1]);  // (20+50+10+80)/4 = 40.0
    free(proms);
    // Filtrar columna 1 con umbral > 25 (deberian quedar filas 1 y 3)
    size_t filt_filas = 0;
    int **filtrada = matriz_filtrar_por_columna(mat, filas, cols, 1, 25, &filt_filas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(2, (int)filt_filas);
    ASSERT_INT_EQ(5, filtrada[0][0]);   // Fila 1 original
    ASSERT_INT_EQ(2, filtrada[1][0]);   // Fila 3 original
    // Liberacion limpia
    matriz_liberar(&mat, filas);
    matriz_liberar(&filtrada, filt_filas);
    ASSERT_PTR_NULL(mat);
    ASSERT_PTR_NULL(filtrada);

    
    SUBCASE("Exportacion y Carga CSV integra");
    const char *archivo_tmp = "test_temp.csv";
    size_t filas_2 = 2, cols_2 = 2;
    int **mat_2 = matriz_crear(filas_2, cols_2);
    mat_2[0][0] = 100; mat_2[0][1] = 200;
    mat_2[1][0] = 300; mat_2[1][1] = 400;
    int res_exp = matriz_exportar_csv(archivo_tmp, mat_2, filas_2, cols_2, ',');
    ASSERT_INT_EQ(0, res_exp);
    size_t c_filas = 0, c_cols = 0;
    int **cargada = matriz_cargar_desde_csv(archivo_tmp, ',', &c_filas, &c_cols);
    ASSERT_PTR_NOT_NULL(cargada);
    ASSERT_INT_EQ(2, (int)c_filas);
    ASSERT_INT_EQ(2, (int)c_cols);
    ASSERT_INT_EQ(100, cargada[0][0]);
    ASSERT_INT_EQ(400, cargada[1][1]);
    matriz_liberar(&mat_2, filas_2);
    matriz_liberar(&cargada, c_filas);
    remove(archivo_tmp);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_pipeline_matricial);
    return TEST_REPORT();
}
