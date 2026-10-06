/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 5.
 */

#include <stdio.h>
#include "p1_test.h"
#include "puntero_cadena.h"

TEST(prueba_longitud)
{
    const char *texto = "Hola";

    ASSERT_INT_EQ(4, longitud_con_punteros(texto, 10));
}

TEST(prueba_longitud_capacidad)
{
    const char *texto = "Programacion";

    ASSERT_INT_EQ(5, longitud_con_punteros(texto, 5));
}

TEST(prueba_longitud_null)
{
    ASSERT_INT_EQ(0, longitud_con_punteros(NULL, 10));
}

TEST(prueba_copiar)
{
    char destino[20];

    ASSERT_TRUE(copiar_con_punteros(destino, 20, "Hola"));
    ASSERT_STR_EQ("Hola", destino);
}

TEST(prueba_copiar_truncado)
{
    char destino[5];

    ASSERT_TRUE(!copiar_con_punteros(destino, 5, "Programacion"));
    ASSERT_STR_EQ("Prog", destino);
}

TEST(prueba_copiar_null)
{
    char destino[10];

    ASSERT_TRUE(!copiar_con_punteros(NULL, 10, "Hola"));
    ASSERT_TRUE(!copiar_con_punteros(destino, 10, NULL));
}

TEST(prueba_copiar_capacidad_cero)
{
    char destino[10];

    ASSERT_TRUE(!copiar_con_punteros(destino, 0, "Hola"));
}

TEST(prueba_concatenar)
{
    char destino[20] = "Hola";

    ASSERT_TRUE(concatenar_con_punteros(destino, 20, " mundo"));
    ASSERT_STR_EQ("Hola mundo", destino);
}

TEST(prueba_concatenar_truncado)
{
    char destino[8] = "Hola";

    ASSERT_TRUE(!concatenar_con_punteros(destino, 8, " mundo"));
    ASSERT_STR_EQ("Hola mu", destino);
}

TEST(prueba_concatenar_null)
{
    char destino[20] = "Hola";

    ASSERT_TRUE(!concatenar_con_punteros(NULL, 20, " mundo"));
    ASSERT_TRUE(!concatenar_con_punteros(destino, 20, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: Ejercicio 5",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_longitud);
    RUN_TEST(prueba_longitud_capacidad);
    RUN_TEST(prueba_longitud_null);

    RUN_TEST(prueba_copiar);
    RUN_TEST(prueba_copiar_truncado);
    RUN_TEST(prueba_copiar_null);
    RUN_TEST(prueba_copiar_capacidad_cero);

    RUN_TEST(prueba_concatenar);
    RUN_TEST(prueba_concatenar_truncado);
    RUN_TEST(prueba_concatenar_null);

    return TEST_REPORT();
}