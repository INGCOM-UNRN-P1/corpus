/**
 * @file prueba.c
 * @brief Suite de pruebas unitarias para el Ejercicio 6 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "ordenamiento.h"

TEST(prueba_buscar_puntero_minimo)
{
    int datos[] = {40, 10, 50, 20, 30};

    SUBCASE("Minimo en rango completo");
    {
        const int *min = buscar_puntero_minimo(datos, datos + 5);
        ASSERT_TRUE(min != NULL);
        ASSERT_PTR_EQ(datos + 1, min);
        ASSERT_INT_EQ(10, *min);
    }

    SUBCASE("Minimo en subrango");
    {
        const int *min = buscar_puntero_minimo(datos + 2, datos + 5);
        ASSERT_TRUE(min != NULL);
        ASSERT_PTR_EQ(datos + 3, min);
        ASSERT_INT_EQ(20, *min);
    }

    SUBCASE("Rangos invalidos o nulos");
    {
        ASSERT_PTR_EQ(NULL, buscar_puntero_minimo(NULL, datos + 2));
        ASSERT_PTR_EQ(NULL, buscar_puntero_minimo(datos, NULL));
        ASSERT_PTR_EQ(NULL, buscar_puntero_minimo(datos + 3, datos + 1));
        ASSERT_PTR_EQ(NULL, buscar_puntero_minimo(datos, datos));
    }
}

TEST(prueba_ordenar_seleccion_punteros)
{
    SUBCASE("Arreglo desordenado comun");
    {
        int datos[] = {64, 25, 12, 22, 11};
        ASSERT_TRUE(ordenar_seleccion_punteros(datos, 5));
        ASSERT_INT_EQ(11, *(datos + 0));
        ASSERT_INT_EQ(12, *(datos + 1));
        ASSERT_INT_EQ(22, *(datos + 2));
        ASSERT_INT_EQ(25, *(datos + 3));
        ASSERT_INT_EQ(64, *(datos + 4));
    }

    SUBCASE("Arreglo ya ordenado e invertido");
    {
        int ordenado[] = {1, 2, 3};
        ASSERT_TRUE(ordenar_seleccion_punteros(ordenado, 3));
        ASSERT_INT_EQ(1, *(ordenado + 0));
        ASSERT_INT_EQ(2, *(ordenado + 1));
        ASSERT_INT_EQ(3, *(ordenado + 2));

        int invertido[] = {3, 2, 1};
        ASSERT_TRUE(ordenar_seleccion_punteros(invertido, 3));
        ASSERT_INT_EQ(1, *(invertido + 0));
        ASSERT_INT_EQ(2, *(invertido + 1));
        ASSERT_INT_EQ(3, *(invertido + 2));
    }

    SUBCASE("Casos borde (0, 1 elemento o nulo)");
    {
        int unico[] = {99};
        ASSERT_TRUE(ordenar_seleccion_punteros(unico, 1));
        ASSERT_INT_EQ(99, *(unico + 0));

        ASSERT_TRUE(ordenar_seleccion_punteros(unico, 0));
        ASSERT_FALSE(ordenar_seleccion_punteros(NULL, 5));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 6 (Ordenamiento por Seleccion)", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_puntero_minimo);
    RUN_TEST(prueba_ordenar_seleccion_punteros);
    return TEST_REPORT();
}
