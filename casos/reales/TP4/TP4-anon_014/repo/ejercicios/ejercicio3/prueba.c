/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("Clon independiente del original");
    char original[] = "hola";
    char *clon = clonar_cadena(original);
    original[0] = 'X';
    ASSERT_STR_EQ("hola", clon);
    free(clon);

    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(clonar_cadena(NULL));
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Union de dos cadenas");
    char *unida = unir_cadenas_dinamicas("Progra", "macion");
    ASSERT_STR_EQ("Programacion", unida);
    free(unida);

    SUBCASE("Con cadena vacia");
    char *solo = unir_cadenas_dinamicas("", "abc");
    ASSERT_STR_EQ("abc", solo);
    free(solo);

    SUBCASE("Argumentos nulos");
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "abc"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("abc", NULL));
}

TEST(prueba_invertir_cadena_dinamico)
{
    SUBCASE("Inversion");
    char *invertida = invertir_cadena_dinamico("recursos");
    ASSERT_STR_EQ("sosrucer", invertida);
    free(invertida);

    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(invertir_cadena_dinamico(NULL));
}

TEST(prueba_partir_por_delimitador)
{
    SUBCASE("Tokens con uno vacio en el medio");
    size_t cantidad = 0;
    char **tokens = partir_por_delimitador("a,bc,,d", ',', &cantidad);
    ASSERT_UINT_EQ(4, cantidad);
    ASSERT_STR_EQ("a", tokens[0]);
    ASSERT_STR_EQ("bc", tokens[1]);
    ASSERT_STR_EQ("", tokens[2]);
    ASSERT_STR_EQ("d", tokens[3]);
    liberar_tokens(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);

    SUBCASE("Sin delimitador da un solo token");
    char **uno = partir_por_delimitador("hola", ';', &cantidad);
    ASSERT_UINT_EQ(1, cantidad);
    ASSERT_STR_EQ("hola", uno[0]);
    liberar_tokens(&uno, cantidad);

    SUBCASE("Cadena nula");
    ASSERT_PTR_NULL(partir_por_delimitador(NULL, ',', &cantidad));
    ASSERT_UINT_EQ(0, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    RUN_TEST(prueba_invertir_cadena_dinamico);
    RUN_TEST(prueba_partir_por_delimitador);
    return TEST_REPORT();
}
