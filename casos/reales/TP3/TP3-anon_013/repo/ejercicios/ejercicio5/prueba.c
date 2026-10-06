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
    SUBCASE("La copia tiene exito");
    char origen[] = "Texto";
    char destino[sizeof(origen)];
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), origen));
    ASSERT_STR_EQ(origen, destino);

    SUBCASE("capacidad destino < capacidad origen");
    char origen2[] = "Texto mas largo";
    char destino2[sizeof(origen2) - 5];
    ASSERT_FALSE(copiar_con_punteros(destino2, sizeof(destino2), origen2));
    ASSERT_STR_CONTAINS(origen2, destino2);

    SUBCASE("capacidad 0");
    char origen3[] = "Texto mas largo";
    char destino3[0];
    ASSERT_FALSE(copiar_con_punteros(destino3, sizeof(destino3), origen3));

    SUBCASE("Cadenas con terminador");
    char origen4[] = "";
    char destino4[] = "Esto se sobreescribe";
    ASSERT_TRUE(copiar_con_punteros(destino4, sizeof(destino4), origen4));
    ASSERT_STR_EQ("", destino4);

    char origen5[] = "Esto se copia";
    char destino5[] = "";
    ASSERT_FALSE(copiar_con_punteros(destino5, sizeof(destino5), origen5));
    ASSERT_STR_EQ("", destino5);

    SUBCASE("Punteros nulos");
    ASSERT_FALSE(copiar_con_punteros(NULL, sizeof(destino), origen));
    ASSERT_FALSE(copiar_con_punteros(destino, sizeof(destino), NULL));
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("La concatenación tiene exito");
    char origen[] = "Texto final";
    char destino[50] = "Texto inicial - ";
    ASSERT_TRUE(concatenar_con_punteros(destino, sizeof(destino), origen));
    ASSERT_STR_CONTAINS(destino, origen);

    SUBCASE("La cadena origen no entra en destino");
    char origen2[] = "Texto final que no va a entrar en destino";
    char destino2[20] = "Texto inicial - ";
    ASSERT_FALSE(concatenar_con_punteros(destino2, sizeof(destino2), origen2));
    ASSERT_STR_EQ("Texto inicial - Tex", destino2);

    SUBCASE("capacidad 0");
    char origen3[] = "Texto mas largo";
    char destino3[0];
    ASSERT_FALSE(concatenar_con_punteros(destino3, sizeof(destino3), origen3));

    SUBCASE("Cadenas con terminador");
    char origen4[] = "";
    char destino4[25] = "Texto inicial - ";
    ASSERT_TRUE(concatenar_con_punteros(destino4, sizeof(destino4), origen4));
    ASSERT_STR_EQ("Texto inicial - ", destino4);

    char origen5[] = "Texto final";
    char destino5[] = "";
    ASSERT_FALSE(concatenar_con_punteros(destino5, sizeof(destino5), origen5));
    ASSERT_STR_EQ("", destino5);

    SUBCASE("Punteros nulos");
    ASSERT_FALSE(concatenar_con_punteros(NULL, sizeof(destino), origen));
    ASSERT_FALSE(concatenar_con_punteros(destino, sizeof(destino), NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);

    return TEST_REPORT();
}
