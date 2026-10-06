/**
 * @file prueba.c
 * @brief Pruebas de integracion de Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "texto.h"
#include "cadenas.h"

TEST(prueba_unir_con_separador)
{
    char destino[32];

    SUBCASE("Union normal de cadenas");

    ASSERT_TRUE(
        unir_con_separador(
            destino,
            sizeof(destino),
            "Hola",
            "Mundo",
            " "
        )
    );

    ASSERT_STR_EQ("Hola Mundo", destino);

    SUBCASE("Truncamiento en espacio acotado");

    char chico[6];

    ASSERT_FALSE(
        unir_con_separador(
            chico,
            sizeof(chico),
            "Hola",
            "Mundo",
            " "
        )
    );

    ASSERT_INT_EQ('\0', chico[5]);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 2",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_unir_con_separador);

    return TEST_REPORT();
}