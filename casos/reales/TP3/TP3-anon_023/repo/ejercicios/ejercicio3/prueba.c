/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    SUBCASE("Copia arreglo valido");
    {
        int origen[] = {10, 20, 30, 40};
        int destino[4] = {0};

        ASSERT_TRUE(copiar_arreglo(destino, origen, 4));
        ASSERT_INT_EQ(10, *(destino + 0));
        ASSERT_INT_EQ(20, *(destino + 1));
        ASSERT_INT_EQ(30, *(destino + 2));
        ASSERT_INT_EQ(40, *(destino + 3));
    }

    SUBCASE("Copia cantidad cero");
    {
        int origen[] = {5, 6};
        int destino[2] = {99, 99};

        ASSERT_TRUE(copiar_arreglo(destino, origen, 0));
        ASSERT_INT_EQ(99, *(destino + 0));
        ASSERT_INT_EQ(99, *(destino + 1));
    }

    SUBCASE("Punteros nulos con cantidad mayor a cero");
    {
        int arr[2] = {1, 2};

        ASSERT_FALSE(copiar_arreglo(NULL, arr, 2));
        ASSERT_FALSE(copiar_arreglo(arr, NULL, 2));
        ASSERT_FALSE(copiar_arreglo(NULL, NULL, 2));
    }
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Inversion arreglo cantidad par");
    {
        int arr[] = {1, 2, 3, 4};

        ASSERT_TRUE(invertir_arreglo(arr, 4));
        ASSERT_INT_EQ(4, *(arr + 0));
        ASSERT_INT_EQ(3, *(arr + 1));
        ASSERT_INT_EQ(2, *(arr + 2));
        ASSERT_INT_EQ(1, *(arr + 3));
    }

    SUBCASE("Inversion arreglo cantidad impar");
    {
        int arr[] = {10, 20, 30};

        ASSERT_TRUE(invertir_arreglo(arr, 3));
        ASSERT_INT_EQ(30, *(arr + 0));
        ASSERT_INT_EQ(20, *(arr + 1));
        ASSERT_INT_EQ(10, *(arr + 2));
    }

    SUBCASE("Inversion arreglo un solo elemento o vacio");
    {
        int unico[] = {42};

        ASSERT_TRUE(invertir_arreglo(unico, 1));
        ASSERT_INT_EQ(42, *(unico + 0));

        ASSERT_TRUE(invertir_arreglo(unico, 0));
    }

    SUBCASE("Puntero nulo con cantidad mayor a cero");
    {
        ASSERT_FALSE(invertir_arreglo(NULL, 5));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3 (Copia e Inversion)", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}