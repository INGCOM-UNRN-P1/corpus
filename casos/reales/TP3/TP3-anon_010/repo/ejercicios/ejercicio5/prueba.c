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

TEST(prueba_longitud_con_punteros)
{
    SUBCASE("Longitud normal");
    ASSERT_INT_EQ(5, (int)longitud_con_punteros("Hola!", 10));

    SUBCASE("Sin terminador dentro de la capacidad");
    ASSERT_INT_EQ(3, (int)longitud_con_punteros("abc", 3));

    SUBCASE("Cadena nula");
    ASSERT_INT_EQ(10, (int)longitud_con_punteros(NULL, 10));
}

TEST(prueba_copiar_con_punteros)
{
    char destino[10];

    SUBCASE("Copia completa");
    ASSERT_TRUE(copiar_con_punteros(destino, 10, "Hola"));
    ASSERT_STR_EQ("Hola", destino);

    SUBCASE("Truncamiento por capacidad");
    char destino_corto[3];
    ASSERT_FALSE(copiar_con_punteros(destino_corto, 3, "Hola"));
    ASSERT_STR_EQ("Ho", destino_corto);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "Hola"));
    ASSERT_FALSE(copiar_con_punteros(destino, 10, NULL));
}

TEST(prueba_concatenar_con_punteros)
{
    char destino[10] = "Hola";

    SUBCASE("Concatenacion completa");
    ASSERT_TRUE(concatenar_con_punteros(destino, 10, "!!"));
    ASSERT_STR_EQ("Hola!!", destino);

    SUBCASE("Truncamiento por capacidad");
    char destino_corto[6] = "Hola";
    ASSERT_FALSE(concatenar_con_punteros(destino_corto, 6, "!!"));
    ASSERT_STR_EQ("Hola!", destino_corto);

    SUBCASE("Parametros invalidos");
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "!!"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5 (Cadenas con Punteros)", conteo_args, argumentos);
    RUN_TEST(prueba_longitud_con_punteros);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
