/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include "p1_test.h"
#include <stdio.h>

TEST(prueba_crear_matriz_plana)
{
    int *matriz = crear_matriz_plana(2, 3);

    ASSERT_TRUE(matriz != NULL);

    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 0), 0);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 1), 0);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 2), 0);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 0), 0);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 1), 0);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 2), 0);

    liberar_matriz_plana(matriz);
}

TEST(prueba_crear_matriz_dimensiones_invalidas)
{
    int *matriz = NULL;

    matriz = crear_matriz_plana(0, 3);
    ASSERT_TRUE(matriz == NULL);

    matriz = crear_matriz_plana(3, 0);
    ASSERT_TRUE(matriz == NULL);

    matriz = crear_matriz_plana(0, 0);
    ASSERT_TRUE(matriz == NULL);
}

TEST(prueba_asignar_y_obtener_celda)
{
    int *matriz = crear_matriz_plana(3, 4);

    ASSERT_TRUE(matriz != NULL);

    asignar_celda(matriz, 4, 0, 0, 10);
    asignar_celda(matriz, 4, 1, 2, 25);
    asignar_celda(matriz, 4, 2, 3, -7);

    ASSERT_INT_EQ(obtener_celda(matriz, 4, 0, 0), 10);
    ASSERT_INT_EQ(obtener_celda(matriz, 4, 1, 2), 25);
    ASSERT_INT_EQ(obtener_celda(matriz, 4, 2, 3), -7);

    liberar_matriz_plana(matriz);
}

TEST(prueba_asignar_y_obtener_matriz_completa)
{
    int *matriz = crear_matriz_plana(2, 3);

    ASSERT_TRUE(matriz != NULL);

    asignar_celda(matriz, 3, 0, 0, 1);
    asignar_celda(matriz, 3, 0, 1, 2);
    asignar_celda(matriz, 3, 0, 2, 3);
    asignar_celda(matriz, 3, 1, 0, 4);
    asignar_celda(matriz, 3, 1, 1, 5);
    asignar_celda(matriz, 3, 1, 2, 6);

    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 0), 1);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 1), 2);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 0, 2), 3);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 0), 4);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 1), 5);
    ASSERT_INT_EQ(obtener_celda(matriz, 3, 1, 2), 6);

    liberar_matriz_plana(matriz);
}

TEST(prueba_funciones_con_puntero_nulo)
{
    ASSERT_INT_EQ(obtener_celda(NULL, 3, 0, 0), 0);

    asignar_celda(NULL, 3, 0, 0, 10);

    liberar_matriz_plana(NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);

    RUN_TEST(prueba_crear_matriz_plana);
    RUN_TEST(prueba_crear_matriz_dimensiones_invalidas);
    RUN_TEST(prueba_asignar_y_obtener_celda);
    RUN_TEST(prueba_asignar_y_obtener_matriz_completa);
    RUN_TEST(prueba_funciones_con_puntero_nulo);

    return TEST_REPORT();
}
