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
#include "p1_arrays.h"
#include "recorrido.h"

TEST(prueba_copiar_arreglo)
{
    SUBCASE("Guardas ante punteros nulos");
    int origen[3] = {1, 2, 3};
    int destino[3] = {0};
    ASSERT_FALSE(copiar_arreglo(NULL, origen, 3));
    ASSERT_FALSE(copiar_arreglo(destino, NULL, 3));

    SUBCASE("Copia correcta de elementos");
    int datos[4] = {10, 20, 30, 40};
    int copia[4] = {0};
    ASSERT_TRUE(copiar_arreglo(copia, datos, 4));
    ASSERT_ARRAY_INT_EQ(datos, copia, 4);

    SUBCASE("Copia con cantidad cero");
    ASSERT_TRUE(copiar_arreglo(copia, datos, 0));
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("Arreglo con cantidad impar");
    int impar[5] = {1, 2, 3, 4, 5};
    int esperado_impar[5] = {5, 4, 3, 2, 1};
    invertir_arreglo(impar, 5);
    ASSERT_ARRAY_INT_EQ(esperado_impar, impar, 5);

    SUBCASE("Arreglo con cantidad par");
    int par[4] = {10, 20, 30, 40};
    int esperado_par[4] = {40, 30, 20, 10};
    invertir_arreglo(par, 4);
    ASSERT_ARRAY_INT_EQ(esperado_par, par, 4);

    SUBCASE("Casos de borde: un elemento o nulo");
    int unitario[1] = {42};
    invertir_arreglo(unitario, 1);
    ASSERT_INT_EQ(42, unitario[0]);
    invertir_arreglo(NULL, 5);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
