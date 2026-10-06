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
    SUBCASE("Clonacion de cadena valida");
    const char *original = "Programacion 1";
    char *clon = clonar_cadena(original);
    ASSERT_PTR_NOT_NULL(clon);
    ASSERT_STR_EQ("Programacion 1", clon);
    ASSERT_TRUE(clon != original);
    free(clon);
 
    SUBCASE("Clonacion de cadena vacia");
    char *vacia = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    free(vacia);
 
    SUBCASE("El clon es independiente del original");
    char modificable[] = "hola";
    char *copia = clonar_cadena(modificable);
    ASSERT_PTR_NOT_NULL(copia);
    modificable[0] = 'X';
    ASSERT_STR_EQ("hola", copia);
    ASSERT_STR_EQ("Xola", modificable);
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
 
    SUBCASE("Union con una cadena vacia");
    char *con_vacia_izq = unir_cadenas_dinamicas("", "abc");
    ASSERT_PTR_NOT_NULL(con_vacia_izq);
    ASSERT_STR_EQ("abc", con_vacia_izq);
    free(con_vacia_izq);
 
    char *con_vacia_der = unir_cadenas_dinamicas("abc", "");
    ASSERT_PTR_NOT_NULL(con_vacia_der);
    ASSERT_STR_EQ("abc", con_vacia_der);
    free(con_vacia_der);
 
    SUBCASE("Union de dos cadenas vacias");
    char *ambas_vacias = unir_cadenas_dinamicas("", "");
    ASSERT_PTR_NOT_NULL(ambas_vacias);
    ASSERT_STR_EQ("", ambas_vacias);
    free(ambas_vacias);
 
    SUBCASE("El resultado es independiente de las entradas");
    char primera[] = "ab";
    char segunda[] = "cd";
    char *resultado = unir_cadenas_dinamicas(primera, segunda);
    ASSERT_PTR_NOT_NULL(resultado);
    primera[0] = 'X';
    segunda[0] = 'Y';
    ASSERT_STR_EQ("abcd", resultado);
    free(resultado);
 
    SUBCASE("Entradas nulas");
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "abc"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("abc", NULL));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, NULL));
}
 
int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
