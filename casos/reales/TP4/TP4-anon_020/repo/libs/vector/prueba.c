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
    SUBCASE("Fusion de bloques contiguos");
    int primero[] = {1, 2, 3};
    int segundo[] = {4, 5};
    int esperado[] = {1, 2, 3, 4, 5};
    int *fusionado = fusionar_bloques_enteros(primero, 3, segundo, 2);
    ASSERT_PTR_NOT_NULL(fusionado);
    ASSERT_ARRAY_INT_EQ(esperado, fusionado, 5);
    free(fusionado);

    SUBCASE("Casos invalidos");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 2, segundo, 2));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(primero, 0, NULL, 0));
}

TEST(prueba_bloque_enteros_agregar)
{
    SUBCASE("Agregar un valor al final");
    int *bloque = crear_bloque_enteros(2);
    size_t cantidad = 2U;
    ASSERT_PTR_NOT_NULL(bloque);
    bloque[0] = 10;
    bloque[1] = 20;

    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 30));
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);
    ASSERT_INT_EQ(30, bloque[2]);

    liberar_bloque_enteros(&bloque);
    ASSERT_PTR_NULL(bloque);

    SUBCASE("Argumentos invalidos");
    ASSERT_FALSE(agregar_al_bloque_enteros(NULL, &cantidad, 5));
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque, NULL, 5));
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
