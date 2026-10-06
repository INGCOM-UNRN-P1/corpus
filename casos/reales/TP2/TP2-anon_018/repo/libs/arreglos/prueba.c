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
    SUBCASE("Casos vacios y nulos");
    ASSERT_INT_EQ(0, (int)arreglo_compactar(NULL, 5, 1));
    int vacio[] = {1};
    ASSERT_INT_EQ(0, (int)arreglo_compactar(vacio, 0, 1));

    SUBCASE("Valor que no esta en el arreglo");
    int sin_valor[] = {1, 2, 3};
    int esperado_sin_valor[] = {1, 2, 3};
    ASSERT_INT_EQ(3, (int)arreglo_compactar(sin_valor, 3, 9));
    ASSERT_ARRAY_INT_EQ(esperado_sin_valor, sin_valor, 3);

    SUBCASE("Elimina apariciones y mantiene el orden");
    int datos[] = {1, 7, 2, 7, 3};
    int esperado_datos[] = {1, 2, 3};
    ASSERT_INT_EQ(3, (int)arreglo_compactar(datos, 5, 7));
    ASSERT_ARRAY_INT_EQ(esperado_datos, datos, 3);

    SUBCASE("Valor al principio y al final");
    int extremos[] = {5, 1, 2, 5};
    int esperado_extremos[] = {1, 2};
    ASSERT_INT_EQ(2, (int)arreglo_compactar(extremos, 4, 5));
    ASSERT_ARRAY_INT_EQ(esperado_extremos, extremos, 2);

    SUBCASE("Apariciones consecutivas");
    int seguidos[] = {1, 0, 0, 0, 2};
    int esperado_seguidos[] = {1, 2};
    ASSERT_INT_EQ(2, (int)arreglo_compactar(seguidos, 5, 0));
    ASSERT_ARRAY_INT_EQ(esperado_seguidos, seguidos, 2);

    SUBCASE("Todos los elementos coinciden");
    int todos[] = {4, 4, 4};
    ASSERT_INT_EQ(0, (int)arreglo_compactar(todos, 3, 4));

    SUBCASE("Un solo elemento");
    int uno_igual[] = {8};
    int uno_distinto[] = {8};
    ASSERT_INT_EQ(0, (int)arreglo_compactar(uno_igual, 1, 8));
    ASSERT_INT_EQ(1, (int)arreglo_compactar(uno_distinto, 1, 3));
}


TEST(prueba_arreglo_fusionar)
{
    SUBCASE("Parametros invalidos");
    int a_inv[] = {1, 2};
    int dest_inv[4];
    ASSERT_INT_EQ(0, (int)arreglo_fusionar(a_inv, 2, a_inv, 2, NULL, 4));
    ASSERT_INT_EQ(0, (int)arreglo_fusionar(a_inv, 2, a_inv, 2, dest_inv, 0));
    ASSERT_INT_EQ(0, (int)arreglo_fusionar(NULL, 2, a_inv, 2, dest_inv, 4));
    ASSERT_INT_EQ(0, (int)arreglo_fusionar(a_inv, 2, NULL, 2, dest_inv, 4));

    SUBCASE("Un arreglo vacio");
    int solo[] = {1, 2, 3};
    int dest_uno[5];
    ASSERT_INT_EQ(3, (int)arreglo_fusionar(NULL, 0, solo, 3, dest_uno, 5));
    ASSERT_ARRAY_INT_EQ(solo, dest_uno, 3);

    SUBCASE("Fusion normal con repetidos");
    int a[] = {1, 4, 6};
    int b[] = {2, 4, 9};
    int dest[6];
    int esperado[] = {1, 2, 4, 4, 6, 9};
    ASSERT_INT_EQ(6, (int)arreglo_fusionar(a, 3, b, 3, dest, 6));
    ASSERT_ARRAY_INT_EQ(esperado, dest, 6);

    SUBCASE("Un arreglo completo antes que el otro");
    int menores[] = {1, 2};
    int mayores[] = {3, 4};
    int dest_orden[4];
    int esperado_orden[] = {1, 2, 3, 4};
    ASSERT_INT_EQ(4, (int)arreglo_fusionar(mayores, 2, menores, 2, dest_orden, 4));
    ASSERT_ARRAY_INT_EQ(esperado_orden, dest_orden, 4);

    SUBCASE("Capacidad insuficiente no desborda");
    int dest_corto[6] = {-1, -1, -1, -1, -1, -1};
    int esperado_corto[] = {1, 2, 4, 4};
    ASSERT_INT_EQ(4, (int)arreglo_fusionar(a, 3, b, 3, dest_corto, 4));
    ASSERT_ARRAY_INT_EQ(esperado_corto, dest_corto, 4);
    ASSERT_INT_EQ(-1, dest_corto[4]);
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