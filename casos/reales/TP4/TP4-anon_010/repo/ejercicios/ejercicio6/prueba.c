/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "consulta_csv.h"
 
TEST(prueba_cargar_y_filtrar)
{
    SUBCASE("Carga de CSV y filtrado por columna");
    FILE *archivo = fopen("consulta_prueba.csv", "w");
    ASSERT_PTR_NOT_NULL(archivo);
    fprintf(archivo, "1,10\n2,20\n3,30\n");
    fclose(archivo);
 
    size_t filas = 0;
    size_t columnas = 0;
    int *matriz = cargar_matriz_csv("consulta_prueba.csv", &filas, &columnas);
    ASSERT_PTR_NOT_NULL(matriz);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(2, (int)columnas);
    ASSERT_INT_EQ(30, matriz[5]);
 
    size_t filas_filtradas = 0;
    int *filtrada = filtrar_filas_mayores(matriz, filas, columnas, 1, 15, &filas_filtradas);
    ASSERT_PTR_NOT_NULL(filtrada);
    ASSERT_INT_EQ(2, (int)filas_filtradas);
    ASSERT_INT_EQ(2, filtrada[0]);
    ASSERT_INT_EQ(30, filtrada[3]);
    free(filtrada);
 
    SUBCASE("Sin coincidencias o archivo inexistente");
    ASSERT_PTR_NULL(filtrar_filas_mayores(matriz, filas, columnas, 1, 100, &filas_filtradas));
    ASSERT_INT_EQ(0, (int)filas_filtradas);
    ASSERT_PTR_NULL(cargar_matriz_csv("no_existe.csv", &filas, &columnas));
    free(matriz);
    remove("consulta_prueba.csv");
}
 
TEST(prueba_estadisticas_columnas)
{
    SUBCASE("Sumas y promedios por columna");
    int datos[] = {1, 10, 3, 20};
    float *sumas = sumar_columnas(datos, 2, 2);
    float *promedios = promediar_columnas(datos, 2, 2);
    ASSERT_PTR_NOT_NULL(sumas);
    ASSERT_PTR_NOT_NULL(promedios);
    ASSERT_TRUE(sumas[0] == 4.0f && sumas[1] == 30.0f);
    ASSERT_TRUE(promedios[0] == 2.0f && promedios[1] == 15.0f);
    free(sumas);
    free(promedios);
}
 
TEST(prueba_exportar_matriz_csv)
{
    SUBCASE("Exportar y volver a cargar");
    int datos[] = {1, -2, 3, 4};
    ASSERT_TRUE(exportar_matriz_csv(datos, 2, 2, "consulta_salida.csv"));
 
    size_t filas = 0;
    size_t columnas = 0;
    int *releida = cargar_matriz_csv("consulta_salida.csv", &filas, &columnas);
    ASSERT_PTR_NOT_NULL(releida);
    ASSERT_INT_EQ(2, (int)filas);
    ASSERT_INT_EQ(-2, releida[1]);
    ASSERT_INT_EQ(4, releida[3]);
    free(releida);
    remove("consulta_salida.csv");
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_cargar_y_filtrar);
    RUN_TEST(prueba_estadisticas_columnas);
    RUN_TEST(prueba_exportar_matriz_csv);
    return TEST_REPORT();
}
