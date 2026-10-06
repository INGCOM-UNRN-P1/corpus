/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    SUBCASE("Copia arreglo con varios elementos");
    int origen[] = {10, 20, 30, 40};
    int destino[] = {0, 0, 0, 0};

    ASSERT_TRUE(copiar_arreglo(origen, destino, 4));
    ASSERT_INT_EQ(10, *destino);
    ASSERT_INT_EQ(20, *(destino + 1));
    ASSERT_INT_EQ(30, *(destino + 2));
    ASSERT_INT_EQ(40, *(destino + 3));

    SUBCASE("Copia arreglo de un elemento");
    int origen_unico[] = {77};
    int destino_unico[] = {0};

    ASSERT_TRUE(copiar_arreglo(origen_unico, destino_unico, 1));
    ASSERT_INT_EQ(77, *destino_unico);

    SUBCASE("Cantidad cero");
    int origen_vacio[] = {5};
    int destino_vacio[] = {99};

    ASSERT_TRUE(copiar_arreglo(origen_vacio, destino_vacio, 0));
    ASSERT_INT_EQ(99, *destino_vacio);

    SUBCASE("Puntero origen nulo");
    int destino_valido[] = {1, 2};

    ASSERT_FALSE(copiar_arreglo(NULL, destino_valido, 2));
    ASSERT_INT_EQ(1, *destino_valido);
    ASSERT_INT_EQ(2, *(destino_valido + 1));

    SUBCASE("Puntero destino nulo");
    int origen_valido[] = {1, 2};

    ASSERT_FALSE(copiar_arreglo(origen_valido, NULL, 2));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Invierte cantidad par");
    int datos_pares[] = {1, 2, 3, 4};

    ASSERT_TRUE(invertir_arreglo(datos_pares, 4));
    ASSERT_INT_EQ(4, *datos_pares);
    ASSERT_INT_EQ(3, *(datos_pares + 1));
    ASSERT_INT_EQ(2, *(datos_pares + 2));
    ASSERT_INT_EQ(1, *(datos_pares + 3));

    SUBCASE("Invierte cantidad impar");
    int datos_impares[] = {1, 2, 3, 4, 5};

    ASSERT_TRUE(invertir_arreglo(datos_impares, 5));
    ASSERT_INT_EQ(5, *datos_impares);
    ASSERT_INT_EQ(4, *(datos_impares + 1));
    ASSERT_INT_EQ(3, *(datos_impares + 2));
    ASSERT_INT_EQ(2, *(datos_impares + 3));
    ASSERT_INT_EQ(1, *(datos_impares + 4));

    SUBCASE("Arreglo de un elemento");
    int unico[] = {42};

    ASSERT_TRUE(invertir_arreglo(unico, 1));
    ASSERT_INT_EQ(42, *unico);

    SUBCASE("Cantidad cero");
    int sin_recorrido[] = {8};

    ASSERT_TRUE(invertir_arreglo(sin_recorrido, 0));
    ASSERT_INT_EQ(8, *sin_recorrido);

    SUBCASE("Puntero nulo");
    ASSERT_FALSE(invertir_arreglo(NULL, 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
