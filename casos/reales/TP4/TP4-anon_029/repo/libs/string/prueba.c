/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include "cadenas.h"
#include "cadenas_tp2.h"
#include "p1_test.h"
#include <stdio.h>

TEST(prueba_cadena_duplicar_segura)
{
    SUBCASE("Duplicacion de cadena valida");
    char *dup = cadena_duplicar_segura("Programacion 1", 30);
    ASSERT_PTR_NOT_NULL(dup);
    ASSERT_STR_EQ("Programacion 1", dup);
    cadena_liberar_segura(&dup);
    ASSERT_PTR_NULL(dup);

    SUBCASE("Cadena nula o capacidad cero");
    ASSERT_PTR_NULL(cadena_duplicar_segura(NULL, 10));
    ASSERT_PTR_NULL(cadena_duplicar_segura("hola", 0));
}

TEST(prueba_cadena_unir_dinamica)
{
    SUBCASE("Union exitosa en heap");
    char *unida = cadena_unir_dinamica("Hola ", 10, "Mundo", 10);
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);
    cadena_liberar_segura(&unida);
    ASSERT_PTR_NULL(unida);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_unir_dinamica(NULL, 10, "test", 10));
    ASSERT_PTR_NULL(cadena_unir_dinamica("test", 10, NULL, 10));
}
// los 2 test son teoricos hasta poder solucionar el tema dee compilacion
TEST(prueba_cadena_subcadena_dinamica)
{
    SUBCASE("Extarccion exitosa");
    char *porcion = cadena_subcadena_dinamica("ABCDEF", 7, 2, 2);
    ASSERT_PTR_NOT_NULL(porcion);
    ASSERT_INT_EQ("CD", porcion);
    cadena_liberar_segura(&porcion);
    ASSERT_PTR_NULL(porcion);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 3, 2, 1));
    ASSERT_PTR_NULL(cadena_subcadena_dinamica("ABC", 0, 2, 3));
}

TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion exitosa");
    char *invetido = cadena_invertir_dinamica("olaH", 4);
    ASSERT_PTR_NOT_NULL(invetido);
    ASSERT_INT_EQ("Hola", invetido);
    cadena_liberar_segura(&invetido);
    ASSERT_PTR_NULL(invetido);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 4));
    ASSERT_PTR_NULL(cadena_invertir_dinamica("ABC", 0));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libstring", conteo_args,
                          argumentos);
    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);
    return TEST_REPORT();
}
