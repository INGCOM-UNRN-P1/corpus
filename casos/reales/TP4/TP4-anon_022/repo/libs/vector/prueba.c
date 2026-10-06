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

TEST(prueba_bloque_enteros_fusionar)
{
    SUBCASE("Fusion de dos bloques");

    int primero[] = {10, 20, 30};
    int segundo[] = {40, 50};

    int *fusion = fusionar_bloques_enteros(
        primero, 3,
        segundo, 2
    );

    ASSERT_PTR_NOT_NULL(fusion);

    int esperado[] = {10, 20, 30, 40, 50};
    ASSERT_ARRAY_INT_EQ(esperado, fusion, 5);

    liberar_bloque_enteros(&fusion);
    ASSERT_PTR_NULL(fusion);

    SUBCASE("Ambos bloques NULL retornan NULL");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 0, NULL, 0));

    SUBCASE("Primer bloque vacio (NULL con cantidad 0)");
    int solo_b[] = {7, 8, 9};
    fusion = fusionar_bloques_enteros(NULL, 0, solo_b, 3);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_ARRAY_INT_EQ(solo_b, fusion, 3);
    liberar_bloque_enteros(&fusion);

    SUBCASE("Segundo bloque vacio (NULL con cantidad 0)");
    fusion = fusionar_bloques_enteros(solo_b, 3, NULL, 0);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_ARRAY_INT_EQ(solo_b, fusion, 3);
    liberar_bloque_enteros(&fusion);

    SUBCASE("Ambos bloques de un elemento");

    int primero_uno[] = {1};
    int segundo_uno[] = {2};

    int *fusion_uno = fusionar_bloques_enteros(
        primero_uno, 1,
        segundo_uno, 1
    );

    ASSERT_PTR_NOT_NULL(fusion_uno);

    int esperado_uno[] = {1, 2};
    ASSERT_ARRAY_INT_EQ(esperado_uno, fusion_uno, 2);

    liberar_bloque_enteros(&fusion_uno);
    ASSERT_PTR_NULL(fusion_uno);
}

TEST(prueba_bloque_enteros_agregar)
{
    SUBCASE("Agregar a bloque existente");
    int *bloque_existente = crear_bloque_enteros(3);
    bloque_existente[0] = 10;
    bloque_existente[1] = 20;
    bloque_existente[2] = 30;

    size_t cantidad_existente = 3;

    bool resultado_existente = agregar_al_bloque_enteros(&bloque_existente, &cantidad_existente, 40);

    ASSERT_TRUE(resultado_existente);
    ASSERT_UINT_EQ(4, cantidad_existente);

    int esperado_existente[] = {10, 20, 30, 40};
    ASSERT_ARRAY_INT_EQ(esperado_existente, bloque_existente, 4);

    liberar_bloque_enteros(&bloque_existente);

    SUBCASE("Agregar varios valores");
    int *bloque_varios = crear_bloque_enteros(2);
    bloque_varios[0] = 10;
    bloque_varios[1] = 20;

    size_t cantidad_varios = 2;

    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque_varios, &cantidad_varios, 30));
    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque_varios, &cantidad_varios, 40));
    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque_varios, &cantidad_varios, 50));

    ASSERT_UINT_EQ(5, cantidad_varios);

    int esperado_varios[] = {10, 20, 30, 40, 50};
    ASSERT_ARRAY_INT_EQ(esperado_varios, bloque_varios, 5);

    liberar_bloque_enteros(&bloque_varios);

    SUBCASE("Agregar a bloque vacío");
    int *bloque_vacio = NULL;
    size_t cantidad_vacio = 0;

    bool resultado_vacio = agregar_al_bloque_enteros(&bloque_vacio, &cantidad_vacio, 42);

    ASSERT_TRUE(resultado_vacio);
    ASSERT_UINT_EQ(1, cantidad_vacio);
    ASSERT_INT_EQ(42, bloque_vacio[0]);

    liberar_bloque_enteros(&bloque_vacio);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libvector", conteo_args, argumentos);
    RUN_TEST(prueba_bloque_enteros_creacion_liberacion);
    RUN_TEST(prueba_bloque_enteros_redimensionar);
    RUN_TEST(prueba_bloque_enteros_fusionar);
    RUN_TEST(prueba_bloque_enteros_agregar);
    return TEST_REPORT();
}
