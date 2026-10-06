/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(test_matriz_crear_y_contiguidad)
{
    size_t filas = 3;
    size_t columnas = 4;
    int **m = matriz_crear(filas, columnas);

    ASSERT_TRUE(m != NULL);
    ASSERT_TRUE(*m != NULL);

    
    ASSERT_TRUE(*(m + 1) == *m + columnas);
    ASSERT_TRUE(*(m + 2) == *m + (2 * columnas));

    
    ASSERT_TRUE(*(*(m + 0) + 0) == 0);
    ASSERT_TRUE(*(*(m + 2) + 3) == 0);

    matriz_destruir(&m);
    ASSERT_TRUE(m == NULL);
}

TEST(test_matriz_crear_parametros_invalidos)
{
    int **m1 = matriz_crear(0, 5);
    int **m2 = matriz_crear(5, 0);

    ASSERT_TRUE(m1 == NULL);
    ASSERT_TRUE(m2 == NULL);
}

TEST(test_matriz_lectura_escritura)
{
    size_t filas = 2;
    size_t columnas = 2;
    int **m = matriz_crear(filas, columnas);

    *(*(m + 0) + 0) = 10;
    *(*(m + 0) + 1) = 20;
    *(*(m + 1) + 0) = 30;
    *(*(m + 1) + 1) = 40;

    ASSERT_TRUE(*(*(m + 0) + 0) == 10);
    ASSERT_TRUE(*(*(m + 0) + 1) == 20);
    ASSERT_TRUE(*(*(m + 1) + 0) == 30);
    ASSERT_TRUE(*(*(m + 1) + 1) == 40);

    matriz_destruir(&m);
    ASSERT_TRUE(m == NULL);
}

TEST(test_matriz_csv_inexistente)
{
    size_t f = 0, c = 0;
    int **m = matriz_cargar_desde_csv("archivo_no_existente.csv", &f, &c);
    ASSERT_TRUE(m == NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(test_matriz_crear_y_contiguidad);
    RUN_TEST(test_matriz_crear_parametros_invalidos);
    RUN_TEST(test_matriz_lectura_escritura);
    RUN_TEST(test_matriz_csv_inexistente);
    return TEST_REPORT();
}
