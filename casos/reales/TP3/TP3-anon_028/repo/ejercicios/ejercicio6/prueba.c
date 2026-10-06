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
    int arreglo[5] = {40, 10, 50, 20, 30};

    const int *min = buscar_puntero_minimo(arreglo, arreglo + 5);
    ASSERT_PTR_NOT_NULL(min);
    ASSERT_INT_EQ(10, *min);

    const int *min_sub = buscar_puntero_minimo(arreglo + 2, arreglo + 5);
    ASSERT_PTR_NOT_NULL(min_sub);
    ASSERT_INT_EQ(20, *min_sub);

    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, arreglo + 5));
    ASSERT_PTR_NULL(buscar_puntero_minimo(arreglo + 3, arreglo + 1));
}

TEST(prueba_ordenar_seleccion_punteros)
{
    int arreglo[5] = {50, 20, 10, 40, 30};

    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 5));

    ASSERT_INT_EQ(10, *(arreglo + 0));
    ASSERT_INT_EQ(20, *(arreglo + 1));
    ASSERT_INT_EQ(30, *(arreglo + 2));
    ASSERT_INT_EQ(40, *(arreglo + 3));
    ASSERT_INT_EQ(50, *(arreglo + 4));

    ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 5));
    ASSERT_FALSE(ordenar_seleccion_punteros(arreglo, 0));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
