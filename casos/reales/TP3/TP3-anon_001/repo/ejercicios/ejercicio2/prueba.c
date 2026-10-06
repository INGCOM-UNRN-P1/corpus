/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include "estadistica.h"
#include "p1_test.h"

TEST(probar_calcular_estadisticas) {
    int arr[] = {10, -2, 5, 20, 8};
    size_t cant = 5;
    int min = 0, max = 0;
    double prom = 0.0;

    // Caso exitoso
    ASSERT_TRUE(calcular_estadisticas(arr, cant, &min, &max, &prom) == 1);
    ASSERT_INT_EQ(min, -2);
    ASSERT_INT_EQ(max, 20);
    ASSERT_DOUBLE_NEAR_REL(prom, 8.2, 0.001);

    // Casos limite / NULL
    ASSERT_FALSE(calcular_estadisticas(arr, 0, &min, &max, &prom));
    ASSERT_FALSE(calcular_estadisticas(NULL, cant, &min, &max, &prom));
    ASSERT_FALSE(calcular_estadisticas(arr, cant, NULL, &max, &prom));
}

TEST(probar_contar_en_rango) {
    int arr[] = {10, -2, 5, 20, 8};
    size_t cant = 5;
    size_t coincidencia = 0;

    // Caso exitoso (rango [-2, 8])
    ASSERT_TRUE(contar_en_rango(arr, cant, -2, 8, &coincidencia) == 1);
    ASSERT_INT_EQ((int)coincidencia, 3);

    // Fuera de rango
    ASSERT_TRUE(contar_en_rango(arr, cant, 100, 200, &coincidencia) == 1);
    ASSERT_INT_EQ((int)coincidencia, 0);

    // Casos con NULL
    ASSERT_FALSE(contar_en_rango(NULL, cant, 0, 10, &coincidencia));
    ASSERT_FALSE(contar_en_rango(arr, cant, 0, 10, NULL));
}

int main(void) {
    RUN_TEST(probar_calcular_estadisticas);
    RUN_TEST(probar_contar_en_rango);

    return 0;
}
