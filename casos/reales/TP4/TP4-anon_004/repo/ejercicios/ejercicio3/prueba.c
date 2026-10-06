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
#include <stdlib.h>

TEST(prueba_clonar_cadena)
{
    char original[] = "UNRN";
    char *copia = NULL;

    SUBCASE("Copia independiente y terminada");

    copia = clonar_cadena(original);

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_PTR_NE(original, copia);
    ASSERT_STR_EQ("UNRN", copia);
    ASSERT_INT_EQ('\0', copia[4]);

    copia[0] = 'u';

    ASSERT_STR_EQ("UNRN", original);

    free(copia);
    copia = NULL;


    SUBCASE("Cadena vacia");

    copia = clonar_cadena("");

    ASSERT_PTR_NOT_NULL(copia);
    ASSERT_STR_EQ("", copia);

    free(copia);
    copia = NULL;


    SUBCASE("Entrada nula");

    ASSERT_PTR_NULL(
        clonar_cadena(NULL)
    );
}

TEST(prueba_unir_cadenas_dinamicas)
{
    char primera[] = "Hola ";
    char segunda[] = "UNRN";

    const char *entradas[] = {"", "UNRN", ""};
    const char *segundas[] = {"UNRN", "", ""};
    const char *esperadas[] = {"UNRN", "UNRN", ""};

    char *unida = NULL;
    size_t posicion = 0;


    SUBCASE("Union independiente sin alterar originales");

    unida = unir_cadenas_dinamicas(
        primera,
        segunda
    );

    ASSERT_PTR_NOT_NULL(unida);
    ASSERT_STR_EQ("Hola UNRN", unida);
    ASSERT_INT_EQ('\0', unida[9]);

    unida[0] = 'h';

    ASSERT_STR_EQ("Hola ", primera);
    ASSERT_STR_EQ("UNRN", segunda);

    free(unida);
    unida = NULL;


    SUBCASE("Una o ambas cadenas vacias");

    for (posicion = 0; posicion < 3; posicion++)
    {
        unida = unir_cadenas_dinamicas(
            entradas[posicion],
            segundas[posicion]
        );

        ASSERT_PTR_NOT_NULL(unida);
        ASSERT_STR_EQ(
            esperadas[posicion],
            unida
        );

        free(unida);
        unida = NULL;
    }


    SUBCASE("Parametros nulos");

    ASSERT_PTR_NULL(
        unir_cadenas_dinamicas(NULL, "UNRN")
    );

    ASSERT_PTR_NULL(
        unir_cadenas_dinamicas("UNRN", NULL)
    );

    ASSERT_PTR_NULL(
        unir_cadenas_dinamicas(NULL, NULL)
    );
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 3",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_clonar_cadena);
    RUN_TEST(prueba_unir_cadenas_dinamicas);

    return TEST_REPORT();
}
