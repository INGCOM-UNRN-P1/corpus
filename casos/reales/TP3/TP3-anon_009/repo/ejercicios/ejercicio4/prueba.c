

#include <stdio.h>
#include "p1_test.h"
#include "busqueda.h"


TEST(prueba_buscar_primero)
{
    SUBCASE("Casos bordes - Arreglo NULL o cantidad 0");
    {
        int datos[] = {10, 20, 30};

        ASSERT_TRUE(buscar_primero(NULL, 3, 10) == NULL);
        ASSERT_TRUE(buscar_primero(datos, 0, 10) == NULL);
    }

    SUBCASE("Búsqueda exitosa - Elemento único y repetido");
    {
        int datos[] = {5, 12, 42, 12, 99};
        size_t cantidad = 5;

        const int *p_primer = buscar_primero(datos, cantidad, 5);
        ASSERT_TRUE(p_primer == datos);
        ASSERT_INT_EQ(5, *p_primer);

        const int *p_repetido = buscar_primero(datos, cantidad, 12);
        ASSERT_TRUE(p_repetido == (datos + 1));
        ASSERT_INT_EQ(12, *p_repetido);

        const int *p_ultimo = buscar_primero(datos, cantidad, 99);
        ASSERT_TRUE(p_ultimo == (datos + 4));
        ASSERT_INT_EQ(99, *p_ultimo);
    }

    SUBCASE("Elemento inexistente");
    {
        int datos[] = {1, 2, 3, 4};
        ASSERT_TRUE(buscar_primero(datos, 4, 100) == NULL);
    }
}

TEST(prueba_distancia_punteros)
{
    SUBCASE("Casos bordes e inválidos - NULL o fuera de orden");
    {
        int datos[] = {10, 20, 30};

        ASSERT_INT_EQ(-1, (int)distancia_punteros(NULL, datos));
        ASSERT_INT_EQ(-1, (int)distancia_punteros(datos, NULL));
        ASSERT_INT_EQ(-1, (int)distancia_punteros(datos + 2, datos));
    }

    SUBCASE("Cálculo de distancia y coincidencia con índices");
    {
        int datos[] = {100, 200, 300, 400, 500};

        ASSERT_INT_EQ(0, (int)distancia_punteros(datos, datos));
        ASSERT_INT_EQ(2, (int)distancia_punteros(datos, datos + 2));
        ASSERT_INT_EQ(4, (int)distancia_punteros(datos, datos + 4));

        const int *hallado = buscar_primero(datos, 5, 400);
        ASSERT_TRUE(hallado != NULL);
        ASSERT_INT_EQ(3, (int)distancia_punteros(datos, hallado));
    }
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 4", conteo_args, argumentos);
    RUN_TEST(prueba_buscar_primero);
    RUN_TEST(prueba_distancia_punteros);
    return TEST_REPORT();
}
