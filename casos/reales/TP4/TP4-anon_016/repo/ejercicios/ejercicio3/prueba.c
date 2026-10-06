/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "cadena_dinamica.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("Cadena normal");
    const char *original = "hola";
    char *copia = clonar_cadena(original);
    ASSERT_TRUE(copia != NULL);
    ASSERT_TRUE(copia != original);
    ASSERT_STR_EQ("hola", copia);
    cadena_liberar_segura(&copia);
 
    SUBCASE("Cadena vacia");
    char *vacia = clonar_cadena("");
    ASSERT_TRUE(vacia != NULL);
    ASSERT_STR_EQ("", vacia);
    cadena_liberar_segura(&vacia);
 
    SUBCASE("Origen NULL");
    ASSERT_TRUE(clonar_cadena(NULL) == NULL);
}
 
TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Dos cadenas normales");
    char *unida = unir_cadenas_dinamicas("ho", "la");
    ASSERT_TRUE(unida != NULL);
    ASSERT_STR_EQ("hola", unida);
    cadena_liberar_segura(&unida);
 
    SUBCASE("Una cadena vacia");
    char *con_vacia = unir_cadenas_dinamicas("", "hola");
    ASSERT_TRUE(con_vacia != NULL);
    ASSERT_STR_EQ("hola", con_vacia);
    cadena_liberar_segura(&con_vacia);
 
    SUBCASE("Las dos vacias");
    char *ambas_vacias = unir_cadenas_dinamicas("", "");
    ASSERT_TRUE(ambas_vacias != NULL);
    ASSERT_STR_EQ("", ambas_vacias);
    cadena_liberar_segura(&ambas_vacias);
 
    SUBCASE("Alguna cadena NULL");
    ASSERT_TRUE(unir_cadenas_dinamicas(NULL, "la") == NULL);
    ASSERT_TRUE(unir_cadenas_dinamicas("ho", NULL) == NULL);
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args,
                          argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
 
