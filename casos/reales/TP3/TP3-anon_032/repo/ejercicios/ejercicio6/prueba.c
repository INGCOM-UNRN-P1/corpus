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
    int arreglo[] = {10, -2, 1, 0 , 30, -10, 22};

    SUBCASE("Caso normal");
    ASSERT_INT_EQ(-10, *buscar_puntero_minimo(arreglo, &arreglo[6]));

    SUBCASE("Rango invertido");
    ASSERT_PTR_NULL(buscar_puntero_minimo(&arreglo[6], arreglo));

    SUBCASE("Punteros nulos");
    ASSERT_PTR_NULL(buscar_puntero_minimo(NULL, &arreglo[6]));    
    ASSERT_PTR_NULL(buscar_puntero_minimo(arreglo, NULL));


    SUBCASE("Rango vacio");
    ASSERT_PTR_NULL(buscar_puntero_minimo(arreglo, arreglo));
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Caso normal");
    int arreglo[] = {1, 23, 4, -10, 0, -10, 100};
    int arreglo_ordenado[] = {-10, -10, 0, 1, 4, 23, 100};
    ASSERT_TRUE(ordenar_seleccion_punteros(arreglo, 6));
    ASSERT_ARRAY_INT_EQ(arreglo_ordenado, arreglo, 6);

    SUBCASE("Arreglo nulo");
    ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 6));

    SUBCASE("Capacidad cero");
    ASSERT_FALSE(ordenar_seleccion_punteros(arreglo, 0));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
