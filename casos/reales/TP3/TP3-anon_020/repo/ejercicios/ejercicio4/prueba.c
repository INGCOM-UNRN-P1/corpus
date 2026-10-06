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
    SUBCASE("Primer valor encontrado");
    int datos[] = {4, 8, 15, 16, 23, 42};
    const int *resultado = buscar_primero(datos, 6, 15);
    ASSERT_TRUE(resultado != NULL);
    ASSERT_TRUE(resultado == &datos[2]);
    ASSERT_INT_EQ(15, *resultado);

    SUBCASE("Valor ausente");
    ASSERT_TRUE(buscar_primero(datos, 6, 99) == NULL);

    SUBCASE("Arreglo nulo");
    ASSERT_TRUE(buscar_primero(NULL, 3, 4) == NULL);
}

TEST(prueba_distancia_punteros)
{
    int datos[] = {10, 20, 30, 40};
    const int *encontrado = buscar_primero(datos, 4, 30);

    ASSERT_INT_EQ(2, (int)distancia_punteros(datos, encontrado));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, NULL));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, encontrado));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
