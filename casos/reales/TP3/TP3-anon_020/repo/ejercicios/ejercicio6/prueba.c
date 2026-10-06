/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    SUBCASE("Rango valido");
    int datos[] = {9, 4, 7, 1, 6};
    const int *minimo = buscar_puntero_minimo(datos, datos + 5);
    ASSERT_TRUE(minimo != NULL);
    ASSERT_TRUE(minimo == &datos[3]);

    SUBCASE("Rango invalido");
    ASSERT_TRUE(buscar_puntero_minimo(NULL, NULL) == NULL);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Ordenamiento efectivo");
    int datos[] = {9, 4, 7, 1, 6};
    ASSERT_TRUE(ordenar_seleccion_punteros(datos, 5));
    ASSERT_INT_EQ(1, datos[0]);
    ASSERT_INT_EQ(4, datos[1]);
    ASSERT_INT_EQ(6, datos[2]);
    ASSERT_INT_EQ(7, datos[3]);
    ASSERT_INT_EQ(9, datos[4]);

    SUBCASE("Entrada invalida");
    ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
