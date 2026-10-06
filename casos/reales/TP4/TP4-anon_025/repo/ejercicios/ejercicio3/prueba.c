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
#include <stdlib.h>

static void destruir_cadena(char **puntero)
{
    if (puntero != NULL && *puntero != NULL)
    {
        free(*puntero);
        *puntero = NULL;
    }
}

TEST(prueba_clonar_cadena)
{
    
    SUBCASE("Clonacion normal");
    char *copia = clonar_cadena("UNRN");
    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("UNRN", copia);
    destruir_cadena(&copia);
    ASSERT_PTR_NULL(copia);

    SUBCASE("Casos borde (cadena vacia y NULL)");
    char *vacia = clonar_cadena("");
    ASSERT_PTR_NOT_NULL(vacia);
    ASSERT_STR_EQ("", vacia);
    destruir_cadena(&vacia);
    ASSERT_PTR_NULL(clonar_cadena(NULL));

}

TEST(prueba_unir_cadenas_dinamicas)
{
    SUBCASE("Union normal");
    char *union_cadena = unir_cadenas_dinamicas("Hola ", "mundo");
    ASSERT_PTR_NOT_NULL(union_cadena);
    ASSERT_STR_EQ("Hola mundo", union_cadena);
    destruir_cadena(&union_cadena);

    SUBCASE("Casos borde (entrada nulas)");
    ASSERT_PTR_NULL(unir_cadenas_dinamicas("Algo", NULL));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, "Algo"));
    ASSERT_PTR_NULL(unir_cadenas_dinamicas(NULL, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);
    return TEST_REPORT();
}
