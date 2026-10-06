/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo_copia_todos)
{
    int origen[] = {7, -2, 0, 15, 3};
    int destino[5] = {0};
    copiar_arreglo(destino, origen, 5);
    ASSERT_ARRAY_INT_EQ(origen, destino, 5);
}

TEST(prueba_copiar_arreglo_retorna_true)
{
    int origen[] = {1, 2, 3};
    int destino[3] = {0};
    ASSERT_TRUE(copiar_arreglo(destino, origen, 3));
}

TEST(prueba_copiar_arreglo_destino_mayor)
{
    // Solo debe escribir 'cantidad' elementos y dejar el resto intacto.
    int origen[] = {4, 5};
    int destino[4] = {9, 9, 9, 9};
    int esperado[] = {4, 5, 9, 9};
    copiar_arreglo(destino, origen, 2);
    ASSERT_ARRAY_INT_EQ(esperado, destino, 4);
}

TEST(prueba_copiar_arreglo_cantidad_cero)
{
    int origen[] = {1};
    int destino[] = {8};
    copiar_arreglo(destino, origen, 0);
    ASSERT_INT_EQ(8, *destino);
}

TEST(prueba_copiar_arreglo_destino_nulo)
{
    int origen[] = {1, 2};
    ASSERT_FALSE(copiar_arreglo(NULL, origen, 2));
}

TEST(prueba_copiar_arreglo_origen_nulo)
{
    int destino[2] = {0};
    ASSERT_FALSE(copiar_arreglo(destino, NULL, 2));
}

TEST(prueba_invertir_arreglo_par)
{
    int datos[] = {1, 2, 3, 4};
    int esperado[] = {4, 3, 2, 1};
    invertir_arreglo(datos, 4);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 4);
}

TEST(prueba_invertir_arreglo_impar)
{
    int datos[] = {10, 20, 30, 40, 50};
    int esperado[] = {50, 40, 30, 20, 10};
    invertir_arreglo(datos, 5);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 5);
}

TEST(prueba_invertir_arreglo_un_elemento)
{
    int datos[] = {42};
    invertir_arreglo(datos, 1);
    ASSERT_INT_EQ(42, *datos);
}

TEST(prueba_invertir_arreglo_dos_veces)
{
    int datos[] = {3, -1, 8};
    int esperado[] = {3, -1, 8};
    invertir_arreglo(datos, 3);
    invertir_arreglo(datos, 3);
    ASSERT_ARRAY_INT_EQ(esperado, datos, 3);
}

TEST(prueba_invertir_arreglo_nulo)
{
    // No debe romper: con NULL la función no hace nada.
    invertir_arreglo(NULL, 5);
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);
    RUN_TEST(prueba_copiar_arreglo_copia_todos);
    RUN_TEST(prueba_copiar_arreglo_retorna_true);
    RUN_TEST(prueba_copiar_arreglo_destino_mayor);
    RUN_TEST(prueba_copiar_arreglo_cantidad_cero);
    RUN_TEST(prueba_copiar_arreglo_destino_nulo);
    RUN_TEST(prueba_copiar_arreglo_origen_nulo);
    RUN_TEST(prueba_invertir_arreglo_par);
    RUN_TEST(prueba_invertir_arreglo_impar);
    RUN_TEST(prueba_invertir_arreglo_un_elemento);
    RUN_TEST(prueba_invertir_arreglo_dos_veces);
    RUN_TEST(prueba_invertir_arreglo_nulo);
    return TEST_REPORT();
}
