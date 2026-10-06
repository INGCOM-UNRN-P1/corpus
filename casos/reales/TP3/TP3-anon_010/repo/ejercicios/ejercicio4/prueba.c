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
    SUBCASE("Valor encontrado");
    int datos[] = {5, 12, 18, 12, 30};
    const int *resultado = buscar_primero(datos, 5, 12);
    ASSERT_TRUE(resultado == &datos[1]);

    SUBCASE("Valor no encontrado o arreglo nulo");
    ASSERT_TRUE(buscar_primero(datos, 5, 40) == NULL);
    ASSERT_TRUE(buscar_primero(NULL, 5, 12) == NULL);
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("Distancia valida");
    int datos[] = {5, 12, 18, 12, 30};
    ASSERT_INT_EQ(3, (int)distancia_punteros(datos, &datos[3]));

    SUBCASE("Casos de error");
    ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, &datos[0]));
    ASSERT_INT_EQ(-1, (int)distancia_punteros(&datos[2], &datos[0]));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4 (Busqueda)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}