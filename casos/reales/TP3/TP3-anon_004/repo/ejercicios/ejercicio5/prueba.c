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

TEST(prueba_copiar_con_punteros)
{
    char destino[10];

    SUBCASE("Copia normal exitosa");
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), "hola"));
    ASSERT_STR_EQ("hola", destino);

    SUBCASE("Truncamiento estricto");
    ASSERT_FALSE(copiar_con_punteros(destino, 4, "lenguaje"));
    ASSERT_STR_EQ("len", destino);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "hola"));
    ASSERT_FALSE(copiar_con_punteros(destino, 0, "hola"));
    ASSERT_FALSE(copiar_con_punteros(destino, 10, NULL));
}

TEST(prueba_concatenar_con_punteros)
{
    char destino[16];

    SUBCASE("Concatenacion normal");
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), "Hola "));
    ASSERT_TRUE(concatenar_con_punteros(destino, sizeof(destino), "Mundo"));
    ASSERT_STR_EQ("Hola Mundo", destino);

    SUBCASE("Concatenacion con truncamiento");
    char corto[7];
    ASSERT_TRUE(copiar_con_punteros(corto, sizeof(corto), "ABC"));
    ASSERT_FALSE(concatenar_con_punteros(corto, sizeof(corto), "DEFGH"));
    ASSERT_STR_EQ("ABCDEF", corto);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "test"));
    ASSERT_FALSE(concatenar_con_punteros(destino, 0, "test"));
    ASSERT_FALSE(concatenar_con_punteros(destino, 10, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
