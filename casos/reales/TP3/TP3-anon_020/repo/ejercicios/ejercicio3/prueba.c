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
    SUBCASE("Copia valida");
    int origen[] = {1, 2, 3, 4};
    int destino[4] = {0};
    ASSERT_TRUE(copiar_arreglo(origen, destino, 4));
    ASSERT_INT_EQ(1, destino[0]);
    ASSERT_INT_EQ(2, destino[1]);
    ASSERT_INT_EQ(3, destino[2]);
    ASSERT_INT_EQ(4, destino[3]);

    SUBCASE("Punteros invalidos");
    int datos[] = {5, 6};
    ASSERT_FALSE(copiar_arreglo(NULL, datos, 2));
    ASSERT_FALSE(copiar_arreglo(datos, NULL, 2));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Inversion basica");
    int valores[] = {10, 20, 30, 40};
    ASSERT_TRUE(invertir_arreglo(valores, 4));
    ASSERT_INT_EQ(40, valores[0]);
    ASSERT_INT_EQ(30, valores[1]);
    ASSERT_INT_EQ(20, valores[2]);
    ASSERT_INT_EQ(10, valores[3]);

    SUBCASE("Arreglo de un elemento");
    int unico[] = {7};
    ASSERT_TRUE(invertir_arreglo(unico, 1));
    ASSERT_INT_EQ(7, unico[0]);

    SUBCASE("Puntero nulo");
    ASSERT_FALSE(invertir_arreglo(NULL, 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
