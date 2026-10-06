/**
 * @file prueba.c
 * @brief Pruebas unitarias de libvector con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "vector.h"

TEST(prueba_bloque_enteros_creacion_liberacion)
{
    SUBCASE("Creacion y liberacion de bloque en heap");
    int *bloque = crear_bloque_enteros(5U);
    ASSERT_PTR_NOT_NULL(bloque);
    for (size_t indice = 0U; indice < 5U; indice++)
    {
        ASSERT_INT_EQ(0, bloque[indice]);
        bloque[indice] = (int)(indice + 1U) * 10;
    }
    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);
    ASSERT_PTR_NULL(bloque);

    SUBCASE("Manejo seguro de punteros nulos o tamano cero");
    ASSERT_PTR_NULL(crear_bloque_enteros(0U));
    int *nulo = NULL;
    liberar_bloque_enteros(&nulo);
    liberar_bloque_enteros(NULL);
}

TEST(prueba_bloque_enteros_redimensionar)
{
    SUBCASE("Redimensionar bloque a mayor tamano");
    int *bloque = crear_bloque_enteros(2U);
    ASSERT_PTR_NOT_NULL(bloque);
    bloque[0] = 42;
    bloque[1] = 84;

    int *ampliado = redimensionar_bloque_enteros(bloque, 4U);
    ASSERT_PTR_NOT_NULL(ampliado);
    ASSERT_INT_EQ(42, ampliado[0]);
    ASSERT_INT_EQ(84, ampliado[1]);
    ampliado[2] = 126;
    ampliado[3] = 168;
    ASSERT_INT_EQ(168, ampliado[3]);

    liberar_bloque_enteros(&ampliado);
    ASSERT_PTR_NULL(ampliado);

    SUBCASE("Redimensionar a cero libera el bloque");
    bloque = crear_bloque_enteros(2U);
    ASSERT_PTR_NOT_NULL(bloque);
    bloque = redimensionar_bloque_enteros(bloque, 0U);
    ASSERT_PTR_NULL(bloque);
}

TEST(prueba_fusionar_bloques_enteros)
{
    int primero[] = {1, 2, 3};
    int segundo[] = {4, 5};
    int *fusion = fusionar_bloques_enteros(primero, 3U, segundo, 2U);

    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_INT_EQ(1, fusion[0]);
    ASSERT_INT_EQ(3, fusion[2]);
    ASSERT_INT_EQ(4, fusion[3]);
    ASSERT_INT_EQ(5, fusion[4]);
    liberar_bloque_enteros(&fusion);

    SUBCASE("Permite un bloque vacio");
    fusion = fusionar_bloques_enteros(NULL, 0U, segundo, 2U);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_INT_EQ(4, fusion[0]);
    ASSERT_INT_EQ(5, fusion[1]);
    liberar_bloque_enteros(&fusion);

    SUBCASE("Parametros invalidos");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 2U, segundo, 2U));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 0U, NULL, 0U));
}

TEST(prueba_agregar_al_bloque_enteros)
{
    int *bloque = NULL;
    size_t cantidad = 0U;

    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 10));
    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 20));
    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 30));
    ASSERT_UINT_EQ(3U, cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(30, bloque[2]);

    ASSERT_FALSE(agregar_al_bloque_enteros(NULL, &cantidad, 40));
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque, NULL, 40));

    liberar_bloque_enteros(&bloque);
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
