/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    int arreglo[] = {5, 2, 8, 1, 4};

    const int *inicio = arreglo;
    const int *fin = arreglo + 5;

    const int *minimo = buscar_puntero_minimo(inicio, fin);

    ASSERT_TRUE(minimo != NULL);
    ASSERT_TRUE(*minimo == 1);
}

TEST(prueba_buscar_puntero_minimo_un_elemento)
{
    int arreglo[] = {7};

    const int *inicio = arreglo;
    const int *fin = arreglo + 1;

    const int *minimo = buscar_puntero_minimo(inicio, fin);

    ASSERT_TRUE(minimo != NULL);
    ASSERT_TRUE(*minimo == 7);
}

TEST(prueba_buscar_puntero_minimo_rango_vacio)
{
    int arreglo[] = {5, 2, 8};

    const int *minimo = buscar_puntero_minimo(arreglo, arreglo);

    ASSERT_TRUE(minimo == NULL);
}

TEST(prueba_buscar_puntero_minimo_nulo)
{
    const int *minimo = buscar_puntero_minimo(NULL, NULL);

    ASSERT_TRUE(minimo == NULL);
}

TEST(prueba_buscar_puntero_minimo_rango_parcial)
{
    int arreglo[] = {9, 7, 5, 3, 1, 8};

    const int *inicio = arreglo + 1;
    const int *fin = arreglo + 5;

    const int *minimo = buscar_puntero_minimo(inicio, fin);

    ASSERT_TRUE(minimo != NULL);
    ASSERT_TRUE(*minimo == 1);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    int arreglo[] = {5, 2, 8, 1, 4};

    bool resultado = ordenar_seleccion_punteros(arreglo, 5);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(arreglo[0] == 1);
    ASSERT_TRUE(arreglo[1] == 2);
    ASSERT_TRUE(arreglo[2] == 4);
    ASSERT_TRUE(arreglo[3] == 5);
    ASSERT_TRUE(arreglo[4] == 8);
}

TEST(prueba_ordenar_seleccion_punteros_ordenado)
{
    int arreglo[] = {1, 2, 3, 4, 5};

    bool resultado = ordenar_seleccion_punteros(arreglo, 5);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(arreglo[0] == 1);
    ASSERT_TRUE(arreglo[1] == 2);
    ASSERT_TRUE(arreglo[2] == 3);
    ASSERT_TRUE(arreglo[3] == 4);
    ASSERT_TRUE(arreglo[4] == 5);
}

TEST(prueba_ordenar_seleccion_punteros_inverso)
{
    int arreglo[] = {5, 4, 3, 2, 1};

    bool resultado = ordenar_seleccion_punteros(arreglo, 5);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(arreglo[0] == 1);
    ASSERT_TRUE(arreglo[1] == 2);
    ASSERT_TRUE(arreglo[2] == 3);
    ASSERT_TRUE(arreglo[3] == 4);
    ASSERT_TRUE(arreglo[4] == 5);
}

TEST(prueba_ordenar_seleccion_punteros_un_elemento)
{
    int arreglo[] = {7};

    bool resultado = ordenar_seleccion_punteros(arreglo, 1);

    ASSERT_TRUE(resultado);
    ASSERT_TRUE(arreglo[0] == 7);
}

TEST(prueba_ordenar_seleccion_punteros_vacio)
{
    bool resultado = ordenar_seleccion_punteros(NULL, 0);

    ASSERT_TRUE(resultado);
}

TEST(prueba_ordenar_seleccion_punteros_nulo)
{
    bool resultado = ordenar_seleccion_punteros(NULL, 5);

    ASSERT_TRUE(!resultado);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);

    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_buscar_puntero_minimo_un_elemento);
    RUN_TEST(prueba_buscar_puntero_minimo_rango_vacio);
    RUN_TEST(prueba_buscar_puntero_minimo_nulo);
    RUN_TEST(prueba_buscar_puntero_minimo_rango_parcial);

    RUN_TEST(prueba_ordenar_seleccion_punteros);
    RUN_TEST(prueba_ordenar_seleccion_punteros_ordenado);
    RUN_TEST(prueba_ordenar_seleccion_punteros_inverso);
    RUN_TEST(prueba_ordenar_seleccion_punteros_un_elemento);
    RUN_TEST(prueba_ordenar_seleccion_punteros_vacio);
    RUN_TEST(prueba_ordenar_seleccion_punteros_nulo);

    return TEST_REPORT();
}