/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 1 con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "intercambio.h"


void ordenar_par(int *menor, int *mayor);
void ordenar_tria(int *a, int *b, int *c);
bool sumar_acumulado(const int *arreglo, size_t cantidad, long long *resultado);

TEST(prueba_ordenar_par)
{
    SUBCASE("Par desordenado");
    int primero = 80;
    int segundo = 20;
    ordenar_par(&primero, &segundo);
    ASSERT_INT_EQ(20, primero);
    ASSERT_INT_EQ(80, segundo);

    SUBCASE("Par ya ordenado");
    int primero2 = 10;
    int segundo2 = 50;
    ordenar_par(&primero2, &segundo2);
    ASSERT_INT_EQ(10, primero2);
    ASSERT_INT_EQ(50, segundo2);

    SUBCASE("Valores identicos");
    int id1 = 15;
    int id2 = 15;
    ordenar_par(&id1, &id2);
    ASSERT_INT_EQ(15, id1);
    ASSERT_INT_EQ(15, id2);

    SUBCASE("Punteros nulos");
    int val = 5;
    ordenar_par(NULL, &val);
    ASSERT_INT_EQ(5, val);
    ordenar_par(&val, NULL);
    ASSERT_INT_EQ(5, val);
}

TEST(prueba_ordenar_tria)
{
    SUBCASE("Trio invertido");
    int a = 30, b = 20, c = 10;
    ordenar_tria(&a, &b, &c);
    ASSERT_INT_EQ(10, a);
    ASSERT_INT_EQ(20, b);
    ASSERT_INT_EQ(30, c);

    SUBCASE("Trio ya ordenado");
    int x = 1, y = 2, z = 3;
    ordenar_tria(&x, &y, &z);
    ASSERT_INT_EQ(1, x);
    ASSERT_INT_EQ(2, y);
    ASSERT_INT_EQ(3, z);

    SUBCASE("Trio desordenado intermedio");
    int d = 15, e = 5, f = 10;
    ordenar_tria(&d, &e, &f);
    ASSERT_INT_EQ(5, d);
    ASSERT_INT_EQ(10, e);
    ASSERT_INT_EQ(15, f);

    SUBCASE("Puntero nulo en trio");
    int v1 = 10, v2 = 5;
    ordenar_tria(&v1, NULL, &v2);
    ASSERT_INT_EQ(10, v1);
    ASSERT_INT_EQ(5, v2);
}

TEST(prueba_sumar_acumulado)
{
    SUBCASE("Suma acumulada de arreglo valido");
    int datos[] = {10, 20, 30, 40};
    long long suma = 0;
    ASSERT_TRUE(sumar_acumulado(datos, 4, &suma));
    ASSERT_INT_EQ(100, (int)suma);

    SUBCASE("Arreglo vacio");
    long long suma_vacia = 999;
    ASSERT_TRUE(sumar_acumulado(datos, 0, &suma_vacia));
    ASSERT_INT_EQ(0, (int)suma_vacia);

    SUBCASE("Punteros nulos");
    long long suma_err = 0;
    ASSERT_FALSE(sumar_acumulado(NULL, 4, &suma_err));
    ASSERT_FALSE(sumar_acumulado(datos, 4, NULL));
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 1 (Ordenamiento y Suma)", conteo_args, argumentos);
    RUN_TEST(prueba_ordenar_par);
    RUN_TEST(prueba_ordenar_tria);
    RUN_TEST(prueba_sumar_acumulado);
    return TEST_REPORT();
}
