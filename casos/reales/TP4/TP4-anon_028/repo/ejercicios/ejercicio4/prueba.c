/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear_destruir)
{
    
    int **m = matriz_crear(2, 3);
    ASSERT_PTR_NOT_NULL(m);

    m[0][0] = 10;
    m[0][1] = 20;
    m[0][2] = 30;
    m[1][0] = 40;
    m[1][1] = 50;
    m[1][2] = 60;

    ASSERT_INT_EQ(10, m[0][0]);
    ASSERT_INT_EQ(60, m[1][2]);

    ASSERT_PTR_EQ(&m[0][3], &m[1][0]);

    matriz_destruir(m);
}

TEST(prueba_matriz_dimensiones_invalidas)
{
    int **m1 = matriz_crear(0, 5);
    ASSERT_PTR_NULL(m1);

    int **m2 = matriz_crear(5, 0);
    ASSERT_PTR_NULL(m2);
}

TEST(prueba_matriz_cargar_csv)
{
    const char *nombre_csv = "test_matriz.csv";
    FILE *f = fopen(nombre_csv, "w");
    ASSERT_PTR_NOT_NULL(f);
    fprintf(f, "1,2,3\n4,5,6\n7,8,9\n");
    fclose(f);

    size_t filas = 0, cols = 0;
    int **matriz = matriz_cargar_desde_csv(nombre_csv, &filas, &cols);

    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(3, (int)cols);

    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(5, matriz[1][1]);
    ASSERT_INT_EQ(9, matriz[2][2]);

    matriz_destruir(matriz);
    remove(nombre_csv);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_destruir);
    RUN_TEST(prueba_matriz_dimensiones_invalidas);
    RUN_TEST(prueba_matriz_cargar_csv);
    return TEST_REPORT();
}
