/**
 * @file prueba.c
 * @brief Pruebas unitarias de libvector con el framework p1_test.
 *
 * Trabajo Práctico 4 - Programación 1 - UNRN
 */

#include <stdio.h>
#include <stdlib.h>

#include "p1_test.h"
#include "vector.h"


TEST(prueba_bloque_enteros_creacion_liberacion)
{
    int *bloque = NULL;
    int *nulo = NULL;
    size_t i = 0;

    SUBCASE("Creacion y liberacion de bloque en heap");

    bloque = crear_bloque_enteros(5);

    ASSERT_PTR_NOT_NULL(bloque);

    for (i = 0; i < 5; i++)
    {
        ASSERT_INT_EQ(0, bloque[i]);
        bloque[i] = (int)(i + 1) * 10;
    }

    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);

    ASSERT_PTR_NULL(bloque);


    SUBCASE("Manejo seguro de punteros nulos o tamano cero");

    ASSERT_PTR_NULL(crear_bloque_enteros(0));

    liberar_bloque_enteros(&nulo);

    ASSERT_PTR_NULL(nulo);

    liberar_bloque_enteros(NULL);
}


TEST(prueba_bloque_enteros_redimensionar)
{
    int *bloque = NULL;
    int *ampliado = NULL;

    SUBCASE("Redimensionar bloque a mayor tamano");

    bloque = crear_bloque_enteros(2);

    ASSERT_PTR_NOT_NULL(bloque);

    bloque[0] = 42;
    bloque[1] = 84;

    ampliado = redimensionar_bloque_enteros(bloque, 4);

    ASSERT_PTR_NOT_NULL(ampliado);

    ASSERT_INT_EQ(42, ampliado[0]);
    ASSERT_INT_EQ(84, ampliado[1]);

    ampliado[2] = 126;
    ampliado[3] = 168;

    ASSERT_INT_EQ(126, ampliado[2]);
    ASSERT_INT_EQ(168, ampliado[3]);

    liberar_bloque_enteros(&ampliado);

    ASSERT_PTR_NULL(ampliado);


    SUBCASE("Redimensionar a tamano cero");

    bloque = crear_bloque_enteros(3);

    ASSERT_PTR_NOT_NULL(bloque);

    bloque = redimensionar_bloque_enteros(bloque, 0);

    ASSERT_PTR_NULL(bloque);
}


TEST(prueba_fusionar_bloques_enteros)
{
    int primero[] = {1, 2, 3};
    int segundo[] = {4, 5};
    int *resultado = NULL;

    SUBCASE("Fusion de dos bloques validos");

    resultado = fusionar_bloques_enteros(
        primero,
        3,
        segundo,
        2
    );

    ASSERT_PTR_NOT_NULL(resultado);

    ASSERT_INT_EQ(1, resultado[0]);
    ASSERT_INT_EQ(2, resultado[1]);
    ASSERT_INT_EQ(3, resultado[2]);
    ASSERT_INT_EQ(4, resultado[3]);
    ASSERT_INT_EQ(5, resultado[4]);

    free(resultado);


    SUBCASE("Fusion con primer bloque vacio");

    resultado = fusionar_bloques_enteros(
        NULL,
        0,
        segundo,
        2
    );

    ASSERT_PTR_NOT_NULL(resultado);

    ASSERT_INT_EQ(4, resultado[0]);
    ASSERT_INT_EQ(5, resultado[1]);

    free(resultado);


    SUBCASE("Fusion con segundo bloque vacio");

    resultado = fusionar_bloques_enteros(
        primero,
        3,
        NULL,
        0
    );

    ASSERT_PTR_NOT_NULL(resultado);

    ASSERT_INT_EQ(1, resultado[0]);
    ASSERT_INT_EQ(2, resultado[1]);
    ASSERT_INT_EQ(3, resultado[2]);

    free(resultado);


    SUBCASE("Fusion de dos bloques vacios");

    resultado = fusionar_bloques_enteros(
        NULL,
        0,
        NULL,
        0
    );

    ASSERT_PTR_NULL(resultado);
}


TEST(prueba_agregar_al_bloque_enteros)
{
    int *bloque = NULL;
    size_t cantidad = 0;
    bool resultado = false;

    SUBCASE("Agregar primer elemento");

    resultado = agregar_al_bloque_enteros(
        &bloque,
        &cantidad,
        10
    );

    ASSERT_TRUE(resultado);

    ASSERT_PTR_NOT_NULL(bloque);
    ASSERT_INT_EQ(1, cantidad);
    ASSERT_INT_EQ(10, bloque[0]);


    SUBCASE("Agregar segundo elemento");

    resultado = agregar_al_bloque_enteros(
        &bloque,
        &cantidad,
        20
    );

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(2, cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);


    SUBCASE("Agregar tercer elemento");

    resultado = agregar_al_bloque_enteros(
        &bloque,
        &cantidad,
        30
    );

    ASSERT_TRUE(resultado);

    ASSERT_INT_EQ(3, cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);
    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);

    ASSERT_PTR_NULL(bloque);


    SUBCASE("Puntero de bloque nulo");

    resultado = agregar_al_bloque_enteros(
        NULL,
        &cantidad,
        40
    );

    ASSERT_TRUE(resultado == false);


    SUBCASE("Puntero de cantidad nulo");

    resultado = agregar_al_bloque_enteros(
        &bloque,
        NULL,
        40
    );

    ASSERT_TRUE(resultado == false);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS(
        "Suite de Pruebas: libvector",
        conteo_args,
        argumentos
    );

    RUN_TEST(prueba_bloque_enteros_creacion_liberacion);
    RUN_TEST(prueba_bloque_enteros_redimensionar);
    RUN_TEST(prueba_fusionar_bloques_enteros);
    RUN_TEST(prueba_agregar_al_bloque_enteros);

    return TEST_REPORT();
}