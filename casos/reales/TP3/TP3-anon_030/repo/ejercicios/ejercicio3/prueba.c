/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    int origen[] = {10, 20, 30, 40, 50};
    int destino[5];

    ASSERT_TRUE(copiar_arreglo(origen, destino, 5));

    ASSERT_INT_EQ(10, *destino);
    ASSERT_INT_EQ(20, *(destino + 1));
    ASSERT_INT_EQ(30, *(destino + 2));
    ASSERT_INT_EQ(40, *(destino + 3));
    ASSERT_INT_EQ(50, *(destino + 4));
}

TEST(prueba_copiar_un_elemento)
{
    int origen[] = {25};
    int destino[1];

    ASSERT_TRUE(copiar_arreglo(origen, destino, 1));
    ASSERT_INT_EQ(25, *destino);
}

TEST(prueba_copiar_null)
{
    int arreglo[] = {1, 2, 3};

    ASSERT_TRUE(!copiar_arreglo(NULL, arreglo, 3));
    ASSERT_TRUE(!copiar_arreglo(arreglo, NULL, 3));
}

TEST(prueba_invertir_impar)
{
    int arreglo[] = {1, 2, 3, 4, 5};

    ASSERT_TRUE(invertir_arreglo(arreglo, 5));

    ASSERT_INT_EQ(5, *arreglo);
    ASSERT_INT_EQ(4, *(arreglo + 1));
    ASSERT_INT_EQ(3, *(arreglo + 2));
    ASSERT_INT_EQ(2, *(arreglo + 3));
    ASSERT_INT_EQ(1, *(arreglo + 4));
}

TEST(prueba_invertir_par)
{
    int arreglo[] = {1, 2, 3, 4};

    ASSERT_TRUE(invertir_arreglo(arreglo, 4));

    ASSERT_INT_EQ(4, *arreglo);
    ASSERT_INT_EQ(3, *(arreglo + 1));
    ASSERT_INT_EQ(2, *(arreglo + 2));
    ASSERT_INT_EQ(1, *(arreglo + 3));
}

TEST(prueba_invertir_un_elemento)
{
    int arreglo[] = {7};

    ASSERT_TRUE(invertir_arreglo(arreglo, 1));
    ASSERT_INT_EQ(7, *arreglo);
}

TEST(prueba_invertir_null)
{
    ASSERT_TRUE(!invertir_arreglo(NULL, 5));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 3",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_copiar_un_elemento);
    RUN_TEST(prueba_copiar_null);
    RUN_TEST(prueba_invertir_impar);
    RUN_TEST(prueba_invertir_par);
    RUN_TEST(prueba_invertir_un_elemento);
    RUN_TEST(prueba_invertir_null);

    return TEST_REPORT();
}