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
    SUBCASE("Extraccion parcial");
    char *subcadena = cadena_subcadena_dinamica("Hola Mundo", 30, 0, 4);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("Hola", subcadena);
    cadena_liberar_segura(&subcadena);
    ASSERT_PTR_NULL(subcadena);

    SUBCASE("Cantidad supera caracteres disponibles");
    subcadena = cadena_subcadena_dinamica("Programacion 1", 30, 13, 10);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("1", subcadena);
    cadena_liberar_segura(&subcadena);
    ASSERT_PTR_NULL(subcadena);

    SUBCASE("Inicio fuera de la cadena");
    subcadena = cadena_subcadena_dinamica("Hola", 10, 4, 3);
    ASSERT_PTR_NOT_NULL(subcadena);
    ASSERT_STR_EQ("", subcadena);
    cadena_liberar_segura(&subcadena);
    ASSERT_PTR_NULL(subcadena);

    SUBCASE("Origen nulo o capacidad cero");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 3));
    ASSERT_PTR_NULL(cadena_subcadena_dinamica("Hola", 0, 0, 3));
}

TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion de cadena");
    char *invertida = cadena_invertir_dinamica("Hola Mundo", 30);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("odnuM aloH", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);

    SUBCASE("Cadena vacia");
    invertida = cadena_invertir_dinamica("", 1);
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("", invertida);
    cadena_liberar_segura(&invertida);
    ASSERT_PTR_NULL(invertida);

    SUBCASE("Origen nulo o capacidad cero");
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
