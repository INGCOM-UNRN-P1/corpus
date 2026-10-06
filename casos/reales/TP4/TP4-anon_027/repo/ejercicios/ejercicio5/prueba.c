/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv)
{
    SUBCASE("Separar linea CSV estandar");
    const char *linea_0 = "Juan,Perez,30";
    size_t cant_tokens_0 = 0;
    char **tokens_0 = dividir_linea_csv(linea_0, ',', &cant_tokens_0);
    ASSERT_PTR_NOT_NULL(tokens_0);
    ASSERT_INT_EQ(3, (int)cant_tokens_0);
    ASSERT_STR_EQ("Juan", tokens_0[0]);
    ASSERT_STR_EQ("Perez", tokens_0[1]);
    ASSERT_STR_EQ("30", tokens_0[2]);
    liberar_arreglo_cadenas(&tokens_0, cant_tokens_0);
    ASSERT_PTR_NULL(tokens_0);

    SUBCASE("Campos vacios intermedios");
    const char *linea_1 = "a,,c";
    size_t cant_tokens_1 = 0;
    char **tokens_1 = dividir_linea_csv(linea_1, ',', &cant_tokens_1);
    ASSERT_PTR_NOT_NULL(tokens_1);
    ASSERT_INT_EQ(3, (int)cant_tokens_1);
    ASSERT_STR_EQ("a", tokens_1[0]);
    ASSERT_STR_EQ("", tokens_1[1]);
    ASSERT_STR_EQ("c", tokens_1[2]);
    liberar_arreglo_cadenas(&tokens_1, cant_tokens_1);
    ASSERT_PTR_NULL(tokens_1);
    

    SUBCASE("Linea sin delimitadores");
    const char *linea_2 = "palabra_unica";
    size_t cant_tokens_2 = 0;
    char **tokens_2 = dividir_linea_csv(linea_2, ';', &cant_tokens_2);
    ASSERT_PTR_NOT_NULL(tokens_2);
    ASSERT_INT_EQ(1, (int)cant_tokens_2);
    ASSERT_STR_EQ("palabra_unica", tokens_2[0]);
    liberar_arreglo_cadenas(&tokens_2, cant_tokens_2);
    ASSERT_PTR_NULL(tokens_2);
    

    SUBCASE("Validacion de punteros NULL");
    size_t cant_tokens_3 = 10;
    char **res_null_linea = dividir_linea_csv(NULL, ',', &cant_tokens_3);
    ASSERT_PTR_NULL(res_null_linea);
    char **res_null_cant = dividir_linea_csv("hola,mundo", ',', NULL);
    ASSERT_PTR_NULL(res_null_cant);
}


TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Liberacion normal de arreglo de cadenas");
    size_t cantidad_0 = 3;
    char **lineas_0 = malloc(cantidad_0 * sizeof(char *));
    ASSERT_PTR_NOT_NULL(lineas_0);
    lineas_0[0] = strdup("Alfa");
    lineas_0[1] = strdup("Beta");
    lineas_0[2] = strdup("Gamma");
    liberar_arreglo_cadenas(&lineas_0, cantidad_0);
    ASSERT_PTR_NULL(lineas_0);
    

    SUBCASE("Arreglo con elementos NULL intermedios");
    size_t cantidad_1 = 3;
    char **lineas_1 = malloc(cantidad_1 * sizeof(char *));
    ASSERT_PTR_NOT_NULL(lineas_1);
    lineas_1[0] = strdup("Primero");
    lineas_1[1] = NULL;
    lineas_1[2] = strdup("Tercero");
    liberar_arreglo_cadenas(&lineas_1, cantidad_1);
    ASSERT_PTR_NULL(lineas_1);
    

    SUBCASE("Arreglo con cantidad cero");
    size_t cantidad_2 = 0;
    char **lineas_2 = malloc(sizeof(char *));
    ASSERT_PTR_NOT_NULL(lineas_2);
    liberar_arreglo_cadenas(&lineas_2, cantidad_2);
    ASSERT_PTR_NULL(lineas_2);
    

    SUBCASE("Robustez ante punteros NULL");
    char **lineas_null = NULL;
    liberar_arreglo_cadenas(&lineas_null, 5);
    ASSERT_PTR_NULL(lineas_null);
    liberar_arreglo_cadenas(NULL, 5);
}




int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_cadenas);
    return TEST_REPORT();
}
