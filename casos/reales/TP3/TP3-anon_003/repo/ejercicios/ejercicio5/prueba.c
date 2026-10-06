/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_ejercicio5)
{
    char destino[20];

    ASSERT_TRUE(copiar_con_punteros(destino, 20, "Hola"));
    ASSERT_TRUE(strcmp(destino, "Hola") == 0);

    ASSERT_TRUE(!copiar_con_punteros(destino, 5, "Hola mundo"));
    ASSERT_TRUE(strcmp(destino, "Hola") == 0);

    copiar_con_punteros(destino, 20, "Hola");
    ASSERT_TRUE(concatenar_con_punteros(destino, 20, " mundo"));
    ASSERT_TRUE(strcmp(destino, "Hola mundo") == 0);

    copiar_con_punteros(destino, 20, "Hola");
    ASSERT_TRUE(!concatenar_con_punteros(destino, 8, " mundo"));
    ASSERT_TRUE(strcmp(destino, "Hola mu") == 0);

    ASSERT_TRUE(!copiar_con_punteros(NULL, 10, "Hola"));
    ASSERT_TRUE(!copiar_con_punteros(destino, 0, "Hola"));
    ASSERT_TRUE(!copiar_con_punteros(destino, 10, NULL));

    ASSERT_TRUE(!concatenar_con_punteros(NULL, 10, "Hola"));
    ASSERT_TRUE(!concatenar_con_punteros(destino, 0, "Hola"));
    ASSERT_TRUE(!concatenar_con_punteros(destino, 10, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_ejercicio5);
    return TEST_REPORT();
}