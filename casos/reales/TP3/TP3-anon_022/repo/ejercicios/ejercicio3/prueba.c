/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 3.
 *
 * Tarea del estudiante:
 * Diseñar e implementar las pruebas unitarias completas con p1_test
 * para validar las funciones diseñadas e implementadas.
 */

#include <stdio.h>
#include "p1_test.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo_exitosa)
{
    int origen[] = {1, 2, 3, 4, 5};
    int destino[5] = {0};

    SUBCASE("Copia exitosa con arreglos no nulos");
    bool resultado = copiar_arreglo(origen, 5, destino);

    ASSERT_TRUE(resultado);
    ASSERT_ARRAY_INT_EQ(origen, destino, 5);
}

TEST(prueba_copiar_arreglo_un_elemento)
{
    int origen[] = {42};
    int destino[] = {0};

    SUBCASE("Copia de un solo elemento");
    bool resultado = copiar_arreglo(origen, 1, destino);

    ASSERT_TRUE(resultado);
    ASSERT_ARRAY_INT_EQ(origen, destino, 1);
}

TEST(prueba_copiar_arreglo_cantidad_cero)
{
    int origen[] = {1, 2, 3};
    int destino[] = {9, 9, 9};
    int esperado[] = {9, 9, 9};

    SUBCASE("Cantidad 0 no debe modificar destino");
    bool resultado = copiar_arreglo(origen, 0, destino);

    ASSERT_TRUE(resultado);
    ASSERT_ARRAY_INT_EQ(esperado, destino, 3);
}

TEST(prueba_copiar_arreglo_punteros_nulos)
{
    int destino[3] = {0};
    int origen[] = {1, 2, 3};

    SUBCASE("Origen nulo");
    ASSERT_FALSE(copiar_arreglo(NULL, 3, destino));

    SUBCASE("Destino nulo");
    ASSERT_FALSE(copiar_arreglo(origen, 3, NULL));
}

TEST(prueba_copiar_arreglo_mismo_arreglo)
{
    int arreglo[] = {1, 2, 3, 4};
    int esperado[] = {1, 2, 3, 4};

    SUBCASE("Origen y destino apuntan al mismo arreglo");
    bool resultado = copiar_arreglo(arreglo, 4, arreglo);

    ASSERT_TRUE(resultado);
    ASSERT_ARRAY_INT_EQ(esperado, arreglo, 4);
}

TEST(prueba_invertir_arreglo_longitud_par)
{
    int arreglo[] = {1, 2, 3, 4};
    int esperado[] = {4, 3, 2, 1};

    SUBCASE("Arreglo de longitud par");
    invertir_arreglo(arreglo, 4);

    ASSERT_ARRAY_INT_EQ(esperado, arreglo, 4);
}

TEST(prueba_invertir_arreglo_longitud_impar)
{
    int arreglo[] = {1, 2, 3, 4, 5};
    int esperado[] = {5, 4, 3, 2, 1};

    SUBCASE("Arreglo de longitud impar (elemento central fijo)");
    invertir_arreglo(arreglo, 5);

    ASSERT_ARRAY_INT_EQ(esperado, arreglo, 5);
}

TEST(prueba_invertir_arreglo_casos_borde)
{
    int unico[] = {42};
    int esperado_unico[] = {42};

    SUBCASE("Arreglo nulo no debe fallar");
    invertir_arreglo(NULL, 5);

    SUBCASE("Cantidad 0 no modifica nada");
    invertir_arreglo(unico, 0);
    ASSERT_ARRAY_INT_EQ(esperado_unico, unico, 1);

    SUBCASE("Cantidad 1 no modifica nada");
    invertir_arreglo(unico, 1);
    ASSERT_ARRAY_INT_EQ(esperado_unico, unico, 1);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);

    RUN_TEST(prueba_copiar_arreglo_exitosa);
    RUN_TEST(prueba_copiar_arreglo_un_elemento);
    RUN_TEST(prueba_copiar_arreglo_cantidad_cero);
    RUN_TEST(prueba_copiar_arreglo_punteros_nulos);
    RUN_TEST(prueba_copiar_arreglo_mismo_arreglo);

    RUN_TEST(prueba_invertir_arreglo_longitud_par);
    RUN_TEST(prueba_invertir_arreglo_longitud_impar);
    RUN_TEST(prueba_invertir_arreglo_casos_borde);

    return TEST_REPORT();
}