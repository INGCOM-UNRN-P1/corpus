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
    
    SUBCASE("copia exitosa completa de una cadena");
    {
        char buffer[20];
        bool resultado = copiar_con_punteros(buffer, 20, "Hola");

        ASSERT_TRUE(resultado);
        ASSERT_TRUE(strcmp(buffer, "Hola") == 0);
    }

    SUBCASE("copia con truncamiento forzado");
    {
        char buffer_chico[4];
        bool resultado_truncado = copiar_con_punteros(buffer_chico, 4, "Hola");

        ASSERT_FALSE(resultado_truncado);
        ASSERT_TRUE(strcmp(buffer_chico, "Hol") == 0);
    }
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("concatenacion exitosa con espacio de sobra");
    {
        char buffer[20] = "Hola ";
        bool resultado = concatenar_con_punteros(buffer, 20, "Mundo");

        ASSERT_TRUE(resultado);
        ASSERT_TRUE(strcmp(buffer, "Hola Mundo") == 0);
    }

    SUBCASE("concatenacion con truncamiento por limite");
    {
        char buffer_limite[9] = "Hola ";
        bool resultado_truncado = concatenar_con_punteros(buffer_limite, 9, "Mundo");

        ASSERT_FALSE(resultado_truncado);
        ASSERT_TRUE(strcmp(buffer_limite, "Hola Mun") == 0);
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
