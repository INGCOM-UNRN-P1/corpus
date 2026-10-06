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
#include "cadenas.h"

TEST(prueba_clonar_cadena)
{
    SUBCASE("Clonar cadena normal");
    char *copia = clonar_cadena("Hola Mundo");
    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("Hola Mundo", copia);
    cadena_liberar_segura(&copia);
    ASSERT_PTR_NULL(copia);
    

    SUBCASE("Clonar cadena vacia");
    char *copia_1 = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(copia_1);
    ASSERT_STR_EQ("", copia_1);
    cadena_liberar_segura(&copia_1);
    

    SUBCASE("Origen nulo");
    char *copia_2 = clonar_cadena(NULL);
    ASSERT_PTR_NULL(copia_2);
}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Concatenar dos cadenas normales");
    char *resultado_0 = unir_cadenas_dinamicas("Hola ", "Mundo");
    ASSERT_PTR_NOT_NULL(resultado_0);
    ASSERT_STR_EQ("Hola Mundo", resultado_0);
    cadena_liberar_segura(&resultado_0);
    ASSERT_PTR_NULL(resultado_0);
    
    SUBCASE("Primera cadena vacia");
    char *resultado_1 = unir_cadenas_dinamicas("", "Mundo");
    ASSERT_PTR_NOT_NULL(resultado_1);
    ASSERT_STR_EQ("Mundo", resultado_1);
    cadena_liberar_segura(&resultado_1);
    ASSERT_PTR_NULL(resultado_1);

    SUBCASE("Segunda cadena vacia");
    char *resultado_2 = unir_cadenas_dinamicas("Hola", "");
    ASSERT_PTR_NOT_NULL(resultado_2);
    ASSERT_STR_EQ("Hola", resultado_2);
    cadena_liberar_segura(&resultado_2);
    ASSERT_PTR_NULL(resultado_2);

    SUBCASE("Ambas cadenas vacias");
    char *resultado_3 = unir_cadenas_dinamicas("", "");
    ASSERT_PTR_NOT_NULL(resultado_3);
    ASSERT_STR_EQ("", resultado_3);
    cadena_liberar_segura(&resultado_3);
    ASSERT_PTR_NULL(resultado_3);

    SUBCASE("Primera cadena nula");
    char *resultado_4 = unir_cadenas_dinamicas(NULL, "Mundo");
    ASSERT_PTR_NULL(resultado_4);

    SUBCASE("Segunda cadena nula");
    char *resultado_5 = unir_cadenas_dinamicas("Hola", NULL);
    ASSERT_PTR_NULL(resultado_5);

    SUBCASE("Ambas cadenas nulas"); 
    char *resultado_6 = unir_cadenas_dinamicas(NULL, NULL);
    ASSERT_PTR_NULL(resultado_6);
}




int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
