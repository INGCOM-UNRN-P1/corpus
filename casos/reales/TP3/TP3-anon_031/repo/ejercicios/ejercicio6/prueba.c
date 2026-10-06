/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    SUBCASE("Minimo en posicion intermedia");
    int datos[] = {8, 3, 5, 1, 9};

    const int *minimo = buscar_puntero_minimo(datos, datos + 5);

    ASSERT_TRUE(minimo != NULL);
    ASSERT_INT_EQ(1, *minimo);
    ASSERT_TRUE(minimo == datos + 3);

    SUBCASE("Minimo al inicio");
    int inicio_minimo[] = {1, 2, 3, 4};

    minimo = buscar_puntero_minimo(inicio_minimo, inicio_minimo + 4);

    ASSERT_TRUE(minimo == inicio_minimo);

    SUBCASE("Valores repetidos");
    int repetidos[] = {4, 2, 2, 8};

    minimo = buscar_puntero_minimo(repetidos, repetidos + 4);

    ASSERT_TRUE(minimo == repetidos + 1);
    ASSERT_INT_EQ(2, *minimo);

    SUBCASE("Rango vacio");
    int unico[] = {7};

    ASSERT_TRUE(buscar_puntero_minimo(unico, unico) == NULL);

    SUBCASE("Rango invalido");
    ASSERT_TRUE(buscar_puntero_minimo(unico + 1, unico) == NULL);

    SUBCASE("Punteros nulos");
    ASSERT_TRUE(buscar_puntero_minimo(NULL, unico + 1) == NULL);
    ASSERT_TRUE(buscar_puntero_minimo(unico, NULL) == NULL);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Arreglo desordenado");
    int datos[] = {64, 25, 12, 22, 11};

    ASSERT_TRUE(ordenar_seleccion_punteros(datos, 5));
    ASSERT_INT_EQ(11, *datos);
    ASSERT_INT_EQ(12, *(datos + 1));
    ASSERT_INT_EQ(22, *(datos + 2));
    ASSERT_INT_EQ(25, *(datos + 3));
    ASSERT_INT_EQ(64, *(datos + 4));

    SUBCASE("Arreglo ya ordenado");
    int ordenado[] = {1, 2, 3, 4};

    ASSERT_TRUE(ordenar_seleccion_punteros(ordenado, 4));
    ASSERT_INT_EQ(1, *ordenado);
    ASSERT_INT_EQ(2, *(ordenado + 1));
    ASSERT_INT_EQ(3, *(ordenado + 2));
    ASSERT_INT_EQ(4, *(ordenado + 3));

    SUBCASE("Arreglo en orden inverso");
    int inverso[] = {5, 4, 3, 2, 1};

    ASSERT_TRUE(ordenar_seleccion_punteros(inverso, 5));
    ASSERT_INT_EQ(1, *inverso);
    ASSERT_INT_EQ(2, *(inverso + 1));
    ASSERT_INT_EQ(3, *(inverso + 2));
    ASSERT_INT_EQ(4, *(inverso + 3));
    ASSERT_INT_EQ(5, *(inverso + 4));

    SUBCASE("Elementos repetidos");
    int repetidos[] = {3, 1, 3, 2, 1};

    ASSERT_TRUE(ordenar_seleccion_punteros(repetidos, 5));
    ASSERT_INT_EQ(1, *repetidos);
    ASSERT_INT_EQ(1, *(repetidos + 1));
    ASSERT_INT_EQ(2, *(repetidos + 2));
    ASSERT_INT_EQ(3, *(repetidos + 3));
    ASSERT_INT_EQ(3, *(repetidos + 4));

    SUBCASE("Un elemento");
    int unico[] = {42};

    ASSERT_TRUE(ordenar_seleccion_punteros(unico, 1));
    ASSERT_INT_EQ(42, *unico);

    SUBCASE("Cantidad cero");
    int sin_recorrido[] = {9};

    ASSERT_TRUE(ordenar_seleccion_punteros(sin_recorrido, 0));
    ASSERT_INT_EQ(9, *sin_recorrido);

    SUBCASE("Arreglo nulo");
    ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 5));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
