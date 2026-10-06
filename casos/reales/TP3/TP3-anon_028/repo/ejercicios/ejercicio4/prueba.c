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
    int arreglo[5] = {10, 20, 30, 40, 50};

    const int *hallado = buscar_primero(arreglo, 5, 30);
    ASSERT_PTR_NOT_NULL(hallado);
    ASSERT_INT_EQ(30, *hallado);

    ASSERT_PTR_NULL(buscar_primero(arreglo, 5, 99));

    ASSERT_PTR_NULL(buscar_primero(NULL, 5, 10));
}

TEST(prueba_distancia_punteros)
{
    int arreglo[5] = {10, 20, 30, 40, 50};
    const int *elemento = arreglo + 3; 

    long dist = distancia_punteros(arreglo, elemento);
    ASSERT_INT_EQ(3, (int)dist);

    ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, elemento));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(arreglo, NULL));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(arreglo + 3, arreglo + 1));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
