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
    int arreglo[] = {10, 20, 30, 40};

    const int *resultado = buscar_primero(arreglo, 4, 30);

    ASSERT_TRUE(resultado == arreglo + 2);
}

TEST(prueba_buscar_primero_repetido)
{
    int arreglo[] = {10, 20, 30, 10, 50};

    const int *resultado = buscar_primero(arreglo, 5, 10);

    ASSERT_TRUE(resultado == arreglo);
}

TEST(prueba_buscar_primero_inexistente)
{
    int arreglo[] = {10, 20, 30, 40};

    const int *resultado = buscar_primero(arreglo, 4, 50);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_buscar_primero_null)
{
    const int *resultado = buscar_primero(NULL, 4, 10);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_buscar_primero_cero)
{
    int arreglo[] = {10, 20, 30};

    const int *resultado = buscar_primero(arreglo, 0, 10);

    ASSERT_TRUE(resultado == NULL);
}

TEST(prueba_distancia_punteros)
{
    int arreglo[] = {10, 20, 30, 40, 50};

    const int *inicio = arreglo;
    const int *elemento = arreglo + 3;

    ptrdiff_t resultado = distancia_punteros(inicio, elemento);

    ASSERT_TRUE(resultado == 3);
}

TEST(prueba_distancia_punteros_iguales)
{
    int arreglo[] = {10, 20, 30, 40};

    const int *inicio = arreglo;
    const int *elemento = arreglo;

    ptrdiff_t resultado = distancia_punteros(inicio, elemento);

    ASSERT_TRUE(resultado == 0);
}

TEST(prueba_distancia_punteros_null)
{
    int arreglo[] = {10, 20, 30};

    const int *elemento = arreglo + 1;

    ptrdiff_t resultado = distancia_punteros(NULL, elemento);

    ASSERT_TRUE(resultado == -1);
}

TEST(prueba_distancia_punteros_menor)
{
    int arreglo[] = {10, 20, 30, 40};

    const int *inicio = arreglo + 3;
    const int *elemento = arreglo + 2;

    ptrdiff_t resultado = distancia_punteros(inicio, elemento);

    ASSERT_TRUE(resultado == -1);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_buscar_primero_repetido);
    RUN_TEST(prueba_buscar_primero_inexistente);
    RUN_TEST(prueba_buscar_primero_null);
    RUN_TEST(prueba_buscar_primero_cero);

    RUN_TEST(prueba_distancia_punteros);
    RUN_TEST(prueba_distancia_punteros_iguales);
    RUN_TEST(prueba_distancia_punteros_null);
    RUN_TEST(prueba_distancia_punteros_menor);
    return TEST_REPORT();
}
