/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadenas.h"

TEST(prueba_cadena_duplicar_segura)
{
    char *duplicada = cadena_duplicar_segura("Programacion 1", 30U);
    ASSERT_PTR_NOT_NULL(duplicada);
    ASSERT_STR_EQ("Programacion 1", duplicada);
    cadena_liberar_segura(&duplicada);
    ASSERT_PTR_NULL(duplicada);

    SUBCASE("Respeta la capacidad maxima");
    duplicada = cadena_duplicar_segura("abcdef", 3U);
    ASSERT_PTR_NOT_NULL(duplicada);
    ASSERT_STR_EQ("abc", duplicada);
    cadena_liberar_segura(&duplicada);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(cadena_duplicar_segura(NULL, 10U));
    ASSERT_PTR_NULL(cadena_duplicar_segura("hola", 0U));
}

TEST(prueba_cadena_unir_dinamica)
{
    char *unida = cadena_unir_dinamica("Hola ", 10U, "Mundo", 10U);
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);
    cadena_liberar_segura(&unida);
    ASSERT_PTR_NULL(unida);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_unir_dinamica(NULL, 10U, "test", 10U));
    ASSERT_PTR_NULL(cadena_unir_dinamica("test", 10U, NULL, 10U));
}

TEST(prueba_cadena_subcadena_dinamica)
{
    char *subcadena = cadena_subcadena_dinamica("Programacion", 20U, 3U, 5U);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("grama", subcadena);
    cadena_liberar_segura(&subcadena);

    subcadena = cadena_subcadena_dinamica("hola", 10U, 20U, 3U);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("", subcadena);
    cadena_liberar_segura(&subcadena);
}

TEST(prueba_cadena_invertir_dinamica)
{
    char *invertida = cadena_invertir_dinamica("abcd", 10U);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("dcba", invertida);
    cadena_liberar_segura(&invertida);

    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10U));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libstring", conteo_args, argumentos);
    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);
    return TEST_REPORT();
}
