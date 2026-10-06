/**
 * @file prueba.c
 * @brief Pruebas unitarias de libpunteros con el framework p1_test.
 *
 * Trabajo Práctico 3 - Programación 1 - UNRN
 */

#include "p1_test.h"
#include "punteros.h"
#include <stdio.h>

TEST(prueba_intercambiar)
{
    SUBCASE("Intercambio estandar de enteros");
    int x = 42;
    int y = 99;
    intercambiar(&x, &y);
    ASSERT_INT_EQ(99, x);
    ASSERT_INT_EQ(42, y);

    SUBCASE("Intercambio con valores negativos");
    int a = -15;
    int b = 30;
    intercambiar(&a, &b);
    ASSERT_INT_EQ(30, a);
    ASSERT_INT_EQ(-15, b);

    SUBCASE("Intercambio con misma direccion");
    int n = 7;
    intercambiar(&n, &n);
    ASSERT_INT_EQ(7, n);

    SUBCASE("Punteros nulos no deben provocar fallo");
    int val = 10;
    intercambiar(NULL, &val);
    ASSERT_INT_EQ(10, val);
    intercambiar(&val, NULL);
    ASSERT_INT_EQ(10, val);
    intercambiar(NULL, NULL);
}

TEST(prueba_obtener_min_max)
{
    SUBCASE("Arreglo valido estandar");
    int datos[] = {14, -3, 8, 25, 0, -10, 4};
    int min_val = 0;
    int max_val = 0;
    ASSERT_TRUE(obtener_min_max(datos, 7, &min_val, &max_val));
    ASSERT_INT_EQ(-10, min_val);
    ASSERT_INT_EQ(25, max_val);

    SUBCASE("Arreglo con un unico elemento");
    int unico[] = {42};
    int min_u = 0;
    int max_u = 0;
    ASSERT_TRUE(obtener_min_max(unico, 1, &min_u, &max_u));
    ASSERT_INT_EQ(42, min_u);
    ASSERT_INT_EQ(42, max_u);

    SUBCASE("Casos de error y punteros nulos");
    int min_err = 0;
    int max_err = 0;
    int datos_err[] = {1, 2, 3};
    ASSERT_FALSE(obtener_min_max(NULL, 3, &min_err, &max_err));
    ASSERT_FALSE(obtener_min_max(datos_err, 0, &min_err, &max_err));
    ASSERT_FALSE(obtener_min_max(datos_err, 3, NULL, &max_err));
    ASSERT_FALSE(obtener_min_max(datos_err, 3, &min_err, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libpunteros", conteo_args,
                          argumentos);
    RUN_TEST(prueba_intercambiar);
    RUN_TEST(prueba_obtener_min_max);
    return TEST_REPORT();
}
