/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"
 
TEST(prueba_matriz_crear_destruir)
{
    SUBCASE("Matriz en cero con bloque contiguo");
    int **matriz = matriz_crear(2, 3);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(0, matriz[1][2]);
    ASSERT_TRUE(matriz[1] == matriz[0] + 3);
    matriz[1][2] = 7;
    ASSERT_INT_EQ(7, matriz[1][2]);
    matriz_destruir(matriz);
 
    SUBCASE("Dimensiones invalidas");
    ASSERT_PTR_NULL(matriz_crear(0, 3));
    ASSERT_PTR_NULL(matriz_crear(3, 0));
}
 
TEST(prueba_matriz_cargar_desde_csv)
{
    SUBCASE("Carga de un CSV valido");
    FILE *archivo = fopen("matriz_prueba.csv", "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "1,2,3\n4,-5,6\n");
    fclose(archivo);
 
    size_t filas = 0;
    size_t columnas = 0;
    int **matriz = matriz_cargar_desde_csv("matriz_prueba.csv", &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(3, (int)columnas);
    ASSERT_INT_EQ(1, matriz[0][0]);
    ASSERT_INT_EQ(-5, matriz[1][1]);
    matriz_destruir(matriz);
 
    SUBCASE("Archivo inexistente o con filas de distinto largo");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("no_existe.csv", &filas, &columnas));
    archivo = fopen("matriz_prueba.csv", "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "1,2\n3\n");
    fclose(archivo);
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("matriz_prueba.csv", &filas, &columnas));
    remove("matriz_prueba.csv");
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear_destruir);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}
