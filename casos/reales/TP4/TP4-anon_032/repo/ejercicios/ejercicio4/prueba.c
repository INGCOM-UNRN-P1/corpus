/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_crear_liberar_matriz_plana)
{
    SUBCASE("Caso normal");
    int *matriz = crear_matriz_plana(3, 3);
    ASSERT_PTR_NOT_NULL(matriz);
    for (size_t i = 0; i < 9; i++)
    {
        ASSERT_INT_EQ(0, matriz[i]);
    }
    liberar_matriz_plana(&matriz);
    ASSERT_PTR_NULL(matriz);

    SUBCASE("Parametros invalidos");
    int *matriz_cero = crear_matriz_plana(0, 0);
    ASSERT_PTR_NULL(matriz_cero);
    
}

TEST(prueba_obtener_asignar_celda)
{
    int *matriz = crear_matriz_plana(3, 3);

    SUBCASE("Caso normal");
    asignar_celda(matriz, 3, 2, 2, 1);
    int valor = 0;
    obtener_celda(matriz, 3, 2, 2, &valor);
    ASSERT_INT_EQ(1, valor);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(asignar_celda(NULL, 3, 2, 2, 1));
    ASSERT_FALSE(obtener_celda(NULL, 3, 2, 2, &valor));
    ASSERT_FALSE(obtener_celda(matriz, 3, 2, 2, NULL));

    liberar_matriz_plana(&matriz);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_crear_liberar_matriz_plana);
    RUN_TEST(prueba_obtener_asignar_celda);
    return TEST_REPORT();
}
