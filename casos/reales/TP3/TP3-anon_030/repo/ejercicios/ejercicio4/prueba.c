/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    int arreglo[] = {10, 20, 30, 40, 50};

    const int *resultado = buscar_primero(arreglo, 5, 30);

    ASSERT_TRUE(resultado != NULL);
    ASSERT_INT_EQ(30, *resultado);
}

TEST(prueba_buscar_primera_aparicion)
{
    int arreglo[] = {10, 20, 30, 20, 40};

    const int *resultado = buscar_primero(arreglo, 5, 20);

    ASSERT_TRUE(resultado == arreglo + 1);
}

TEST(prueba_valor_no_encontrado)
{
    int arreglo[] = {10, 20, 30};

    const int *resultado = buscar_primero(arreglo, 3, 100);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_buscar_null)
{
    const int *resultado = buscar_primero(NULL, 5, 10);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_cantidad_cero)
{
    int arreglo[] = {10, 20, 30};

    const int *resultado = buscar_primero(arreglo, 0, 10);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_distancia_punteros)
{
    int arreglo[] = {10, 20, 30, 40, 50};

    ptrdiff_t distancia = distancia_punteros(arreglo, arreglo + 3);

    ASSERT_INT_EQ(3, distancia);
}

TEST(prueba_distancia_inicio)
{
    int arreglo[] = {10, 20, 30};

    ptrdiff_t distancia = distancia_punteros(arreglo, arreglo);

    ASSERT_INT_EQ(0, distancia);
}

TEST(prueba_distancia_null)
{
    int arreglo[] = {10, 20, 30};

    ASSERT_INT_EQ(-1, distancia_punteros(NULL, arreglo));
    ASSERT_INT_EQ(-1, distancia_punteros(arreglo, NULL));
}

TEST(prueba_elemento_antes_inicio)
{
    int arreglo[] = {10, 20, 30, 40};

    const int *inicio = arreglo + 2;
    const int *elemento = arreglo + 1;

    ASSERT_INT_EQ(-1, distancia_punteros(inicio, elemento));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 4",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_buscar_primera_aparicion);
    RUN_TEST(prueba_valor_no_encontrado);
    RUN_TEST(prueba_buscar_null);
    RUN_TEST(prueba_cantidad_cero);
    RUN_TEST(prueba_distancia_punteros);
    RUN_TEST(prueba_distancia_inicio);
    RUN_TEST(prueba_distancia_null);
    RUN_TEST(prueba_elemento_antes_inicio);

    return TEST_REPORT();
}