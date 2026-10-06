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

TEST(prueba_clonar_cadena)
{
    SUBCASE("Clonar cadena");
    char *copia = clonar_cadena("Hola mundo");

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("Hola mundo", copia);

    free(copia);

    SUBCASE("Cadena vacia");
    copia = clonar_cadena("");

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("", copia);

    free(copia);

    SUBCASE("Origen NULL");
    copia = clonar_cadena(NULL);

    ASSERT_PTR_NULL(copia);
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Unir dos cadenas");
    char *resultado = unir_cadenas_dinamicas("Hola ", "mundo");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("Hola mundo", resultado);

    free(resultado);

    SUBCASE("Unir cadenas vacias");
    resultado = unir_cadenas_dinamicas("", "");

    ASSERT_PTR_NOT_NULL(resultado);
    ASSERT_STR_EQ("", resultado);

    free(resultado);

    SUBCASE("Primera cadena NULL");
    resultado = unir_cadenas_dinamicas(NULL, "mundo");

    ASSERT_PTR_NULL(resultado);

    SUBCASE("Segunda cadena NULL");
    resultado = unir_cadenas_dinamicas("Hola", NULL);

    ASSERT_PTR_NULL(resultado);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
