/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("Copia completa, cabe con margen");
    char buffer[10];
    ASSERT_TRUE(copiar_con_punteros(buffer, sizeof(buffer), "Hola"));
    ASSERT_TRUE(strcmp(buffer, "Hola") == 0);

    SUBCASE("Truncamiento por capacidad insuficiente");
    char buffer_chico[4];
    ASSERT_FALSE(copiar_con_punteros(buffer_chico, sizeof(buffer_chico), "Bariloche"));
    ASSERT_INT_EQ(3, (int)strlen(buffer_chico));

    SUBCASE("Parametros invalidos");
    char buffer_err[5];
    ASSERT_FALSE(copiar_con_punteros(NULL, 5, "Hola"));
    ASSERT_FALSE(copiar_con_punteros(buffer_err, 5, NULL));
    ASSERT_FALSE(copiar_con_punteros(buffer_err, 0, "Hola"));
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("Concatenacion completa, cabe con margen");
    char buffer[12] = "Hola";
    ASSERT_TRUE(concatenar_con_punteros(buffer, sizeof(buffer), " Mundo"));
    ASSERT_TRUE(strcmp(buffer, "Hola Mundo") == 0);

    SUBCASE("Truncamiento por capacidad insuficiente");
    char buffer_chico[8] = "Hola";
    ASSERT_FALSE(concatenar_con_punteros(buffer_chico, sizeof(buffer_chico), " Mundo"));
    ASSERT_INT_EQ(7, (int)strlen(buffer_chico));

    SUBCASE("Parametros invalidos");
    char buffer_err[5] = "";
    ASSERT_FALSE(concatenar_con_punteros(NULL, 5, "Hola"));
    ASSERT_FALSE(concatenar_con_punteros(buffer_err, 5, NULL));
    ASSERT_FALSE(concatenar_con_punteros(buffer_err, 0, "Hola"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
