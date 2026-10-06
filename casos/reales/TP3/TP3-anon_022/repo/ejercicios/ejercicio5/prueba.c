/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include <string.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_longitud_con_punteros)
{
    SUBCASE("Cadena normal dentro de la capacidad");
    ASSERT_UINT_EQ(4, longitud_con_punteros("hola\0resto", 10));

    SUBCASE("Cadena vacia");
    ASSERT_UINT_EQ(0, longitud_con_punteros("", 5));

    SUBCASE("Sin terminador dentro del rango");
    char sin_nulo[4] = {'a', 'b', 'c', 'd'};
    ASSERT_UINT_EQ(4, longitud_con_punteros(sin_nulo, 4));

    SUBCASE("Cadena nula");
    ASSERT_UINT_EQ(0, longitud_con_punteros(NULL, 5));

    SUBCASE("Capacidad cero");
    ASSERT_UINT_EQ(0, longitud_con_punteros("hola", 0));
}

TEST(prueba_copiar_con_punteros)
{
    char destino[16];

    SUBCASE("Copia completa sin truncar");
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), "hola"));
    ASSERT_STR_EQ("hola", destino);

    SUBCASE("Copia truncada");
    char chico[4];
    ASSERT_FALSE(copiar_con_punteros(chico, sizeof(chico), "muy largo"));
    ASSERT_UINT_EQ(3, strlen(chico));
    ASSERT_STR_EQ("muy", chico);

    SUBCASE("Cadena vacia como origen");
    ASSERT_TRUE(copiar_con_punteros(destino, sizeof(destino), ""));
    ASSERT_STR_EQ("", destino);

    SUBCASE("Capacidad exacta (solo lugar para el terminador)");
    char minimo[1];
    ASSERT_FALSE(copiar_con_punteros(minimo, sizeof(minimo), "a"));
    ASSERT_STR_EQ("", minimo);

    SUBCASE("Destino nulo");
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "hola"));

    SUBCASE("Origen nulo");
    ASSERT_FALSE(copiar_con_punteros(destino, sizeof(destino), NULL));

    SUBCASE("Capacidad cero");
    ASSERT_FALSE(copiar_con_punteros(destino, 0, "hola"));
}

TEST(prueba_concatenar_con_punteros)
{
    char destino[16];

    SUBCASE("Concatenacion completa sin truncar");
    copiar_con_punteros(destino, sizeof(destino), "Hola");
    ASSERT_TRUE(concatenar_con_punteros(destino, sizeof(destino),
                                         ", mundo"));
    ASSERT_STR_EQ("Hola, mundo", destino);

    SUBCASE("Concatenacion truncada");
    char chico[8];
    copiar_con_punteros(chico, sizeof(chico), "abc");
    ASSERT_FALSE(concatenar_con_punteros(chico, sizeof(chico), "defghij"));
    ASSERT_UINT_EQ(7, strlen(chico));
    ASSERT_STR_EQ("abcdefg", chico);

    SUBCASE("Origen vacio");
    copiar_con_punteros(destino, sizeof(destino), "Hola");
    ASSERT_TRUE(concatenar_con_punteros(destino, sizeof(destino), ""));
    ASSERT_STR_EQ("Hola", destino);

    SUBCASE("Capacidad exacta (solo lugar para el terminador)");
    char minimo[1];
    copiar_con_punteros(minimo, sizeof(minimo), "");
    ASSERT_TRUE(concatenar_con_punteros(minimo, sizeof(minimo), ""));
    ASSERT_STR_EQ("", minimo);

    SUBCASE("Destino sin espacio disponible (sin terminador en rango)");
    char lleno[4] = {'a', 'b', 'c', 'd'};
    ASSERT_FALSE(concatenar_con_punteros(lleno, sizeof(lleno), "x"));

    SUBCASE("Destino nulo");
    ASSERT_FALSE(concatenar_con_punteros(NULL, 10, "hola"));

    SUBCASE("Origen nulo");
    ASSERT_FALSE(concatenar_con_punteros(destino, sizeof(destino), NULL));

    SUBCASE("Capacidad cero");
    ASSERT_FALSE(concatenar_con_punteros(destino, 0, "hola"));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                           argumentos);
    RUN_TEST(prueba_longitud_con_punteros);
    RUN_TEST(prueba_copiar_con_punteros);
    RUN_TEST(prueba_concatenar_con_punteros);
    return TEST_REPORT();
}