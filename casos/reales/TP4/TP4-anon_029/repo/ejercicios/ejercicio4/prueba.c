/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include "p1_test.h"
#include <stdio.h>

TEST(prueba_matriz_crear)
{
    SUBCASE("Matriz valida");
    int **matriz = matriz_crear(2, 2);
    ASSERT_PTR_NOT_NULL(matriz);
    // valor de las celdas de la matriz:
    *(*(matriz + 0) + 0) = 10;
    *(*(matriz + 0) + 1) = 20;
    *(*(matriz + 1) + 0) = 30;
    *(*(matriz + 1) + 1) = 40;
    // Guardo los valores en variables
    int celda_00 = *(*(matriz + 0) + 0);
    int celda_01 = *(*(matriz + 0) + 1);
    int celda_10 = *(*(matriz + 1) + 0);
    int celda_11 = *(*(matriz + 1) + 1);
    // Asserts
    ASSERT_INT_EQ(10, celda_00);
    ASSERT_INT_EQ(20, celda_01);
    ASSERT_INT_EQ(30, celda_10);
    ASSERT_INT_EQ(40, celda_11);

    matriz_destruir(matriz);
    matriz = NULL;

    SUBCASE("Fallo por no filas y/o columnas");
    int **matriz_falla_00 = matriz_crear(0, 0);
    ASSERT_PTR_NULL(matriz_falla_00);
    int **matriz_falla_01 = matriz_crear(2, 0);
    ASSERT_PTR_NULL(matriz_falla_01);
    matriz_destruir(matriz_falla_01);
    matriz_falla_01 = NULL;
    int **matriz_falla_02 = matriz_crear(0, 2);
    ASSERT_PTR_NULL(matriz_falla_02);
    matriz_destruir(matriz_falla_02);
    matriz_falla_02 = NULL;
}
TEST(prueba_matriz_cargar_desde_csv)
{
    size_t filas = 0;
    size_t columnas = 0;
    SUBCASE("Caso valido");
    int **matriz_archivo =
        matriz_cargar_desde_csv("matriz.csv", &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz_archivo);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(2, (int)columnas);

    // Guardo los valores esperado en variables
    int esperado_00 = 10;
    int esperado_01 = 20;
    int esperado_10 = 30;
    int esperado_11 = 40;
    // guardo lso valors obtenidos en variables
    int obtenido_00 = *(*(matriz_archivo + 0) + 0);
    int obtenido_01 = *(*(matriz_archivo + 0) + 1);
    int obtenido_10 = *(*(matriz_archivo + 1) + 0);
    int obtenido_11 = *(*(matriz_archivo + 1) + 1);
    // Asserts
    ASSERT_INT_EQ(esperado_00, obtenido_00);
    ASSERT_INT_EQ(esperado_01, obtenido_01);
    ASSERT_INT_EQ(esperado_10, obtenido_10);
    ASSERT_INT_EQ(esperado_11, obtenido_11);

    matriz_destruir(matriz_archivo);
    matriz_archivo = NULL;

    SUBCASE("Fallo por no filas y/o columnas");
    int **matriz_falla_00 = matriz_cargar_desde_csv("matriz.csv", 0, 0);
    ASSERT_PTR_NULL(matriz_falla_00);
    int **matriz_falla_01 = matriz_cargar_desde_csv("matriz.csv", 2, 0);
    ASSERT_PTR_NULL(matriz_falla_01);
    matriz_destruir(matriz_falla_01);
    matriz_falla_01 = NULL;
    int **matriz_falla_02 = matriz_cargar_desde_csv("matriz.csv", 0, 2);
    ASSERT_PTR_NULL(matriz_falla_02);
    matriz_destruir(matriz_falla_02);
    matriz_falla_02 = NULL;

    SUBCASE("Fallo por archivo NULL");
    int **matriz_falla_03 = matriz_cargar_desde_csv(NULL, 2, 2);
    ASSERT_PTR_NULL(matriz_falla_03);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);
    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}
