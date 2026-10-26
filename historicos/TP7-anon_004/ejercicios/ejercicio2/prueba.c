/**
 * @file prueba.c
 * @brief Pruebas completas del Ejercicio 2 con p1_test.
 */

#include <stdio.h>
#include <stdlib.h>
#include "p1_test.h"
#include "matrices.h"
#include "algebra_matrices.h"

bool matriz_sumar(const matriz_t *a, const matriz_t *b, matriz_t *resultado);
bool matriz_multiplicar(const matriz_t *a, const matriz_t *b, matriz_t *resultado);

TEST(prueba_algebra_matrices)
{
    matriz_t a, b, suma, prod;
    matriz_crear(&a, 2, 2);
    matriz_crear(&b, 2, 2);

    matriz_asignar(&a, 0, 0, 1); matriz_asignar(&a, 0, 1, 2);
    matriz_asignar(&a, 1, 0, 3); matriz_asignar(&a, 1, 1, 4);

    matriz_asignar(&b, 0, 0, 5); matriz_asignar(&b, 0, 1, 6);
    matriz_asignar(&b, 1, 0, 7); matriz_asignar(&b, 1, 1, 8);

    SUBCASE("Suma de matrices");
    ASSERT_TRUE(matriz_sumar(&a, &b, &suma));
    int s00 = 0, s11 = 0;
    matriz_obtener(&suma, 0, 0, &s00);
    matriz_obtener(&suma, 1, 1, &s11);
    ASSERT_INT_EQ(6, s00);
    ASSERT_INT_EQ(12, s11);
    matriz_destruir(&suma);

    SUBCASE("Multiplicacion de matrices");
    ASSERT_TRUE(matriz_multiplicar(&a, &b, &prod));
    int p00 = 0, p01 = 0;
    matriz_obtener(&prod, 0, 0, &p00);
    matriz_obtener(&prod, 0, 1, &p01);
    ASSERT_INT_EQ(19, p00); 
    ASSERT_INT_EQ(22, p01); 
    matriz_destruir(&prod);

    matriz_destruir(&a);
    matriz_destruir(&b);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: Ejercicio 2", conteo_args, argumentos);
    RUN_TEST(prueba_algebra_matrices);
    return TEST_REPORT();
}
