/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    char bufer[10];

    SUBCASE("Copia completa exitosa");
    {
        ASSERT_TRUE(copiar_con_punteros(bufer, 10, "Hola"));
        ASSERT_STR_EQ("Hola", bufer);
    }

    SUBCASE("Copia con truncamiento seguro");
    {
        ASSERT_FALSE(copiar_con_punteros(bufer, 5, "Programacion"));
        ASSERT_STR_EQ("Prog", bufer);
    }

    SUBCASE("Copia cadena vacia");
    {
        ASSERT_TRUE(copiar_con_punteros(bufer, 5, ""));
        ASSERT_STR_EQ("", bufer);
    }

    SUBCASE("Parametros invalidos y capacidad cero");
    {
        ASSERT_FALSE(copiar_con_punteros(NULL, 10, "Hola"));
        ASSERT_FALSE(copiar_con_punteros(bufer, 10, NULL));
        ASSERT_FALSE(copiar_con_punteros(bufer, 0, "Hola"));
    }
}

TEST(prueba_concatenar_con_punteros)
{
    char bufer[15];

    SUBCASE("Concatenacion completa exitosa");
    {
        copiar_con_punteros(bufer, 15, "Hola ");
        ASSERT_TRUE(concatenar_con_punteros(bufer, 15, "Mundo"));
        ASSERT_STR_EQ("Hola Mundo", bufer);
    }

    SUBCASE("Concatenacion con truncamiento");
    {
        copiar_con_punteros(bufer, 8, "Hola ");
        ASSERT_FALSE(concatenar_con_punteros(bufer, 8, "Mundo!"));
        ASSERT_STR_EQ("Hola Mu", bufer);
    }

    SUBCASE("Parametros invalidos");
    {
        ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "Test"));
        ASSERT_FALSE(concatenar_con_punteros(bufer, 10, NULL));
        ASSERT_FALSE(concatenar_con_punteros(bufer, 0, "Test"));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5 (Cadenas con Punteros)", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
