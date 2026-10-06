/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Divide una linea con varios campos");

    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("uno,dos,tres", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(3, cantidad);
    ASSERT_STR_EQ("uno", tokens[0]);
    ASSERT_STR_EQ("dos", tokens[1]);
    ASSERT_STR_EQ("tres", tokens[2]);

    liberar_arreglo_cadenas(&tokens, cantidad);


    SUBCASE("Conserva campos vacios");

    cantidad = 0;
    tokens = dividir_linea_csv("uno,,tres", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(3, cantidad);
    ASSERT_STR_EQ("uno", tokens[0]);
    ASSERT_STR_EQ("", tokens[1]);
    ASSERT_STR_EQ("tres", tokens[2]);

    liberar_arreglo_cadenas(&tokens, cantidad);


    SUBCASE("Una linea vacia produce un token vacio");

    cantidad = 0;
    tokens = dividir_linea_csv("", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(1, cantidad);
    ASSERT_STR_EQ("", tokens[0]);

    liberar_arreglo_cadenas(&tokens, cantidad);


    SUBCASE("Linea nula");

    cantidad = 10;
    tokens = dividir_linea_csv(NULL, ',', &cantidad);

    ASSERT_PTR_NULL(tokens);
    ASSERT_UINT_EQ(0, cantidad);


    SUBCASE("Puntero de cantidad nulo");

    tokens = dividir_linea_csv("uno,dos", ',', NULL);

    ASSERT_PTR_NULL(tokens);
}

TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Libera el arreglo y establece el puntero en NULL");

    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("uno,dos", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(tokens);

    liberar_arreglo_cadenas(&tokens, cantidad);

    ASSERT_PTR_NULL(tokens);


    SUBCASE("Acepta un puntero ya nulo");

    tokens = NULL;

    liberar_arreglo_cadenas(&tokens, 0);

    ASSERT_PTR_NULL(tokens);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_cadenas);
    return TEST_REPORT();
}