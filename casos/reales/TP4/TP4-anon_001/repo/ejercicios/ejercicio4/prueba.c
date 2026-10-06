/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include "matriz_dinamica.h"
#include "p1_test.h"
#include <stdio.h>

TEST(test_crear_dimensiones_invalidas)
{
    ASSERT_TRUE(matriz_crear(0, 5) == NULL);
    ASSERT_TRUE(matriz_crear(5, 0) == NULL);
    ASSERT_TRUE(matriz_crear(0, 0) == NULL);
}

TEST(test_crear_y_modificar_matriz_valida)
{
    size_t filas = 2;
    size_t columnas = 3;
    int **matriz = matriz_crear(filas, columnas);

    // 1. Verificar que no devolvió NULL.
    ASSERT_TRUE(matriz != NULL);
    ASSERT_TRUE(matriz[0] != NULL);
    ASSERT_TRUE(matriz[1] != NULL);

    // 2 Verificar que el bloque sea contiguo (Flecha 1 debe estar a 'columnas'
    // enteros de Flecha 0)
    ASSERT_TRUE(matriz[1] == matriz[0] + columnas);

    // 3. Probar escritura y lectura de celdas.
    matriz[0][0] = 10;
    matriz[1][2] = 60;
    ASSERT_TRUE(matriz[0][0] == 10);
    ASSERT_TRUE(matriz[1][2] == 60);

    matriz_destruir(matriz);
}

TEST(test_destruir_matriz_null)
{

    matriz_destruir(NULL);
    ASSERT_TRUE(true);
}

TEST(test_cargar_csv_inexistente)
{
    size_t f = 0, c = 0;
    int **matriz = matriz_cargar_desde_csv("no_existe.csv", &f, &c);
    ASSERT_TRUE(matriz == NULL);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);

    RUN_TEST(test_crear_dimensiones_invalidas);
    RUN_TEST(test_crear_y_modificar_matriz_valida);
    RUN_TEST(test_destruir_matriz_null);
    RUN_TEST(test_cargar_csv_inexistente);

    return TEST_REPORT();
}
