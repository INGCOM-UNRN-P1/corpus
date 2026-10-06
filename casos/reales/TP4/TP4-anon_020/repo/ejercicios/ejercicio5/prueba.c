/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Tokenizacion simple");
    char **tokens = NULL;
    size_t cantidad = 0U;

    tokens = dividir_linea_csv("a,b,c", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("a", tokens[0]);
    ASSERT_STR_EQ("b", tokens[1]);
    ASSERT_STR_EQ("c", tokens[2]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);

    SUBCASE("Linea de un solo token");
    tokens = dividir_linea_csv("solo", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("solo", tokens[0]);
    liberar_arreglo_cadenas(&tokens, cantidad);

    SUBCASE("Argumentos invalidos");
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
    ASSERT_PTR_NULL(dividir_linea_csv("a,b", ',', NULL));
}

TEST(prueba_lista_cadenas)
{
    SUBCASE("Lista vacia");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0U;
    ASSERT_PTR_NULL(lista);
    ASSERT_INT_EQ(0, (int)cantidad);

    SUBCASE("Agregar elementos a la lista");
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "uno"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "dos"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "tres"));
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("uno", lista[0]);
    ASSERT_STR_EQ("dos", lista[1]);
    ASSERT_STR_EQ("tres", lista[2]);
    lista_cadenas_destruir(lista, cantidad);

    SUBCASE("Argumentos invalidos");
    char **lista_invalida = NULL;
    size_t cant_inv = 0U;
    ASSERT_FALSE(lista_cadenas_agregar(NULL, &cant_inv, "x"));
    ASSERT_FALSE(lista_cadenas_agregar(&lista_invalida, NULL, "x"));
    ASSERT_FALSE(lista_cadenas_agregar(&lista_invalida, &cant_inv, NULL));
    lista_cadenas_destruir(NULL, 0U);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_lista_cadenas);
    return TEST_REPORT();
}