/**
 * @file prueba.c
 * @brief Pruebas unitarias de libarreglos con el framework p1_test.
 *
 * Trabajo Práctico 2 - Programación 1 - UNRN
 */

#include <stdio.h>
#include "p1_test.h"
#include "p1_arrays.h"
#include "arreglos.h"

TEST(prueba_arreglo_sumar)
{
    SUBCASE("Arreglo vacio o nulo");
    ASSERT_INT_EQ(0, (int)arreglo_sumar(NULL, 0));

    SUBCASE("Arreglo con varios elementos");
    int valores[] = {1, 2, 3, 4, 5};
    ASSERT_INT_EQ(15, (int)arreglo_sumar(valores, 5));

    SUBCASE("Arreglo con numeros negativos");
    int mixtos[] = {10, -5, -3, 2};
    ASSERT_INT_EQ(4, (int)arreglo_sumar(mixtos, 4));
}

TEST(prueba_arreglo_buscar)
{
    int valores[] = {10, 20, 30, 20, 50};

    SUBCASE("Busqueda en vacio o nulo");
    ASSERT_INT_EQ(-1, arreglo_buscar(NULL, 0, 10));

    SUBCASE("Primera aparicion de repetido");
    ASSERT_INT_EQ(1, arreglo_buscar(valores, 5, 20));
    ASSERT_INT_EQ(0, arreglo_buscar(valores, 5, 10));

    SUBCASE("Elemento ausente");
    ASSERT_INT_EQ(-1, arreglo_buscar(valores, 5, 99));
}

TEST(prueba_arreglo_invertir)
{
    SUBCASE("Arreglo impar");
    int impar[] = {1, 2, 3, 4, 5};
    int esperado[] = {5, 4, 3, 2, 1};
    arreglo_invertir(impar, 5);
    ASSERT_ARRAY_INT_EQ(esperado, impar, 5);

    SUBCASE("Arreglo par");
    int par[] = {10, 20, 30, 40};
    int invertido[] = {40, 30, 20, 10};
    arreglo_invertir(par, 4);
    ASSERT_ARRAY_INT_EQ(invertido, par, 4);
}

TEST(prueba_arreglo_ordenado)
{
    SUBCASE("Casos borde y nulos");
    ASSERT_FALSE(arreglo_ordenado(NULL, 5));
    int unico[] = {42};
    ASSERT_TRUE(arreglo_ordenado(unico, 1));
    ASSERT_TRUE(arreglo_ordenado(unico, 0));

    SUBCASE("Arreglos ordenados");
    int ordenado[] = {1, 3, 5, 7, 9};
    ASSERT_TRUE(arreglo_ordenado(ordenado, 5));
    int repetidos[] = {2, 2, 4, 4, 8};
    ASSERT_TRUE(arreglo_ordenado(repetidos, 5));

    SUBCASE("Arreglos desordenados");
    int desordenado[] = {1, 5, 3, 7};
    ASSERT_FALSE(arreglo_ordenado(desordenado, 4));
    int invertido[] = {9, 8, 7, 6};
    ASSERT_FALSE(arreglo_ordenado(invertido, 4));
}

TEST(prueba_arreglo_contar)
{
    SUBCASE("Casos vacios y nulos");
    ASSERT_INT_EQ(0, (int)arreglo_contar(NULL, 5, 10));
    int vacio[] = {1};
    ASSERT_INT_EQ(0, (int)arreglo_contar(vacio, 0, 10));

    SUBCASE("Sin apariciones");
    int datos[] = {1, 2, 3, 4, 5};
    ASSERT_INT_EQ(0, (int)arreglo_contar(datos, 5, 99));

    SUBCASE("Aparicion unica y multiple");
    int repetidos[] = {4, 2, 4, 7, 4, 8, 4};
    ASSERT_INT_EQ(4, (int)arreglo_contar(repetidos, 7, 4));
    ASSERT_INT_EQ(1, (int)arreglo_contar(repetidos, 7, 2));

    SUBCASE("Todos los elementos coinciden");
    int todos[] = {3, 3, 3};
    ASSERT_INT_EQ(3, (int)arreglo_contar(todos, 3, 3));
}
TEST(prueba_arreglo_compactar)
{
    SUBCASE("Compactar elemento inexistente o arreglo nulo");
    int datos1[] = {1, 2, 3};
    ASSERT_INT_EQ(3, (int)arreglo_compactar(datos1, 3, 99));
    ASSERT_INT_EQ(0, (int)arreglo_compactar(NULL, 0, 1));

    SUBCASE("Eliminar todas las apariciones");
    int datos2[] = {4, 2, 4, 4, 3};
    int esperado2[] = {2, 3};
    size_t nueva = arreglo_compactar(datos2, 5, 4);
    ASSERT_INT_EQ(2, (int)nueva);
    ASSERT_ARRAY_INT_EQ(esperado2, datos2, nueva);

    SUBCASE("Eliminar sin dejar huecos y preservar orden");
    int datos3[] = {1, 0, 2, 0, 3};
    int esperado3[] = {1, 2, 3};
    nueva = arreglo_compactar(datos3, 5, 0);
    ASSERT_INT_EQ(3, (int)nueva);
    ASSERT_ARRAY_INT_EQ(esperado3, datos3, nueva);
}

TEST(prueba_arreglo_fusionar)
{
    SUBCASE("Fusion basica con capacidad suficiente");
    int a[] = {1, 3, 5};
    int b[] = {2, 4, 6, 8};
    int dest[10];
    size_t escrito = arreglo_fusionar(a, 3, b, 4, dest, 10);
    int esperado1[] = {1,2,3,4,5,6,8};
    ASSERT_INT_EQ(7, (int)escrito);
    ASSERT_ARRAY_INT_EQ(esperado1, dest, escrito);

    SUBCASE("Fusion con capacidad limitada debe truncar");
    int dest2[4];
    escrito = arreglo_fusionar(a, 3, b, 4, dest2, 4);
    ASSERT_INT_EQ(4, (int)escrito);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libarreglos", conteo_args, argumentos);
    RUN_TEST(prueba_arreglo_sumar);
    RUN_TEST(prueba_arreglo_buscar);
    RUN_TEST(prueba_arreglo_invertir);
    RUN_TEST(prueba_arreglo_ordenado);
    RUN_TEST(prueba_arreglo_contar);
    RUN_TEST(prueba_arreglo_compactar);
    RUN_TEST(prueba_arreglo_fusionar);
    return TEST_REPORT();
}
