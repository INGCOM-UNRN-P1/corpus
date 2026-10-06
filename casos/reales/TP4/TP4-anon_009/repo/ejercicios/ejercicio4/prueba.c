/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

TEST(prueba_matriz_crear_y_destruir)
{
    size_t filas = 2;
    size_t columnas = 3;
    int **matriz = matriz_crear(filas, columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    if (matriz != NULL)
    {
        ASSERT_PTR_NOT_NULL(*matriz);
        int *fila_0 = *matriz;
        int *fila_1 = *(matriz + 1);
        ASSERT_PTR_EQ(fila_1, fila_0 + columnas);
        matriz_destruir(matriz);
    }
    ASSERT_PTR_NULL(matriz_crear(0, 5));
    ASSERT_PTR_NULL(matriz_crear(5, 0));    
}

TEST(prueba_matriz_csv_invalido)
{
    size_t f = 0, c = 0;
    int **matriz = matriz_cargar_desde_csv("archivo_inexistente.csv", &f, &c);
    ASSERT_PTR_NULL(matriz);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_y_destruir);
    RUN_TEST(prueba_matriz_csv_invalido);
    return TEST_REPORT();
}
