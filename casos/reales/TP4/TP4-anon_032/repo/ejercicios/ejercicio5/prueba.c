/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "lista_dinamica.h"

TEST(prueba_lista_cadenas_crear_agregar)
{
    SUBCASE("Caso normal");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;
    ASSERT_PTR_NULL(lista);
    lista_cadenas_agregar(&lista, &cantidad, "Hola", 5);
    ASSERT_PTR_NOT_NULL(lista);
    lista_cadenas_agregar(&lista, &cantidad, ", ", 3);
    lista_cadenas_agregar(&lista, &cantidad, "Mundo!", 7);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("Hola", lista[0]);
    ASSERT_STR_EQ(", ", lista[1]);
    ASSERT_STR_EQ("Mundo!", lista[2]);
    lista_cadenas_destruir(lista, cantidad);

    SUBCASE("Caso con truncamiento");
    char **lista_truncada = lista_cadenas_crear();
    cantidad = 0;
    lista_cadenas_agregar(&lista_truncada, &cantidad, "Hola, Mundo!", 3);
    ASSERT_STR_EQ("Hol", lista_truncada[0]);
    lista_cadenas_destruir(lista_truncada, cantidad);

    SUBCASE("Parametros invalidos");
    char **invalida = lista_cadenas_crear();
    ASSERT_FALSE(lista_cadenas_agregar(&invalida, NULL, "", 1));
    ASSERT_FALSE(lista_cadenas_agregar(NULL, &cantidad, "", 1));
    ASSERT_FALSE(lista_cadenas_agregar(&invalida, &cantidad, NULL, 1));
    ASSERT_FALSE(lista_cadenas_agregar(&invalida, &cantidad, "", 0));
}

TEST(prueba_lista_cadenas_destruir)
{
    SUBCASE("Caso normal");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;
    lista_cadenas_agregar(&lista, &cantidad, "holis", 6);
    lista_cadenas_destruir(lista, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_lista_cadenas_crear_agregar);
    RUN_TEST(prueba_lista_cadenas_destruir);
    return TEST_REPORT();
}
