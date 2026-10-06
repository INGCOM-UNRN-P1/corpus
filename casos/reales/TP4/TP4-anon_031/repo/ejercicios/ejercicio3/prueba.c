/**
 * @file prueba.c
 * @brief Pruebas unitarias del Ejercicio 3.
 */

#include <stdlib.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_y_unir_cadenas)
{
    char *clon = clonar_cadena("memoria");
    char *unida = unir_cadenas_dinamicas("Programacion ", "I");

    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("memoria", clon);
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Programacion I", unida);

    free(clon);
    free(unida);

    ASSERT_PTR_NULL(clonar_cadena(NULL));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "x"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("x", NULL));
}

TEST(prueba_invertir_cadena_dinamico)
{
    char *invertida = invertir_cadena_dinamico("abcdef");
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("fedcba", invertida);
    free(invertida);

    invertida = invertir_cadena_dinamico("");
    ASSERT_PTR_NOT_NULL(invertida);
    ASSERT_STR_EQ("", invertida);
    free(invertida);

    ASSERT_PTR_NULL(invertir_cadena_dinamico(NULL));
}

TEST(prueba_partir_por_delimitador)
{
    size_t cantidad = 0U;
    char **partes = partir_por_delimitador("uno,dos,tres", ',', &cantidad);

    ASSERT_PTR_NOT_NULL(partes);
    ASSERT_UINT_EQ(3U, cantidad);
    ASSERT_STR_EQ("uno", partes[0]);
    ASSERT_STR_EQ("dos", partes[1]);
    ASSERT_STR_EQ("tres", partes[2]);
    liberar_partes_cadena(&partes, cantidad);
    ASSERT_PTR_NULL(partes);

    SUBCASE("Conserva campos vacios");
    partes = partir_por_delimitador("a,,b,", ',', &cantidad);
    ASSERT_PTR_NOT_NULL(partes);
    ASSERT_UINT_EQ(4U, cantidad);
    ASSERT_STR_EQ("a", partes[0]);
    ASSERT_STR_EQ("", partes[1]);
    ASSERT_STR_EQ("b", partes[2]);
    ASSERT_STR_EQ("", partes[3]);
    liberar_partes_cadena(&partes, cantidad);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(partir_por_delimitador(NULL, ',', &cantidad));
    ASSERT_PTR_NULL(partir_por_delimitador("abc", ',', NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_y_unir_cadenas);
    RUN_TEST(prueba_invertir_cadena_dinamico);
    RUN_TEST(prueba_partir_por_delimitador);
    return TEST_REPORT();
}
