/**
 * @file prueba.c
 * @brief Pruebas unitarias de libvector con el framework p1_test.
 *
 * Trabajo Práctico 4 - Programación 1 - UNRN
 */

#include "p1_test.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

TEST(prueba_bloque_enteros_creacion_liberacion)
{
    SUBCASE("Creacion y liberacion de bloque en heap");
    int *bloque = crear_bloque_enteros(5);
    ASSERT_PTR_NOT_NULL(bloque);
    for (size_t i = 0; i < 5; ++i)
    {
        ASSERT_INT_EQ(0, bloque[i]);
        bloque[i] = (int)(i + 1) * 10;
    }
    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);
    ASSERT_PTR_NULL(bloque);

    SUBCASE("Manejo seguro de punteros nulos o tamano cero");
    ASSERT_PTR_NULL(crear_bloque_enteros(0));
    int *nulo = NULL;
    liberar_bloque_enteros(&nulo);
    liberar_bloque_enteros(NULL);
}

TEST(prueba_bloque_enteros_redimensionar)
{
    SUBCASE("Redimensionar bloque a mayor tamano");
    int *bloque = crear_bloque_enteros(2);
    ASSERT_PTR_NOT_NULL(bloque);
    bloque[0] = 42;
    bloque[1] = 84;

    int *ampliado = redimensionar_bloque_enteros(bloque, 4);
    ASSERT_PTR_NOT_NULL(ampliado);
    ASSERT_INT_EQ(42, ampliado[0]);
    ASSERT_INT_EQ(84, ampliado[1]);

    ampliado[2] = 126;
    ampliado[3] = 168;
    ASSERT_INT_EQ(168, ampliado[3]);

    liberar_bloque_enteros(&ampliado);
    ASSERT_PTR_NULL(ampliado);
}

TEST(prueba_fusionar_bloques_enteros)
{
    SUBCASE("Fusion de dos bloques de distinto tamanio");
    int *primero = crear_bloque_enteros(2);
    ASSERT_PTR_NOT_NULL(primero);
    primero[0] = 3;
    primero[1] = 5;

    int *segundo = crear_bloque_enteros(5);
    ASSERT_PTR_NOT_NULL(segundo);
    segundo[0] = 0;
    segundo[1] = 1;
    segundo[2] = 2;
    segundo[3] = 4;
    segundo[4] = 6;

    int *fusion = fusionar_bloques_enteros(primero, 2, segundo, 5);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_INT_EQ(3, fusion[0]);
    ASSERT_INT_EQ(5, fusion[1]);
    ASSERT_INT_EQ(0, fusion[2]);
    ASSERT_INT_EQ(1, fusion[3]);
    ASSERT_INT_EQ(2, fusion[4]);
    ASSERT_INT_EQ(4, fusion[5]);
    ASSERT_INT_EQ(6, fusion[6]);

    // liberacion de memoria
    liberar_bloque_enteros(&primero);
    ASSERT_PTR_NULL(primero);

    liberar_bloque_enteros(&segundo);
    ASSERT_PTR_NULL(segundo);

    liberar_bloque_enteros(&fusion);
    ASSERT_PTR_NULL(fusion);
}

TEST(prueba_agregar_al_bloque_enteros)
{
    SUBCASE("Insercion de un valor al final del puntero");
    size_t cantidad = 2;
    int *bloque = crear_bloque_enteros(cantidad);
    ASSERT_PTR_NOT_NULL(bloque);

    bloque[0] = 10;
    bloque[1] = 20;

    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 30));
    ASSERT_INT_EQ(3, cantidad);
    ASSERT_PTR_NOT_NULL(bloque);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);
    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);
    ASSERT_PTR_NULL(bloque);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libvector", conteo_args,
                          argumentos);
    RUN_TEST(prueba_bloque_enteros_creacion_liberacion);
    RUN_TEST(prueba_bloque_enteros_redimensionar);
    RUN_TEST(prueba_fusionar_bloques_enteros);
    RUN_TEST(prueba_agregar_al_bloque_enteros);
    return TEST_REPORT();
}
