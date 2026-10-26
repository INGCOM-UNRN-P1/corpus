/**
 * @file prueba.c
 * @brief Pruebas unitarias de libmatrices con p1_test.
 */

#include <stdio.h>
#include "p1_test.h"
#include "matrices.h"

TEST(prueba_matriz_operaciones_basicas)
{
    matriz_t m;
    ASSERT_TRUE(matriz_crear(&m, 3, 4));
    ASSERT_PTR_NOT_NULL(m.filas);
    ASSERT_PTR_NOT_NULL(m.datos);
    ASSERT_INT_EQ(3, (int)m.cant_filas);
    ASSERT_INT_EQ(4, (int)m.cant_columnas);

    ASSERT_TRUE(matriz_asignar(&m, 1, 2, 42));
    int val = 0;
    ASSERT_TRUE(matriz_obtener(&m, 1, 2, &val));
    ASSERT_INT_EQ(42, val);

    ASSERT_FALSE(matriz_asignar(&m, 3, 0, 10));
    ASSERT_FALSE(matriz_obtener(&m, 0, 4, &val));

    matriz_destruir(&m);
    ASSERT_PTR_NULL(m.filas);
    ASSERT_PTR_NULL(m.datos);
}

int main(int conteo_args, char **argumentos)
{
    TEST_SUITE_BEGIN_ARGS("Suite de Pruebas: libmatrices", conteo_args, argumentos);
    RUN_TEST(prueba_matriz_operaciones_basicas);
    return TEST_REPORT();
}
