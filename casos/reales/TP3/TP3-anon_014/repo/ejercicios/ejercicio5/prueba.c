/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_copiar_entra_completa)
{
    char destino[10] = "";
    copiar_con_punteros(destino, 10, "hola");
    ASSERT_STR_EQ("hola", destino);
}

TEST(prueba_copiar_retorna_true)
{
    char destino[10] = "";
    ASSERT_TRUE(copiar_con_punteros(destino, 10, "hola"));
}

TEST(prueba_copiar_justo_en_capacidad)
{
    // "hola" ocupa 5 bytes con el '\0': entra exacto.
    char destino[5] = "";
    ASSERT_TRUE(copiar_con_punteros(destino, 5, "hola"));
}

TEST(prueba_copiar_trunca_contenido)
{
    char destino[4] = "";
    copiar_con_punteros(destino, 4, "programa");
    ASSERT_STR_EQ("pro", destino);
}

TEST(prueba_copiar_trunca_retorna_false)
{
    char destino[4] = "";
    ASSERT_FALSE(copiar_con_punteros(destino, 4, "programa"));
}

TEST(prueba_copiar_cadena_vacia)
{
    char destino[4] = "xyz";
    copiar_con_punteros(destino, 4, "");
    ASSERT_STR_EQ("", destino);
}

TEST(prueba_copiar_capacidad_uno)
{
    char destino[1] = {'x'};
    copiar_con_punteros(destino, 1, "abc");
    ASSERT_INT_EQ('\0', *destino);
}

TEST(prueba_copiar_capacidad_cero)
{
    char destino[4] = "abc";
    ASSERT_FALSE(copiar_con_punteros(destino, 0, "hola"));
}

TEST(prueba_copiar_destino_nulo)
{
    ASSERT_FALSE(copiar_con_punteros(NULL, 10, "hola"));
}

TEST(prueba_copiar_origen_nulo)
{
    char destino[10] = "";
    ASSERT_FALSE(copiar_con_punteros(destino, 10, NULL));
}

TEST(prueba_concatenar_entra_completa)
{
    char destino[16] = "Hola";
    concatenar_con_punteros(destino, 16, ", mundo");
    ASSERT_STR_EQ("Hola, mundo", destino);
}

TEST(prueba_concatenar_retorna_true)
{
    char destino[16] = "Hola";
    ASSERT_TRUE(concatenar_con_punteros(destino, 16, ", mundo"));
}

TEST(prueba_concatenar_destino_vacio)
{
    char destino[8] = "";
    concatenar_con_punteros(destino, 8, "abc");
    ASSERT_STR_EQ("abc", destino);
}

TEST(prueba_concatenar_trunca_contenido)
{
    char destino[8] = "abcd";
    concatenar_con_punteros(destino, 8, "efghij");
    ASSERT_STR_EQ("abcdefg", destino);
}

TEST(prueba_concatenar_trunca_retorna_false)
{
    char destino[8] = "abcd";
    ASSERT_FALSE(concatenar_con_punteros(destino, 8, "efghij"));
}

TEST(prueba_concatenar_destino_lleno)
{
    char destino[4] = "abc";
    ASSERT_FALSE(concatenar_con_punteros(destino, 4, "d"));
}

TEST(prueba_concatenar_sin_terminador)
{
    // Un destino sin '\0' dentro de la capacidad no es una cadena válida.
    char destino[3] = {'a', 'b', 'c'};
    ASSERT_FALSE(concatenar_con_punteros(destino, 3, "d"));
}

TEST(prueba_concatenar_destino_nulo)
{
    ASSERT_FALSE(concatenar_con_punteros(NULL, 8, "abc"));
}

TEST(prueba_concatenar_origen_nulo)
{
    char destino[8] = "abc";
    ASSERT_FALSE(concatenar_con_punteros(destino, 8, NULL));
}

TEST(prueba_longitud_cadena_normal)
{
    ASSERT_UINT_EQ(5, longitud_con_punteros("hola!", 10));
}

TEST(prueba_longitud_cadena_vacia)
{
    ASSERT_UINT_EQ(0, longitud_con_punteros("", 10));
}

TEST(prueba_longitud_limitada_por_capacidad)
{
    char sin_terminador[4] = {'a', 'b', 'c', 'd'};
    ASSERT_UINT_EQ(4, longitud_con_punteros(sin_terminador, 4));
}

TEST(prueba_longitud_cadena_nula)
{
    ASSERT_UINT_EQ(0, longitud_con_punteros(NULL, 10));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 5", conteo_args,
                          argumentos);
    RUN_TEST(prueba_copiar_entra_completa);
    RUN_TEST(prueba_copiar_retorna_true);
    RUN_TEST(prueba_copiar_justo_en_capacidad);
    RUN_TEST(prueba_copiar_trunca_contenido);
    RUN_TEST(prueba_copiar_trunca_retorna_false);
    RUN_TEST(prueba_copiar_cadena_vacia);
    RUN_TEST(prueba_copiar_capacidad_uno);
    RUN_TEST(prueba_copiar_capacidad_cero);
    RUN_TEST(prueba_copiar_destino_nulo);
    RUN_TEST(prueba_copiar_origen_nulo);
    RUN_TEST(prueba_concatenar_entra_completa);
    RUN_TEST(prueba_concatenar_retorna_true);
    RUN_TEST(prueba_concatenar_destino_vacio);
    RUN_TEST(prueba_concatenar_trunca_contenido);
    RUN_TEST(prueba_concatenar_trunca_retorna_false);
    RUN_TEST(prueba_concatenar_destino_lleno);
    RUN_TEST(prueba_concatenar_sin_terminador);
    RUN_TEST(prueba_concatenar_destino_nulo);
    RUN_TEST(prueba_concatenar_origen_nulo);
    RUN_TEST(prueba_longitud_cadena_normal);
    RUN_TEST(prueba_longitud_cadena_vacia);
    RUN_TEST(prueba_longitud_limitada_por_capacidad);
    RUN_TEST(prueba_longitud_cadena_nula);
    return TEST_REPORT();
}
