/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_con_punteros)
{
    SUBCASE("Copia completa");
    char destino[10] = "";

    ASSERT_TRUE(copiar_con_punteros(destino, 10, "hola"));
    ASSERT_INT_EQ('h', *destino);
    ASSERT_INT_EQ('o', *(destino + 1));
    ASSERT_INT_EQ('l', *(destino + 2));
    ASSERT_INT_EQ('a', *(destino + 3));
    ASSERT_INT_EQ('\0', *(destino + 4));

    SUBCASE("Copia exacta con espacio para terminador");
    char exacto[5] = "";

    ASSERT_TRUE(copiar_con_punteros(exacto, 5, "abcd"));
    ASSERT_INT_EQ('\0', *(exacto + 4));

    SUBCASE("Copia truncada");
    char corto[4] = "";

    ASSERT_FALSE(copiar_con_punteros(corto, 4, "abcdef"));
    ASSERT_INT_EQ('a', *corto);
    ASSERT_INT_EQ('b', *(corto + 1));
    ASSERT_INT_EQ('c', *(corto + 2));
    ASSERT_INT_EQ('\0', *(corto + 3));

    SUBCASE("Cadena vacia");
    char vacio[4] = "xxx";

    ASSERT_TRUE(copiar_con_punteros(vacio, 4, ""));
    ASSERT_INT_EQ('\0', *vacio);

    SUBCASE("Parametros invalidos");
    char valido[5] = "abc";

    ASSERT_FALSE(copiar_con_punteros(NULL, 5, "hola"));
    ASSERT_FALSE(copiar_con_punteros(valido, 5, NULL));
    ASSERT_FALSE(copiar_con_punteros(valido, 0, "hola"));
}

TEST(prueba_longitud_con_punteros)
{
    SUBCASE("Longitud normal");
    ASSERT_INT_EQ(4, (int)longitud_con_punteros("hola", 10));

    SUBCASE("Cadena vacia");
    ASSERT_INT_EQ(0, (int)longitud_con_punteros("", 10));

    SUBCASE("Capacidad menor que longitud real");
    ASSERT_INT_EQ(3, (int)longitud_con_punteros("abcdef", 3));

    SUBCASE("Puntero nulo");
    ASSERT_INT_EQ(0, (int)longitud_con_punteros(NULL, 10));
}

TEST(prueba_concatenar_con_punteros)
{
    SUBCASE("Concatenacion completa");
    char destino[20] = "Hola";

    ASSERT_TRUE(concatenar_con_punteros(destino, 20, " mundo"));
    ASSERT_INT_EQ(10, (int)longitud_con_punteros(destino, 20));

    SUBCASE("Concatenacion truncada");
    char corto[7] = "Hola";

    ASSERT_FALSE(concatenar_con_punteros(corto, 7, " mundo"));
    ASSERT_INT_EQ('H', *corto);
    ASSERT_INT_EQ('o', *(corto + 1));
    ASSERT_INT_EQ('l', *(corto + 2));
    ASSERT_INT_EQ('a', *(corto + 3));
    ASSERT_INT_EQ(' ', *(corto + 4));
    ASSERT_INT_EQ('m', *(corto + 5));
    ASSERT_INT_EQ('\0', *(corto + 6));

    SUBCASE("Origen vacio");
    char sin_cambio[10] = "hola";

    ASSERT_TRUE(concatenar_con_punteros(sin_cambio, 10, ""));
    ASSERT_INT_EQ(4, (int)longitud_con_punteros(sin_cambio, 10));

    SUBCASE("Destino sin terminador dentro de capacidad");
    char sin_fin[4] = {'a', 'b', 'c', 'd'};

    ASSERT_FALSE(concatenar_con_punteros(sin_fin, 4, "x"));

    SUBCASE("Parametros invalidos");
    char valido[10] = "abc";

    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "x"));
    ASSERT_FALSE(concatenar_con_punteros(valido, 10, NULL));
    ASSERT_FALSE(concatenar_con_punteros(valido, 0, "x"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_longitud_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}
