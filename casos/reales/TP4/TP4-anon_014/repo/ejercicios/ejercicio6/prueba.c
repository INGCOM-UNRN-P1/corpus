/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"

#define ARCHIVO_ENTRADA "prueba_ejercicio6_entrada.csv"
#define ARCHIVO_SALIDA "prueba_ejercicio6_salida.csv"
#define ARCHIVO_TEXTO "prueba_ejercicio6_texto.txt"

TEST(prueba_csv_cargar_matriz)
{
    SUBCASE("Carga de un CSV valido");
    FILE *archivo = fopen(ARCHIVO_ENTRADA, "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "3,2\n1,10\n2,20\n3,30\n");
    fclose(archivo);

    size_t filas = 0;
    size_t columnas = 0;
    int *m = csv_cargar_matriz(ARCHIVO_ENTRADA, &filas, &columnas);
    remove(ARCHIVO_ENTRADA);
    int esperado[] = {1, 10, 2, 20, 3, 30};
    ASSERT_UINT_EQ(3, filas);
    ASSERT_UINT_EQ(2, columnas);
    ASSERT_ARRAY_INT_EQ(esperado, m, 6);
    free(m);

    SUBCASE("Archivo inexistente");
    ASSERT_PTR_NULL(csv_cargar_matriz("no_existe.csv", &filas, &columnas));
}

TEST(prueba_csv_filtrar_filas)
{
    SUBCASE("Filas con columna 1 mayor a 15");
    int m[] = {1, 10, 2, 20, 3, 30};
    size_t filas_resultado = 0;
    int *filtrada = csv_filtrar_filas(m, 3, 2, 1, 15, &filas_resultado);
    int esperado[] = {2, 20, 3, 30};
    ASSERT_UINT_EQ(2, filas_resultado);
    ASSERT_ARRAY_INT_EQ(esperado, filtrada, 4);
    free(filtrada);

    SUBCASE("Ninguna fila cumple");
    ASSERT_PTR_NULL(csv_filtrar_filas(m, 3, 2, 1, 100, &filas_resultado));
    ASSERT_UINT_EQ(0, filas_resultado);

    SUBCASE("Columna fuera de rango");
    ASSERT_PTR_NULL(csv_filtrar_filas(m, 3, 2, 5, 0, &filas_resultado));
}

TEST(prueba_csv_estadisticas)
{
    SUBCASE("Sumas y promedios por columna");
    int m[] = {1, 10, 2, 20, 3, 31};
    float *sumas = csv_sumas_columnas(m, 3, 2);
    float *promedios = csv_promedios_columnas(m, 3, 2);
    ASSERT_DOUBLE_EQ(6.0, sumas[0], 0.0001);
    ASSERT_DOUBLE_EQ(61.0, sumas[1], 0.0001);
    ASSERT_DOUBLE_EQ(2.0, promedios[0], 0.0001);
    ASSERT_DOUBLE_NEAR_REL(20.3333, promedios[1], 0.001);
    free(promedios);
    free(sumas);

    SUBCASE("Sin filas no hay promedio");
    ASSERT_PTR_NULL(csv_promedios_columnas(m, 0, 2));
}

TEST(prueba_csv_exportar_y_recargar)
{
    SUBCASE("Lo exportado se vuelve a cargar igual");
    int m[] = {5, -6, 7, 8};
    ASSERT_TRUE(csv_exportar_matriz(ARCHIVO_SALIDA, m, 2, 2));

    size_t filas = 0;
    size_t columnas = 0;
    int *recargada = csv_cargar_matriz(ARCHIVO_SALIDA, &filas, &columnas);
    remove(ARCHIVO_SALIDA);
    ASSERT_UINT_EQ(2, filas);
    ASSERT_UINT_EQ(2, columnas);
    ASSERT_ARRAY_INT_EQ(m, recargada, 4);
    free(recargada);
}

TEST(prueba_leer_y_filtrar_lineas)
{
    SUBCASE("Leer todas las lineas de un flujo");
    FILE *archivo = fopen(ARCHIVO_TEXTO, "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "error: disco\ninfo: ok\nerror: red\n");
    fclose(archivo);

    archivo = fopen(ARCHIVO_TEXTO, "r");
    ASSERT_PTR_NOT_NULL(archivo);
    size_t cantidad = 0;
    char **lineas = leer_lineas(archivo, &cantidad);
    fclose(archivo);
    remove(ARCHIVO_TEXTO);
    ASSERT_UINT_EQ(3, cantidad);
    ASSERT_STR_EQ("info: ok", lineas[1]);

    SUBCASE("Filtrar por subcadena");
    size_t cantidad_filtradas = 0;
    char **filtradas = filtrar_lineas(lineas, cantidad, "error",
                                      &cantidad_filtradas);
    ASSERT_UINT_EQ(2, cantidad_filtradas);
    ASSERT_STR_EQ("error: disco", filtradas[0]);
    ASSERT_STR_EQ("error: red", filtradas[1]);

    SUBCASE("Liberacion deja los punteros en NULL");
    liberar_lineas(&filtradas, cantidad_filtradas);
    liberar_lineas(&lineas, cantidad);
    ASSERT_PTR_NULL(filtradas);
    ASSERT_PTR_NULL(lineas);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_csv_cargar_matriz);
    RUN_TEST(prueba_csv_filtrar_filas);
    RUN_TEST(prueba_csv_estadisticas);
    RUN_TEST(prueba_csv_exportar_y_recargar);
    RUN_TEST(prueba_leer_y_filtrar_lineas);
    return TEST_REPORT();
}
