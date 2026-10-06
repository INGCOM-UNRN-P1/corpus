/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    int origen[] = {0,1,2,3,4,5,6,7,8,9};
    int destino[10];
    size_t cantidad_a_copiar = sizeof(destino)/sizeof(destino[0]);
    size_t inicio = 0;

    SUBCASE("Arreglos del mismo tamaño");
    ASSERT_TRUE(copiar_arreglo(origen, 10, destino, 10, inicio, cantidad_a_copiar));
    ASSERT_ARRAY_INT_EQ(origen, destino, 10);

    SUBCASE("Arreglos de diferente mismo tamaño");
    ASSERT_FALSE(copiar_arreglo(origen, 10, destino, 5, inicio, cantidad_a_copiar));
    ASSERT_FALSE(copiar_arreglo(origen, 5, destino, 10, inicio, cantidad_a_copiar));
    ASSERT_ARRAY_INT_EQ(origen, destino, 5);

    SUBCASE("Inicio > 0 y dentro de los límites");
    inicio = 3;
    ASSERT_TRUE(copiar_arreglo(origen, 10, destino, 10, inicio, cantidad_a_copiar - inicio));
    ASSERT_ARRAY_INT_EQ(origen + inicio, destino, 7);

    SUBCASE("Inicio > 0 y fuera de límite");
    inicio = 20;
    ASSERT_FALSE(copiar_arreglo(origen, 10, destino, 10, inicio, 10));

    SUBCASE("Inicio comienza donde origen termina, y cantidad a copiar es 0");
    ASSERT_TRUE(copiar_arreglo(origen, 10, destino, 10, 10, 0));

    SUBCASE("Inicio comienza donde origen termina, y cantidad a copiar es > 0");
    ASSERT_FALSE(copiar_arreglo(origen, 10, destino, 10, 10, 1));

    SUBCASE("Cantidad a copiar excede el tamaño de los arreglos");
    ASSERT_FALSE(copiar_arreglo(origen, 10, destino, 10, 0, 20));
    ASSERT_ARRAY_INT_EQ(origen, destino, 10); // arreglos aún así deberian coincidir hasta 'tamaño' elementos

    SUBCASE("Arreglos nulos");
    ASSERT_FALSE(copiar_arreglo(NULL, 10, destino, 10, 0, 20));
    ASSERT_FALSE(copiar_arreglo(origen, 10, NULL, 10, 0, 20));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Arreglo normal");
    int arreglo[] = {1,2,3,4,5,6,7,8,9,0};
    int esperado[] = {0,9,8,7,6,5,4,3,2,1};
    ASSERT_TRUE(invertir_arreglo(arreglo, 10));
    ASSERT_ARRAY_INT_EQ(esperado, arreglo, 10);

    SUBCASE("Arreglo de tamaño 0");
    int arreglo2[] = {};
    int esperado2[] = {};
    ASSERT_TRUE(invertir_arreglo(arreglo2, 0));
    ASSERT_ARRAY_INT_EQ(esperado2, arreglo2, 0);

    SUBCASE("Arreglo de tamaño 1");
    int arreglo3[] = {1};
    int esperado3[] = {1};
    ASSERT_TRUE(invertir_arreglo(arreglo3, 1));
    ASSERT_ARRAY_INT_EQ(esperado3, arreglo3, 1);

    SUBCASE("Arreglo nulo");
    ASSERT_FALSE(invertir_arreglo(NULL, 10));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);

    return TEST_REPORT();
}
