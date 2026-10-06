/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadenas.h"

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

TEST(prueba_cadena_subcadena_dinamica)
{
    SUBCASE("extraccion existosa en heap");
    char *sub1 = cadena_subcadena_dinamica("estructuras", 20, 2, 6);
    ASSERT_PTR_NOT_NULL(sub1);
    ASSERT_STR_EQ("tructu", sub1);
    cadena_liberar_segura(&sub1);
    ASSERT_PTR_NULL(sub1);

    SUBCASE("argumento invalido y limites");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 5));
}

TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("inversion exitosa en heap");
    char *invertida = cadena_invertir_dinamica("Hola", 10);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("aloH", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);

    SUBCASE("argumentos invalidos");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10));
    ASSERT_PTR_NULL(cadena_invertir_dinamica("Hola", 0));
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
