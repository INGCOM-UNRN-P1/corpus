/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    SUBCASE("Caso nulos/incorrecto");
    int arr_nulo[] = {1,2,3,4,5};
    ASSERT_INT_EQ(NULL, buscar_primero(arr_nulo, 0, 4));
    ASSERT_INT_EQ(NULL, buscar_primero(NULL, 5, 4));

    SUBCASE("Caso encontrado");
    const int *esperado = buscar_primero(arr_nulo, 5, 4);
    ASSERT_INT_EQ(esperado, buscar_primero(arr_nulo, 5, 4));

    SUBCASE("Caso no encontrado");
    const int *esperado2 = buscar_primero(arr_nulo, 5, 20);

    ASSERT_INT_EQ(esperado2, buscar_primero(arr_nulo, 5, 20));

}

TEST(prueba_distancia_punteros)
{
    SUBCASE("Caso nulos);
    int arr_global[] = {1,2,3,4,5};
    ASSERT_INT_EQ(NULL, distancia_punteros(arr_global, 0, 4));
    ASSERT_INT_EQ(NULL, distancia_punteros(NULL, 5, 4));

    SUBCASE("Caso no encontrado");

}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
