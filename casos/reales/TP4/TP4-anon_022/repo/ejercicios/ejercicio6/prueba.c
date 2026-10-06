/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>

#include "p1_test.h"
#include "consulta_csv.h"


TEST(prueba_cargar_csv)
{
    FILE *archivo = fopen("prueba_datos.csv", "w");

    fprintf(archivo, "10,20,30\n");
    fprintf(archivo, "40,50,60\n");

    fclose(archivo);

    size_t filas = 0;
    size_t columnas = 0;

    int *matriz =
        cargar_csv("prueba_datos.csv", &filas, &columnas);

    int esperado[] = {
        10, 20, 30,
        40, 50, 60
    };

    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(3, columnas);
    ASSERT_ARRAY_INT_EQ(esperado, matriz, 6);

    liberar_matriz(&matriz);
    remove("prueba_datos.csv");
}


TEST(prueba_filtrar_filas)
{
    int matriz[] = {
        10, 20, 30,
        40, 50, 60,
        70, 15, 80
    };

    size_t filas_resultado = 0;

    int *resultado =
        filtrar_filas(
            matriz,
            3,
            3,
            1,
            20,
            &filas_resultado
        );

    int esperado[] = {
        40, 50, 60
    };

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_UINT_EQ(1, filas_resultado);
    ASSERT_ARRAY_INT_EQ(esperado, resultado, 3);

    liberar_matriz(&resultado);
}


TEST(prueba_calcular_sumas_columnas)
{
    int matriz[] = {
        10, 20, 30,
        40, 50, 60
    };

    float *sumas =
        calcular_sumas_columnas(matriz, 2, 3);

    ASSERT_PTR_NOT_NULL(sumas);

    ASSERT_DOUBLE_EQ(50.0, sumas[0], 0.001);
    ASSERT_DOUBLE_EQ(70.0, sumas[1], 0.001);
    ASSERT_DOUBLE_EQ(90.0, sumas[2], 0.001);

    free(sumas);
}


TEST(prueba_calcular_promedios_columnas)
{
    int matriz[] = {
        10, 20, 30,
        40, 50, 60
    };

    float *promedios =
        calcular_promedios_columnas(matriz, 2, 3);

    ASSERT_PTR_NOT_NULL(promedios);

    ASSERT_DOUBLE_EQ(25.0, promedios[0], 0.001);
    ASSERT_DOUBLE_EQ(35.0, promedios[1], 0.001);
    ASSERT_DOUBLE_EQ(45.0, promedios[2], 0.001);

    free(promedios);
}


TEST(prueba_exportar_csv)
{
    int matriz[] = {
        10, 20,
        30, 40
    };

    bool resultado =
        exportar_csv(
            "prueba_salida.csv",
            matriz,
            2,
            2
        );

    ASSERT_TRUE(resultado);

    size_t filas = 0;
    size_t columnas = 0;

    int *matriz_leida =
        cargar_csv(
            "prueba_salida.csv",
            &filas,
            &columnas
        );

    ASSERT_PTR_NOT_NULL(matriz_leida);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(2, columnas);
    ASSERT_ARRAY_INT_EQ(matriz, matriz_leida, 4);

    liberar_matriz(&matriz_leida);
    remove("prueba_salida.csv");
}


TEST(prueba_liberar_matriz)
{
    int *matriz = malloc(4 * sizeof(int));

    ASSERT_PTR_NOT_NULL(matriz);

    liberar_matriz(&matriz);

    ASSERT_PTR_NULL(matriz);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 6",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_cargar_csv);
    RUN_TEST(prueba_filtrar_filas);
    RUN_TEST(prueba_calcular_sumas_columnas);
    RUN_TEST(prueba_calcular_promedios_columnas);
    RUN_TEST(prueba_exportar_csv);
    RUN_TEST(prueba_liberar_matriz);

    return TEST_REPORT();
}