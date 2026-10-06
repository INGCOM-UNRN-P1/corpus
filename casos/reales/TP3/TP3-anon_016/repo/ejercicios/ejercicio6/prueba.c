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
    SUBCASE("Minimo en el medio del rango");
    int datos[] = {8, 3, 9, 1, 6};
    const int *minimo = buscar_puntero_minimo(&datos[0], &datos[4]);
    ASSERT_TRUE(minimo != NULL);
    ASSERT_INT_EQ(1, *minimo);

    SUBCASE("Minimo en el primer elemento");
    int datos2[] = {2, 5, 7, 9};
    const int *minimo2 = buscar_puntero_minimo(&datos2[0], &datos2[3]);
    ASSERT_INT_EQ(2, *minimo2);

    SUBCASE("Rango invalido o puntero nulo");
    ASSERT_TRUE(buscar_puntero_minimo(NULL, &datos[2]) == NULL);
    ASSERT_TRUE(buscar_puntero_minimo(&datos[3], &datos[0]) == NULL);
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Arreglo desordenado");
    int numeros[] = {40, 10, 30, 20, 50};
    ordenar_seleccion_punteros(numeros, 5);
    ASSERT_INT_EQ(10, numeros[0]);
    ASSERT_INT_EQ(20, numeros[1]);
    ASSERT_INT_EQ(30, numeros[2]);
    ASSERT_INT_EQ(40, numeros[3]);
    ASSERT_INT_EQ(50, numeros[4]);

    SUBCASE("Arreglo ya ordenado");
    int ordenado[] = {1, 2, 3, 4};
    ordenar_seleccion_punteros(ordenado, 4);
    ASSERT_INT_EQ(1, ordenado[0]);
    ASSERT_INT_EQ(2, ordenado[1]);
    ASSERT_INT_EQ(3, ordenado[2]);
    ASSERT_INT_EQ(4, ordenado[3]);

    SUBCASE("Arreglo de un solo elemento");
    int unico[] = {7};
    ordenar_seleccion_punteros(unico, 1);
    ASSERT_INT_EQ(7, unico[0]);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6", conteo_args, argumentos);
     RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
