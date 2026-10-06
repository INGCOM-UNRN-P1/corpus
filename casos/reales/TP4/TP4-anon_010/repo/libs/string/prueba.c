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
    SUBCASE("Subcadena valida");
    char *sub = cadena_subcadena_dinamica("Programacion", 20, 3, 4);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("gram", sub);
    cadena_liberar_segura(&sub);
 
    SUBCASE("Inicio fuera de rango y origen nulo");
    char *vacia = cadena_subcadena_dinamica("hola", 10, 8, 2);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 2));
}
 
TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion de cadena valida");
    char *inv = cadena_invertir_dinamica("abc123", 20);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("321cba", inv);
    cadena_liberar_segura(&inv);
 
    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10));
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
