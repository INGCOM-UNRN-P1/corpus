/**
 * @file prueba.c
 * @brief Pruebas unitarias de libstring con p1_test.
 */

#include "cadenas.h"
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

TEST(prueba_cadena_liberar_segura)
{
    SUBCASE("Liberación exitosa");
    char *ptr = malloc(sizeof("Esta cadena en el heap va a ser liberada"));
    ASSERT_PTR_NOT_NULL(ptr);
    strcpy(ptr, "Esta cadena en el heap va a ser liberada");
    ASSERT_PTR_NOT_NULL_MSG(ptr, "Esta cadena en el heap va a ser liberada");
    cadena_liberar_segura(&ptr);
    ASSERT_PTR_NULL(ptr);
}

TEST(prueba_cadena_subcadena_dinamica)
{
    SUBCASE("Extraer exitoso");
    char *sub = cadena_subcadena_dinamica("Hola Mundo", 20, 5, 5);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("Mundo", sub);
    cadena_liberar_segura(&sub);
    ASSERT_PTR_NULL(sub);

    SUBCASE("Extraer desde el comienzo hasta la mitad");
    sub = cadena_subcadena_dinamica("Hola Mundo", 20, 0, 4);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("Hola", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("Cantidad a extraer supera tamaño");
    sub = cadena_subcadena_dinamica("Hola Mundo", 20, 5, 100);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("Mundo", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("Cantidad = 0"); // devuelve ""
    sub = cadena_subcadena_dinamica("Hola Mundo", 20, 0, 0);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("Inicio igual que la longitud");
    sub = cadena_subcadena_dinamica("Hola Mundo", 20, 10, 10);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("Inicio mayor a la longitud");
    sub = cadena_subcadena_dinamica("Hola Mundo", 30, 20, 10);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("Cadena origen vacia");
    sub = cadena_subcadena_dinamica("", 5, 0, 5);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("capacidad_max insuficiente");
    sub = cadena_subcadena_dinamica("Hola Mundo", 4, 0, 10);
    ASSERT_PTR_NOT_NULL(sub);
    ASSERT_STR_EQ("Hola", sub);
    cadena_liberar_segura(&sub);

    SUBCASE("puntero nulo");
    ASSERT_PTR_NULL(cadena_subcadena_dinamica(NULL, 10, 0, 3));
}

TEST(prueba_cadena_invertir_dinamica)
{
    SUBCASE("Inversion de cadena exitosa par");
    char *inv = cadena_invertir_dinamica("hola", 10);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("aloh", inv);
    cadena_liberar_segura(&inv);
    ASSERT_PTR_NULL(inv);

    SUBCASE("Inversion de cadena exitosa impar");
    inv = cadena_invertir_dinamica("abcde", 10);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("edcba", inv);
    cadena_liberar_segura(&inv);

    SUBCASE("Cadena de un solo caracter");
    inv = cadena_invertir_dinamica("a", 5);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("a", inv);
    cadena_liberar_segura(&inv);

    SUBCASE("Cadena vacía");
    inv = cadena_invertir_dinamica("", 5);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("", inv);
    cadena_liberar_segura(&inv);

    SUBCASE("capacidad_max insuficiente");
    inv = cadena_invertir_dinamica("abcdef", 3);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("cba", inv);
    cadena_liberar_segura(&inv);

    SUBCASE("No modifica la cadena origen");
    char origen[] = "hola";
    inv = cadena_invertir_dinamica(origen, 5);
    ASSERT_PTR_NOT_NULL(inv);
    ASSERT_STR_EQ("hola", origen);
    ASSERT_STR_EQ("aloh", inv);
    cadena_liberar_segura(&inv);

    SUBCASE("puntero nulo y capacidad 0");
    ASSERT_PTR_NULL(cadena_invertir_dinamica(NULL, 10));
    ASSERT_PTR_NULL(cadena_invertir_dinamica("hola", 0));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libstring", conteo_args,
                          argumentos);
    RUN_TEST(prueba_cadena_duplicar_segura);
    RUN_TEST(prueba_cadena_unir_dinamica);
    RUN_TEST(prueba_cadena_liberar_segura);
    RUN_TEST(prueba_cadena_subcadena_dinamica);
    RUN_TEST(prueba_cadena_invertir_dinamica);
    return TEST_REPORT();
}
