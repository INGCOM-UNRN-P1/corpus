/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "registro_csv.h"

TEST(prueba_dividir_linea_csv_basico)
{
    SUBCASE("Linea con tres campos");
    size_t cantidad = 99;
    char **tokens = dividir_linea_csv("Juan,25,Bariloche", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("Juan", tokens[0]);
    ASSERT_STR_EQ("25", tokens[1]);
    ASSERT_STR_EQ("Bariloche", tokens[2]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);
 
    SUBCASE("Linea sin delimitador: un unico campo");
    char **unico = dividir_linea_csv("hola", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(unico);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("hola", unico[0]);
    liberar_arreglo_cadenas(&unico, cantidad);
 
    SUBCASE("Otro delimitador");
    char **puntos = dividir_linea_csv("a;b c;d", ';', &cantidad);
    ASSERT_PTR_NOT_NULL(puntos);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("a", puntos[0]);
    ASSERT_STR_EQ("b c", puntos[1]);
    ASSERT_STR_EQ("d", puntos[2]);
    liberar_arreglo_cadenas(&puntos, cantidad);
}
 
TEST(prueba_dividir_linea_csv_campos_vacios)
{
    size_t cantidad = 99;
 
    SUBCASE("Campo vacio en el medio");
    char **medio = dividir_linea_csv("a,,c", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(medio);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("a", medio[0]);
    ASSERT_STR_EQ("", medio[1]);
    ASSERT_STR_EQ("c", medio[2]);
    liberar_arreglo_cadenas(&medio, cantidad);
 
    SUBCASE("Campos vacios al principio y al final");
    char **bordes = dividir_linea_csv(",a,", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(bordes);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("", bordes[0]);
    ASSERT_STR_EQ("a", bordes[1]);
    ASSERT_STR_EQ("", bordes[2]);
    liberar_arreglo_cadenas(&bordes, cantidad);
 
    SUBCASE("Linea vacia: un unico campo vacio");
    char **vacia = dividir_linea_csv("", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("", vacia[0]);
    liberar_arreglo_cadenas(&vacia, cantidad);
 
    SUBCASE("Solo delimitadores");
    char **solo = dividir_linea_csv(",,", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(solo);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("", solo[0]);
    ASSERT_STR_EQ("", solo[1]);
    ASSERT_STR_EQ("", solo[2]);
    liberar_arreglo_cadenas(&solo, cantidad);
}
 
TEST(prueba_dividir_linea_csv_independencia_y_errores)
{
    SUBCASE("Los campos son copias independientes de la linea");
    char linea[] = "ab,cd";
    size_t cantidad = 99;
    char **tokens = dividir_linea_csv(linea, ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    ASSERT_INT_EQ(2, (int)cantidad);
    ASSERT_TRUE(tokens[0] != linea);
    linea[0] = 'X';
    linea[3] = 'Y';
    ASSERT_STR_EQ("ab", tokens[0]);
    ASSERT_STR_EQ("cd", tokens[1]);
    liberar_arreglo_cadenas(&tokens, cantidad);
 
    SUBCASE("Linea nula: retorna NULL y cantidad 0");
    cantidad = 99;
    ASSERT_PTR_NULL(dividir_linea_csv(NULL, ',', &cantidad));
    ASSERT_INT_EQ(0, (int)cantidad);
 
    SUBCASE("Puntero de cantidad nulo");
    ASSERT_PTR_NULL(dividir_linea_csv("a,b", ',', NULL));
}
 
TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Liberar deja el puntero en NULL");
    size_t cantidad = 0;
    char **tokens = dividir_linea_csv("x,y,z", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(tokens);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_PTR_NULL(tokens);
 
    SUBCASE("Liberar punteros nulos no hace nada");
    char **nulo = NULL;
    liberar_arreglo_cadenas(&nulo, 3);
    ASSERT_PTR_NULL(nulo);
    liberar_arreglo_cadenas(NULL, 3);
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_dividir_linea_csv_basico);
    RUN_TEST(prueba_dividir_linea_csv_campos_vacios);
    RUN_TEST(prueba_dividir_linea_csv_independencia_y_errores);
    RUN_TEST(prueba_liberar_arreglo_cadenas);
    return TEST_REPORT();
}
