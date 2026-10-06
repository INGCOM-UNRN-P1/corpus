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

TEST(prueba_copiar_arreglo)
{
    SUBCASE("Copia de arreglo valido ");
    const int origen[] = {2, 4, -10, 20};
    int destino[4] = {0, 0, 0, 0};
    ASSERT_TRUE(copiar_arreglo(origen, 4, destino));
    ASSERT_INT_EQ(2, destino[0]);
    ASSERT_INT_EQ(4, destino[1]);
    ASSERT_INT_EQ(-10, destino[2]);
    ASSERT_INT_EQ(20, destino[3]);

    SUBCASE("Cantidad cero y punteros nulos");
    int destino3[1] = {99};
    ASSERT_FALSE(copiar_arreglo(origen, 0, destino3));
    ASSERT_FALSE(copiar_arreglo(NULL, 1, destino3));
    ASSERT_FALSE(copiar_arreglo(origen, 1, NULL));
    ASSERT_INT_EQ(99, destino3[0]);
}

TEST(prueba_invertir_arreglo)
{
    SUBCASE("inverir validos");
    int par[] = {1, 2, 3, 4};
    ASSERT_TRUE(invertir_arreglo(par, 4));
    ASSERT_INT_EQ(4, par[0]);
    ASSERT_INT_EQ(3, par[1]);
    ASSERT_INT_EQ(2, par[2]);
    ASSERT_INT_EQ(1, par[3]);

    SUBCASE("Cantidad cero y puntero nulo");
    int vacio[] = {1, 2, 3};
    ASSERT_FALSE(invertir_arreglo(vacio, 0));
    ASSERT_FALSE(invertir_arreglo(NULL, 3));
    ASSERT_INT_EQ(1, vacio[0]);
    ASSERT_INT_EQ(2, vacio[1]);
    ASSERT_INT_EQ(3, vacio[2]);
}


int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 3", conteo_args, argumentos);
    RUN_TEST(prueba_copiar_arreglo);
    RUN_TEST(prueba_invertir_arreglo);
    return TEST_REPORT();
}
