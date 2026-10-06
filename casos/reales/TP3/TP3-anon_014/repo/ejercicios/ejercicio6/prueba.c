/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_minimo_en_el_medio)
{
    int datos[] = {9, 4, -2, 7};
    ASSERT_PTR_EQ(datos + 2, buscar_puntero_minimo(datos, datos + 4));
}

TEST(prueba_minimo_al_inicio)
{
    int datos[] = {-5, 4, 2, 7};
    ASSERT_PTR_EQ(datos, buscar_puntero_minimo(datos, datos + 4));
}

TEST(prueba_minimo_al_final)
{
    int datos[] = {5, 4, 2, 1};
    ASSERT_PTR_EQ(datos + 3, buscar_puntero_minimo(datos, datos + 4));
}

TEST(prueba_minimo_repetido_devuelve_primero)
{
    int datos[] = {3, 1, 8, 1};
    ASSERT_PTR_EQ(datos + 1, buscar_puntero_minimo(datos, datos + 4));
}

TEST(prueba_minimo_subrango)
{
    // El -9 queda fuera del rango [datos + 1, datos + 3).
    int datos[] = {-9, 6, 2, -1};
    ASSERT_PTR_EQ(datos + 2, buscar_puntero_minimo(datos + 1, datos + 3));
}

TEST(prueba_minimo_rango_vacio)
{
    int datos[] = {1, 2};
    ASSERT_PTR_NULL(buscar_puntero_minimo(datos, datos));
}

TEST(prueba_minimo_rango_invertido)
{
    int datos[] = {1, 2};
    ASSERT_PTR_NULL(buscar_puntero_minimo(datos + 2, datos));
}

TEST(prueba_minimo_inicio_nulo)
{
    int datos[] = {1, 2};
    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, datos + 2));
}

TEST(prueba_minimo_fin_nulo)
{
    int datos[] = {1, 2};
    ASSERT_PTR_NULL(buscar_puntero_minimo(datos, NULL));
}

TEST(prueba_ordenar_desordenado)
{
    int datos[] = {29, -4, 13, 0, 8};
    int esperado[] = {-4, 0, 8, 13, 29};
    ordenar_seleccion_punteros(datos, 5);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 5);
}

TEST(prueba_ordenar_ya_ordenado)
{
    int datos[] = {1, 2, 3, 4};
    int esperado[] = {1, 2, 3, 4};
    ordenar_seleccion_punteros(datos, 4);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 4);
}

TEST(prueba_ordenar_invertido)
{
    int datos[] = {5, 4, 3, 2, 1};
    int esperado[] = {1, 2, 3, 4, 5};
    ordenar_seleccion_punteros(datos, 5);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 5);
}

TEST(prueba_ordenar_con_repetidos)
{
    int datos[] = {3, 1, 3, 1, 2};
    int esperado[] = {1, 1, 2, 3, 3};
    ordenar_seleccion_punteros(datos, 5);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 5);
}

TEST(prueba_ordenar_un_elemento)
{
    int datos[] = {42};
    ordenar_seleccion_punteros(datos, 1);
    ASSERT_INT_EQ(42, *datos);
}

TEST(prueba_ordenar_cantidad_cero)
{
    int datos[] = {2, 1};
    int esperado[] = {2, 1};
    ordenar_seleccion_punteros(datos, 0);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 2);
}

TEST(prueba_ordenar_nulo)
{
    // No debe romper: con NULL la función no hace nada.
    ordenar_seleccion_punteros(NULL, 3);
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);
    RUN_TEST(prueba_minimo_en_el_medio);
    RUN_TEST(prueba_minimo_al_inicio);
    RUN_TEST(prueba_minimo_al_final);
    RUN_TEST(prueba_minimo_repetido_devuelve_primero);
    RUN_TEST(prueba_minimo_subrango);
    RUN_TEST(prueba_minimo_rango_vacio);
    RUN_TEST(prueba_minimo_rango_invertido);
    RUN_TEST(prueba_minimo_inicio_nulo);
    RUN_TEST(prueba_minimo_fin_nulo);
    RUN_TEST(prueba_ordenar_desordenado);
    RUN_TEST(prueba_ordenar_ya_ordenado);
    RUN_TEST(prueba_ordenar_invertido);
    RUN_TEST(prueba_ordenar_con_repetidos);
    RUN_TEST(prueba_ordenar_un_elemento);
    RUN_TEST(prueba_ordenar_cantidad_cero);
    RUN_TEST(prueba_ordenar_nulo);
    return TEST_REPORT();
}
