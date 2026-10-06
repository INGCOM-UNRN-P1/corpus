#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("clonacion de cadena normal");
    {
        char *clon = clonar_cadena("ingenieria");
        ASSERT_PTR_NOT_NULL(clon);
        ASSERT_STR_EQ("ingenieria", clon);
        free(clon);
    }

    SUBCASE("clonacion de cadena vacia");
    {
        char *clon = clonar_cadena("");
        ASSERT_PTR_NOT_NULL(clon);
        ASSERT_STR_EQ("", clon);
        free(clon);
    }

    SUBCASE("parametros invalidos");
    {
        ASSERT_PTR_NULL(clonar_cadena(NULL));
    }
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("union de dos cadenas normales");
    {
        char *unida = unir_cadenas_dinamicas("hola ", "mundo");
        ASSERT_PTR_NOT_NULL(unida);
        ASSERT_STR_EQ("hola mundo", unida);
        free(unida);
    }

    SUBCASE("union con una cadena vacia");
    {
        char *unida = unir_cadenas_dinamicas("test", "");
        ASSERT_PTR_NOT_NULL(unida);
        ASSERT_STR_EQ("test", unida);
        free(unida);
    }

    SUBCASE("parametros invalidos");
    {
        ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "mundo"));
        ASSERT_PTR_NULL(unir_cadenas_dinamicas("hola", NULL));
        ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, NULL));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("suite de pruebas: ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}