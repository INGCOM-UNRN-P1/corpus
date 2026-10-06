/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

#define ARCHIVO_TEMPORAL "prueba_ejercicio4.csv"

TEST(prueba_matriz_crear)
{
    SUBCASE("Matriz en cero con filas contiguas");
    int **matriz = matriz_crear(2, 3);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(0, matriz[1][2]);
    ASSERT_PTR_EQ(matriz[0] + 3, matriz[1]);
    matriz[1][2] = 7;
    ASSERT_INT_EQ(7, matriz[0][5]);
    matriz_destruir(matriz);
    matriz = NULL;

    SUBCASE("Dimensiones invalidas");
    ASSERT_PTR_NULL(matriz_crear(0, 3));
    ASSERT_PTR_NULL(matriz_crear(3, 0));
}

TEST(prueba_matriz_cargar_desde_csv)
{
    SUBCASE("Carga de un CSV valido");
    FILE *archivo = fopen(ARCHIVO_TEMPORAL, "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "2,3\n1,2,3\n4,5,6\n");
    fclose(archivo);

    size_t filas = 0;
    size_t columnas = 0;
    int **matriz = matriz_cargar_desde_csv(ARCHIVO_TEMPORAL, &filas,
                                           &columnas);
    remove(ARCHIVO_TEMPORAL);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(3, columnas);
    ASSERT_INT_EQ(3, matriz[0][2]);
    ASSERT_INT_EQ(4, matriz[1][0]);
    matriz_destruir(matriz);
    matriz = NULL;

    SUBCASE("Archivo inexistente");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("no_existe.csv", &filas,
                                            &columnas));
}

TEST(prueba_matriz_csv_incompleto)
{
    SUBCASE("Faltan valores respecto de las dimensiones");
    FILE *archivo = fopen(ARCHIVO_TEMPORAL, "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "2,2\n1,2\n3\n");
    fclose(archivo);

    size_t filas = 0;
    size_t columnas = 0;
    int **matriz = matriz_cargar_desde_csv(ARCHIVO_TEMPORAL, &filas,
                                           &columnas);
    remove(ARCHIVO_TEMPORAL);
    ASSERT_PTR_NULL(matriz);
}

TEST(prueba_matriz_plana)
{
    SUBCASE("Asignar y obtener celdas");
    int *m = crear_matriz_plana(3, 2);
    ASSERT_PTR_NOT_NULL(m);
    ASSERT_INT_EQ(0, obtener_celda(m, 2, 2, 1));
    ASSERT_TRUE(asignar_celda(m, 2, 2, 1, 42));
    ASSERT_INT_EQ(42, obtener_celda(m, 2, 2, 1));
    ASSERT_INT_EQ(42, m[2 * 2 + 1]);

    SUBCASE("Columna fuera de rango");
    ASSERT_FALSE(asignar_celda(m, 2, 0, 2, 1));
    liberar_matriz_plana(m);
    m = NULL;

    SUBCASE("Dimensiones invalidas");
    ASSERT_PTR_NULL(crear_matriz_plana(0, 5));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_crear);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    RUN_TEST(prueba_matriz_csv_incompleto);
    RUN_TEST(prueba_matriz_plana);
    return TEST_REPORT();
}
