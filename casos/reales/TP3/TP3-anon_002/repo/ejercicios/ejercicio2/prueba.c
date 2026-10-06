/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "estadistica.h"


bool calcular_estadisticas(const int *arreglo, size_t cantidad, int *minimo, int *maximo, double *promedio);
bool contar_en_rango(const int *arreglo, size_t cantidad, int limite_inf, int limite_sup, size_t *coincidencias);

TEST(prueba_calcular_estadisticas)
{
    SUBCASE("Estadisticas de arreglo valido");
    int datos[] = {10, 20, 30, 40};
    int min_val = 0;
    int max_val = 0;
    double prom = 0.0;
    ASSERT_TRUE(calcular_estadisticas(datos, 4, &min_val, &max_val, &prom));
    ASSERT_INT_EQ(10, min_val);
    ASSERT_INT_EQ(40, max_val);
    ASSERT_DOUBLE_EQ(25.0, prom, 0.001);

    SUBCASE("Parametros invalidos o nulos");
    int min_err = 0;
    int max_err = 0;
    double prom_err = 0.0;
    int datos_err[] = {1, 2};
    ASSERT_FALSE(calcular_estadisticas(NULL, 2, &min_err, &max_err, &prom_err));
    ASSERT_FALSE(calcular_estadisticas(datos_err, 0, &min_err, &max_err, &prom_err));
    ASSERT_FALSE(calcular_estadisticas(datos_err, 2, NULL, &max_err, &prom_err));
    ASSERT_FALSE(calcular_estadisticas(datos_err, 2, &min_err, NULL, &prom_err));
    ASSERT_FALSE(calcular_estadisticas(datos_err, 2, &min_err, &max_err, NULL));
}

TEST(prueba_contar_en_rango)
{
    SUBCASE("Conteo con elementos dentro de rango");
    int datos[] = {5, 12, 18, 25, 30, 42};
    size_t total = 0;
    ASSERT_TRUE(contar_en_rango(datos, 6, 10, 30, &total));
    ASSERT_INT_EQ(4, (int)total);

    SUBCASE("Conteo sin coincidencias");
    size_t ninguna = 99;
    ASSERT_TRUE(contar_en_rango(datos, 6, 50, 100, &ninguna));
    ASSERT_INT_EQ(0, (int)ninguna);

    SUBCASE("Parametros invalidos");
    size_t err_count = 0;
    ASSERT_FALSE(contar_en_rango(NULL, 6, 10, 30, &err_count));
    ASSERT_FALSE(contar_en_rango(datos, 6, 10, 30, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2 (Estadísticas)", conteo_args, argumentos);
    RUN_TEST(prueba_calcular_estadisticas);
    RUN_TEST(prueba_contar_en_rango);
    return TEST_REPORT();
}
