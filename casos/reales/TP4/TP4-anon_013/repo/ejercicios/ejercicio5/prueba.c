/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    size_t cantidad = 0;
    int error = SIN_ERROR;

    SUBCASE("Particion exitosa");
    char **tokens = dividir_linea_csv("Cadena separada exitosamente", ' ', &cantidad, &error);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(3, cantidad);
    ASSERT_INT_EQ(SIN_ERROR, error);
    ASSERT_STR_EQ("Cadena", tokens[0]);
    ASSERT_STR_EQ("separada", tokens[1]);
    ASSERT_STR_EQ("exitosamente", tokens[2]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);

    SUBCASE("Separador que no sea espacio");
    tokens = dividir_linea_csv("Cadena separada;exitosamene", ';', &cantidad, &error);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(2, cantidad);
    ASSERT_STR_EQ("Cadena separada", tokens[0]);
    ASSERT_STR_EQ("exitosamene", tokens[1]);
    liberar_arreglo_cadenas(&tokens, cantidad);

    SUBCASE("Linea sin separador");
    tokens = dividir_linea_csv("hola", ',', &cantidad, &error);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(1, cantidad);
    ASSERT_STR_EQ("hola", tokens[0]);
    liberar_arreglo_cadenas(&tokens, cantidad);

    SUBCASE("Delimitadores seguidos y en los extremos");
    tokens = dividir_linea_csv(",,,Este vale,,,Este tambien,,,", ',', &cantidad, &error);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(2, cantidad);
    ASSERT_STR_EQ("Este vale", tokens[0]);
    ASSERT_STR_EQ("Este tambien", tokens[1]);
    liberar_arreglo_cadenas(&tokens, cantidad);

    SUBCASE("Punteros nulos (salvo error)");
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad, &error));
    ASSERT_INT_EQ(ERROR_PUNTERO_NULO, error);
    ASSERT_PTR_NULL(dividir_linea_csv("a,b", ',', NULL, &error));
    ASSERT_INT_EQ(ERROR_PUNTERO_NULO, error);

    SUBCASE("Linea vacia");
    ASSERT_PTR_NULL(dividir_linea_csv("", ',', &cantidad, &error));
    ASSERT_INT_EQ(ERROR_CAPACIDAD, error);

    SUBCASE("Linea de solo delimitadores");
    ASSERT_PTR_NULL(dividir_linea_csv(",,,,,", ',', &cantidad, &error));
    ASSERT_INT_EQ(ERROR_SIN_CARACTER_VALIDO, error);
    ASSERT_UINT_EQ(0, cantidad);

    SUBCASE("Si error es NULL no psa nada");
    tokens = dividir_linea_csv("a,b", ',', &cantidad, NULL);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_UINT_EQ(2, cantidad);
    liberar_arreglo_cadenas(&tokens, cantidad);
}

TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Liberacion anula el puntero");
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("a,s,d,f,g,h", ',', &cantidad, NULL);
    ASSERT_PTR_NOT_NULL(tokens);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);

    SUBCASE("Punteros nulos (no deberia explotar)");
    char **nulo = NULL;
    liberar_arreglo_cadenas(&nulo, 0);
    liberar_arreglo_cadenas(NULL, 0);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_cadenas);

    return TEST_REPORT();
}
