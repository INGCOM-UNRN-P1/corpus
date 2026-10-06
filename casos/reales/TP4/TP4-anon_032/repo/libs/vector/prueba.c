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
    SUBCASE("Caso normal");
    int primer_bloque[] = {1, 2, 3, 4, 5, 6};
    int segundo_bloque[] = {7, 8, 9, 10};

    int *bloque = fusionar_bloques_enteros(primer_bloque, 6, segundo_bloque, 4);
    int *bloque_nulo = NULL;

    ASSERT_PTR_NOT_NULL(bloque);
    ASSERT_INT_EQ(10, bloque[9]);

    SUBCASE("Punteros nulos");
    bloque_nulo = fusionar_bloques_enteros(NULL, 6, segundo_bloque, 4);
    ASSERT_PTR_NULL(bloque_nulo);
    bloque_nulo = fusionar_bloques_enteros(primer_bloque, 6, NULL, 4);
    ASSERT_PTR_NULL(bloque_nulo);
    
    liberar_bloque_enteros(&bloque);
}

TEST(prueba_agregar_al_bloque_enteros)
{
    SUBCASE("CASO NORMAL");
    size_t cantidad = 4;
    int *bloque = crear_bloque_enteros(cantidad);
    for (size_t i = 0; i < cantidad; i++)
    {
        bloque[i] = (i + 1);
    }
    ASSERT_INT_EQ(1, bloque[0]);
    ASSERT_INT_EQ(2, bloque[1]);
    ASSERT_INT_EQ(3, bloque[2]);
    ASSERT_INT_EQ(4, bloque[3]);
    
    ASSERT_TRUE(agregar_al_bloque_enteros(&bloque, &cantidad, 5));
    ASSERT_INT_EQ(5, (int)cantidad);
    ASSERT_INT_EQ(5, bloque[4]);

    SUBCASE("Caso cantidad cero");
    cantidad = 0;
    int *bloque_vacio = crear_bloque_enteros(cantidad);
    
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque_vacio, &cantidad, 1));

    SUBCASE("Caso pounteros nulos");
    ASSERT_FALSE(agregar_al_bloque_enteros(NULL, &cantidad, 5));
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque, NULL, 5));
    
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
