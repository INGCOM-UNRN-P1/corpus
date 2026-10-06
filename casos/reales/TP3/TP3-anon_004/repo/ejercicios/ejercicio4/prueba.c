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
    int lista[5] = {5, 10, 15, 10, 20};

    SUBCASE("Localizar primera coincidencia");
    const int *hallado = buscar_primero(lista, 5, 10);
    ASSERT_PTR_NOT_NULL(hallado);
    ASSERT_PTR_EQ(&lista[1], hallado);
    ASSERT_INT_EQ(10, *hallado);

    SUBCASE("Elemento ausente");
    ASSERT_PTR_NULL(buscar_primero(lista, 5, 99));

    SUBCASE("Casos de guarda: nulo o vacio");
    ASSERT_PTR_NULL(buscar_primero(NULL, 5, 10));
    ASSERT_PTR_NULL(buscar_primero(lista, 0, 10));
}

TEST(prueba_distancia_punteros)
{
    int lista[5] = {1, 2, 3, 4, 5};
    size_t desplazamiento = 0;

    SUBCASE("Calculo de distancia valido");
    ASSERT_TRUE(distancia_punteros(lista, &lista[3], &desplazamiento));
    ASSERT_INT_EQ(3, (int)desplazamiento);

    SUBCASE("Distancia al mismo elemento");
    ASSERT_TRUE(distancia_punteros(lista, lista, &desplazamiento));
    ASSERT_INT_EQ(0, (int)desplazamiento);

    SUBCASE("Punteros invalidos u orden invertido");
    ASSERT_FALSE(distancia_punteros(NULL, lista, &desplazamiento));
    ASSERT_FALSE(distancia_punteros(lista, NULL, &desplazamiento));
    ASSERT_FALSE(distancia_punteros(lista, &lista[2], NULL));
    ASSERT_FALSE(distancia_punteros(&lista[3], &lista[1], &desplazamiento));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
