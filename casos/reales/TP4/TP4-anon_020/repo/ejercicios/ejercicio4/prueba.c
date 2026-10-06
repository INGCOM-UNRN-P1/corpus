/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matriz_dinamica.h"

#define RUTA_PRUEBA "matriz_prueba_tmp.csv"

TEST(prueba_crear_y_acceder_matriz_plana)
{
    SUBCASE("Creacion, acceso y liberacion de matriz plana");
    int *matriz_plana = crear_matriz_plana(2, 3);
    ASSERT_PTR_NOT_NULL(matriz_plana);
    asignar_celda(matriz_plana, 3, 1, 2, 7);
    ASSERT_INT_EQ(7, obtener_celda(matriz_plana, 3, 1, 2));
    liberar_matriz_plana(matriz_plana);

    SUBCASE("Casos invalidos");
    ASSERT_PTR_NULL(crear_matriz_plana(0, 3));
    ASSERT_PTR_NULL(crear_matriz_plana(2, 0));
}

TEST(prueba_matriz_por_filas)
{
    SUBCASE("Creacion y destrucion de matriz por filas");
    int **matriz_por_filas = matriz_crear(2, 2);
    ASSERT_PTR_NOT_NULL(matriz_por_filas);
    matriz_por_filas[0][0] = 4;
    matriz_por_filas[1][1] = 9;
    ASSERT_INT_EQ(4, matriz_por_filas[0][0]);
    ASSERT_INT_EQ(9, matriz_por_filas[1][1]);
    matriz_destruir(matriz_por_filas, 2);

    SUBCASE("Casos invalidos");
    ASSERT_PTR_NULL(matriz_crear(0, 2));
    ASSERT_PTR_NULL(matriz_crear(2, 0));
}

TEST(prueba_matriz_cargar_desde_csv)
{
    SUBCASE("Carga correcta desde archivo CSV");
    FILE *archivo_csv = NULL;
    size_t filas_leidas = 0U;
    size_t columnas_leidas = 0U;
    int **matriz_cargada = NULL;

    archivo_csv = fopen(RUTA_PRUEBA, "w");
    ASSERT_PTR_NOT_NULL(archivo_csv);
    fprintf(archivo_csv, "1,2,3\n4,5,6\n");
    fclose(archivo_csv);

    matriz_cargada = matriz_cargar_desde_csv(RUTA_PRUEBA, &filas_leidas,
                                             &columnas_leidas);
    ASSERT_PTR_NOT_NULL(matriz_cargada);
    ASSERT_INT_EQ(2, (int)filas_leidas);
    ASSERT_INT_EQ(3, (int)columnas_leidas);
    ASSERT_INT_EQ(1, matriz_cargada[0][0]);
    ASSERT_INT_EQ(2, matriz_cargada[0][1]);
    ASSERT_INT_EQ(3, matriz_cargada[0][2]);
    ASSERT_INT_EQ(4, matriz_cargada[1][0]);
    ASSERT_INT_EQ(5, matriz_cargada[1][1]);
    ASSERT_INT_EQ(6, matriz_cargada[1][2]);

    matriz_destruir(matriz_cargada, filas_leidas);
    remove(RUTA_PRUEBA);

    SUBCASE("Ruta invalida");
    ASSERT_PTR_NULL(matriz_cargar_desde_csv(NULL, &filas_leidas,
                                            &columnas_leidas));
    ASSERT_PTR_NULL(matriz_cargar_desde_csv("/ruta/inexistente.csv",
                                            &filas_leidas,
                                            &columnas_leidas));

    SUBCASE("Fila con columnas inconsistentes");
    archivo_csv = fopen(RUTA_PRUEBA, "w");
    ASSERT_PTR_NOT_NULL(archivo_csv);
    fprintf(archivo_csv, "1,2,3\n4,5\n");
    fclose(archivo_csv);

    ASSERT_PTR_NULL(matriz_cargar_desde_csv(RUTA_PRUEBA, &filas_leidas,
                                            &columnas_leidas));
    remove(RUTA_PRUEBA);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args,
                          argumentos);
    RUN_TEST(prueba_crear_y_acceder_matriz_plana);
    RUN_TEST(prueba_matriz_por_filas);
    RUN_TEST(prueba_matriz_cargar_desde_csv);
    return TEST_REPORT();
}