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
    SUBCASE("Copia de arreglo valido de tamaño par");
    int origen[] = {10, 20, 30, 40};
    int destino[4] = {0};
    ASSERT_TRUE(copiar_arreglo(origen, destino, 4));
    ASSERT_INT_EQ(10, destino[0]);
    ASSERT_INT_EQ(20, destino[1]);
    ASSERT_INT_EQ(30, destino[2]);
    ASSERT_INT_EQ(40, destino[3]);

    SUBCASE("Copia con cantidad cero");
    int orig[] = {1, 2, 3};
    int dest[3] = {99, 99, 99};
    ASSERT_TRUE(copiar_arreglo(orig, dest, 0));

    SUBCASE("Punteros nulos en copiar_arreglo");
    int datos[] = {1, 2};
    int dest_err[2] = {0};
    ASSERT_FALSE(copiar_arreglo(NULL, dest_err, 2));
    ASSERT_FALSE(copiar_arreglo(datos, NULL, 2));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Inversion de arreglo con cantidad par");
    int datos1[] = {1, 2, 3, 4};
    ASSERT_TRUE(invertir_arreglo(datos1, 4));
    ASSERT_INT_EQ(4, datos1[0]);
    ASSERT_INT_EQ(3, datos1[1]);
    ASSERT_INT_EQ(2, datos1[2]);
    ASSERT_INT_EQ(1, datos1[3]);

    SUBCASE("Inversion de arreglo con cantidad impar");
    int datos2[] = {5, 10, 15};
    ASSERT_TRUE(invertir_arreglo(datos2, 3));
    ASSERT_INT_EQ(15, datos2[0]);
    ASSERT_INT_EQ(10, datos2[1]);
    ASSERT_INT_EQ(5, datos2[2]);

    SUBCASE("Inversion de arreglo vacio o de un solo elemento");
    int unico[] = {42};
    ASSERT_TRUE(invertir_arreglo(unico, 1));
    ASSERT_INT_EQ(42, unico[0]);
    ASSERT_TRUE(invertir_arreglo(unico, 0));

    SUBCASE("Puntero nulo en invertir_arreglo");
    ASSERT_FALSE(invertir_arreglo(NULL, 3));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3 (Copia e Inversión)", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
