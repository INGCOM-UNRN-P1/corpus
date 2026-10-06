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
    SUBCASE("Clonacion exitosa");
    char origen[] = "Este texto va a ser clonado";
    char *ptr_clon = clonar_cadena(origen);
    ASSERT_PTR_NOT_NULL(ptr_clon);
    ASSERT_STR_EQ("Este texto va a ser clonado", ptr_clon);
    ASSERT_PTR_NE(origen, ptr_clon); // los punteros no son iguales ('origen'
                                     // apunta al stack 'clon' apunta al hep)
    cadena_liberar_segura(&ptr_clon);
    ASSERT_PTR_NULL(ptr_clon);

    SUBCASE("Cadena vacía");
    ptr_clon = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(ptr_clon);
    ASSERT_STR_EQ("", ptr_clon);
    cadena_liberar_segura(&ptr_clon);

    SUBCASE("puntero nulo");
    ASSERT_PTR_NULL(clonar_cadena(NULL));
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Union exitosa");
    char *ptr_union = unir_cadenas_dinamicas("Texto 1 - ", "Texto 2");
    ASSERT_PTR_NOT_NULL(ptr_union);
    ASSERT_STR_EQ("Texto 1 - Texto 2", ptr_union);
    cadena_liberar_segura(&ptr_union);
    ASSERT_PTR_NULL(ptr_union);

    SUBCASE("Primera cadena es "
            "");
    ptr_union = unir_cadenas_dinamicas("", "Texto 2");
    ASSERT_PTR_NOT_NULL(ptr_union);
    ASSERT_STR_EQ("Texto 2", ptr_union);
    cadena_liberar_segura(&ptr_union);

    SUBCASE("Segunda cadena es "
            "");
    ptr_union = unir_cadenas_dinamicas("Texto 1 -", "");
    ASSERT_PTR_NOT_NULL(ptr_union);
    ASSERT_STR_EQ("Texto 1 -", ptr_union);
    cadena_liberar_segura(&ptr_union);

    SUBCASE("Ambas son "
            "");
    ptr_union = unir_cadenas_dinamicas("", "");
    ASSERT_PTR_NOT_NULL(ptr_union);
    ASSERT_STR_EQ("", ptr_union);
    cadena_liberar_segura(&ptr_union);

    SUBCASE("punteros nulos");
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "test"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("test", NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);

    return TEST_REPORT();
}
