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
    char buffer[10];

    ASSERT_TRUE(copiar_con_punteros(buffer, sizeof(buffer), "Hola"));
    ASSERT_INT_EQ('H', *buffer);
    ASSERT_INT_EQ('\0', *(buffer + 4));

    ASSERT_FALSE(copiar_con_punteros(buffer, 4, "HolaMundo"));
    ASSERT_INT_EQ('\0', *(buffer + 3));

    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "Test"));
    ASSERT_FALSE(copiar_con_punteros(buffer, 10, NULL));
    ASSERT_FALSE(copiar_con_punteros(buffer, 0, "Test"));
}

TEST(prueba_concatenar_con_punteros)
{
    char buffer[12] = "Hola";

    ASSERT_TRUE(concatenar_con_punteros(buffer, sizeof(buffer), " Mundo"));
    ASSERT_INT_EQ(' ', *(buffer + 4));
    ASSERT_INT_EQ('\0', *(buffer + 10));

    char buffer_corto[8] = "Hola";
    ASSERT_FALSE(concatenar_con_punteros(buffer_corto, sizeof(buffer_corto), " Muchachada"));
    ASSERT_INT_EQ('\0', *(buffer_corto + 7));

    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "Test"));
    ASSERT_FALSE(concatenar_con_punteros(buffer, 10, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
