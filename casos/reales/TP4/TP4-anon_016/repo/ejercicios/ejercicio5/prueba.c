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
 
    SUBCASE("Linea normal");
    char **tokens = dividir_linea_csv("a,b,c", ',', &cantidad);
    ASSERT_TRUE(tokens != NULL);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("a", tokens[0]);
    ASSERT_STR_EQ("c", tokens[2]);
    liberar_arreglo_cadenas(&tokens, cantidad);
    ASSERT_TRUE(tokens == NULL);
 
    SUBCASE("Campo vacio en el medio");
    char **con_vacio = dividir_linea_csv("a,,b", ',', &cantidad);
    ASSERT_TRUE(con_vacio != NULL);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_STR_EQ("", con_vacio[1]);
    liberar_arreglo_cadenas(&con_vacio, cantidad);
 
    SUBCASE("Linea vacia");
    char **vacia = dividir_linea_csv("", ',', &cantidad);
    ASSERT_TRUE(vacia != NULL);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_STR_EQ("", vacia[0]);
    liberar_arreglo_cadenas(&vacia, cantidad);
 
    SUBCASE("Linea NULL");
    ASSERT_TRUE(dividir_linea_csv(NULL, ',', &cantidad) == NULL);
}
 
TEST(prueba_liberar_arreglo_cadenas)
{
    SUBCASE("Puntero NULL no hace nada");
    char **nulo = NULL;
    liberar_arreglo_cadenas(NULL, 0);
    liberar_arreglo_cadenas(&nulo, 0);
    ASSERT_TRUE(nulo == NULL);
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);
    RUN_TEST(prueba_dividir_linea_csv);
    RUN_TEST(prueba_liberar_arreglo_cadenas);
    return TEST_REPORT();
}
