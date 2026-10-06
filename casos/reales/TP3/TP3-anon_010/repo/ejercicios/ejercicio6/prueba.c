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
    SUBCASE("Minimo en rango normal");
    int datos[] = {30, 10, 40, 20};
    const int *minimo = buscar_puntero_minimo(datos, datos + 4);
    ASSERT_TRUE(minimo == &datos[1]);

    SUBCASE("Rango invalido o punteros nulos");
    ASSERT_TRUE(buscar_puntero_minimo(datos, datos) == NULL);
    ASSERT_TRUE(buscar_puntero_minimo(NULL, datos + 4) == NULL);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Arreglo desordenado");
    int datos[] = {30, 10, 40, 20};
    ordenar_seleccion_punteros(datos, 4);
    ASSERT_INT_EQ(10, datos[0]);
    ASSERT_INT_EQ(20, datos[1]);
    ASSERT_INT_EQ(30, datos[2]);
    ASSERT_INT_EQ(40, datos[3]);

    SUBCASE("Arreglo nulo no falla");
    ordenar_seleccion_punteros(NULL, 4);
    ASSERT_TRUE(true);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6 (Seleccion)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
