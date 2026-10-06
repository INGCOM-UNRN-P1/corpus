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
    SUBCASE("Extraccion de subcadena valida");
    char *subcadena = cadena_subcadena_dinamica("Programacion", 12, 3, 5);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("grama", subcadena);
    cadena_liberar_segura(&subcadena);
    ASSERT_PTR_NULL(subcadena);

    SUBCASE("Inicio fuera de rango");
    char *vacia = cadena_subcadena_dinamica("Hola", 5, 10, 3);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
    ASSERT_PTR_NULL(vacia);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 5, 0, 2));
    ASSERT_PTR_NULL(cadena_subcadena_dinamica("Hola", 0, 0, 2));
}

TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion de cadena valida");
    char *invertida = cadena_invertir_dinamica("abcd", 5);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("dcba", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 5));
    ASSERT_PTR_NULL(cadena_invertir_dinamica("abc", 0));
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
