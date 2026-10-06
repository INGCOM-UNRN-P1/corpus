/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "cadena_dinamica.h"
 
TEST(prueba_clonar_cadena)
{
    SUBCASE("Clon independiente del original");
    char origen[] = "hola";
    char *copia = clonar_cadena(origen);
    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("hola", copia);
    origen[0] = 'X';
    ASSERT_STR_EQ("hola", copia);
    free(copia);
 
    SUBCASE("Origen nulo");
    ASSERT_PTR_NULL(clonar_cadena(NULL));
}
 
TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Union de dos cadenas");
    char *unida = unir_cadenas_dinamicas("Hola ", "Mundo");
    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola Mundo", unida);
    free(unida);
 
    SUBCASE("Segunda vacia y argumentos nulos");
    char *solo_primera = unir_cadenas_dinamicas("abc", "");
    ASSERT_PTR_NOT_NULL(solo_primera);
    ASSERT_STR_EQ("abc", solo_primera);
    free(solo_primera);
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "x"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("x", NULL));
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
