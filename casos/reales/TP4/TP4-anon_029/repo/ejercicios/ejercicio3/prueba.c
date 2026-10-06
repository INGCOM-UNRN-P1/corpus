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

TEST(prueba_clonar_cadena)
{
    SUBCASE("Origen no NULL");
    const char *origen = "Hola";
    char *clon = clonar_cadena(origen);
    ASSERT_PTR_NOT_NULL(clon);
    free(clon);
    clon = NULL;

    SUBCASE("Origen NULL");
    char *clon_fallido = clonar_cadena(NULL);
    ASSERT_PTR_NULL(clon_fallido);

    SUBCASE("Caso valido");
    const char *cadena = "Funciona";
    char *clon_correcto = clonar_cadena(cadena);
    ASSERT_STR_EQ("Funciona", clon_correcto);
    free(clon_correcto);
    clon_correcto = NULL;
}

TEST(prueba_unir_cadenas_dinamicas)
{
    const char *primera = "Hola";
    const char *segunda = " mundo";

    SUBCASE("Primera y segunda no NULL");
    char *unido = unir_cadenas_dinamicas(primera, segunda);
    ASSERT_PTR_NOT_NULL(unido);
    free(unido);
    unido = NULL;

    SUBCASE("Primero y Segunda NULL");
    char *union_fallida_primera = unir_cadenas_dinamicas(NULL, segunda);
    ASSERT_PTR_NULL(union_fallida_primera);
    char *union_fallida_segunda = unir_cadenas_dinamicas(primera, NULL);
    ASSERT_PTR_NULL(union_fallida_segunda);
    char *union_fallida_total = unir_cadenas_dinamicas(NULL, NULL);
    ASSERT_PTR_NULL(union_fallida_total);

    SUBCASE("Caso valido");
    char *union_valida = unir_cadenas_dinamicas(primera, segunda);
    ASSERT_STR_EQ("Hola mundo", union_valida);
    free(union_valida);
    union_valida = NULL;
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
