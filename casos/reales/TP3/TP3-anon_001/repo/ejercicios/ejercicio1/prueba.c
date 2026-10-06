/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include "intercambio.h"
#include "p1_test.h"

TEST(probar_ordenar_par) {
    int x = 10, y = 5;
    
    // Caso desordenado
    ordenar_par(&x, &y);
    ASSERT_INT_EQ(x, 5);
    ASSERT_INT_EQ(y, 10);

    // Caso ya ordenado
    x = 3; y = 8;
    ordenar_par(&x, &y);
    ASSERT_INT_EQ(x, 3);
    ASSERT_INT_EQ(y, 8);

    // Caso valores iguales
    x = 4; y = 4;
    ordenar_par(&x, &y);
    ASSERT_INT_EQ(x, 4);
    ASSERT_INT_EQ(y, 4);

    // Manejo de NULL
    ordenar_par(NULL, &y);
    ordenar_par(&x, NULL);
}

TEST(probar_ordenar_tria) {
    int a = 9, b = 2, c = 5;

    // Caso desordenado
    ordenar_tria(&a, &b, &c);
    ASSERT_INT_EQ(a, 2);
    ASSERT_INT_EQ(b, 5);
    ASSERT_INT_EQ(c, 9);

    // Caso todos iguales
    a = 7; b = 7; c = 7;
    ordenar_tria(&a, &b, &c);
    ASSERT_INT_EQ(a, 7);
    ASSERT_INT_EQ(b, 7);
    ASSERT_INT_EQ(c, 7);

    // Manejo de NULL
    ordenar_tria(&a, NULL, &c);
}

TEST(probar_sumar_acumulado) {
    int arr[] = {10, -5, 15};
    long long res = 0;

    // Caso exitoso
    ASSERT_TRUE(sumar_acumulado(arr, 3, &res));
    ASSERT_INT_EQ((int)res, 20);

    // Arreglo vacio (cantidad = 0)
    res = 999;
    ASSERT_TRUE(sumar_acumulado(arr, 0, &res));
    ASSERT_INT_EQ((int)res, 0);

    // Casos con NULL
    ASSERT_FALSE(sumar_acumulado(NULL, 3, &res));
    ASSERT_FALSE(sumar_acumulado(arr, 3, NULL));
}

int main(void) {
    RUN_TEST(probar_ordenar_par);
    RUN_TEST(probar_ordenar_tria);
    RUN_TEST(probar_sumar_acumulado);

    return 0;
}