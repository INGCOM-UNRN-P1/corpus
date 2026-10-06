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
    SUBCASE("Fusionar dos bloques no vacios");
    int primero[] = {10, 20};
    int segundo[] = {30, 40, 50};
    int *fusionado = fusionar_bloques_enteros
    (primero, 2, segundo, 3);
    ASSERT_PTR_NOT_NULL(fusionado);
    ASSERT_INT_EQ(10, fusionado[0]);
    ASSERT_INT_EQ(20, fusionado[1]);
    ASSERT_INT_EQ(30, fusionado[2]);
    ASSERT_INT_EQ(40, fusionado[3]);
    ASSERT_INT_EQ(50, fusionado[4]);
    liberar_bloque_enteros(&fusionado);
    ASSERT_PTR_NULL(fusionado);
    

    SUBCASE("Fusionar cuando el primer bloque es NULL");
    int seg[] = {5, 10, 15};
    int *fusionado_0 = fusionar_bloques_enteros
    (NULL, 0, seg, 3);
    ASSERT_PTR_NOT_NULL(fusionado_0);
    ASSERT_INT_EQ(5, fusionado_0[0]);
    ASSERT_INT_EQ(10, fusionado_0[1]);
    ASSERT_INT_EQ(15, fusionado_0[2]);
    liberar_bloque_enteros(&fusionado_0);
    ASSERT_PTR_NULL(fusionado_0);
    

    SUBCASE("Fusionar cuando el segundo bloque es NULL");
    int primer[] = {100, 200};
    int *fusionado_1 = fusionar_bloques_enteros(primer, 2, NULL, 0);
    ASSERT_PTR_NOT_NULL(fusionado_1);
    ASSERT_INT_EQ(100, fusionado_1[0]);
    ASSERT_INT_EQ(200, fusionado_1[1]);
    liberar_bloque_enteros(&fusionado_1);
    ASSERT_PTR_NULL(fusionado_1);


    SUBCASE("Fusionar cuando ambos bloques son vacios o nulos");
    int *fusionado_2 = fusionar_bloques_enteros(NULL, 0, NULL, 0);
    ASSERT_PTR_NULL(fusionado_2);
}



TEST(prueba_agregar_al_bloque_enteros)
{
    SUBCASE("Agregar elemento a un bloque con elementos existentes");
    size_t cantidad = 2;
    int *bloq = crear_bloque_enteros(cantidad);
    ASSERT_PTR_NOT_NULL(bloq);
    bloq[0] = 10;
    bloq[1] = 20;
    bool resultado = agregar_al_bloque_enteros(&bloq, &cantidad, 30);
    ASSERT_TRUE(resultado);
    ASSERT_INT_EQ(3, (int)cantidad);
    ASSERT_PTR_NOT_NULL(bloq);
    ASSERT_INT_EQ(10, bloq[0]);
    ASSERT_INT_EQ(20, bloq[1]);
    ASSERT_INT_EQ(30, bloq[2]);
    liberar_bloque_enteros(&bloq);
    ASSERT_PTR_NULL(bloq);
    

    SUBCASE("Agregar elementos secuenciales a un bloque inicial en NULL");
    int *bloque_2 = NULL;
    size_t cantidad_2 = 0;
    bool ok1 = agregar_al_bloque_enteros(&bloque_2, &cantidad_2, 100);
    ASSERT_TRUE(ok1);
    ASSERT_INT_EQ(1, (int)cantidad_2);
    ASSERT_PTR_NOT_NULL(bloque_2);
    ASSERT_INT_EQ(100, bloque_2[0]);
    bool ok2 = agregar_al_bloque_enteros(&bloque_2, &cantidad_2, 200);
    ASSERT_TRUE(ok2);
    ASSERT_INT_EQ(2, (int)cantidad_2);
    ASSERT_INT_EQ(200, bloque_2[1]);
    liberar_bloque_enteros(&bloque_2);
    ASSERT_PTR_NULL(bloque_2);

    SUBCASE("Parametros nulos devuelven false");
    size_t cantidad_3 = 0;
    int *bloque_3 = NULL;
    ASSERT_FALSE(agregar_al_bloque_enteros(NULL, &cantidad_3, 50));
    ASSERT_FALSE(agregar_al_bloque_enteros(&bloque_3, NULL, 50));
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
