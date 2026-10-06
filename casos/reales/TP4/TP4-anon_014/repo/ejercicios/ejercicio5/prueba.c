/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_lista_cadenas_agregar)
{
    SUBCASE("Agregar partiendo de la lista vacia");
    char **lista = lista_cadenas_crear();
    size_t cantidad = 0;
    ASSERT_PTR_NULL(lista);
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "uno"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "dos"));
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, "tres"));
    ASSERT_UINT_EQ(3, cantidad);
    ASSERT_STR_EQ("uno", lista[0]);
    ASSERT_STR_EQ("tres", lista[2]);

    SUBCASE("La lista guarda copias, no la cadena original");
    char original[] = "cuatro";
    ASSERT_TRUE(lista_cadenas_agregar(&lista, &cantidad, original));
    original[0] = 'X';
    ASSERT_STR_EQ("cuatro", lista[3]);

    SUBCASE("Argumentos nulos");
    ASSERT_FALSE(lista_cadenas_agregar(&lista, &cantidad, NULL));
    ASSERT_FALSE(lista_cadenas_agregar(NULL, &cantidad, "x"));
    ASSERT_UINT_EQ(4, cantidad);

    lista_cadenas_destruir(lista, cantidad);
    lista = NULL;
}

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Campos normales y vacios");
    size_t cantidad = 0;
    char **campos = dividir_linea_csv("Ana,,Bariloche,", ',', &cantidad);
    ASSERT_UINT_EQ(4, cantidad);
    ASSERT_STR_EQ("Ana", campos[0]);
    ASSERT_STR_EQ("", campos[1]);
    ASSERT_STR_EQ("Bariloche", campos[2]);
    ASSERT_STR_EQ("", campos[3]);
    liberar_arreglo_cadenas(&campos, cantidad);
    ASSERT_PTR_NULL(campos);

    SUBCASE("Otro delimitador");
    char **otros = dividir_linea_csv("1;2", ';', &cantidad);
    ASSERT_UINT_EQ(2, cantidad);
    ASSERT_STR_EQ("2", otros[1]);
    liberar_arreglo_cadenas(&otros, cantidad);

    SUBCASE("Linea nula");
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
    ASSERT_UINT_EQ(0, cantidad);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_lista_cadenas_agregar);
    RUN_TEST(prueba_dividir_linea_csv);
    return TEST_REPORT();
}
