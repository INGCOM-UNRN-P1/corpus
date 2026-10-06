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

TEST(prueba_bloque_enteros_redimensionar_casos_borde)
{
    SUBCASE("redimensionar a menor tamaño conserva los primeros elementos");
    int *bloque =
    crear_bloque_enteros(4);
    ASSERT_PTR_NOT_NULL(bloque);
    for (size_t i = 0; i < 4; ++i)
    {
        bloque[i] = (int)(i + 1);
    }
    int *reducido = redimensionar_bloque_enteros(bloque, 2);
    ASSERT_PTR_NOT_NULL(reducido);
    ASSERT_INT_EQ(1, reducido[0]);
    ASSERT_INT_EQ(2, reducido[1]);

    SUBCASE("redimensionar a cero libera e bloque y retorna NULL");

    ASSERT_PTR_NULL(redimensionar_bloque_enteros(reducido, 0));
    
    SUBCASE("Redimensionar un bloque NULL reserva uno nuevo");
    int *nuevo = redimensionar_bloque_enteros(NULL, 3);
    ASSERT_PTR_NOT_NULL(nuevo);
    nuevo[2] = 7;
    ASSERT_INT_EQ(7, nuevo[2]);
    liberar_bloque_enteros(&nuevo);
    ASSERT_PTR_NULL(nuevo);
}
 
TEST(prueba_fusionar_bloques_enteros)
{
    SUBCASE("Fusion de dos bloques: primero seguido del segundo");
    const int a[] = {1, 2, 3};
    const int b[] = {4, 5};
    int *fusionado = fusionar_bloques_enteros(a, 3, b, 2);
    ASSERT_PTR_NOT_NULL(fusionado);
    for (size_t i = 0; i < 5; ++i) {
        ASSERT_INT_EQ((int)(i + 1), fusionado[i]);
    }
    liberar_bloque_enteros(&fusionado);
    ASSERT_PTR_NULL(fusionado);
 
    SUBCASE("El resultado es una copia independiente de las entradas");
    int origen_a[] = {10, 20};
    int origen_b[] = {30};
    int *copia = fusionar_bloques_enteros(origen_a, 2, origen_b, 1);
    ASSERT_PTR_NOT_NULL(copia);
    origen_a[0] = -1;
    origen_b[0] = -1;
    ASSERT_INT_EQ(10, copia[0]);
    ASSERT_INT_EQ(20, copia[1]);
    ASSERT_INT_EQ(30, copia[2]);
    liberar_bloque_enteros(&copia);
 
    SUBCASE("Un bloque NULL con cantidad 0 equivale a un bloque vacio");
    int *solo_segundo = fusionar_bloques_enteros(NULL, 0, b, 2);
    ASSERT_PTR_NOT_NULL(solo_segundo);
    ASSERT_INT_EQ(4, solo_segundo[0]);
    ASSERT_INT_EQ(5, solo_segundo[1]);
    liberar_bloque_enteros(&solo_segundo);
 
    int *solo_primero = fusionar_bloques_enteros(a, 3, NULL, 0);
    ASSERT_PTR_NOT_NULL(solo_primero);
    ASSERT_INT_EQ(1, solo_primero[0]);
    ASSERT_INT_EQ(3, solo_primero[2]);
    liberar_bloque_enteros(&solo_primero);
 
    SUBCASE("Parametros invalidos retornan NULL");
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 0, NULL, 0));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(NULL, 2, b, 2));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(a, 3, NULL, 1));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(a, 0, b, 0));
    ASSERT_PTR_NULL(fusionar_bloques_enteros(a, SIZE_MAX, b, 1));
}
 
TEST(prueba_agregar_al_bloque_enteros)
{
    SUBCASE("Agregar desde un bloque vacio (NULL, cantidad 0)");
    int *bloque = NULL;
    size_t cantidad = 0;
    ASSERT_INT_EQ(1, (int)agregar_al_bloque_enteros(&bloque, &cantidad, 10));
    ASSERT_PTR_NOT_NULL(bloque);
    ASSERT_INT_EQ(1, (int)cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
 
    ASSERT_INT_EQ(1, (int)agregar_al_bloque_enteros(&bloque, &cantidad, 20));
    ASSERT_INT_EQ(1, (int)agregar_al_bloque_enteros(&bloque, &cantidad, 30));
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_INT_EQ(10, bloque[0]);
    ASSERT_INT_EQ(20, bloque[1]);
    ASSERT_INT_EQ(30, bloque[2]);
    liberar_bloque_enteros(&bloque);
    ASSERT_PTR_NULL(bloque);
 
    SUBCASE("Muchas inserciones sucesivas conservan todos los valores");
    int *secuencia = NULL;
    size_t total = 0;
    for (int i = 0; i < 100; ++i) {
        ASSERT_INT_EQ(1, (int)agregar_al_bloque_enteros(&secuencia, &total, i * 2));
    }
    ASSERT_INT_EQ(100, (int)total);
    for (size_t i = 0; i < total; ++i) {
        ASSERT_INT_EQ((int)i * 2, secuencia[i]);
    }
    liberar_bloque_enteros(&secuencia);
 
    SUBCASE("Agregar a un bloque creado con crear_bloque_enteros");
    int *existente = crear_bloque_enteros(2);
    ASSERT_PTR_NOT_NULL(existente);
    size_t cant_existente = 2;
    ASSERT_INT_EQ(1, (int)agregar_al_bloque_enteros(&existente, &cant_existente, 99));
    ASSERT_INT_EQ(3, (int)cant_existente);
    ASSERT_INT_EQ(0, existente[0]);
    ASSERT_INT_EQ(0, existente[1]);
    ASSERT_INT_EQ(99, existente[2]);
    liberar_bloque_enteros(&existente);
 
    SUBCASE("Parametros invalidos retornan false y no modifican el estado");
    size_t cant = 0;
    int *ptr = NULL;
    ASSERT_INT_EQ(0, (int)agregar_al_bloque_enteros(NULL, &cant, 1));
    ASSERT_INT_EQ(0, (int)agregar_al_bloque_enteros(&ptr, NULL, 1));
    cant = 3; 
    ASSERT_INT_EQ(0, (int)agregar_al_bloque_enteros(&ptr, &cant, 1));
    ASSERT_INT_EQ(3, (int)cant);
    ASSERT_PTR_NULL(ptr);
}
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libvector", conteo_args, argumentos);
    RUN_TEST(prueba_bloque_enteros_creacion_liberacion);
    RUN_TEST(prueba_bloque_enteros_redimensionar);
    return TEST_REPORT();
}
