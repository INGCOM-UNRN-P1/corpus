
/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include <stdio.h>
#include "p1_test.h"
#include "consulta_csv.h"
#include "matriz_dinamica.h"


static int **crear_matriz_de_prueba(void)
{
    int **matriz = matriz_crear(3, 2);

    if (matriz != NULL)
    {
        matriz[0][0] = 1;
        matriz[0][1] = 5;
        matriz[1][0] = 2;
        matriz[1][1] = 8;
        matriz[2][0] = 3;
        matriz[2][1] = 2;
    }

    return matriz;
}

TEST(prueba_matriz_filtrar_por_columna)
{
    int **matriz = crear_matriz_de_prueba();
    size_t filas_filtradas = 0;

    SUBCASE("Filas de la columna 1 mayores que 4");
    int **filtrada = matriz_filtrar_por_columna(matriz, 3, 2, 1, 4,
                                                &filas_filtradas);
    ASSERT_TRUE(filtrada != NULL);
    ASSERT_INT_EQ(2, (int)filas_filtradas);
    ASSERT_INT_EQ(1, filtrada[0][0]);
    ASSERT_INT_EQ(8, filtrada[1][1]);
    matriz_destruir(filtrada);

    SUBCASE("Ninguna fila cumple");
    ASSERT_TRUE(matriz_filtrar_por_columna(matriz, 3, 2, 1, 100,
                                           &filas_filtradas) == NULL);
    ASSERT_INT_EQ(0, (int)filas_filtradas);

    SUBCASE("Columna fuera de rango o matriz NULL");
    ASSERT_TRUE(matriz_filtrar_por_columna(matriz, 3, 2, 5, 0,
                                           &filas_filtradas) == NULL);
    ASSERT_TRUE(matriz_filtrar_por_columna(NULL, 3, 2, 1, 0,
                                           &filas_filtradas) == NULL);

    matriz_destruir(matriz);
}

TEST(prueba_estadisticas_por_columna)
{
    int **matriz = crear_matriz_de_prueba();

    SUBCASE("Sumas y promedios");
    float *sumas = matriz_sumar_columnas(matriz, 3, 2);
    float *promedios = matriz_promediar_columnas(matriz, 3, 2);
    ASSERT_TRUE(sumas != NULL);
    ASSERT_TRUE(promedios != NULL);
    ASSERT_TRUE(sumas[0] == 6.0f);
    ASSERT_TRUE(sumas[1] == 15.0f);
    ASSERT_TRUE(promedios[0] == 2.0f);
    ASSERT_TRUE(promedios[1] == 5.0f);
    liberar_arreglo_floats(&sumas);
    liberar_arreglo_floats(&promedios);
    ASSERT_TRUE(sumas == NULL);

    SUBCASE("Matriz NULL o sin filas");
    ASSERT_TRUE(matriz_sumar_columnas(NULL, 3, 2) == NULL);
    ASSERT_TRUE(matriz_promediar_columnas(matriz, 0, 2) == NULL);

    matriz_destruir(matriz);
}

TEST(prueba_matriz_exportar_csv)
{
    int **matriz = crear_matriz_de_prueba();

    SUBCASE("Exportar y volver a cargar");
    bool exportada = matriz_exportar_csv("prueba_salida.csv", matriz, 3, 2);
    ASSERT_TRUE(exportada);
    size_t filas = 0;
    size_t columnas = 0;
    int **leida = matriz_cargar_desde_csv("prueba_salida.csv", &filas,
                                          &columnas);
    ASSERT_TRUE(leida != NULL);
    ASSERT_INT_EQ(3, (int)filas);
    ASSERT_INT_EQ(2, (int)columnas);
    ASSERT_INT_EQ(8, leida[1][1]);
    matriz_destruir(leida);
    remove("prueba_salida.csv");

    SUBCASE("Argumentos invalidos");
    ASSERT_TRUE(!matriz_exportar_csv(NULL, matriz, 3, 2));
    ASSERT_TRUE(!matriz_exportar_csv("prueba_salida.csv", NULL, 3, 2));

    matriz_destruir(matriz);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);
    RUN_TEST(prueba_matriz_filtrar_por_columna);
    RUN_TEST(prueba_estadisticas_por_columna);
    RUN_TEST(prueba_matriz_exportar_csv);
    return TEST_REPORT();
}