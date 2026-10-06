/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    SUBCASE("Encuentra valor presente");
    int datos[] = {5, 10, 15, 20};

    const int *resultado = buscar_primero(datos, 4, 15);

    ASSERT_TRUE(resultado != NULL);
    ASSERT_INT_EQ(15, *resultado);

    SUBCASE("Encuentra la primera ocurrencia");
    int repetidos[] = {7, 3, 7, 7};

    const int *primero = buscar_primero(repetidos, 4, 7);

    ASSERT_TRUE(primero != NULL);
    ASSERT_TRUE(primero == repetidos);
    ASSERT_INT_EQ(7, *primero);

    SUBCASE("Valor inexistente");
    int otros[] = {1, 2, 3};

    ASSERT_TRUE(buscar_primero(otros, 3, 99) == NULL);

    SUBCASE("Cantidad cero");
    int unico[] = {42};

    ASSERT_TRUE(buscar_primero(unico, 0, 42) == NULL);

    SUBCASE("Arreglo nulo");
    ASSERT_TRUE(buscar_primero(NULL, 3, 10) == NULL);
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("Distancia de elemento interno");
    int datos[] = {10, 20, 30, 40, 50};

    ASSERT_INT_EQ(3, (int)distancia_punteros(datos, datos + 3));

    SUBCASE("Distancia al primer elemento");
    ASSERT_INT_EQ(0, (int)distancia_punteros(datos, datos));

    SUBCASE("Elemento antes del inicio");
    ASSERT_INT_EQ(-1, (int)distancia_punteros(datos + 2, datos + 1));

    SUBCASE("Inicio nulo");
    ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, datos));

    SUBCASE("Elemento nulo");
    ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, NULL));
}

TEST(prueba_busqueda_y_distancia)
{
    SUBCASE("Busqueda seguida de calculo de distancia");
    int datos[] = {12, 24, 36, 48};

    const int *resultado = buscar_primero(datos, 4, 36);

    ASSERT_TRUE(resultado != NULL);
    ASSERT_INT_EQ(2, (int)distancia_punteros(datos, resultado));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    RUN_TEST(prueba_busqueda_y_distancia);
    return TEST_REPORT();
}
