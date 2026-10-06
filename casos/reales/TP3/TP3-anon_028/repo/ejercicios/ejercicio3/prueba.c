/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    int orig[5] = {10, 20, 30, 40, 50};
    int dest[5] = {0};

    ASSERT_TRUE(copiar_arreglo(orig, dest, 5));
    for(int i = 0; i <5; i++){
        ASSERT_INT_EQ(orig[i], dest[i]);
    }

    ASSERT_FALSE(copiar_arreglo(NULL, dest, 5));
    ASSERT_FALSE(copiar_arreglo(orig, NULL, 5));
}

TEST(prueba_invertir_arreglo)
{
    int arr[5] = {1, 2, 3, 4, 5};

    ASSERT_TRUE(invertir_arreglo(arr, 5));
    ASSERT_INT_EQ(5, arr[0]);
    ASSERT_INT_EQ(4, arr[1]);
    ASSERT_INT_EQ(3, arr[2]);
    ASSERT_INT_EQ(2, arr[3]);
    ASSERT_INT_EQ(1, arr[4]);

    int arr2[4] = {10, 20, 30, 40};
    ASSERT_TRUE(invertir_arreglo(arr2, 4));
    ASSERT_INT_EQ(40, arr2[0]);
    ASSERT_INT_EQ(30, arr2[1]);

    ASSERT_FALSE(invertir_arreglo(NULL, 5));

}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
