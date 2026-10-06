/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 4 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"

TEST(prueba_buscar_primero)
{
    int datos[] = {10, 20, 30, 20, 50};
    size_t n = 5;

    SUBCASE("Elemento presente al inicio");
    {
        const int *p = buscar_primero(datos, n, 10);
        ASSERT_TRUE(p != NULL);
        ASSERT_PTR_EQ(datos, p);
        ASSERT_INT_EQ(10, *p);
    }

    SUBCASE("Elemento duplicado devuelve la primera aparicion");
    {
        const int *p = buscar_primero(datos, n, 20);
        ASSERT_TRUE(p != NULL);
        ASSERT_PTR_EQ(datos + 1, p);
        ASSERT_INT_EQ(20, *p);
    }

    SUBCASE("Elemento al final");
    {
        const int *p = buscar_primero(datos, n, 50);
        ASSERT_TRUE(p != NULL);
        ASSERT_PTR_EQ(datos + 4, p);
        ASSERT_INT_EQ(50, *p);
    }

    SUBCASE("Elemento inexistente");
    {
        const int *p = buscar_primero(datos, n, 999);
        ASSERT_PTR_EQ(NULL, p);
    }

    SUBCASE("Arreglo vacio o nulo");
    {
        ASSERT_PTR_EQ(NULL, buscar_primero(datos, 0, 10));
        ASSERT_PTR_EQ(NULL, buscar_primero(NULL, n, 10));
    }
}

TEST(prueba_distancia_punteros)
{
    int datos[] = {5, 15, 25, 35};

    SUBCASE("Distancia a elementos validos");
    {
        const int *p_primero = datos + 0;
        const int *p_tercero = datos + 2;

        ASSERT_INT_EQ(0, (int)distancia_punteros(datos, p_primero));
        ASSERT_INT_EQ(2, (int)distancia_punteros(datos, p_tercero));
    }

    SUBCASE("Puntero elemento anterior a inicio");
    {
        const int *invalido = datos - 1;
        ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, invalido));
    }

    SUBCASE("Punteros nulos");
    {
        ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, datos));
        ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, NULL));
        ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, NULL));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4 (Busqueda y Punteros)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
