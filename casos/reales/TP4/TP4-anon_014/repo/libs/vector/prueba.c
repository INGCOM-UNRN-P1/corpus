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
    SUBCASE("Creacion y liberacion de bloque en heap");
    int *bloque = crear_bloque_enteros(5);
    ASSERT_PTR_NOT_NULL(bloque);
    for (size_t i = 0; i < 5; ++i) {
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
    SUBCASE("Fusion de dos bloques con tamano exacto");
    int primero[] = {1, 2};
    int segundo[] = {3, 4, 5};
    int esperado[] = {1, 2, 3, 4, 5};
    int *fusion = fusionar_bloques_enteros(primero, 2, segundo, 3);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_ARRAY_INT_EQ(esperado, fusion, 5);
    liberar_bloque_enteros(&fusion);

    SUBCASE("Un solo bloque valido");
    int *solo = fusionar_bloques_enteros(NULL, 0, segundo, 3);
    ASSERT_PTR_NOT_NULL(solo);
    ASSERT_ARRAY_INT_EQ(segundo, solo, 3);
    liberar_bloque_enteros(&solo);

    SUBCASE("Ambos nulos");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 0, NULL, 0));
}

TEST(prueba_agregar_al_bloque_enteros)
{
    SUBCASE("Agregar partiendo de un bloque vacio");
    int *bloque = NULL;
    size_t cantidad = 0;
    for (int i = 1; i <= 4; i++)
    {
        ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, i * 10));
    }
    int esperado[] = {10, 20, 30, 40};
    ASSERT_UINT_EQ(4, cantidad);
    ASSERT_ARRAY_INT_EQ(esperado, bloque, 4);
    liberar_bloque_enteros(&bloque);

    SUBCASE("Argumentos nulos");
    ASSERT_FALSE(agregar_al_bloque_enteros(NULL, &cantidad, 1));
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque, NULL, 1));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libvector", conteo_args, argumentos);
    RUN_TEST(prueba_bloque_enteros_creacion_liberacion);
    RUN_TEST(prueba_bloque_enteros_redimensionar);
    RUN_TEST(prueba_fusionar_bloques_enteros);
    RUN_TEST(prueba_agregar_al_bloque_enteros);
    return TEST_REPORT();
}
