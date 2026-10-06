/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include <string.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("Copia completa");
    char destino[20] = {0};
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), "programa"));
    ASSERT_TRUE(strcmp(destino, "programa") == 0);

    SUBCASE("Truncamiento");
    char truncado[6] = {0};
    ASSERT_FALSE(copiar_con_punteros(truncado, sizeof(truncado), "abcdef"));
    ASSERT_TRUE(strcmp(truncado, "abcde") == 0);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "abc"));
    ASSERT_FALSE(copiar_con_punteros(destino, 0, "abc"));
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("Concatenacion normal");
    char destino[20] = "hola";
    ASSERT_TRUE(concatenar_con_punteros(destino, sizeof(destino), " mundo"));
    ASSERT_TRUE(strcmp(destino, "hola mundo") == 0);

    SUBCASE("Concatenacion con truncamiento");
    char truncado[8] = "abc";
    ASSERT_FALSE(concatenar_con_punteros(truncado, sizeof(truncado), "defghi"));
    ASSERT_TRUE(strcmp(truncado, "abcdefg") == 0);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "abc"));
    ASSERT_FALSE(concatenar_con_punteros(destino, 0, "abc"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
