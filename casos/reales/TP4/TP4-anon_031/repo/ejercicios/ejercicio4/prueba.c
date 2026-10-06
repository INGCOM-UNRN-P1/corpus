/**
 * @file prueba.c
 * @brief Pruebas unitarias del Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear_y_destruir)
{
    int **matriz = matriz_crear(2U, 3U);

    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_PTR_NOT_NULL(matriz[0]);
    ASSERT_TRUE(matriz[1] == matriz[0] + 3);
    ASSERT_INT_EQ(0, matriz[0][0]);
    ASSERT_INT_EQ(0, matriz[1][2]);

    matriz[0][1] = 7;
    matriz[1][2] = 15;
    ASSERT_INT_EQ(7, matriz[0][1]);
    ASSERT_INT_EQ(15, matriz[1][2]);

    matriz_destruir(matriz);

    ASSERT_PTR_NULL(matriz_crear(0U, 3U));
    ASSERT_PTR_NULL(matriz_crear(2U, 0U));
}

TEST(prueba_matriz_plana)
{
    int *matriz = crear_matriz_plana(3U, 2U);

    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(0, obtener_celda(matriz, 2U, 2U, 1U));

    asignar_celda(matriz, 2U, 0U, 1U, 4);
    asignar_celda(matriz, 2U, 2U, 1U, 9);
    ASSERT_INT_EQ(4, obtener_celda(matriz, 2U, 0U, 1U));
    ASSERT_INT_EQ(9, obtener_celda(matriz, 2U, 2U, 1U));

    liberar_matriz_plana(matriz);
    ASSERT_PTR_NULL(crear_matriz_plana(0U, 2U));
}

TEST(prueba_matriz_cargar_desde_csv)
{
    const char *ruta = "matriz_prueba.csv";
    FILE *archivo = fopen(ruta, "w");
    size_t filas = 0U;
    size_t columnas = 0U;
    int **matriz = NULL;

    ASSERT_PTR_NOT_NULL(archivo);
    if (archivo != NULL)
    {
        fputs("1,2,3\n4,5,6\n7,8,9\n", archivo);
        fclose(archivo);
    }

    matriz = matriz_cargar_desde_csv(ruta, &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_UINT_EQ(3U, filas);
    ASSERT_UINT_EQ(3U, columnas);
    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(6, matriz[1][2]);
    ASSERT_INT_EQ(8, matriz[2][1]);

    matriz_destruir(matriz);
    remove(ruta);

    SUBCASE("Archivo inexistente");
    matriz = matriz_cargar_desde_csv("archivo_que_no_existe.csv", &filas, &columnas);
    ASSERT_PTR_NULL(matriz);
    ASSERT_UINT_EQ(0U, filas);
    ASSERT_UINT_EQ(0U, columnas);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_y_destruir);
    RUN_TEST(prueba_matriz_plana);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}
