/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include <string.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    char *clon = clonar_cadena("Hola");
    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("Hola", clon);
    cadena_liberar_segura(&clon);
    ASSERT_PTR_NULL(clon);

    char *clon_null = clonar_cadena(NULL);
    ASSERT_PTR_NULL(clon_null);
}

TEST(prueba_unir_cadenas_dinamicas)
{
    char *unida = unir_cadenas_dinamicas("Buenas ", "Noches");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Buenas Noches", unida);
    cadena_liberar_segura(&unida);
    ASSERT_PTR_NULL(unida);

    char *res1 = unir_cadenas_dinamicas(NULL, "Test");
    ASSERT_PTR_NULL(res1);
    char *res2 = unir_cadenas_dinamicas("Test", NULL);
    ASSERT_PTR_NULL(res2);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
