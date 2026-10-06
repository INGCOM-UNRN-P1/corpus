/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero_en_el_medio)
{
    int datos[] = {5, 9, 13, 21};
    ASSERT_PTR_EQ(datos + 2, buscar_primero(datos, 4, 13));
}

TEST(prueba_buscar_primero_al_inicio)
{
    int datos[] = {5, 9, 13, 21};
    ASSERT_PTR_EQ(datos, buscar_primero(datos, 4, 5));
}

TEST(prueba_buscar_primero_al_final)
{
    int datos[] = {5, 9, 13, 21};
    ASSERT_PTR_EQ(datos + 3, buscar_primero(datos, 4, 21));
}

TEST(prueba_buscar_primero_repetido)
{
    // Con valores repetidos debe devolver la primera aparición.
    int datos[] = {4, 7, 1, 7, 7};
    ASSERT_PTR_EQ(datos + 1, buscar_primero(datos, 5, 7));
}

TEST(prueba_buscar_primero_no_existe)
{
    int datos[] = {1, 2, 3};
    ASSERT_PTR_NULL(buscar_primero(datos, 3, 99));
}

TEST(prueba_buscar_primero_cantidad_cero)
{
    int datos[] = {1};
    ASSERT_PTR_NULL(buscar_primero(datos, 0, 1));
}

TEST(prueba_buscar_primero_arreglo_nulo)
{
    ASSERT_PTR_NULL(buscar_primero(NULL, 3, 1));
}

TEST(prueba_distancia_punteros_mismo_elemento)
{
    int datos[] = {1, 2, 3};
    ASSERT_INT_EQ(0, (int)distancia_punteros(datos, datos));
}

TEST(prueba_distancia_punteros_elemento_interno)
{
    int datos[] = {1, 2, 3, 4, 5};
    ASSERT_INT_EQ(4, (int)distancia_punteros(datos, datos + 4));
}

TEST(prueba_distancia_punteros_con_busqueda)
{
    int datos[] = {10, 20, 30, 40};
    const int *encontrado = buscar_primero(datos, 4, 30);
    ASSERT_INT_EQ(2, (int)distancia_punteros(datos, encontrado));
}

TEST(prueba_distancia_punteros_elemento_antes)
{
    int datos[] = {1, 2, 3};
    ASSERT_INT_EQ(DISTANCIA_INVALIDA,
                  (int)distancia_punteros(datos + 2, datos));
}

TEST(prueba_distancia_punteros_inicio_nulo)
{
    int datos[] = {1, 2, 3};
    ASSERT_INT_EQ(DISTANCIA_INVALIDA, (int)distancia_punteros(NULL, datos));
}

TEST(prueba_distancia_punteros_elemento_nulo)
{
    // Caso típico: se pasa directo el resultado de una búsqueda fallida.
    int datos[] = {1, 2, 3};
    const int *encontrado = buscar_primero(datos, 3, 99);
    ASSERT_INT_EQ(DISTANCIA_INVALIDA,
                  (int)distancia_punteros(datos, encontrado));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);
    RUN_TEST(prueba_buscar_primero_en_el_medio);
    RUN_TEST(prueba_buscar_primero_al_inicio);
    RUN_TEST(prueba_buscar_primero_al_final);
    RUN_TEST(prueba_buscar_primero_repetido);
    RUN_TEST(prueba_buscar_primero_no_existe);
    RUN_TEST(prueba_buscar_primero_cantidad_cero);
    RUN_TEST(prueba_buscar_primero_arreglo_nulo);
    RUN_TEST(prueba_distancia_punteros_mismo_elemento);
    RUN_TEST(prueba_distancia_punteros_elemento_interno);
    RUN_TEST(prueba_distancia_punteros_con_busqueda);
    RUN_TEST(prueba_distancia_punteros_elemento_antes);
    RUN_TEST(prueba_distancia_punteros_inicio_nulo);
    RUN_TEST(prueba_distancia_punteros_elemento_nulo);
    return TEST_REPORT();
}
