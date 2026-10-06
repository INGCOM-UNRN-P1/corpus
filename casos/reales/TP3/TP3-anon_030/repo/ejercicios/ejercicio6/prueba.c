/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_minimo)
{
    int arreglo[] = {5, 2, 8, 1, 4};

    const int *minimo =
        buscar_puntero_minimo(arreglo, arreglo + 5);

    ASSERT_TRUE(minimo != NULL);
    ASSERT_INT_EQ(1, *minimo);
}

TEST(prueba_buscar_minimo_primero)
{
    int arreglo[] = {1, 2, 3, 4};

    const int *minimo =
        buscar_puntero_minimo(arreglo, arreglo + 4);

    ASSERT_TRUE(minimo == arreglo);
}

TEST(prueba_buscar_minimo_null)
{
    ASSERT_TRUE(buscar_puntero_minimo(NULL, NULL) == NULL);
}

TEST(prueba_buscar_rango_vacio)
{
    int arreglo[] = {1, 2, 3};

    ASSERT_TRUE(buscar_puntero_minimo(arreglo, arreglo) == NULL);
}

TEST(prueba_ordenar)
{
    int arreglo[] = {5, 2, 8, 1, 4};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 5));

    ASSERT_INT_EQ(1, *arreglo);
    ASSERT_INT_EQ(2, *(arreglo + 1));
    ASSERT_INT_EQ(4, *(arreglo + 2));
    ASSERT_INT_EQ(5, *(arreglo + 3));
    ASSERT_INT_EQ(8, *(arreglo + 4));
}

TEST(prueba_ordenar_ya_ordenado)
{
    int arreglo[] = {1, 2, 3, 4, 5};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 5));

    ASSERT_INT_EQ(1, *arreglo);
    ASSERT_INT_EQ(2, *(arreglo + 1));
    ASSERT_INT_EQ(3, *(arreglo + 2));
    ASSERT_INT_EQ(4, *(arreglo + 3));
    ASSERT_INT_EQ(5, *(arreglo + 4));
}

TEST(prueba_ordenar_inverso)
{
    int arreglo[] = {5, 4, 3, 2, 1};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 5));

    ASSERT_INT_EQ(1, *arreglo);
    ASSERT_INT_EQ(2, *(arreglo + 1));
    ASSERT_INT_EQ(3, *(arreglo + 2));
    ASSERT_INT_EQ(4, *(arreglo + 3));
    ASSERT_INT_EQ(5, *(arreglo + 4));
}

TEST(prueba_ordenar_repetidos)
{
    int arreglo[] = {3, 1, 3, 2, 1};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 5));

    ASSERT_INT_EQ(1, *arreglo);
    ASSERT_INT_EQ(1, *(arreglo + 1));
    ASSERT_INT_EQ(2, *(arreglo + 2));
    ASSERT_INT_EQ(3, *(arreglo + 3));
    ASSERT_INT_EQ(3, *(arreglo + 4));
}

TEST(prueba_ordenar_un_elemento)
{
    int arreglo[] = {10};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 1));
    ASSERT_INT_EQ(10, *arreglo);
}

TEST(prueba_ordenar_null)
{
    ASSERT_TRUE(!ordenar_seleccion_punteros(NULL, 5));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 6",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_buscar_minimo);
    RUN_TEST(prueba_buscar_minimo_primero);
    RUN_TEST(prueba_buscar_minimo_null);
    RUN_TEST(prueba_buscar_rango_vacio);
    RUN_TEST(prueba_ordenar);
    RUN_TEST(prueba_ordenar_ya_ordenado);
    RUN_TEST(prueba_ordenar_inverso);
    RUN_TEST(prueba_ordenar_repetidos);
    RUN_TEST(prueba_ordenar_un_elemento);
    RUN_TEST(prueba_ordenar_null);

    return TEST_REPORT();
}