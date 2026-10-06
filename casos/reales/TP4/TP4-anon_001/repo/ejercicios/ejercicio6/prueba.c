/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 */

#include "consulta_csv.h"
#include "p1_test.h"
#include <stdio.h>

// Función auxiliar para liberar las matrices creadas dinámicamente durante los
// tests
static void liberar_matriz_test(int **matriz, size_t filas)
{
    if (matriz == NULL)
    {
        return;
    }
    size_t i = 0;
    while (i < filas)
    {
        free(matriz[i]);
        i++;
    }
    free(matriz);
}

TEST(test_filtrar_parametros_invalidos)
{
    size_t filas_filtradas = 99;

    ASSERT_TRUE(matriz_filtrar_por_columna(NULL, 3, 3, 0, 10,
                                           &filas_filtradas) == NULL);
    ASSERT_TRUE(filas_filtradas == 0);

    int r0[] = {10, 20};
    int *matriz[] = {r0};

    // Indice de columna fuera de rango
    ASSERT_TRUE(matriz_filtrar_por_columna(matriz, 1, 2, 5, 10,
                                           &filas_filtradas) == NULL);
    ASSERT_TRUE(filas_filtradas == 0);
}

TEST(test_filtrar_sin_coincidencias)
{
    int r0[] = {10, 20};
    int r1[] = {5, 15};
    int *matriz[] = {r0, r1};
    size_t filas_filtradas = 99;

    // Ningun valor en columna 0 supera 100
    int **resultado =
        matriz_filtrar_por_columna(matriz, 2, 2, 0, 100, &filas_filtradas);

    ASSERT_TRUE(resultado == NULL);
    ASSERT_TRUE(filas_filtradas == 0);
}

TEST(test_filtrar_y_promedios)
{
    int r0[] = {10, 20, 30};
    int r1[] = {5, 50, 15};
    int r2[] = {40, 10, 60};
    int *matriz[] = {r0, r1, r2};
    size_t filas_filtradas = 0;

    // Filtrar por columna 0 con umbral > 8 (pasan fila 0 y fila 2)
    int **filtrada =
        matriz_filtrar_por_columna(matriz, 3, 3, 0, 8, &filas_filtradas);

    ASSERT_TRUE(filtrada != NULL);
    ASSERT_TRUE(filas_filtradas == 2);
    ASSERT_TRUE(filtrada[0][0] == 10 && filtrada[0][1] == 20 &&
                filtrada[0][2] == 30);
    ASSERT_TRUE(filtrada[1][0] == 40 && filtrada[1][1] == 10 &&
                filtrada[1][2] == 60);

    // Calculo de promedios sobre la matriz filtrada
    float *promedios = matriz_calcular_promedios(filtrada, filas_filtradas, 3);
    ASSERT_TRUE(promedios != NULL);
    ASSERT_TRUE(promedios[0] == 25.0f); // (10 + 40) / 2
    ASSERT_TRUE(promedios[1] == 15.0f); // (20 + 10) / 2
    ASSERT_TRUE(promedios[2] == 45.0f); // (30 + 60) / 2

    free(promedios);
    liberar_matriz_test(filtrada, filas_filtradas);
}

TEST(test_exportar_csv)
{
    int r0[] = {10, 20};
    int r1[] = {30, 40};
    int *matriz[] = {r0, r1};

    // Exportacion exitosa
    ASSERT_TRUE(matriz_exportar_csv("test_salida.csv", matriz, 2, 2) == true);

    // Parametros invalidos
    ASSERT_TRUE(matriz_exportar_csv(NULL, matriz, 2, 2) == false);
    ASSERT_TRUE(matriz_exportar_csv("test_salida.csv", NULL, 2, 2) == false);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args,
                          argumentos);

    RUN_TEST(test_filtrar_parametros_invalidos);
    RUN_TEST(test_filtrar_sin_coincidencias);
    RUN_TEST(test_filtrar_y_promedios);
    RUN_TEST(test_exportar_csv);

    return TEST_REPORT();
}
