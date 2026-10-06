/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include "cadena_dinamica.h"
#include "p1_test.h"
#include <stdio.h>
#include <stdlib.h>



TEST(prueba_clonar_cadena_valida)
{
    const char *origen = "Hola Mundo";
    char *clon = clonar_cadena(origen);

    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_PTR_NE(
        origen,
        clon); // Verifica que apunten a direcciones de memoria distintas.
    ASSERT_STR_EQ(origen, clon);

    free(clon);
}

TEST(prueba_clonar_cadena_vacia)
{
    char *clon = clonar_cadena("");

    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("", clon);

    free(clon);
}

TEST(prueba_clonar_cadena_null)
{
    char *clon = clonar_cadena(NULL);

    ASSERT_PTR_NULL(clon);
}



TEST(prueba_unir_cadenas_valida)
{
    char *resultado = unir_cadenas_dinamicas("Hola ", "Mundo");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola Mundo", resultado);

    free(resultado);
}

TEST(prueba_unir_cadenas_con_vacia)
{
    char *resultado = unir_cadenas_dinamicas("Hola", "");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola", resultado);

    free(resultado);
}

TEST(prueba_unir_cadenas_null)
{
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "Mundo"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("Hola", NULL));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, NULL));
}



int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);

    RUN_TEST(prueba_clonar_cadena_valida);
    RUN_TEST(prueba_clonar_cadena_vacia);
    RUN_TEST(prueba_clonar_cadena_null);

    RUN_TEST(prueba_unir_cadenas_valida);
    RUN_TEST(prueba_unir_cadenas_con_vacia);
    RUN_TEST(prueba_unir_cadenas_null);

    return TEST_REPORT();
}
