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
    SUBCASE("Fusionar dos bloques conserva el orden");
    int a[] = {1, 2};
    int b[] = {3, 4, 5};
    int *fusion = fusionar_bloques_enteros(a, 2, b, 3);
    ASSERT_PTR_NOT_NULL(fusion);
    ASSERT_INT_EQ(1, fusion[0]);
    ASSERT_INT_EQ(3, fusion[2]);
    ASSERT_INT_EQ(5, fusion[4]);
    liberar_bloque_enteros(&fusion);
 
    SUBCASE("Fusionar bloques nulos o vacios retorna NULL");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 0, NULL, 0));
}
 
TEST(prueba_bloque_enteros_agregar)
{
    SUBCASE("Agregar valores a un bloque inicialmente nulo");
    int *bloque = NULL;
    size_t cantidad = 0;
    ASSERT_INT_EQ(1, agregar_al_bloque_enteros(&bloque, &cantidad, 10));
    ASSERT_INT_EQ(1, agregar_al_bloque_enteros(&bloque, &cantidad, 20));
    ASSERT_INT_EQ(2, (int)cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);
    liberar_bloque_enteros(&bloque);
 
    SUBCASE("Parametros nulos retornan false");
    ASSERT_INT_EQ(0, agregar_al_bloque_enteros(NULL, &cantidad, 1));
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
